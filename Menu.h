/*
Parcial exam 1
Luis Enrique Guitron A01018616
Juan Pablo Güitrón A01019936
Data Structures
14/09/2016
legl_1995@hotmail.com
jpgl1997@gmail.com
*/

#include "Array.h"

class Menu
{
    private:
        //Variables//
        int selectedOption;
		std::string continueKey;
        Array<Student> StudentArray;
		
    public:
        //Constructos//
        Menu();
        
        //Main functions//
        void display();
		void gradesByStudent();
		void gradesBySubject();
		void sortedAverages();
		void modifyGrades();
		void writeTextFile();
		
		//Helper methods//
		void goBack();
		void selection(int min, int max);
		
};