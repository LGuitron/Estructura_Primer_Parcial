#include "Menu.h"

Menu::Menu()
{
	std::cout<<std::endl<<"Welcome to the Student Grade System!"<<std::endl<<std::endl;
	//Get Array data from text file and order students by their averages//
	StudentArray.getData();
	StudentArray.mergeS();
}

void Menu::display()
{
    std::cout<<"Please select an option:"<<std::endl;
    std::cout<<"1. View grades by student"<<std::endl;
    std::cout<<"2. View grades by subject"<<std::endl;
    std::cout<<"3. List students sorted by average"<<std::endl;
    std::cout<<"4. Modify grades"<<std::endl;
    std::cout<<"5. Exit"<<std::endl;
	
	std::cin>>selectedOption;
	
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
		std::cout<<"That is not a valid option, please select a number between 1 and 5"<<std::endl;
		display();
		break;
	}
	
	
}

void Menu::gradesByStudent()
{
	std::cout<<std::endl<<"Please select a student index to view his/her grades: "<<std::endl;
	for(int i = 0; i<StudentArray.getSize();i++)
	{
		std::cout<<i+1<<". "<<StudentArray.getStudent(i).getName()<<std::endl;
	}
	
	std::cin>>selectedOption;
	
	if( selectedOption>0 && selectedOption<=StudentArray.getSize())
	{
		StudentArray.getStudent(selectedOption-1).printGrades();
		std::cout<<std::endl<<"Enter any key to continue: ";
		std::cin>>continueKey;
		std::cout<<std::endl;
		display();
	}
	
	else
	{
		std::cout<<"That is not a valid option, please select a number between 1 and "<<StudentArray.getSize()<<std::endl;
		gradesByStudent();
	}
}


//_____________________________________CAMBIAR GETSTUDENT(0) POR FORMA STATIC_____________________________________________//
void Menu::gradesBySubject()
{
	std::cout<<std::endl<<"Please select a subject to view students' grades on it: "<<std::endl;
	for(int i = 0; i<6;i++)
	{
		std::cout<<i+1<<". "<<StudentArray.getStudent(0).getSubject(i)<<std::endl;
	}
	
	std::cin>>selectedOption;
	
	if( selectedOption>0 && selectedOption<=6)
	{
		std::cout<<std::endl<<StudentArray.getStudent(0).getSubject(selectedOption-1)<<std::endl;
		for(int i = 0; i<StudentArray.getSize();i++)
		{
			std::cout<<i+1<<". "<<StudentArray.getStudent(i).getName()<<std::endl;
			std::cout<<": "<<StudentArray.getStudent(i).getGrade(selectedOption-1)<<std::endl;
		}
		std::cout<<std::endl<<"Enter any key to continue: ";
		std::cin>>continueKey;
		std::cout<<std::endl;
		display();
	}
	
	else
	{
		std::cout<<"That is not a valid option, please select a number between 1 and 6"<<std::endl;
		gradesBySubject();
	}
	
}

void Menu::sortedAverages()
{
	for(int i = StudentArray.getSize()-1; i>=0;i--)
	{
		std::cout<<StudentArray.getStudent(i)<<std::endl;
	}
	std::cout<<std::endl<<"Enter any key to continue: ";
	std::cin>>continueKey;
	std::cout<<std::endl;
	display();
}

void Menu::modifyGrades()
{
	
	int selectedSubject;
	int newGrade;
	
	std::cout<<std::endl<<"Please select a student index to modify his/her grades: "<<std::endl;
	for(int i = 0; i<StudentArray.getSize();i++)
	{
		std::cout<<i+1<<". "<<StudentArray.getStudent(i).getName()<<std::endl;
	}
	
	//Select student
	std::cin>>selectedOption;
	if( selectedOption>0 && selectedOption<=StudentArray.getSize())
	{
		std::cout<<std::endl<<"Please select a subject to change the student's grade in it:  "<<std::endl;
		std::cout<<std::endl<<StudentArray.getStudent(selectedOption-1).getName()<<std::endl;
		for(int i = 0; i<6;i++)
		{
			std::cout<<i+1<<". "<<StudentArray.getStudent(0).getSubject(i)<<std::endl;
		}
		std::cin>>selectedSubject;
		
		//Select subject
		if( selectedSubject>0 && selectedSubject<=6)
		{
			std::cout<<std::endl<<StudentArray.getStudent(selectedOption-1).getName()<<std::endl;
			std::cout<<std::endl<<StudentArray.getStudent(0).getSubject(selectedSubject-1)<<std::endl;
			std::cout<<std::endl<<"Enter the new grade:  "<<std::endl;
			std::cin>>newGrade;
			StudentArray.getStudent(selectedOption-1).changeGrade(selectedSubject-1,newGrade);
			StudentArray.mergeS();
			
			std::cout<<std::endl<<"Enter any key to continue: ";
			std::cin>>continueKey;
			std::cout<<std::endl;
			display();
		}
	
		else
		{
			std::cout<<"That is not a valid option, please select a number between 1 and 6"<<std::endl;
			modifyGrades();
		}	
	}
	
	else
	{
		std::cout<<"That is not a valid option, please select a number between 1 and "<<StudentArray.getSize()<<std::endl;
		modifyGrades();
	}
}

void Menu::writeTextFile()
{
   ofstream file;
   file.open("StudentFile(1).txt",fstream::out);

   //Write number of students//
   file << "Number of Students: "<<StudentArray.getSize()<<std::endl;
   
   //Write Subjects//
   for(int i = 0;i<6;i++)
   {
	  file << StudentArray.getStudent(0).getSubject(i)<<" "; 
   }
   file<<endl;
	
	//Student data//
	for(int i=StudentArray.getSize()-1; i>=0;i--)
	{
		file<<StudentArray.getStudent(i).getName()<<std::endl;
		
		for(int j=0; j<6; j++)
		{
			file<<StudentArray.getStudent(i).getGrade(j)<<" ";
		}
		file<<endl;
	}
   file.close();
}