/*
Parcial exam 1
Luis Enrique Guitron A01018616
Juan Pablo Güitrón A01019936
Data Structures
24/08/2016
legl_1995@hotmail.com
jpgl1997@gmail.com
*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Student.h"

template <class type>
class Array
{

private:
	type* data;
	int binarySearchRecursive(type item, int start, int end);

public:
	Array(int size);
	~Array();
	void setElement(int index, type item);
	type getElement(int index);
	void printRecursive(unsigned n);
	void mergeSort();
	void mergePartitions(type * partA,int sizeA ,type* partB, int SizeB, type*partition);
	

	//Searching
	int binarySearchRecursive(type item);

	//Helper method
	bool checkOrdered();
	
	//Operator overloads//
	type & operator [](const int index);
	const type & operator [](const int index)const;
	
	//File Reader//
	void readFile();
};


template <class type>
Array<type>::Array()
{

}

//______________________________________Filling array________________________________//

template <class type>
void Array<type>::setElement(int index, type item)
{
	if(index >=0 && index<size)
	{
		data[index]=item;
	}
}

template <class type>
type Array<type>::getElement(int index)
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

template <class type>
void Array<type>::mergeSort()
{
	mergeSort(size,data);
}
template <class type>
void Array<type>::mergeSort(int partitionSize, type* partition)
{
	
	int middle = (int)(partitionSize/2);
	type partition1[middle];
	type partition2[partitionSize - middle];	
	
	
	//Subdivide array into smaller partitions until they are of size 1//
	if(partitionSize>1)
	{
		for(int i = 0; i<middle; i++)
		{
			partition1[i]=partition[i];
		}	
		
		for(int i = middle; i<partitionSize; i++)
		{
			partition2[i-middle] = partition[i];
		}	
		
		mergeSort(middle,partition1);
		mergeSort(partitionSize-middle,partition2);
		
		//Start sorting partitions, it will start with partitions of size 1 and then go with the bigger ones//
		mergePartitions(partition1,middle,partition2,partitionSize-middle,partition);
	}
	
}
template <class type>
void Array<type>::mergePartitions(type * partA ,int sizeA, type* partB, int sizeB, type* partition)
{
	int index_A=0;
	int index_B=0;
	int index_data=0;
	
	//Make sure to keep inside partitions length when sorting them//
	while(index_A<sizeA && index_B<sizeB)
	{
		if(partA[index_A]<partB[index_B])
		{
			partition[index_data]=partA[index_A];
			index_A++;
		}
		
		else
		{
			partition[index_data]=partB[index_B];
			index_B++;
		}
		index_data++;
	}
	
	//Check if any of the partitions remained with data after one of them is done//
	while(index_A<sizeA)
	{
		partition[index_data]=partA[index_A];
		index_A++;
		index_data++;
	}
	
	while(index_B<sizeB)
	{
		partition[index_data]=partB[index_B];
		index_B++;
		index_data++;
	}
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

//________________________________Operator Overloads_____________________________//
template <class type>
type & Array<type>::operator [](const int index)
{
	if(index >=0 && index<size)
		return data[index];
}

//Read only
//Para que se mande llamar esta funcion se debe mandar a llamad con un Array constante
template <class type>
const type & Array<type>::operator [](const int index)const
{
	if(index >=0 && index<size)
		return data[index];
}

//________________________________File Reader_____________________________________//

template <class type>
void Array<type>::readFile()
{
	FILE * pFile;
   char buffer [50];

   errno_t errorCode = fopen_s(&pFile,"StudentFile.txt" , "r");
   
   if (pFile == NULL) 
		perror ("Error opening file");
		
   else
   {
     while ( ! feof (pFile) )
     {
       if ( fgets (buffer , 100 , pFile) == NULL ) break;
       fputs (buffer , stdout);
     }
     fclose (pFile);
   }

}

template <class type>
Array<type>::~Array()
{
	delete[]data;
}
