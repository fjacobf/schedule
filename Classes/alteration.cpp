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

alteration::alteration(Student student, string type, Class classes){
    this->student=student;
    this->classes = classes;
    this->type=type;
}

