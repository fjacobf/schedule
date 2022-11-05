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
    Uc();
    void insertClass(Class classes);
    string getUcCode()const;
    void SetUcCode(string code);
    void eraselist();
    list<Class> getClassesList();
    friend std::ostream& operator<<(std::ostream& os , const Uc& uc);
    bool operator==(const Uc &c) const;
    void remove(Class aClass);
};


#endif //SCHEDULE_UC_H
