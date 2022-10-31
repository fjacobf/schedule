//
// Created by Utilizador on 31-Oct-22.
//

#ifndef SCHEDULE_DATABASE_H
#define SCHEDULE_DATABASE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Class.h"
#include "UcList.h"
#include "Uc.h"

using namespace std;

class DataBase {
private:
    UcList uclist;
public:
    UcList run();
};


#endif //SCHEDULE_DATABASE_H
