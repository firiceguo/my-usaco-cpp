/*
ID: firiceg1
PROG: gift1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct People {
    string name;
    int money;
};

int FindName(People stu[], const int &NP, const string &name) {
    for (int i=0; i<NP; i++) {
        if (name == stu[i].name)
            return(i);
    }
    return(-1);
}

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    People stu[10];

    int NP;
    fin >> NP;
    string s;
    for (int i=0; i<NP; i++) {
        fin >> s;
        stu[i].name = s;
        stu[i].money = 0;
    }
    string name;
    int amount, number;
    for (int i=0; i<NP; i++) {
        fin >> name;
        fin >> amount >> number;
        int index;
        index = FindName(stu, NP, name);
        if (number)
            stu[index].money = stu[index].money - amount + (amount % number);
        else
            stu[index].money = stu[index].money + amount;
        for (int j=0; j<number; j++) {
            fin >> name;
            index = FindName(stu, NP, name);
            stu[index].money += amount / number;
        }
    }
    for (int i=0; i<NP; i++){
        fout << stu[i].name << ' ' << stu[i].money << endl;
    }
    return 0;
}
