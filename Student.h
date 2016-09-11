#include <string>
#include <stdlib.h>
#include <iostream>
#define sub 6
using namespace std;
class Student
{
    private:
	
		int grades[sub];
        string subjects[sub];
        string name;
        float avGrade;

    public:

        Student();
        ~Student();

        //Set & Get Functions//
		void setName(std::string name);
        void setSubject(int index, string subject);
		std::string getSubject(int index);
        void changeGrade(int index, int grade);
		int subjectExist(string subject);
		
		//Operator Overloads//
        bool operator > (const Student &student);
        bool operator < (const Student &student);
        bool operator >= (const Student &student);
        bool operator <= (const Student &student);

        void printGrades();
        int getGrade(int index);
        string getName();

        friend std::ostream & operator<< (std::ostream & stream, const Student & student);

};
