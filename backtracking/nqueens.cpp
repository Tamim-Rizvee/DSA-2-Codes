#include <bits/stdc++.h>
#define Onii_chan ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define iint long long
#define uwu '\n'
using namespace std;

void print_board(vector<vector<char>> board)
{
    for (auto &x : board)
    {
        for (char &y : x)
            cout << y << " ";
        cout << uwu;
    }
    cout << uwu;
}

bool isSafe(vector<vector<char>> &board , int row , int col)
{
    int n = board.size();
    //horizontal
    for (int i = 0; i < n; i++)
    {
        if(board[row][i] == 'Q')
            return false;
    }

    //vertical safety
    for (int i = 0; i < row; i++)
    {
        if(board[i][col] == 'Q')
            return false;
    }

    //left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--,j--)
    {
        if(board[i][j] == 'Q')
            return false;
    }

    //right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if(board [i][j] == 'Q')
            return false;
    }

    return true;
}

int nQueens(vector<vector<char>> &board, int row)
{
    int n = board.size();

    if (row == n)
    {
        print_board(board);
        return 1;
    }

    int count = 0;

    for (int j = 0; j < n; j++)
    {
        if(isSafe(board , row , j))
        {
            board[row][j] = 'Q';
            count += nQueens(board, row + 1);
            board[row][j] = '.';
        }
    }
    return count;
}

int main()
{
    Onii_chan;
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    cout << nQueens(board, 0) << uwu;
    return 0;
}