//
// Created by user on 10/15/2022.
//

#include "Student.h"

long int Student::getcode() {
    return studentCode;
}

string Student::getname() {
    return studentName;
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

void Student::setclasses(list<Class> list) {
    classes=list;
}