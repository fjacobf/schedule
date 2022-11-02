//
// Created by Utilizador on 02-Nov-22.
//

#include "Menu.h"

Menu::Menu() {}

void Menu::showTimeTable(string a) {
    system("cls");
    UcList uclist = database.getuclist();
    for(Uc x : uclist.getlist()){
        for(Class y : x.getList()){
            if(y.getClassCode() == a) {
                cout << "Uc: " << y.getUcCode() << "\n";
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

int Menu::displayMenu() {
    while(true) {
        system("cls");
        cout << "Main Menu\n";
        cout << "Please make your selection\n";
        cout << "1 - Display Class Time\n";
        cout << "2 - Options\n";
        cout << "3 - Quit\n";
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
            case 3:
                return EXIT_SUCCESS;

        }
    }
}