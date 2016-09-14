/*
Parcial exam 1
Luis Enrique Guitron A01018616
Juan Pablo Güitrón A01019936
Data Structures
14/09/2016
legl_1995@hotmail.com
jpgl1997@gmail.com
*/

#include "Student.h"
//It is required to initialize a static array
std::string Student::subjects[SUBSIZE]={".",".",".",".",".","."};

Student::Student()
{
}

void Student::setName(std::string name)
{
	this->name=name;
}

//Set & Get functions//
void Student::setSubject(int index, std::string subject)
{
    subjects[index]=subject;
}

std::string Student::getSubject(int index)
{
	return Student::subjects[index];
}

void Student::setGrade(int index,int grade)
{
  grades[index]=grade;
  avGrade=0;
  for(int x=0;x<SUBSIZE;x++)
  {
    avGrade+=grades[x];
  }
  avGrade=avGrade/SUBSIZE;
}

//Print Method//
void Student::printGrades()
{
	std::cout<<"\t"<<name<<std::endl;
	for(int x=0;x<SUBSIZE;x++)
	{
		std::cout<<"\t"<<subjects[x]<<": "<<grades[x]<<std::endl;
	}
}

//Operator Overloads//
bool Student::operator > (const Student &student)
{
	return(avGrade>student.avGrade);
}

bool Student::operator < (const Student &student)
{
	return(avGrade<student.avGrade);
}

bool Student::operator >= (const Student &student)
{
	return(avGrade>=student.avGrade);
}

bool Student::operator <= (const Student &student)
{
	return(avGrade<=student.avGrade);
}

std::string Student::getName()
{
  return name;
}
int Student::getGrade(int index)
{
  return grades[index];
}

std::ostream & operator<<(std::ostream & stream, const Student & student)
{
	stream<<student.name<<": "<<student.avGrade;
	return stream;
}

Student::~Student()
{
}
