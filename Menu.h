#include "Array.h"

class Menu
{
    private:
        int selectedOption;
		std::string continueKey;
        Array<Student> StudentArray;
		
    public:
        Menu();
        void display();
		void gradesByStudent();
		void gradesBySubject();
		void sortedAverages();
		void modifyGrades();
		void writeTextFile();
		
};