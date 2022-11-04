//
// Created by Utilizador on 04-Nov-22.
//

#include "alteration.h"

Student alteration::getstudent() {
    return student;
}

Class alteration::getclasses() {
    return classes;
}

string alteration::gettype() {
    return type;
}

void alteration::setclasses(Class aclass) {
    classes = aclass;
}

alteration::alteration(Student student, Class aclass, string type, Class classes) : classes(classes) {
    this->student=student;
    this->classes = aclass;
    this->type=type;
}

