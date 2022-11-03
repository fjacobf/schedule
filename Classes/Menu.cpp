#include "Menu.h"
#include <iostream>
#include <stdlib.h>

Menu::Menu() {}
int Menu::displayMenu() {
    while(true) {
        //cout << "\033[2J\033[1;1H";
        cout << "=====================================================================\n";
        cout << " .d8888b.           888                    888          888          \n";
        cout << "d88P  Y88b          888                    888          888          \n";
        cout << "Y88b.               888                    888          888          \n";
        cout << " \"Y888b.    .d8888b 88888b.   .d88b.   .d88888 888  888 888  .d88b.  \n";
        cout << "    \"Y88b. d88P\"    888 \"88b d8P  Y8b d88\" 888 888  888 888 d8P  Y8b \n";
        cout << "      \"888 888      888  888 88888888 888  888 888  888 888 88888888 \n";
        cout << "      \"888 888      888  888 88888888 888  888 888  888 888 88888888 \n";
        cout << "Y88b  d88P Y88b.    888  888 Y8b.     Y88b 888 Y88b 888 888 Y8b.     \n";
        cout << "\"Y8888P\"   \"Y8888P 888  888  \"Y8888   \"Y88888  \"Y88888 888  \"Y8888  \n";
        cout << "=====================================================================\n";
        cout << "Please make your selection\n";
        cout << "1 - Display Class Time\n";
        cout << "2 - showstudents\n";
        cout << "4 - Quit\n";
        cout << "Selection: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                    system("cls");
                    cout << "Please insert a Class code to see timetable or press q to go back: ";
                    string a;
                    cin >> a;
                    if (a == "q" || a == "Q") {
                        system("cls");
                        break;
                    }
                    showTimeTable(a);
                    system("cls");
                    break;


            }
            case 2: {
                showStudents();
                system("pause");
            }
            case 4:
                system("cls");
                cout << "Thank u for playing!\n";
                return EXIT_SUCCESS;

        }
    }
}
void Menu::showTimeTable(string a) {
    system("cls");
    UcList uclist = database.getuclist();
    for(Uc x : uclist.getlist()){
        for(Class y : x.getClassesList()){
            if(y.getClassCode() == a) {
                cout << "Uc: " << y.getUcCode() << "\n";
                cout << "Capacity: " << y.getCapacity() << "\n";
                for (Time_slot t: y.getTimeSlots()) {
                    cout << "weekday: " << t.getweekday() << "\n";
                    cout << "starthour: " << t.getstarthour() << "\n";
                    cout << "duration: " << t.getduration() << " hours\n";
                    cout << "type: " << t.gettype() << "\n";
                }
                cout << "\n\n\n";
            }
        }
    }
    cout << "\n\n\n";
}

void Menu:: showStudents(){
    list<Student> aux;
    BST<Student> tree = database.getStudentBST();
    if(tree.isEmpty()){
        cout << "empty tree" ;
        return;
    }
    for (auto i = tree.begin(); i != tree.end(); i++)
    {
        aux.push_back(*i);
    }
    for(Student &j : aux){
        cout << j.getcode() << "-" << j << "\n";
        for (Class &i : j.getclasses()){
            cout << i.getUcCode()<< " / " << i.getClassCode() << "\n";
        }
    }
}