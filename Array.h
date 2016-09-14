/*
Parcial exam 1
Luis Enrique Guitron A01018616
Juan Pablo Güitrón A01019936
Data Structures
14/09/2016
legl_1995@hotmail.com
jpgl1997@gmail.com
*/



#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Student.h"

template <class type>
class Array
{

private:
	int size;
	type* data;
	void mergeSort( int middle, int min, int max);
	void mergeSort(int min, int max);
	
	//File Reader//
	void getStudentData();

public:
	Array();
	~Array();
	
	//Set & get methods
	void setElement(int index, type item);
	type & getElement(int index);
	int getSize();
	
	//Sorting
	void mergeS();
};


template <class type>
Array<type>::Array()
{
	getStudentData();
	mergeS();
}

//______________________________________Set & Get Methods________________________________//

template <class type>
void Array<type>::setElement(int index, type item)
{
	if(index >=0 && index<size)
	{
		data[index]=item;
	}
}

template <class type>
type & Array<type>::getElement(int index)
{
	if(index >=0 && index<size)
	{
		return data[index];
	}
	else
	{
		std::cout<<"Invalid index"<<std::endl;
		return data[0];
	}
}

template <class type>	
int Array<type>::getSize()
{
	return size;
}

//__________________________________________Sorting_____________________________________//
template <class Type>
void Array<Type>::mergeS()
{
	mergeSort(0, size - 1);
}

template <class Type>
void Array<Type>::mergeSort(int min, int max)
{
	if (min < max)
	{

		mergeSort(min, min + (max - min) / 2);
		mergeSort((min + (max - min) / 2) + 1, max);

		mergeSort(min + (max - min) / 2, min, max);

	}
}

template <class Type>
void Array<Type>::mergeSort(int middle, int min, int max)
{
	//Variables & counters
	int a = 0;
	int b = 0;
	int count = min;
	int md = middle - min + 1;
	int mu = max - middle;

	//temporal arrays
	Type * cache2 = new Type[mu];
	Type * cache1 = new Type[md];

	//Write the temporal info in the arrays
	for (int x = 0; x < md; x++)
	{
		cache1[x] = data[min + x];

	}
	for (int y = 0; y <mu; y++)
	{
		cache2[y] = data[middle +1+ y];
	}

	//Compare info of the temp arrays
	while (a < md && b < mu)
	{
		if (cache1[a] <= cache2[b])
		{
			data[count] = cache1[a];
			a++;
			count++;
		}
		else
		{
			data[count] = cache2[b];
			b++;
			count++;
		}
	}

	//write the rest of the info
	while (a < md)
	{
		data[count] = cache1[a];
		a++;
		count++;
	}

	while (b < mu)
	{
		data[count] = cache2[b];
		b++;
		count++;
	}
	//delete temporal arrays
	delete[] cache1;
	delete[] cache2;
}

//________________________________File Reader_____________________________________//

template <class type>
void Array<type>::getStudentData()
{
	std::ifstream file;
	char buffer[80];
	std::string currentLine;
	int wordNum=0;
	int lineNum=0;
	
	file.open("StudentFile.txt",std::fstream::in);
   if(file.fail())
   {
      std::cout<<"Error opening file"<<std::endl;
   }
   
	//Read first line, and get the number of students in the array//
	file.getline(buffer,sizeof(buffer));
	currentLine=buffer;
	
	//istringstream distinguishes substrings separated by space//
	std::istringstream iss1(currentLine);
	do
	{
		std::string subString;
		iss1 >> subString;
		
		//Number of students is the first line's fourth
		//word in the StudentFile.txt file
		if(wordNum==3)
		{
			size = atoi(subString.c_str());
			data= new type[size];
		}
		wordNum++;

	}while (iss1);

     //Read second line to get subjects' names//
	file.getline(buffer,sizeof(buffer));
	currentLine=buffer;
	wordNum=0;
	std::istringstream iss2(currentLine);
	do
	{
		std::string subString;
		iss2 >> subString;
		if(wordNum<SUBSIZE)
			Student::setSubject(wordNum,subString);
		wordNum++;

	}while (iss2);
	
	//Read the remaining line to get students' information//
   	while(!file.eof())
	{
		wordNum=0;
		file.getline(buffer,sizeof(buffer));
		currentLine=buffer;
		
		//Name of a student (Even row)//
		if(lineNum%2==0)
		{
			Student newStudent;
			data[lineNum/2]=newStudent;
			data[lineNum/2].setName(currentLine);
		}

		//Grades of a student (Odd row)//
		else
		{
			std::istringstream iss(currentLine);
			do
			{
				std::string grade;
				iss >> grade;
				if(wordNum<SUBSIZE)
					data[(lineNum-1)/2].setGrade(wordNum, atoi(grade.c_str()));
				wordNum++;

			}while (iss);
		}
		lineNum++;
	}
}

template <class type>
Array<type>::~Array()
{
	delete []data;
}