//
// Created by Utilizador on 31-Oct-22.
//

#include "DataBase.h"



UcList DataBase::run() {
    UcList uclist;
    string fclasses = "D:\\AED\\schedule\\arquivos\\classes.csv";
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
                uclist.setUc(ucs);
            ucs.SetUcCode(content[i][1]);
            ucs.eraselist();
        }
        Time_slot time(content[i][5], stof(content[i][4]), stof(content[i][3]), content[i][2]);
        Class classe(0, content[i][1], content[i][0], time);
        if(ucs.getList().size() == 0)
            ucs.insertClass(classe);
        else {
            for(Class x : ucs.getList()){
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
    return uclist;
}

DataBase::DataBase() {}