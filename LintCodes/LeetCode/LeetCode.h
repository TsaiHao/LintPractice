#pragma once
#include <vector>
#include <string>

//3 
int lengthOfLongestSubstring(std::string s);

//5
std::string longestPalindrome(std::string s, int i); //int param used to distinguish from 409

//8
int myAtoi(std::string str);

//11
int maxArea(std::vector<int>& height);

//15
std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

//19
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n);

//22
std::vector<std::string> generateParenthesis(int n);

//29
int divide(int dividend, int divisor);

//43
std::string multiply(std::string num1, std::string num2);

//50
double myPow(double x, int n);

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

//138
struct Node138 {
    int val;
    Node138* next = NULL;
    Node138* random = NULL;
    Node138(int v): val(v) {}
};
Node138* copyRandomList(Node138* head);

//169
int majorityElement(std::vector<int>& nums);

//233
int countDigitOne(int n);

//289
void gameOfLife(std::vector<std::vector<int>>& board);

//300
int lengthOfLIS(std::vector<int>& nums);

//322
int coinChange(std::vector<int> & coins, int amount);

//409
int longestPalindrome(std::string s);

//509
int numWays(int n);

//543
int diameterOfBinaryTree(TreeNode* root);

//695
int maxAreaOfIsland(std::vector<std::vector<int>>& grid);

//721
std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts);

//836
bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2);

//912
std::vector<int> sortArray(std::vector<int>& nums);

//1071
std::string gcdOfStrings(std::string str1, std::string str2);

//1114
//print in order(multithread)

//1160
int countCharacters(std::vector<std::string>& words, std::string chars);

//1162
int maxDistance(std::vector<std::vector<int>>& grid);

//1394
std::string itostring(int i);
std::string compressString(std::string S);

//1488
TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);

//1569
std::vector<int> singleNumbers(std::vector<int>& nums);