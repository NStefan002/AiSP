#include <iostream>
#include <map>
#include <string>


using namespace std;

int main()
{
    map<string, int> brojReci;
    string rec;
    while (cin >> rec)
    {
        brojReci[rec]++;
    }

    for (pair<string, int> p : brojReci)
    {
        cout << "Rec: " << p.first << ", broj ponavljanja: " << p.second << "\n";
    }

    return 0;
}
