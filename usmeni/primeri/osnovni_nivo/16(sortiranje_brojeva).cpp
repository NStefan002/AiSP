#include <functional>
#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> redSaPrioritetom;
    for (int i = 0; i < n; i++)
    {
        int br;
        cin >> br;

        redSaPrioritetom.push(br);
    }

    while (!redSaPrioritetom.empty())
    {
        cout << redSaPrioritetom.top() << ' ';
        redSaPrioritetom.pop();
    }
    cout << endl;

    return 0;
}
