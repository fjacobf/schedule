#include "Database.h"

Database::Database() {
    uclist = readClassesFile();
    readStudent_classesFile();
}

 UcList Database::readClassesFile() {
     UcList uclist;
    string fclasses = "classes.csv";
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    fstream file (fclasses, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";
    Uc ucs;
    for(int i=1;i<content.size();i++)
    {
        bool class_exist = false;
        if(i==1)
            ucs.SetUcCode(content[i][1]);
        else if(content[i][1]!=content[i-1][1]){
            if(!uclist.exists(ucs))
                uclist.addUc(ucs);
            ucs.SetUcCode(content[i][1]);
            ucs.eraselist();
        }
        Time_slot time(content[i][5], stof(content[i][4]), stof(content[i][3]), content[i][2]);
        Class classe(0, content[i][1], content[i][0], time);
        if(ucs.getClassesList().size() == 0)
            ucs.insertClass(classe);
        else {                     //TODO alterar para busca binaria
            for(Class x : ucs.getClassesList()){
                if(x.getClassCode() == classe.getClassCode() && x.getUcCode() == classe.getUcCode()){
                    x.insertTimeSlot(time);
                    class_exist = true;
                    break;
                }
            }
            if(!class_exist)
                ucs.insertClass(classe);

        }



    }
    verifyUc(uclist);
    return uclist;
}

void Database:: readStudent_classesFile(){
    string fclasses = "students_classes.csv";
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    fstream file (fclasses, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";
    bool class_exist = false;
    for(int i=1;i<content.size();i++)
    {
        Class classe(0,content[i][2], content[i][3]);
        if(studentsBST.isEmpty()){
            Student student (stoi(content[i][0]),content[i][1], classe);
            studentsBST.insert(student);
        }
        else{
            Student student (stoi(content[i][0]),content[i][1]);
            if(student == studentsBST.find(student)){
                if(student.getclasses().size()==0){
                    student.insertClass(classe);
                }
                else{
                    //TODO alterar para busca binaria
                    for(Class x : student.getclasses()){
                        if(x==classe){
                            class_exist = true;
                            break;
                        }
                    }
                    if(!class_exist){
                        student.insertClass(classe);
                    }
                }
            }
            else{
                studentsBST.insert(student);
            }

        }

    }

}



UcList Database::getuclist() {
    return uclist;
}

BST<Student> Database::getStudentBST(){
    return studentsBST;
}

void Database::verifyUc(UcList uclist) {
    string fclasses = "classes_per_uc.csv";
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    fstream file (fclasses, ios::in);
    if(file.is_open())
    {
        getline(file, line);
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";
    int i=0, count=0;
    /*while(i < content.size()){
            for(Uc x : uclist.getlist()){
                if(content[i][0] == x.getUcCode())
                    for(Class y : x.getClassesList())
                        if(content[i][1] == y.getClassCode()){
                            count++;
                            i++;
                            break;
                        }

            }

    }
     */
}


