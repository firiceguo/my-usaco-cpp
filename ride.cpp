/*
ID: firiceg1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
    getline(fin, comet);
    getline(fin, group);
    long comet_n = 1, group_n = 1;
    for	(int i = 0; i < comet.length(); i++) {
        comet_n *= comet[i] - 'A' + 1;
    }
    comet_n = comet_n % 47;
    for (int j = 0; j < group.length(); j++) {
        group_n *= group[j] - 'A' + 1;
    }
    group_n = group_n % 47;
    if (comet_n == group_n)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}
