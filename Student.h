#include <string>
#include <stdlib.h>
#include <iostream>
#define SUBSIZE 6
using namespace std;
class Student
{
    private:
	
		int grades[SUBSIZE];
        static std::string subjects[SUBSIZE];
        std::string name;
        float avGrade;

    public:

        Student();
        ~Student();
    
        //Static functions//
        static void setSubject(int index, std::string subject);
		static std::string getSubject(int index);
		
        //Set & Get Functions//
		void setName(std::string name);
        void changeGrade(int index, int grade);
        int getGrade(int index);
        string getName();
		int subjectExist(string subject);
		
		//Print Method
		 void printGrades();
		 
		//Operator Overloads//
        bool operator > (const Student &student);
        bool operator < (const Student &student);
        bool operator >= (const Student &student);
        bool operator <= (const Student &student);
        friend std::ostream & operator<< (std::ostream & stream, const Student & student);

};