#ifndef SCHEDULE_STUDENT_H
#define SCHEDULE_STUDENT_H
#include <string>
#include "Class.h"

using namespace std;
///Classe para os Estudantes.
///
///Um estudante é identificado por um código e nome, e tem um horário associado.

class Student {
private:
    long int studentCode;
    int year;
    string studentName;
    list<Class> classes;
public:
    Student();

    Student(int studentCode, string name);

    Student(int studentCode, string name, Class classe);

    long int getcode() const;

    string getname() const;

    int getyear() const;

    list<Class> getclasses();

    void setcode(long int n);

    void setname(string n);

    void setyear();

    void insertClass(Class classe);

    void popClass(Class classe);

    bool operator==(const Student &student) const;

    bool operator<(const Student &student) const;


    friend std::ostream& operator<<(std::ostream& os , const Student& student);

    list<Time_slot> gettimetable();
};

#endif //SCHEDULE_STUDENT_H
