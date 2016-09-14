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
	int binarySearchRecursive(type item, int start, int end);
	void mergeSort( int middle, int min, int max);
	void mergeSort(int min, int max);

public:
	Array();
	~Array();
	
	//Set & get methods
	void setElement(int index, type item);
	type & getElement(int index);
	int getSize();
	
	//Sorting
	void mergeS();

	//Searching
	int binarySearchRecursive(type item);

	//Helper methods//
	bool checkOrdered();
	void printRecursive(unsigned n);
	
	//File Reader//
	void getData();
};


template <class type>
Array<type>::Array()
{
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

//________________________________________Searching_______________________________________//

template <class type>
int Array<type>::binarySearchRecursive(type item)
{
	return binarySearchRecursive(item, 0, size - 1);
}
template <class type>
int Array<type>::binarySearchRecursive(type item, int start, int end)
{
	//Base case
	if (start > end)
		return -1;

	int middle = (start + end) / 2;

	if (item < data[middle])
		return	binarySearchRecursive(item, start, middle - 1);

	else if (item > data[middle])
		return binarySearchRecursive(item, middle + 1, end);

	else
		return middle;

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


//_________________________________Helper Methods________________________________//
template <class type>
bool Array<type>::checkOrdered()
{
	for (int i = 0; i < size-1; i++)
	{
		if (data[i] > data[i + 1])
		{
			return false;
		}
	}
	return true;
}
	
template <class type>
void Array<type>::printRecursive(unsigned n)
{

	if (n < size)
	{
		std::cout << data[n] << ", ";
		printRecursive(n + 1);
	}

	else
	{
		std::cout << std::endl;
	}
}

//________________________________File Reader_____________________________________//

template <class type>
void Array<type>::getData()
{
	std::ifstream file;
	char buffer[80];
	std::string currentLine;
	int lineNum=0;
	int wordNum=0;
	int currentStudent=0;
	file.open("StudentFile.txt",std::fstream::in);

   if(file.fail())
   {
      std::cout<<"Error opening file"<<std::endl;
   }
   //Get size of array//
    while(lineNum==0)
	{
		file.getline(buffer,sizeof(buffer));
		currentLine=buffer;

		//istringstream distinguishes substrings separated by space//
		std::istringstream iss(currentLine);
		do
		{
			std::string subString;
			iss >> subString;
			if(wordNum==3)
			{
				size = atoi(subString.c_str());
				data= new type[size];
			}
			wordNum++;

		}while (iss);
		lineNum++;
	}

     //Get subjects//
    while(lineNum==1)
	{
		file.getline(buffer,sizeof(buffer));
		currentLine=buffer;
		wordNum=0;
		std::istringstream iss(currentLine);
		do
		{
			std::string subString;
			iss >> subString;
			if(wordNum<SUBSIZE)
				Student::setSubject(wordNum,subString);
			wordNum++;

		}while (iss);
		lineNum++;
	}

   	while(!file.eof())
	{
		wordNum=0;
		file.getline(buffer,sizeof(buffer));
		//Name of a student//
		if(lineNum%2==0)
		{
			Student newStudent;
			data[currentStudent]=newStudent;
			data[currentStudent].setName(buffer);
		}

		//Grades of a student//
		else
		{
			currentLine=buffer;
			std::istringstream iss(currentLine);
			do
			{
				std::string grade;
				iss >> grade;
				if(wordNum<SUBSIZE)
					data[currentStudent].changeGrade(wordNum, atoi(grade.c_str()));
				wordNum++;

			}while (iss);
			currentStudent++;
		}
		lineNum++;
	}
}

template <class type>
Array<type>::~Array()
{
}
