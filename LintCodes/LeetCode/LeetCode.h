#pragma once
#include <vector>
#include <string>

//3 
int lengthOfLongestSubstring(std::string s);

//15
std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

//19
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n);

//29
int divide(int dividend, int divisor);

//43
std::string multiply(std::string num1, std::string num2);

//54
std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix);

//56
std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals);

//98
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode* root);

//121
int maxProfit(std::vector<int>& prices);

//123
int maxProfit3(std::vector<int>& prices);

//133
// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }

    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
Node* cloneGraph(Node* node);

//169
int majorityElement(std::vector<int>& nums);

//233
int countDigitOne(int n);

//300
int lengthOfLIS(std::vector<int>& nums);

//322
int coinChange(std::vector<int> & coins, int amount);

//509
int numWays(int n);

//543
int diameterOfBinaryTree(TreeNode* root);

//721
std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts);

//1071
std::string gcdOfStrings(std::string str1, std::string str2);

//1114
//print in order(multithread)

//1488
TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);