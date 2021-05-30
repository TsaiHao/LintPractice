#include <algorithm>

#include "LeetCode.h"
using namespace std;

class trieTree
{
private:
    struct trieNode {
        int index;
        trieNode* child[26];
        trieNode() {
            index = -1;
            for (int i = 0; i < 26; ++i) {
                child[i] = nullptr;
            }
        }
    };
    trieNode* root = new trieNode();
public:
    friend void search(const trieTree& tree, const string& word, vector<vector<int>>& count, int start);
    void insert(const string& s, const int key)
    {
        trieNode* nodeP = root;
        for (int i = 0; i < s.size(); ++i) {
            int n = s[i] - 'a';
            if (nodeP->child[n] == nullptr) {
                nodeP->child[n] = new trieNode();
            }
            nodeP = nodeP->child[n];
        }
        nodeP->index = key;
    }
};
void search(const trieTree& tree, const string& word, vector<vector<int>>& count, int start)
{
    auto trav = tree.root;
    for (int i = 0; i < word.size(); ++i) {
        int let = word[i] - 'a';
        if (trav->index != -1) {
            count[trav->index].push_back(start);
        }
        if (trav->child[let] == nullptr) {
            return;
        }
        
        trav = trav->child[let];
    }
    if (trav->index != -1) {
        count[trav->index].push_back(start);
    }
}

vector<vector<int>> multiSearch(string big, vector<string>& smalls)
{
    int bigSize = big.size();
    int nSmall = smalls.size();
    trieTree tree;

    for (int i = 0; i < nSmall; ++i) {
        tree.insert(smalls[i], i);
    }
    vector<vector<int>> res(nSmall);
    for (int i = 0; i < bigSize; ++i) {
        string s = big.substr(i, bigSize - i);
        search(tree, s, res, i);
    }

    return res;
}