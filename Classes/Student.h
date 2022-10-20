#ifndef SCHEDULE_STUDENT_H
#define SCHEDULE_STUDENT_H
#include <string>
#include "Class.h"
using namespace std;

//Um estudante é identificado por um código e nome, e
//tem um horário associado.

class Student {
private:
    long int studentCode;
    string studentName;
    list <Class> classes;
public:

    long int getcode();
    string getname();
    list<Class> getclasses();
    void setcode(long int n);
    void setname(string n);
    void setclasses(list<Class> list);

};


#endif //SCHEDULE_STUDENT_H
