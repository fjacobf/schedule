#include "Menu.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <unistd.h>
#include "SortForm.cpp"
#include "alteration.h"
using namespace std;
Menu::Menu() {}
int Menu::displayMenu() {
    while(true) {
        cout << string(50,'\n');
        cout <<
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
                "| [11]Per Class            |              | [21]Students List          |  \n"
                "| [12]Per Year             |              | [22]Timetable per Student  |  \n"
                "| [13]Per UC               |              | [23]Alterations            |  \n"
                "|==========================|              |============================|  \n"
                "|    **UCs & Classes**     |              |                            |  \n"
                "| [31]Ucs List             |              |    [0]Exit                 |  \n"
                "| [32]Classes per UC       |              |    [1]Run Alterations      |  \n"
                "| [33]Class Timetable      |              |                            |  \n"
                "|                          |              |                            |  \n"
                "|==========================|              |============================|  \n";
                ;
        cout << endl;
        cout << "Choose an option:";
        int choice;
        string key;
        cin >> choice;
        vector<int> values = {0,1,11,12,13,21,22,23,31,32,33};
        if(!inputTest(choice,values)) continue;
        switch (choice) {
            case 0:
                    exit(0);
            case 1:
                alteration_run();
                break;
            case 11: //ocupation per class
                    cout << "Type the class:";
                    cin >> key;
                    ocupationSubmenu(2 , key);
                    break;

            case 12://ocupation per year
                    cout << "Type the year:";
                    cin >> key;
                    ocupationSubmenu(4 , key);
                    break;

            case 13://ocupation per uc
                    cout << "Type the uc:";
                    cin >> key;
                    ocupationSubmenu(3 , key);
                    break;

            case 21://Student List
                studentListSubmenu();
                break;

            case 22://Timetable per student
                studentTimetableSubmenu();
                break;

            case 23: //Alterations submenu
                alterationsSubmenu();
                break;

            case 31://Ucs list
                for (auto i : database.getuclist().getlist()){
                    cout << i << "\n";
                }
                system("pause");
                break;

            case 32://Classes per UC
                cout << "Type the UC:";
                cin >> key;
                for (auto i : database.getuclist().getlist()){
                    if (i.getUcCode() == key){
                        for(auto j : i.getClassesList()){
                            cout << j.getClassCode()<<"\n";
                        }
                        break;
                    }
                }
                system("pause");
                break;

            case 33: //Class timetable
                cout << "Type the class:";
                cin >> key;
                classTimetable(key);
                system("pause");
                break;
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
        //TODO Students with more than n UCs
    cout << endl;
    while (true){
        cout << "Choose an option:";
        int choice;
        cin >> choice;
        vector<int> values = {0, 1, 2, 3, 4};
        if (!inputTest(choice, values)) continue;
        string key;
        switch (choice) {
            case 0:
                return; //exit
            case 1: //listagem por geral
                key = "geral";
                break;
            case 2://listagem por turma
                cout << "Type the class:";
                cin >> key;
                break;
            case 3://listagem por UC
                cout << "Type the UC:";
                cin >> key;
                break;
            case 4://listagem por ano
                cout << "Type the year:";
                cin >> key;
                break;
        }
        list<Student> aux = listStudents(choice, key);
        aux = studentOrdenationSubmenu(aux);
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

void Menu:: ocupationSubmenu(int choice, string key){
    list<Student> aux = listStudents(choice, key);
    cout << "\n"
            "|===================================|\n"
            "|          Ocupation of:            |\n"
            "|             " << key << "              |\n"
                                       "|             is:" << aux.size()<< "               |\n"
            "|===================================|\n";
    cout << endl;
    cout << "Do you want to list the students?\n"
            "[1] Yes\n"
            "[0] No\n";
    int c;
    cin >> c;
    vector<int> values = {0,1};
    if(!inputTest(c,values)) return;
    if(c==0) return;
    else {
        aux = studentOrdenationSubmenu(aux);
        for(Student &j : aux){ cout << j << "\n";}
        system("pause");
    }
}

void Menu:: alterationsSubmenu() {
    cout << "\n\n"
            "|=============================|\n"
            "|         How to list?        |\n"
            "|     [1]Add in class         |\n"
            "|     [2]Remove from class    |\n"
            "|     [3]Change               |\n"
            "|=============================|\n";
    //TODO Students with more than n UCs
    cout << endl;
    while (true) {
        string name, UCcode, classCode;
        int studentCode;
        Student student;
        Class classe;
        cout << "Choose an option:";
        int choice;
        cin >> choice;
        vector<int> values = {1, 2, 3};
        if (!inputTest(choice, values)) continue;
        string type;
        switch (choice) {
            case 1:
                type = "add";
                break;
            case 2:
                type = "rem";
                break;
            case 3:
                type = "alt";
                break;
        }
        cout << "Type students name:";
        cin >> name;
        cout << "Type students Code:";
        cin >> studentCode;
        cout << "Type the UC code:";
        cin >> UCcode;
        cout << "Type the class code:";
        cin >> classCode;
        student.setname(name);
        student.setcode(studentCode);
        classe.setUcCode(UCcode);
        classe.setClassCode(classCode);
        alt.push(alteration(student, type, classe));
        return;
    }
}

void Menu::classTimetable(string a) {
    system("cls");
    UcList uclist = database.getuclist();
    for(Uc x : uclist.getlist()){
        for(Class y : x.getClassesList()){
            if(y.getClassCode() == a) {
                cout << "|-------------\n";
                cout << "|Uc: " << y.getUcCode() << "\n";
                cout << "|Capacity: " << y.getCapacity() << "\n";
                cout << "|Timetable\n";
                cout << "|-------------\n";
                for (Time_slot t: y.getTimeSlots()) {
                    cout << "=============================\n"
                            "|type: " << t.gettype() << "                    \n"
                            "|weekday: " << t.getweekday() << "              \n"
                            "|Start hour: " << t.getstarthour() << "         \n"
                            "|duration: " << t.getduration() << " hours      \n"
                            "=============================\n";
                }
                cout << "\n\n";
            }
        }
    }
    cout << "\n\n\n";
}

list<Student> Menu:: listStudents(int choice, string key){
    list<Student> aux;
    BST<Student> tree = database.getStudentBST();
    if(tree.isEmpty()){cout << "empty tree" ;}
    for (auto i = tree.begin(); i != tree.end(); i++) {
        Student student = *i;
        switch (choice) {
            case 1: //listagem geral
                aux.push_back(*i);
                break;
            case 2: //listagem por turma
                for (auto f : student.getclasses()){
                    if(f.getClassCode() == key){
                        aux.push_back(student);
                    }
                }
                break;
            case 3: //listagem por UC
                for (auto f : student.getclasses()){
                    if(f.getUcCode() == key){
                        aux.push_back(student);
                    }
                }
                break;
            case 4: //listagem por ano
                if(student.getyear() == stoi(key)){
                    aux.push_back(student);
                }
                break;
        }
    }
    return aux;
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
    ofstream Myfile("Pedidos_nao_concedidos.txt");
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
                }

                    if (found) {
                        tree.remove(aux);
                        tree.insert(aux);
                        database.set_studentBST(tree);
                        alt.pop();
                        break;
                    }

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
                }

                else {
                    Myfile << "Estudante numero: " << alt.front().getstudent().getcode()
                           << " Tipo de alteração negado: " << alt.front().gettype() << "\n";
                    alt.pop();
                }

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
                    Myfile << "Estudante numero: " << alt.front().getstudent().getcode()
                           << " Tipo de alteração negado: " << alt.front().gettype() << "\n";
                    alt.pop();

                }
            }

            }
        database.set_studentBST(tree);
        Myfile.close();
    }
}



