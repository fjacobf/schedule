//
// Created by user on 10/15/2022.
//

#include "Time_slot.h"

string Time_slot::getweekday() {
    return  weekday;
}

float Time_slot::getstarthour() {
    return startHour;
}

float Time_slot::getduration() {
    return duration;
}

string Time_slot::gettype() {
    return type;
}

void Time_slot::setweekday(string n) {
    weekday = n;
}

void Time_slot::setstarthour(float a) {
    startHour = a;
}

void Time_slot::setduration(float a) {
    duration = a;
}

void Time_slot::settype(string t) {
    type = t;
}

Time_slot::Time_slot(string type, float duration, float startHour, string weekday) {
    setweekday(weekday);
    settype(type);
    setduration(duration);
    setstarthour(startHour);
}
