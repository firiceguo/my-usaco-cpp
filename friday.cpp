/*
ID: firiceg1
PROG: friday
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int isLeap(const int year) {
    if (year % 4 == 0 && year % 100)
        return 1;
    else if (year % 400 == 0)
        return 1;
    else
        return 0;
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int num[7] = {0};
    int N;
    fin >> N;
    int day_each = 0;
    for (int i=1900; i<1900+N; i++){
        if (isLeap(i))
            days[2] = 29;
        else
            days[2] = 28;
        for (int j=1; j<=12; j++){
            num[(day_each + 13)%7]++;
            day_each += days[j];
        }
    }
    fout << num[6] << ' ';
    for (int i=0; i<5; i++)
        fout << num[i] << ' ';
    fout << num[5] << endl;
    return 0;
}
