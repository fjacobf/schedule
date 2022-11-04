#include "Menu.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <unistd.h>
#include "SortForm.cpp"
#include "alteration.h"

Menu::Menu() {}
int Menu::displayMenu() {
    while(true) {
        cout << "\n\n"
                "=====================================================================\n"
                " .d8888b.           888                    888          888          \n"
                "d88P  Y88b          888                    888          888          \n"
                "Y88b.               888                    888          888          \n"
                " \"Y888b.    .d8888b 88888b.   .d88b.   .d88888 888  888 888  .d88b.  \n"
                "    \"Y88b. d88P\"    888 \"88b d8P  Y8b d88\" 888 888  888 888 d8P  Y8b \n"
                "      \"888 888      888  888 88888888 888  888 888  888 888 88888888 \n"
                "      \"888 888      888  888 88888888 888  888 888  888 888 88888888 \n"
                "Y88b  d88P Y88b.    888  888 Y8b.     Y88b 888 Y88b 888 888 Y8b.     \n"
                "\"Y8888P\"   \"Y8888P 888  888  \"Y8888   \"Y88888  \"Y88888 888  \"Y8888  \n"
                "=====================================================================\n"
                "|==========================|              |============================|  \n"
                "|      **Ocupation**       |              |      **Student**           |  \n"
                "|     [11]Per Class X      |              | [21]Students List          |  \n"
                "|     [12]Per Year  X      |              | [22]Timetable per Student X|  \n"
                "|     [13]Per UC   X       |              | [23]Alterations X          |  \n"
                "|==========================|              |============================|  \n"
                "|        **UCs**           |              |                            |  \n"
                "|     [31]Ucs Listing  X   |              | [0]Exit                    |  \n"
                "|     [32]Classes per UC X |              | [1]Save X                  |  \n"
                "|                          |              |                            |  \n"
                "|==========================|              |============================|  \n"
                ;
        cout << endl;
        cout << "Choose an option:";
        int choice;
        cin >> choice;
        vector<int> values = {0,1,11,12,13,21,22,23,31,32,33};
        if(!inputTest(choice,values)) continue;
        switch (choice) {
            case 0: {
                alteration_run();
                exit(0);
            }
            case 1: //save
            case 11: break; //ocupation per class
            case 12: break; //ocupation per year
            case 13: break; //ocupation per uc
            case 21: studentListSubmenu(); break; //TODO Student listing submenu
            case 22: break; //Timetable per student
            case 23:  break; //Alterations submenu
            case 31: break; //Ucs listing
            case 32: break; //Classes per UC
        }
    }
}

void Menu:: studentListSubmenu() {
        cout << "\n\n"
                "|=============================|\n"
                "|         How to list?        |\n"
                "|     [1]List every student   |\n"
                "|     [2]List per class       |\n"
                "|     [3]List per UC          |\n"
                "|     [4]List per year        |\n"
                "|     [0]Exit                 |\n"
                "|=============================|\n";
    cout << endl;
    while (true){
        cout << "Choose an option:";
        int choice;
        cin >> choice;
        vector<int> values = {0, 1, 2, 3, 4};
        if (!inputTest(choice, values)) continue;
        BST<Student> tree = database.getStudentBST();
        list<Student> aux;
        switch (choice) {
            case 0:
                return; //exit
            case 1:
                for (auto i = tree.begin(); i != tree.end(); i++){ aux.push_back(*i); }
                aux = studentOrdenationSubmenu(aux);
                break;
               //listagem por geral
            case 2:
                listStudents(2);
                break;
                //listagem por turma
            case 3:
                listStudents(3);
                break;
                //listagem por UC
            case 4:
                listStudents(4);
                break;
                //listagem por ano
        }
        for(Student &j : aux){ cout << j << "\n";}
        system("pause");
        return;
    }
}

