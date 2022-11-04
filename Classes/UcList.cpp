//
// Created by Utilizador on 31-Oct-22.
//

#include <vector>
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

bool UcList::equilibrium(string uc) {
    for(Uc x : Ucs){
        if(x.getUcCode() == uc){
            int max_diff = 0;
            vector<int> capac;
            for(Class c : x.getClassesList()){
                capac.push_back(c.getCapacity());
            }
            for (int i = 0; i < capac.size(); i++) {
                for (int j = i+1; j < capac.size(); j++)
                    if((capac[j] - capac[i]) > max_diff)
                        max_diff = capac[j] - capac[i];
            }
            if(max_diff>=4)
                return false;
            else
                return true;
        }
    }
    return false;
}

list<Time_slot> UcList::getTimeSlot(string uc, string classe) {
    for(Uc x : Ucs) {
        if (x.getUcCode() == uc)
            for(Class c : x.getClassesList()){
                if(c.getClassCode() == classe)
                    return c.getTimeSlots();
            }
    }
}
