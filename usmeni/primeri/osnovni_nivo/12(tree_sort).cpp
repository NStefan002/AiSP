#include <functional>
#include <iostream>
#include <set>


using namespace std;

int main()
{
    int n;
    cin >> n;

    multiset<int> multiskup;
    while (n--)
    {
        int br;
        cin >> br;

        multiskup.insert(br);
    }

    for (int x : multiskup)
    {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