list<Student> Menu:: studentOrdenationSubmenu(list<Student> studentsList){
    cout << "\n\n"
            "|===================================|\n"
            "|          How to order?            |\n"
            "|   [1]Per name cres. order         |\n"
            "|   [2]Per name decs order          |\n"
            "|   [3]Per student Code cres order  |\n"
            "|   [4]Per student Code decs order  |\n"
            "|===================================|\n";
    cout << endl;
    while (true){
        cout << "Choose an option:";
        int choice;
        cin >> choice;
        vector<int> values = {1, 2, 3, 4};
        if (!inputTest(choice, values)) continue;
        switch (choice) {
            case 1:
                studentsList.sort(sortStudentByNameAsc);
                break;
            case 2:
                studentsList.sort(sortStudentByNameDsc);
                break;
            case 3:
                studentsList.sort(sortStudentByCodeAsc);
                break;
            case 4:
                studentsList.sort(sortStudentByCodeDsc);
                break;
        }
        return studentsList;
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

void Menu:: listStudents(int option){
    list<Student> aux;
    BST<Student> tree = database.getStudentBST();
    if(tree.isEmpty()){cout << "empty tree" ; return;}

    switch (option) {
        case 1:
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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }
}

bool Menu:: inputTest(char choice ,vector<int> values) {
    if (cin.fail() || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid input! Try again!" << endl;
        sleep(1);
        return false;
    }
    binary_search(values.begin(),values.end(),choice);
    if (!binary_search(values.begin(),values.end(),choice)) {
        cout << "Invalid choice! Try again!" << endl;
        sleep(1);
        return false;
}
    return true;
}

void Menu::alteration_run() {
    while (!alt.empty()) {
        BST<Student> tree = database.getStudentBST();
        Student aux = tree.find(alt.front().getstudent());
        string choice = alt.front().gettype();

            if("rem" == choice){ /*remove from class */
                bool found = false;
                for (Class y: aux.getclasses()) {
                        if (alt.front().getclasses() == y) {
                            aux.popClass(y);
                            found = true;
                            break;
                        }

                    if (found) {
                        tree.remove(aux);
                        tree.insert(aux);
                        database.set_studentBST(tree);
                        alt.pop();
                        break;
                    }
                }
                break;
            }
            if("add"==choice) { /*add in a class/uc */
                list<Time_slot> time = gettimetable(alt.front().getstudent().getcode());
                list<Time_slot> pretended;
                bool found = false;
                bool can_do = true;
                for (Uc u: database.getuclist().getlist()) {
                    for (Class c: u.getClassesList()) {
                        if (c == alt.front().getclasses()) {
                            alt.front().getclasses().setTimeSlots(c.getTimeSlots());
                            pretended = c.getTimeSlots();
                            if (c.getCapacity() + 1 > 20)
                                can_do = false;
                        }
                    }
                }
                for (Time_slot t: time) {
                    for (Time_slot p: pretended) {
                        if (p.getweekday() == t.getweekday()) {
                            if ((t.getstarthour() <= p.getstarthour() &&
                                 t.getstarthour() + t.getduration() > p.getstarthour()) ||
                                p.getstarthour() <= t.getstarthour() &&
                                p.getstarthour() + p.getduration() > t.getstarthour()) {
                                can_do = false;
                            }
                        }
                    }
                    if (!can_do)
                        break;
                }
                if(can_do)
                    can_do = database.getuclist().equilibrium(alt.front().getclasses().getUcCode());

                if (can_do) {
                    aux.insertClass(alt.front().getclasses());
                    tree.remove(aux);
                    tree.insert(aux);
                    alt.pop();
                } else {
                    ofstream Myfile("Pedidos_nao_concedidos");
                    Myfile << "Estudante numero: " << alt.front().getstudent().getcode()
                           << " Tipo de alteração negado: " << alt.front().gettype() << "\n";
                    alt.pop();

                }


                break;
            }
            if("alt"==choice){ /*alterate in a class/uc */
                for (Class y: aux.getclasses()) {
                        if (alt.front().getclasses() == y) {
                            aux.popClass(y);
                            break;
                        }
                list<Time_slot> time = gettimetable(alt.front().getstudent().getcode());
                list<Time_slot> pretended;
                bool found = false;
                bool can_do = true;
                for (Uc u: database.getuclist().getlist()) {
                    for (Class c: u.getClassesList()) {
                        if (c == alt.front().getclasses()) {
                            alt.front().getclasses().setTimeSlots(c.getTimeSlots());
                            pretended = c.getTimeSlots();
                            if (c.getCapacity() + 1 > 20)
                                can_do = false;
                        }
                    }
                }
                for (Time_slot t: time) {
                    for (Time_slot p: pretended) {
                        if (p.getweekday() == t.getweekday()) {
                            if ((t.getstarthour() <= p.getstarthour() &&
                                 t.getstarthour() + t.getduration() > p.getstarthour()) ||
                                p.getstarthour() <= t.getstarthour() &&
                                p.getstarthour() + p.getduration() > t.getstarthour()) {
                                can_do = false;
                            }
                        }
                    }
                    if (!can_do)
                        break;
                }
                if(can_do)
                    can_do = database.getuclist().equilibrium(alt.front().getclasses().getUcCode());

                if (can_do) {
                    aux.insertClass(alt.front().getclasses());
                    tree.remove(aux);
                    tree.insert(aux);
                    alt.pop();
                } else {
                    ofstream Myfile("Pedidos_nao_concedidos");
                    Myfile << "Estudante numero: " << alt.front().getstudent().getcode()
                           << " Tipo de alteração negado: " << alt.front().gettype() << "\n";
                    alt.pop();

                }
            }

            }}

}

list<Time_slot> Menu::gettimetable(int code) {
    BST<Student> tree = database.getStudentBST();
    Student student = tree.find(Student(code, ""));
    list<Time_slot> time = student.gettimetable();
    return time;
}
