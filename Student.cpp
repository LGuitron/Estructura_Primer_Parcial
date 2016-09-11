#include "Student.h"

Student::Student()
{
    subjects[0]="Matematicas";
    subjects[1]="Fisica";
    subjects[2]="Quimica";
    subjects[3]="Programacion";
    subjects[4]="Ingles";
    subjects[5]="Etica";
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
	return subjects[index];
}

int Student::subjectExist(string subject)
{
  int x=0;
  while(x<sub)
  {
      if(subjects[x]==subject)
          break;
      x++;
  }

  if (x>=sub)
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
        for(int x=0;x<sub;x++)
        {
          avGrade+=grades[x];
        }
        avGrade=avGrade/sub;
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
	for(int x=0;x<sub;x++)
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
