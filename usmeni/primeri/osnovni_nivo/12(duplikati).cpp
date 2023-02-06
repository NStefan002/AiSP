#include <iostream>
#include <set>


using namespace std;

int main()
{
    int n;
    cin >> n;

    set<unsigned> ipAdrese;
    for (int i = 0; i < n; i++)
    {
        unsigned ip;
        cin >> ip;
        ipAdrese.insert(ip);
    }
    
    cout << ipAdrese.size() << endl;

    return 0;
}
