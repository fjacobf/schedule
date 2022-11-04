//
// Created by Utilizador on 02-Nov-22.
//

#ifndef SCHEDULE_MENU_H
#define SCHEDULE_MENU_H


#include "Database.h"
#include "alteration.h"
///Classe para o menu.
///
///O menu é essencial para o projeto.

class Menu {
private:
    Database database;
    void showTimeTable(string a);
    queue<alteration> alt;
public:
    Menu();
    int displayMenu();
    ///Tests if the @param choice is valid and is inside @param values
    bool inputTest(char choice, vector<int> values);
    ///The submenu for option [21]Student List
    void studentListSubmenu();
    ///Recieves an integer that controls how the students will be listed
    list<struct Student> listStudents(int option, string key);

    void alteration_run();

    list<Time_slot> gettimetable(int code);

    list<struct Student> studentOrdenationSubmenu(list<Student> studentsList);

    void ocupationSubmenu(int choice, string key);
};


#endif //SCHEDULE_MENU_H
