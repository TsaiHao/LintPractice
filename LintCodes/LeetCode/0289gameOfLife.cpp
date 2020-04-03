#include <vector>
#include <algorithm>

#include "LeetCode.h"
using namespace std;

void gameOfLife(vector<vector<int>>& board)
{
    if (board.empty() || board[0].empty()) {
        return;
    }
    int row = board.size(), col = board[0].size();
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<vector<int>> b2(row, vector<int>(col, 0));

    for(int i = 0; i < row; ++i) 
    {
        for (int j = 0; j < col; ++j)
        {
            int lives = 0;
            for (int n = 0; n < 8; ++n)
            {
                int x = i + dx[n], y = j + dy[n];
                if (x > -1 && x < row && y > -1 && y < col)
                {
                    lives += board[x][y];
                }
            }
            if (lives < 2 || lives > 3 || (lives == 2 && board[i][j] == 0))
            {
                b2[i][j] = 0;
            }
            else 
            {
                b2[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < row; ++i)
    {
        copy(b2[i].begin(), b2[i].end(), board[i].begin());
    }
}