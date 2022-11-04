//
// Created by Utilizador on 31-Oct-22.
//

#ifndef SCHEDULE_UCLIST_H
#define SCHEDULE_UCLIST_H
#include "Uc.h"

///Classe para guardar a lista de UCs na classe Database.
///
///Uma cadeira é identificada por um código e tem um conjunto de turmas.

class UcList {
private:
    list<Uc> Ucs;

public:
   void addUc(Uc uni);
   bool exists(Uc uni);
    list<Uc> getlist();
    bool equilibrium(string uc);
    list<Time_slot> getTimeSlot(string uc, string classe);
};


#endif //SCHEDULE_UCLIST_H
