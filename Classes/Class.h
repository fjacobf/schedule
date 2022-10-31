#ifndef SCHEDULE_CLASS_H
#define SCHEDULE_CLASS_H
#include <string>
#include "Time_slot.h"
#include "list"
using namespace std;
///Classe para as Turmas.
///
///Uma turma é identificada por um código e tem um horário associado.
class Class {
private:
    int capacity;
        string ucCode;
        string classCode;
        list<Time_slot> time_slots;
public:


    ///@returns capacity
    int getCapacity();
    ///@returns Classcode
    string getClassCode();
    ///@returns UcCode
    string getUcCode();
    ///@returns Time slots
    list<Time_slot> getTimeSlots();
    ///set capacity with @param c
    void setCapacity(int c);
    /// set classCode with @param code
    void setClassCode(string code);
    /// set UcCode with @param code
    void setUcCode(string code);
    /// set time_slots with @param list
    void setTimeSlots(list<Time_slot> list);
    ///Insert a new time_slot with @param timeSlot
    void insertTimeSlot(Time_slot timeSlot);
    /// creates a new  class Classes
    Class(int c, string ucCode, string ClassCode, Time_slot timeSlot);

};


#endif //SCHEDULE_CLASS_H