void Menu::studentTimetableSubmenu() {
    BST<Student> tree = database.getStudentBST();
    cout << "How would you like to search for the student?\n"
            "[1]By Student Code\n"
            "[2]By Name        \n";
    while (true) {
        list<Time_slot> timetable;
        int code;
        string name;
        int choice;
        cin >> choice;
        Student student;
        vector<int> values = {1, 2};
        if (!inputTest(choice, values)) continue;

        if(choice == 1) {
            cout << "type the code:";
            cin >> code;
            student = tree.find(Student(code, ""));
            timetable = student.gettimetable();
            cout << "==========" << student.getname() << "==========\n";
        }
        else {
            cout << "Type the name:";
            cin >> name;
            for(auto i = tree.begin(); i!=tree.end(); i++){
                student = *i;
                if(student.getname()==name){
                    timetable = student.gettimetable();
                    break;
                }
            }
            cout << "==========" << student.getcode() << "==========\n";
        }
        for (Time_slot t: timetable) {
            cout << "=============================\n"
                    "|type: " << t.gettype() << "\n"
                    "|weekday: " << t.getweekday() << "\n"
                    "|Start hour: " << t.getstarthour() << "\n"
                    "|duration: " << t.getduration() << " hours\n"
                    ;
        }
        system("pause");
        return;
    }
}

list<Time_slot> Menu::gettimetable(int code) {
    BST<Student> tree = database.getStudentBST();
    Student student = tree.find(Student(code, ""));
    list<Time_slot> time = student.gettimetable();
    return time;
}
