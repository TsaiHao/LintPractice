#include <algorithm>
#include <string.h>
#include "LeetCode.h"
using namespace std;

vector<vector<int>> NQueensSolution;
bool* used;
void NQueensDfs(vector<int>& queens, int index, int n)
{
    if (queens.size() >= n) {
        NQueensSolution.push_back(queens);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (used[col]) {
            continue;
        }
        bool dia = false;
        for (int i = 0; i < index; ++i) {
            if (col - queens[i] == index - i || col - queens[i] == i - index) {
                dia = true;
                break;
            }
        }
        if (dia) {
            continue;
        }
        used[col] = true;
        queens.push_back(col);
        NQueensDfs(queens, index + 1, n);
        queens.pop_back();
        used[col] = false;
    }
}
vector<vector<string>> translateNQueenProblem()
{
    vector<vector<string>> res;
    if (NQueensSolution.empty()) {
        return res;
    }
    for (auto& sol : NQueensSolution) {
        vector<string> vs;
        int n = sol.size();
        for (auto x : sol) {
            string s;
            for (int i = 0; i < n; ++i) {
                s.push_back(i == x ? 'Q' : '.');
            }
            vs.push_back(s);
        }
        res.push_back(vs);
    }
    return res;
}
vector<vector<string>> solveNQueens(int n)
{
    vector<int> s;
    vector<vector<string>> res;
    if (n == 1) {
        res.push_back(vector<string>(1, "Q"));
    }
    if (n <= 3) {
        return res;
    }
    used = new bool[n];
    memset(used, false, sizeof(bool) * n);
    NQueensDfs(s, 0, n);
    delete[] used;
    return translateNQueenProblem();
}