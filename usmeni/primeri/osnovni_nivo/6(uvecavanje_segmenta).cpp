#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> kilometri(n + 1, 0);
    int pocetak, kraj, masa;
    for (int i = 0; i < m; i++)
    {
        cin >> pocetak >> kraj >> masa;

        kilometri[pocetak] = masa;
        kilometri[kraj + 1] = -masa;
    }

    int tovar = 0;
    for (int i = 0; i < n; i++)
    {
        tovar += kilometri[i];
        cout << tovar << ' ';
    }
    cout << endl;

    return 0;
}
