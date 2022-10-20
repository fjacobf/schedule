//
// Created by user on 10/15/2022.
//

#include "Class.h"

string Class::getUcCode() {
    return ucCode;
}

int Class::getCapacity() {
    return capacity;
}

string Class::getClassCode() {
    return classCode;
}

list<Time_slot> Class::getTimeSlots() {
    return time_slots;
}

void Class::setCapacity(int c) {
    capacity = c;
}

void Class::setClassCode(string code) {
    classCode=code;
}

void Class::setUcCode(string code) {
    ucCode = code;
}

void Class::setTimeSlots(list<Time_slot> list) {
    time_slots = list;
}