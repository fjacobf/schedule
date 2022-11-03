//
// Created by Utilizador on 02-Nov-22.
//

#ifndef SCHEDULE_MENU_H
#define SCHEDULE_MENU_H


#include "Database.h"

class Menu {
private:
    Database database;
    void showTimeTable(string a);
public:
    Menu();
    int displayMenu();
    void showStudents();
};


#endif //SCHEDULE_MENU_H
