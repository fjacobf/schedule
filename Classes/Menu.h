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
    ///Tests if the @param choice is valid and is inside @param values
    bool inputTest(char choice, vector<int> values);
    ///The submenu for option [21]Student List
    void studentListSubmenu();
    ///Recieves an integer that controls how the students will be listed
    void listStudents(int option);

    list<struct Student> studentOrdenationSubmenu(list<Student> studentsList);
};


#endif //SCHEDULE_MENU_H
