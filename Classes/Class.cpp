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

void Class::insertTimeSlot(Time_slot timeSlot) {
    time_slots.push_back(timeSlot);
}

Class::Class(int c, string ucCode, string ClassCode, Time_slot timeSlot) {
    setCapacity(c);
    setUcCode(ucCode);
    setClassCode(ClassCode);
    insertTimeSlot(timeSlot);
}