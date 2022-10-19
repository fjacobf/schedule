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
};


#endif //SCHEDULE_STUDENT_H
