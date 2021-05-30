#include <vector>
#include <string>
#include <deque>

#include "LeetCode.h"
using namespace std;

bool canConvert(const string& s1, const string& s2)
{
    int diff = 0;
    if (s1.size() != s2.size()) {
        return false;
    }

    for (int i = 0; i < s1.size(); ++i)
    {
        if (s1[i] != s2[i])
        {
            ++diff;
            if (diff > 1) {
                return false;
            }
        }
    }
    return true;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    int len = wordList.size();
    vector<int> layers(len, 0);
    deque<int> candinate{-1};

    while(!candinate.empty())
    {
        int index = candinate.front();
        candinate.pop_front();
        string word;
        if (index == -1) {
            word = beginWord;
        }
        else {
            word = wordList[index];
        }
        for (int i = 0; i < len; ++i)
        {
            if (layers[i] == 0 && canConvert(word, wordList[i]))
            {
                candinate.push_back(i);
                if (index == -1) {
                    layers[i] = 2;
                }
                else {
                    layers[i] = layers[index] + 1;
                }
                if (wordList[i] == endWord) {
                    return layers[i];
                }
            }
        }
    }
    return 0;
}