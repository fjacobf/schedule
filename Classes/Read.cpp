//
// Created by Utilizador on 31-Oct-22.
//

#include "Read.h"



void Read::run() {
    UcList uclist;
    string fclasses = "D:\\AED\\schedule\\arquivos\\classes.csv", fclassperuc, fstudentclasses;
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
    for(int i=1;i<content.size();i++)
    {
        Uc ucs(content[i][1]);
        if(!uclist.exists(ucs))
            uclist.setUc(ucs);
        for(int j=0;j<content[i].size();j++)
        {
            Time_slot time(content[i][5], stof(content[i][4]), stof(content[i][3]), content[i][2]);
            Class classe(0, content[i][1], content[i][0], time);
            ucs.insertClass(classe);


        }
        cout<<"\n";
    }
}

Read::Read() {

}
