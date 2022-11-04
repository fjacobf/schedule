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
#include "BST.h"
#include "Student.h"

using namespace std;
///Classe para a database.
///
///Onde todos os dados são guardados.
class Database {
private:
    BST<Student> studentsBST = BST<Student>(Student(0,"a"));
    UcList uclist;

public:
    UcList readClassesFile();
    UcList getuclist();
    Database();
    void verifyUc();
    void readStudent_classesFile();
    void set_studentBST(BST<Student> tree);
    BST<Student> getStudentBST();
};


#endif //SCHEDULE_DATABASE_H
