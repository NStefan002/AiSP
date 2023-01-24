#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void ucitajITransformisiMatricu(vector<vector<int>> &mat, int n);
int maxZbir(vector<vector<int>> &mat);

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat;
    ucitajITransformisiMatricu(mat, n);

    cout << mat[n][n] << endl;

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
