#include "Student.h"

std::string Student::subjects[SUBSIZE]={".",".",".",".",".","."};

Student::Student()
{
}

void Student::setName(std::string name)
{
	this->name=name;
}

//Set & Get functions//
void Student::setSubject(int index, string subject)
{
    subjects[index]=subject;
}

std::string Student::getSubject(int index)
{
	return Student::subjects[index];
}

int Student::subjectExist(string subject)
{
  int x=0;
  while(x<SUBSIZE)
  {
      if(subjects[x]==subject)
          break;
      x++;
  }

  if (x>=SUBSIZE)
  {
      std::cout<<"The subject doesn't exist"<<std::endl;
      return -1;
  }
  return x;
}

void Student::changeGrade(int index,int grade)
{
    //int id=subjectExist(subject);

    if(index!=-1)
    {
        grades[index]=grade;
        avGrade=0;
        for(int x=0;x<SUBSIZE;x++)
        {
          avGrade+=grades[x];
        }
        avGrade=avGrade/SUBSIZE;
    }
}



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

string Student::getName()
{
  return name;
}
int Student::getGrade(int index)
{
  return grades[index];
}

void Student::printGrades()
{
	std::cout<<"\t"<<name<<std::endl;
	for(int x=0;x<SUBSIZE;x++)
	{
		std::cout<<"\t"<<subjects[x]<<": "<<grades[x]<<std::endl;
	}
}

std::ostream & operator<<(std::ostream & stream, const Student & student)
{
	stream <<"Name: "<<student.name<<std::endl;
  stream <<"Average: "<<student.avGrade<<std::endl;
	return stream;
}

Student::~Student()
{
}
