/*
Parcial exam 1
Luis Enrique Guitron A01018616
Juan Pablo Güitrón A01019936
Data Structures
14/09/2016
legl_1995@hotmail.com
jpgl1997@gmail.com
*/

#include <string>
#include <stdlib.h>
#include <iostream>
#define SUBSIZE 6

class Student
{
    private:
	    
	    //Variables//
		int grades[SUBSIZE];
        static std::string subjects[SUBSIZE];//Static array for students' subjects
        std::string name;
        float avGrade;

    public:

        Student();
        ~Student();
    
        //Static functions for students' subjects//
        static void setSubject(int index, std::string subject);
		static std::string getSubject(int index);
		
        //Set & Get Functions//
		void setName(std::string name);
        void setGrade(int index, int grade);
        int getGrade(int index);
        std::string getName();
		
		//Print Method//
		 void printGrades();
		 
		//Operator Overloads//
        bool operator > (const Student &student);
        bool operator < (const Student &student);
        bool operator >= (const Student &student);
        bool operator <= (const Student &student);
        friend std::ostream & operator<< (std::ostream & stream, const Student & student);

};