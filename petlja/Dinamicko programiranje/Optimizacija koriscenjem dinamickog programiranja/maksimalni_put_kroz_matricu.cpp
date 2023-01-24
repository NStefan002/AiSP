#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

void ucitajITransformisiMatricu(vector<vector<int>> &mat, int n);
void ispisiPutanju(vector<vector<int>> &mat);

int main() 
{
    int n;
    cin >> n;

    vector<vector<int>> mat;
    ucitajITransformisiMatricu(mat, n);

    cout << mat[n][n] << '\n';
    ispisiPutanju(mat);

    return 0;
}

void ucitajITransformisiMatricu(vector<vector<int>> &mat, int n)
{
    mat = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cin >> mat[i][j];
            mat[i][j] += max(mat[i - 1][j], mat[i][j - 1]);
        }
    }
}

void ispisiPutanju(vector<vector<int>> &mat)
{
    int n = mat.size() - 1;
    int i = n, j = n;
    stack<string> putanja;

    // rekonstruisemo putanju
    while (!(i == 1 && j == 1))
    {
        if (mat[i - 1][j] > mat[i][j - 1])
        {
            putanja.push("dole");
            i--;
        }
        else 
        {
            putanja.push("desno");
            j--;
        }
    }

    // dobijamo putanju ispisanu u obrnutom redosledu
    // i zato nam je stek pogodan
    while (!putanja.empty())
    {
        cout << putanja.top() << '\n';
        putanja.pop();
    }
}
