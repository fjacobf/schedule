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
        int capacity; /*!< Capacidade da turma */
        string ucCode; /*!< Código da cadeira desta turma */
        string classCode; /*!< Código da turma */
        list<Time_slot> time_slots; /*!< Lista de horários da turma */
public:


    ///@returns capacity
    int getCapacity() const;
    ///@returns Classcode
    string getClassCode() const;
    ///@returns UcCode
    string getUcCode() const;
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
    ///Insert a new time_slot with @param time_Slot
    void insertTimeSlot(Time_slot timeSlot);
    /// creates a new class with a @param Time_slot
    Class(int c, string ucCode, string ClassCode, Time_slot timeSlot);
    /// creates a new class without a Time Slot
    Class(int c, string ucCode, string ClassCode);

    Class();

    /// Operator of equals
    bool operator==(const Class &c) const;
};


#endif //SCHEDULE_CLASS_H
