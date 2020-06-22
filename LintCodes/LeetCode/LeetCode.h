#pragma once
#include <vector>
#include <string>
#include <iostream>

//-1
template <typename T>
inline void displayArray(const std::vector<T>& arr, std::ostream& os)
{
    for (auto& e : arr) {
        os << e << '\t';
    }
    os << std::endl;
}
template <typename T>
inline void displayMatrix(const std::vector<std::vector<T>>& mat, std::ostream& os)
{
    for (auto& arr : mat) {
        displayArray(arr, os);
    }
}

//3 
int lengthOfLongestSubstring(std::string s);

//4
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);
void test0004();

//5
std::string longestPalindrome(std::string s, int i); //int param used to distinguish from 409

//7
int reverse(int x);
void test0007();

//8
int myAtoi(std::string str);

//10
bool isMatch(std::string s, std::string p);

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

//21
ListNode *mergeTwoList(ListNode *l1, ListNode *l2);

//22
std::vector<std::string> generateParenthesis(int n);

//23
ListNode* mergeKLists(std::vector<ListNode*>& lists);
void test0023();

//29
int divide(int dividend, int divisor);

//30
std::vector<int> findSubstring(std::string s, std::vector<std::string>& words);

//32
int longestValidParentheses(std::string s);

//40
std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target);

//42
int trap(std::vector<int>& height);

//43
std::string multiply(std::string num1, std::string num2);

//46
std::vector<std::vector<int>> permute(std::vector<int>& nums);

//49
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);

//50
double myPow(double x, int n);

//54
std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix);

//55
 bool canJump(std::vector<int>& nums);

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

//102
std::vector<std::vector<int>> levelOrder(TreeNode* root);

//105
TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder, int;

//121
int maxProfit(std::vector<int>& prices);

//123
int maxProfit3(std::vector<int>& prices);

//127
int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList);

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

//144
std::vector<int> preorderTraversal(TreeNode* root);

//151
std::string reverseWords(std::string s);

//152
int maxProduct(std::vector<int>& nums);

//169
int majorityElement(std::vector<int>& nums);

//201
int rangeBitwiseAnd(int m, int n);

//214
std::string shortestPalindrome(std::string s);

//233
int countDigitOne(int n);

//236
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

//240
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);

//289
void gameOfLife(std::vector<std::vector<int>>& board);

//295
// class MedianFinder;

//297
/*
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }
};
*/
//300
int lengthOfLIS(std::vector<int>& nums);

//322
int coinChange(std::vector<int> & coins, int amount);

//343
int cuttingRope(int n);

//347
std::vector<int> topKFrequent(std::vector<int>& nums, int k);
void test0347();

//409
int longestPalindrome(std::string s);

//445
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
int fun445test(int n1, int n2);

//460
// class LFUCache {};

//509
int numWays(int n);

//542
std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& matrix);

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

//921
 int minAddToMakeValid(std::string S);

//946
bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped);

//991
int brokenCalc(int X, int Y);

//1012
int numDupDigitsAtMostN(int N);

//1071
std::string gcdOfStrings(std::string str1, std::string str2);

//1114
//print in order(multithread)

//1144
int movesToMakeZigzag(std::vector<int> &nums);

//1160
int countCharacters(std::vector<std::string>& words, std::string chars);

//1162
int maxDistance(std::vector<std::vector<int>>& grid);

//1300
int findBestValue(std::vector<int>& arr, int target);

//1394
std::string itostring(int i);
std::string compressString(std::string S);

//1411
int numOfWays(int n);

//1488
TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);

//1569
std::vector<int> singleNumbers(std::vector<int>& nums);

//1590
int reversePairs(std::vector<int>& nums);

//1632
std::vector<std::vector<std::string>> solveNQueens(int n);

//1644
int translateNum(int num);

//interview 17-17
std::vector<std::vector<int>> multiSearch(std::string big, std::vector<std::string>& smalls);