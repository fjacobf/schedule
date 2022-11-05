//
// Created by Utilizador on 31-Oct-22.
//

#include "Uc.h"

Uc::Uc(string uccode) {
    this->Uccode = uccode;
}

void Uc::insertClass(Class classes) {
    this->Classes.push_back(classes);
}

string Uc::getUcCode() const{
    return Uccode;
}

void Uc::SetUcCode(string code) {
    Uccode = code;
}

void Uc::eraselist() {
    Classes.clear();
}

list<Class> Uc::getClassesList() {
    return Classes;
}

std::ostream& operator<<(std::ostream& os , const Uc& uc)
{
    os << uc.getUcCode();
    return os;
}

Uc::Uc() {}

void Uc::remove(Class aClass) {
    Classes.remove(aClass);
}

bool Uc::operator==(const Uc &c) const {
    return(Uccode == c.getUcCode());
}
