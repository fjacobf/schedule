//
// Created by user on 10/15/2022.
//

#include "Student.h"
#include <sstream>
Student::Student(int studentCode, string name) {
    setcode(studentCode);
    setname(name);
}

Student::Student(int studentCode, string name, Class classe) {
    setcode(studentCode);
    setname(name);
    insertClass(classe);

}

long int Student::getcode() const {
    return this->studentCode;
}

string Student::getname() const{
    return this->studentName;
}

int Student::getyear() const {
    return this->year;
}

list<Class> Student::getclasses() {
    return classes;
}

void Student::setcode(long n) {
    studentCode = n;
}

void Student::setname(string n) {
    studentName = n;
}

void Student::setyear(int n) {
    year = studentCode/100000;
}

void Student::insertClass(Class classe) {
    this->classes.push_back(classe);
}


//operators overload
bool Student::operator==(const Student& student) const{
    return studentCode == student.getcode();
}

std::ostream& operator<<(std::ostream& os , const Student& student)
{
    os << student.getname() << " - " << student.getcode();
    return os;
}

bool Student::operator<(const Student &student) const
{
    return studentCode < student.getcode();
}