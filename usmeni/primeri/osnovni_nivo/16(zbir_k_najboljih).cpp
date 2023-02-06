#include <functional>
#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, less<int>> redSaPrioritetom;
    for (int i = 0; i < n; i++)
    {
        int br;
        cin >> br;
        redSaPrioritetom.push(br);
    }

    int suma = 0;
    for (int i = 0; i < k; i++)
    {
        suma += redSaPrioritetom.top();
        redSaPrioritetom.pop();
    }

    cout << suma << endl;

    return 0;
}
