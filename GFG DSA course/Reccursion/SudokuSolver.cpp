#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
template <class T>
void in_vector(vector<T> &vec, ll n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
}

bool solveSudoku(vector<vc> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if (isValid(board, i, j, ch))
                    {
                        board[i][j] = ch;
                        if (solveSudoku(board) == true)
                        {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }

    return true;
}
bool isValid(vector<vc> &board, int row, int col, char c)
{
    for (int i = 0; i <= 8; i++)
    {
        if (board[i][col] == c)
            return false;
        if (board[row][i] == c)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);

    return 0;
}