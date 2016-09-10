#include <string>

class Student
{
    private:
    
        float* grades;
        static string[6] subjects;
        string name;
        float avGrade;
        
    public:
    
        Student();
        ~Student();
        void setSubject(int index, string subject);
};