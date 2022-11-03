//
// Created by Utilizador on 31-Oct-22.
//

#ifndef SCHEDULE_UCLIST_H
#define SCHEDULE_UCLIST_H
#include "Uc.h"

class UcList {
private:
    list<Uc> Ucs;

public:
   void addUc(Uc uni);
   bool exists(Uc uni);
    list<Uc> getlist();
};


#endif //SCHEDULE_UCLIST_H
