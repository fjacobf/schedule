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

string Uc::getUcCode() {
    return Uccode;
}