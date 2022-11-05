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
        else {
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
    verifyUc();
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
        bool found = false;
        for(Uc uc : uclist.getlist()){
            for(Class c : uc.getClassesList()){
                if(classe == c) {
                    classe.setTimeSlots(c.getTimeSlots());
                    c.setCapacity(c.getCapacity()+1);
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
        if(studentsBST.isEmpty()){ //testa se a arvore está vazia
            Student student (stoi(content[i][0]),content[i][1], classe);
            studentsBST.insert(student);
        }
        else{
            Student student (stoi(content[i][0]),content[i][1]);
            Student auxstu = studentsBST.find(student);
            if(student == auxstu){ //testa se o estudante do arquivo existe na arvore
                if(auxstu.getclasses().size()==0){ //testa se a lista de classes do estudante está vazia
                    auxstu.insertClass(classe);
                }
                else{ //testa se a classe do arquivo existe na lista de classes do estudante
                    //TODO alterar para busca binaria
                    for(Class x : auxstu.getclasses()){
                        if(x==classe){
                            class_exist = true;
                            break;
                        }
                    }
                    if(!class_exist){ //se a classe na existe na lista ela é inserida
                        auxstu.insertClass(classe);
                    }
                }
                studentsBST.remove(student);
                studentsBST.insert(auxstu);
            }
            else{ //se o estudante do arquivo na existe na arvore, a classe é inserida e ele é inserido na classe
                student.insertClass(classe);
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

void Database::verifyUc() {
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
    ofstream Myfile("classes_per_uc.txt");
    for(int i=1; i<content.size(); i++){
        Myfile << content[i][0] << " " <<content[i][1]<< "\n";
    }
    Myfile.close();

}

void Database::set_studentBST(BST<Student> tree) {
    studentsBST = tree;
}



