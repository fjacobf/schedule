//
// Created by Utilizador on 31-Oct-22.
//

#ifndef SCHEDULE_UC_H
#define SCHEDULE_UC_H
#include "Class.h"

///Classe para as Cadeiras.
///
///Uma cadeira é identificada por um código e tem um conjunto de turmas.

class Uc {
private:
    string Uccode;
    list<Class> Classes;

public:
    Uc(string uccode);
    void insertClass(Class classes);
    string getUcCode()const;
    void SetUcCode(string code);
    void eraselist();
    list<Class> getClassesList();
    friend std::ostream& operator<<(std::ostream& os , const Uc& uc);
    Uc();
};


#endif //SCHEDULE_UC_H
