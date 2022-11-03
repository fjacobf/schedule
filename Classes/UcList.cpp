//
// Created by Utilizador on 31-Oct-22.
//

#include "UcList.h"

void UcList::addUc(Uc uni) {
    Ucs.push_back(uni);
}

bool UcList::exists(Uc uni) {
    for(Uc x : Ucs){
        if(uni.getUcCode() == x.getUcCode())
            return true;
    }
    return false;
}

list<Uc> UcList::getlist() {
    return Ucs;
}