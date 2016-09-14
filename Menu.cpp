/*
Parcial exam 1
Luis Enrique Guitron A01018616
Juan Pablo Güitrón A01019936
Data Structures
14/09/2016
legl_1995@hotmail.com
jpgl1997@gmail.com
*/

#include "Menu.h"

Menu::Menu()
{
	std::cout<<std::endl<<"Welcome to the Student Grade System!"<<std::endl<<std::endl;
}

void Menu::display()
{
    std::cout<<"Please select an option:"<<std::endl;
    std::cout<<"1. View grades by student"<<std::endl;
    std::cout<<"2. View grades by subject"<<std::endl;
    std::cout<<"3. List students sorted by average"<<std::endl;
    std::cout<<"4. Modify grades"<<std::endl;
    std::cout<<"5. Exit"<<std::endl;
    selection(1,5);
	
	switch (selectedOption)
	{
		case 1:
		gradesByStudent();
		break;
		
		case 2:
		gradesBySubject();
		break;
		
		case 3:
		sortedAverages();
		break;
		
		case 4:
		modifyGrades();
		break;
		
		case 5:
		writeTextFile();
		break;
		
		default:
		std::cout<<"Unexpected error"<<std::endl;
		display();
		break;
	}
	
	
}

void Menu::gradesByStudent()
{
	std::cout<<std::endl<<"Please select a student index to view his/her grades: "<<std::endl;
	for(int i = 0; i<StudentArray.getSize();i++)
	{
		std::cout<<i+1<<". "<<StudentArray.getElement(i).getName()<<std::endl;
	}
	
	selection(1,StudentArray.getSize());
	std::cout<<std::endl;
	
	//Print all the grades of the selected student//
	StudentArray.getElement(selectedOption-1).printGrades();
	goBack();
}


//Show student grades by subject//
void Menu::gradesBySubject()
{
	std::cout<<std::endl<<"Please select a subject to view students' grades on it: "<<std::endl;
	for(int i = 0; i<SUBSIZE;i++)
	{
		std::cout<<i+1<<". "<<Student::getSubject(i)<<std::endl;
	}
	
	selection(1,SUBSIZE);
	
	//Print selected subject's name//
	std::cout<<std::endl<<Student::getSubject(selectedOption-1)<<std::endl;
	
	//Print students' names and grades in the selected subject//
	for(int i = 0; i<StudentArray.getSize();i++)
	{
		std::cout<<i+1<<". "<<StudentArray.getElement(i).getName()<<": "<<StudentArray.getElement(i).getGrade(selectedOption-1)<<std::endl;
	}
		
	goBack();

}

//Show sorted array of students
//(Array gets sorted at the Array class constructor
//and whenever a student's grade is modified)
void Menu::sortedAverages()
{
	std::cout<<std::endl;
	for(int i = StudentArray.getSize()-1; i>=0;i--)
	{
		std::cout<<5-i<<". "<<StudentArray.getElement(i)<<std::endl;
	}
	goBack();
}

//Change a specific grade of a student//
void Menu::modifyGrades()
{
	
	int newGrade;
	int student;
	int subject;
	
	std::cout<<std::endl<<"Please select a student index to modify his/her grades: "<<std::endl;
	for(int i = 0; i<StudentArray.getSize();i++)
	{
		std::cout<<i+1<<". "<<StudentArray.getElement(i).getName()<<std::endl;
	}
	
	//Select student
	selection(1,StudentArray.getSize());
	student=selectedOption-1;
	
	std::cout<<std::endl<<"Please select a subject to change the student's grade in it:  "<<std::endl;
	
	std::cout<<StudentArray.getElement(student).getName()<<std::endl;
	for(int i = 0; i<SUBSIZE;i++)
	{
		std::cout<<i+1<<". "<<Student::getSubject(i)<<std::endl;
	}
	
	//Select subject
	selection(1,SUBSIZE);
	subject=selectedOption-1;
	
	std::cout<<std::endl<<StudentArray.getElement(student).getName()<<std::endl;
	std::cout<<Student::getSubject(subject)<<std::endl;
	std::cout<<"Enter the new grade:  "<<std::endl;
	
	selection(0,100);
	newGrade=selectedOption;
	
	StudentArray.getElement(student).setGrade(subject,newGrade);
	StudentArray.mergeS();
	goBack();

}

//Save the data in a file when the program ends//
void Menu::writeTextFile()
{
   std::ofstream file;
   file.open("StudentFile(1).txt",std::fstream::out);

   //Write number of students//
   file << "Number of Students: "<<StudentArray.getSize()<<std::endl;
   
   //Write Subjects//
   for(int i = 0;i<SUBSIZE;i++)
   {
   	  file<<Student::getSubject(i)<<" ";
   }
   file<<std::endl;
	
	//Write student data//
	for(int i=StudentArray.getSize()-1; i>=0;i--)
	{
		//Write students' names//
		file<<StudentArray.getElement(i).getName()<<std::endl;
		
		//Write students' grades//
		for(int j=0; j<SUBSIZE; j++)
		{
			file<<StudentArray.getElement(i).getGrade(j)<<" ";
		}
		file<<std::endl;
	}
   file.close();
}

//Returns to the menu when another function ends//
void Menu::goBack()
{
	std::cout<<std::endl<<"Enter any key to continue: ";
	std::cin>>continueKey;
	std::cout<<std::endl;
	display();
}

//Get the selected option of the user//
//This function validates the inputs introduced by the users//
void Menu::selection(int min,int max)
{
	while(true)
	{
		std::cout<<"Your selection: ";
		
		if ( !(std::cin>>selectedOption) )
        {
          std::cin.clear();
          std::cin.ignore();
          std::cout<<"That is not a valid option, please select a number between "<<min<<" and "<<max<<std::endl;
        }

		else if( selectedOption >= min && selectedOption <= max)
		{
			break;
		}
	
		else
		{
			std::cout<<"That is not a valid option, please select a number between "<<min<<" and "<<max<<std::endl;
		}
	}
}