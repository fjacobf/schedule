//
// Created by Utilizador on 31-Oct-22.
//

#ifndef SCHEDULE_UC_H
#define SCHEDULE_UC_H
#include "Class.h"

class Uc {
private:
    string Uccode;
    list<Class> Classes;

public:
    Uc(string uccode);
    void insertClass(Class classes);
    string getUcCode();
};


#endif //SCHEDULE_UC_H