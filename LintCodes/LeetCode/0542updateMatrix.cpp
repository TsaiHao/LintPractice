#include <algorithm>
#include <utility>
#include <deque>

#include "LeetCode.h"
using namespace std;
typedef pair<int, int> cord;

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
{
    vector<vector<int>> ret = matrix;

    if (matrix.empty() || matrix[0].empty())
    {
        return ret;
    }
    int row = matrix.size(), col = matrix[0].size();

    deque<int> xs, ys;
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (matrix[i][j] == 0) {
                xs.push_back(i);
                ys.push_back(j);
                visited[i][j] = true;
            }
        }
    }

    while (!xs.empty())
    {
        int x = xs.front(), y = ys.front();
        xs.pop_front(); ys.pop_front();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < row && ny < col && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                ret[nx][ny] = ret[x][y] + 1;
                xs.push_back(nx); ys.push_back(ny);
            }
        }
    }

    return ret;
}