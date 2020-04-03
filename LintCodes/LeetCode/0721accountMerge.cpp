#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>

#include "LeetCode.h"
using namespace std;

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
{
	if (accounts.empty()) {
		return accounts;
	}
	vector<vector<string>> res;
	unordered_map<string, vector<int>> emailToName;
	for (int i = 0; i < accounts.size(); ++i) {
		for (auto iter = accounts[i].begin() + 1; iter != accounts[i].end(); ++iter) {
			emailToName[*iter].push_back(i);
		}
	}
	vector<bool> visited(accounts.size(), false);
	set<string> emailList;
	queue<int> searchList;

	for (int i = 0; i < accounts.size(); ++i) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		emailList.clear();
		
		string name = accounts[i][0];
		for (int j = 1; j < accounts[i].size(); ++j) {
			emailList.insert(accounts[i][j]);
			for (auto& n : emailToName[accounts[i][j]]) {
				searchList.push(n);
			}
			while (!searchList.empty()) {
				int searchIndex = searchList.front();
				searchList.pop();
				if (visited[searchIndex]) {
					continue;
				}
				visited[searchIndex] = true;
				auto& ev = accounts[searchIndex];
				for (auto iter = ev.begin() + 1; iter != ev.end(); ++iter) {
					emailList.insert(*iter);
					for (int& newIndex : emailToName[*iter]) {
						searchList.push(newIndex);
					}
				}
			}
		}
		vector<string> tmp({ name });
		for (auto& s : emailList) {
			tmp.push_back(s);
		}
		res.push_back(tmp);
	}
	return res;
}