#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <climits>
#include <functional>
#include <stdint.h>
#include <unordered_set>
#include <bitset>


#include "Trie.h"

using std::vector;
using std::string;
using std::set;
using std::unordered_set;
using std::map;
using std::unordered_map;
using std::queue;
using std::stack;
using std::max;
using std::min;
using std::bitset;


class Trie;
class TrieNode;

#ifndef ANSWER_H
#define ANSWER_H


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
	// Constructor initializes an empty nested list.
	NestedInteger();

	// Constructor initializes a single integer.
	NestedInteger(int value);

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Set this NestedInteger to hold a single integer.
	void setInteger(int value);

	// Set this NestedInteger to hold a nested list and adds a nested integer to it.
	void add(const NestedInteger &ni);

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};

/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation
* class NestedInteger {
*   public:
*     // Return true if this NestedInteger holds a single integer, rather than a nested list.
*     bool isInteger() const;
*
*     // Return the single integer that this NestedInteger holds, if it holds a single integer
*     // The result is undefined if this NestedInteger holds a nested list
*     int getInteger() const;
*
*     // Return the nested list that this NestedInteger holds, if it holds a nested list
*     // The result is undefined if this NestedInteger holds a single integer
*     const vector<NestedInteger> &getList() const;
* };
*/
class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList) {

	}

	int next() {

	}

	bool hasNext() {

	}
};

/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

struct GraphNode {
	string destination;
	double distance;
	GraphNode(string dest, double dist) : destination(dest), distance(dist) {}
};


struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	/*
	Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
	For example:
	Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
	*/
	int addDigits(int num) {
		int result = 1 + ((num - 1) % 9);
		return result;
	}

	/*
	Given a binary tree, find its maximum depth.
	The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
	*/
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		return std::max(leftDepth, rightDepth) + 1;
	}

	/*
	Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
	Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
	*/
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
		return;
	}

	/*
	Given two binary trees, write a function to check if they are equal or not.
	Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
	*/
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		else if (q && p && p->val == q->val) return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
		else return false;
	}

	/*
	Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
	For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
	*/
	void moveZeroes(vector<int>& nums) {
		size_t i = 0;
		size_t j = 0;
		while (j < nums.size()) {
			if (nums[j] != 0) {
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
				i++;
			}
			j++;
		}
		return;
	}

	//Invert a binary tree.
	TreeNode* invertTree(TreeNode* root) {
		if (root) {
			TreeNode *temp = root->left;
			root->left = root->right;
			root->right = temp;

			invertTree(root->left);
			invertTree(root->right);
		}
		return root;
	}

	/*
	Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
	According to the definition of LCA on Wikipedia: The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).
	*/
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
		else if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
		else return root;
	}

	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n) {
			n = n&(n - 1);
			count++;
		}
		return count;
	}

	/*
	Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
	*/
	bool containsDuplicate(vector<int>& nums) {
		set<int> s;
		for (int i : nums) {
			if (s.find(i) == s.end()) s.insert(i);
			else return true;
		}
		return false;
	}

	//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
	int titleToNumber(string s) {
		int number = 0;
		for (size_t i = 0; i < s.size(); i++) {
			char c = s.at(i);
			int current_number = static_cast<int> (c - 'A') + 1;
			number = number * 26 + current_number;
		}
		return number;
	}

	/*
	Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.
	You may assume that the array is non-empty and the majority element always exist in the array.
	*/
	int majorityElement(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}

	/*
	Given two strings s and t, write a function to determine if t is an anagram of s.
	For example,
	s = "anagram", t = "nagaram", return true.
	s = "rat", t = "car", return false.
	*/
	bool isAnagram(string s, string t) {
		size_t lenS = s.length();
		size_t lenT = t.length();
		if (lenT == 0) return false;
		if (lenS != lenT) return false;

		vector<int> count(26, 0);
		for (size_t i = 0; i < lenS; i++) {
			count[s[i] - 'a']++;
		}

		for (size_t i = 0; i < lenT; i++) {
			if (--count[t[i] - 'a'] < 0) return false;

		}
		return true;
	}

	//Given an array of strings, group anagrams together.
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		for (string str : strs) {
			if (result.size() == 0) {
				vector<string> anagrams;
				anagrams.push_back(str);
				result.push_back(anagrams);
			}
			else {
				for (size_t i = 0; i < result.size(); i++) {
					if (isAnagram(result[i][0], str)) {
						for (string s : result[i]) {
							if (s == str) break;
						}
						result[i].push_back(str);
						break;
					}
					if (i == result.size() - 1) {
						vector<string> anagrams;
						anagrams.push_back(str);
						result.push_back(anagrams);
					}
				}
			}
		}

		return result;
	}

	/*
	Given a roman numeral, convert it to an integer.
	Input is guaranteed to be within the range from 1 to 3999.
	*/
	int romanToInt(string s) {
		int val[255];
		val['I'] = 1;
		val['V'] = 5;
		val['X'] = 10;
		val['L'] = 50;
		val['C'] = 100;
		val['D'] = 500;
		val['M'] = 1000;

		int num = 0;
		for (size_t i = 0; i < s.length() - 1; i++) {
			if (val[s[i]] < val[s[i + 1]]) num = num - val[s[i]];
			else num += val[s[i]];
		}
		return num + val[s[s.length() - 1]];
	}

	/*
	Given a sorted linked list, delete all duplicates such that each element appear only once.
	For example,
	Given 1->1->2, return 1->2.
	Given 1->1->2->3->3, return 1->2->3.
	*/
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *cur = head;
		while (cur && cur->next) {
			if (cur->val == cur->next->val) {
				cur->next = cur->next->next;
			}
			else {
				cur = cur->next;
			}
		}
		return head;
	}

	/*
	You are climbing a stair case. It takes n steps to reach to the top.
	Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
	*/
	int climbStairs(int n) {
		if (n == 0 || n == 1 || n == 2) return n;
		vector<int> dp(n + 1);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i < n + 1; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}

	//Reverse a singly linked list.
	ListNode* reverseList(ListNode* head) {
		ListNode *pre = NULL;
		while (head) {
			ListNode *temp = head->next;
			head->next = pre;
			pre = head;
			head = temp;
		}
		return pre;
	}

	/*
	Write a program to check whether a given number is an ugly number.
	Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
	*/
	bool isUgly(int num) {
		if (num <= 0) return false;
		int factor[] = { 2, 3,5 };
		for (int x : factor) {
			while (num%x == 0) num = num / x;
		}
		return num == 1;
	}

	/*
	Write an algorithm to determine if a number is "happy".
	A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
	*/
	bool isHappy(int n) {
		set<int> showedNumbers;
		int sum = n;
		while (sum != 1) {
			n = sum;
			sum = 0;
			while (n > 0) {
				sum += (n % 10)*(n % 10);
				n = n / 10;
			}
			if (showedNumbers.find(sum) != showedNumbers.end()) return false;
			else showedNumbers.insert(sum);
		}
		return true;
	}

	bool canWinNim(int n) {
		return n % 4 != 0;
	}

	//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *result = new ListNode(0);
		ListNode *current = result;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				current->next = l1;
				l1 = l1->next;
			}
			else {
				current->next = l2;
				l2 = l2->next;
			}
			current = current->next;
		}
		if (l1) {
			current->next = l1;
		}
		if (l2) {
			current->next = l2;
		}
		return result->next;
	}

	//Merge k Sorted Lists
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int len = static_cast<int>(lists.size());
		if (len < 1) return NULL;
		ListNode* result = lists[0];
		for (int i = 1; i < len; i++) {
			result = mergeTwoLists(result, lists[i]);
		}
		return result;
	}

	/*
	Given a binary tree, determine if it is height-balanced.
	For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
	*/
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		if (std::abs(treeDepth(root->left) - treeDepth(root->right)) > 1) {
			return false;
		}
		return (isBalanced(root->left) && isBalanced(root->right));
	}

	int treeDepth(TreeNode* root) {
		if (!root) return 0;
		return 1 + std::max(treeDepth(root->left), treeDepth(root->right));
	}

	//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return isSymmetric(root->left, root->right);
	}

	bool isSymmetric(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) {
			return true;
		}
		else if (p == NULL || q == NULL) {
			return false;
		}
		return (p->val == q->val && isSymmetric(p->right, q->left) && isSymmetric(p->left, q->right));
	}
	/*
	Given an array and a value, remove all instances of that value in place and return the new length.
	Do not allocate extra space for another array, you must do this in place with constant memory.
	The order of elements can be changed. It doesn't matter what you leave beyond the new length.
	*/
	int removeElement(vector<int>& nums, int val) {
		size_t i = 0;
		int j = 0;
		auto k = nums.size();
		while (i < nums.size()) {
			if (nums[i] == val) {
				auto temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
				j++;
			}
			i++;
		}
		nums.erase(nums.begin(), nums.begin() + j);
		return static_cast<int>(k - j);
	}

	//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;
		if (!root) return result;
		queue<TreeNode*> treeNodeQueue;
		queue<TreeNode*> nextTreeNodeQueue;
		vector<int> cur;

		treeNodeQueue.push(root);
		while (!treeNodeQueue.empty()) {
			TreeNode* tempNode = treeNodeQueue.front();
			treeNodeQueue.pop();
			cur.push_back(tempNode->val);

			if (tempNode->left) nextTreeNodeQueue.push(tempNode->left);
			if (tempNode->right) nextTreeNodeQueue.push(tempNode->right);

			if (treeNodeQueue.empty()) {
				treeNodeQueue = nextTreeNodeQueue;
				nextTreeNodeQueue = queue<TreeNode*>();
				result.push_back(cur);
				cur.clear();
			}
		}
		std::reverse(result.begin(), result.end());
		return result;
	}

	/*
	Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
	Do not allocate extra space for another array, you must do this in place with constant memory.
	*/
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		size_t i = 0;
		int j = 0;
		auto k = nums.size();
		while (i < nums.size()) {
			if (nums[i] != nums[j]) {
				auto temp = nums[j + 1];
				nums[j + 1] = nums[i];
				nums[i] = temp;
				j++;
			}
			i++;
		}
		return j + 1;
	}

	//Given an integer, write a function to determine if it is a power of two.
	bool isPowerOfTwo(int n) {
		int cnt = 0;
		while (n > 0) {
			cnt += (n & 1);
			n = n >> 1;
		}
		return cnt == 1;
	}

	/*
	You are a professional robber planning to rob houses along a street.
	Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected
	and it will automatically contact the police if two adjacent houses were broken into on the same night.
	Given a list of non-negative integers representing the amount of money of each house,
	determine the maximum amount of money you can rob tonight without alerting the police.
	*/
	int rob(vector<int>& nums) {
		int odd = 0;
		int even = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			if (i % 2 == 1) odd = std::max(odd + nums[i], even);
			else even = std::max(even + nums[i], odd);
		}
		return std::max(odd, even);
	}

	/*
	Given a non-negative number represented as an array of digits, plus one to the number.
	The digits are stored such that the most significant digit is at the head of the list.
	*/
	vector<int> plusOne(vector<int>& digits) {
		int addone = 1;
		for (auto i = digits.size() - 1; i >= 0; i--) {
			int currentDigit = (digits[i] + addone) % 10;
			addone = (digits[i] + addone) / 10;
			digits[i] = currentDigit;
			if (addone == 0) return digits;
		}
		vector<int> result = vector<int>(digits.size() + 1, 0);
		result[0] = 1;
		return result;
	}

	/*
	Given numRows, generate the first numRows of Pascal's triangle.
	[
	[1],
	[1,1],
	[1,2,1],
	[1,3,3,1],
	[1,4,6,4,1]
	]
	*/
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result = vector<vector<int>>();
		if (numRows <= 0) return result;

		vector<int> pre = vector<int>();
		pre.push_back(1);
		result.push_back(pre);

		for (int i = 1; i < numRows; i++) {
			vector<int> cur = vector<int>();
			cur.push_back(1);

			for (size_t j = 0; j < pre.size() - 1; j++) {
				cur.push_back(pre[j] + pre[j + 1]);
			}

			cur.push_back(1);
			result.push_back(cur);
			pre = cur;
		}
		return result;
	}

	//Given an integer n, return the number of trailing zeroes in n!.
	int trailingZeroes(int n) {
		int i = 1;
		int zeros = 0;

		while (n / std::pow(5, 1) >= 1) {
			zeros = static_cast<int>(zeros + n / std::pow(5, 1));
			i++;
		}
		return zeros;
	}

	/*
	Given an index k, return the kth row of the Pascal's triangle.
	For example, given k = 3,
	Return [1,3,3,1].
	*/
	vector<int> getRow(int rowIndex) {
		vector<int> result = vector<int>();
		if (rowIndex < 0) return result;
		result = vector<int>(rowIndex + 1, 1);
		for (int i = 1; i <= rowIndex; i++) {
			for (int j = i - 1; j > 0; j--) {
				result[j] = result[j] + result[j - 1];
			}
		}
		return result;
	}

	//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level from root to leaf).
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (!root) return result;
		queue<TreeNode*> treeNodeQueue;
		queue<TreeNode*> nextTreeNodeQueue;
		vector<int> cur;

		treeNodeQueue.push(root);
		while (!treeNodeQueue.empty()) {
			TreeNode* tempNode = treeNodeQueue.front();
			treeNodeQueue.pop();
			cur.push_back(tempNode->val);

			if (tempNode->left) nextTreeNodeQueue.push(tempNode->left);
			if (tempNode->right) nextTreeNodeQueue.push(tempNode->right);

			if (treeNodeQueue.empty()) {
				treeNodeQueue = nextTreeNodeQueue;
				nextTreeNodeQueue = queue<TreeNode*>();
				result.push_back(cur);
				cur.clear();
			}
		}
		return result;
	}

	//Determine whether an integer is a palindrome. Do this without extra space.
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int div = 1;
		while (x / div >= 10) div = div * 10;
		int left = 0;
		int right = 0;
		while (x > 0) {
			left = x / div;
			right = x % 10;
			if (right != left) return false;

			x = (x%div) / 10;
			div = div / 100;
		}
		return true;
	}

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return NULL;
		ListNode* pa = headA;
		ListNode* pb = headB;

		ListNode* tailA = NULL;
		ListNode* tailB = NULL;

		while (true) {
			if (!pa) pa = headB;
			if (!pb) pb = headA;

			if (!(pa->next)) tailA = pa;
			if (!(pb->next)) tailB = pb;

			if (tailA && tailB && tailA != tailB) return NULL;
			if (pa == pb) return pa;

			pa = pa->next;
			pb = pb->next;
		}
	}

	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left) return minDepth(root->right) + 1;
		if (!root->right) return minDepth(root->left) + 1;

		return std::min(minDepth(root->left), minDepth(root->right)) + 1;
	}

	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int idxA = m - 1;
		int idxB = n - 1;
		int idxM = m + n - 1;
		while (idxA >= 0 && idxB >= 0) {
			if (nums1[idxA] > nums2[idxB]) nums1[idxM--] = nums1[idxA--];
			else nums1[idxM--] = nums2[idxB--];
		}

		while (idxB >= 0) nums1[idxM--] = nums2[idxB--];
		return;
	}

	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		if (!root->left && !root->right && sum - root->val == 0) return true;
		return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
	}

	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		for (int i = 0; i < 32; i++) {
			if ((n & 1) == 1) res = (res << 1) + 1;
			else res = res << 1;
			n = n >> 1;
		}
		return res;
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.size() != 9 || board[0].size() != 9) return false;

		set<char> mySet = set<char>();

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') continue;
				if (mySet.find(board[i][j]) != mySet.end()) return false;
				mySet.insert(board[i][j]);
			}
			mySet.clear();
		}

		for (int j = 0; j < 9; j++) {
			for (int i = 0; i < 9; i++) {
				if (board[i][j] == '.') continue;
				if (mySet.find(board[i][j]) != mySet.end()) return false;
				mySet.insert(board[i][j]);
			}
			mySet.clear();
		}

		for (int k = 0; k < 9; k++) {
			for (int i = k / 3 * 3; i < k / 3 * 3 + 3; i++) {
				for (int j = (k % 3) * 3; j < (k % 3) * 3 + 3; j++) {
					if (board[i][j] == '.') continue;
					if (mySet.find(board[i][j]) != mySet.end()) return false;
					mySet.insert(board[i][j]);
				}
			}
			mySet.clear();
		}
		return true;
	}

	int lengthOfLastWord(string s) {
		if (s.size() < 1) return 0;
		int result = 0;
		for (auto iter = s.end() - 1; iter >= s.begin(); iter--) {
			if (*iter != ' ') result++;
			else if (result > 0) return result;
		}
		return result;
	}

	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		if (C < E || G < A) return (G - E)*(H - F) + (C - A)*(D - B);
		if (D < F || H < B) return (G - E)*(H - F) + (C - A)*(D - B);

		int right = std::min(C, G);
		int left = std::max(A, E);
		int top = std::min(H, D);
		int bottom = std::max(F, B);

		return (G - E)*(H - F) + (C - A)*(D - B) - (right - left)*(top - bottom);
	}

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head || !head->next) return NULL;


		ListNode* fast = head;
		ListNode* slow = head;

		for (int i = 0; i < n; i++) fast = fast->next;

		if (!fast) {
			return head->next;
		}
		else {
			while (fast->next) {
				fast = fast->next;
				slow = slow->next;
			}
		}

		slow->next = slow->next->next;

		return head;
	}

	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, int> myMap;
		for (int i = 0; i < static_cast<int>(nums.size()); i++) {
			if (myMap.find(nums[i]) == myMap.end()) {
				myMap[nums[i]] = i;
			}
			else {
				if (static_cast<int>(i - myMap[nums[i]]) <= k) return true;
				else myMap[nums[i]] = i;
			}
		}
		return false;
	}

	bool isValid(string s) {
		stack<char> st = stack<char>();
		for (size_t i = 0; i < s.size(); i++) {
			if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
				st.push(s[i]);
			}
			else {
				if (st.empty()) return false;
				if ((s[i] == ')') && (st.top() != '(')) return false;
				if ((s[i] == ']') && (st.top() != '[')) return false;
				if ((s[i] == '}') && (st.top() != '{')) return false;
				st.pop();
			}
		}
		return st.empty();
	}

	bool isIsomorphic(string s, string t) {
		map<char, char> myMap = map<char, char>();
		set<char> mySet = set<char>();
		for (size_t i = 0; i < s.size(); i++) {
			if (myMap.find(s[i]) != myMap.end()) {
				if (myMap[s[i]] == t[i]) continue;
				else return false;
			}
			else {
				if (mySet.find(t[i]) == mySet.end()) {
					mySet.insert(t[i]);
					myMap[s[i]] = t[i];
				}
				else {
					return false;
				}
			}
		}
		return true;
	}

	bool wordPattern(string pattern, string str) {
		std::istringstream iss(str);
		unordered_map<char, string> myMap = unordered_map<char, string>();
		int i = 0;
		for (string word; iss >> word; i++) {
			if (myMap.find(pattern[i]) != myMap.end()) {
				if (myMap[pattern[i]] != word) return false;
			}
			else {
				for (unordered_map<char, string>::iterator iter = myMap.begin(); iter != myMap.end(); iter++) {
					if (iter->second == word) return false;
				}
				myMap[pattern[i]] = word;
			}
		}
		return i == pattern.size();
	}

	string cas(string str) {
		string str1;
		int str_cnt = 1;
		char chr = str[0];

		for (size_t i = 1; i <= str.size(); i++) {
			if (chr == str[i]) str_cnt++;
			else {
				char temp = '0' + str_cnt;
				str1 = str1 + temp;
				str1 = str1 + chr;
				chr = str[i];
				str_cnt = 1;
			}
		}
		return str1;
	}

	string countAndSay(int n) {
		if (n == 1) return "1";
		string str = "1";
		string str_read;
		for (int i = 1; i < n; i++) {
			str_read = cas(str);
			str = str_read;
		}
		return str_read;
	}

	string addBinary(string a, string b) {
		if (a.size() == 0) return b;
		if (b.size() == 0) return a;

		int pa = static_cast<int>(a.size()) - 1;
		int pb = static_cast<int>(b.size()) - 1;
		int carry = 0;
		string result = "";

		while (pa >= 0 && pb >= 0) {
			int digit = static_cast<int> (a[pa] - '0' + b[pb] - '0') + carry;
			carry = digit / 2;
			digit = digit % 2;
			result = std::to_string(digit) + result;
			pa--;
			pb--;
		}

		while (pa >= 0) {
			int digit = static_cast<int> (a[pa] - '0') + carry;
			carry = digit / 2;
			digit = digit % 2;
			result = std::to_string(digit) + result;
			pa--;
		}

		while (pb >= 0) {
			int digit = static_cast<int> (b[pb] - '0') + carry;
			carry = digit / 2;
			digit = digit % 2;
			result = std::to_string(digit) + result;
			pb--;
		}

		if (carry > 0) result = std::to_string(carry) + result;
		return result;
	}

	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		if (strs.size() == 1) return strs[0];

		for (size_t i = 0; i < strs[0].size(); i++) {
			for (size_t j = 1; j < strs.size(); j++) {
				if (i > strs[j].size() || strs[j - 1][i] != strs[j][i]) {
					return strs[j].substr(0, i);
				}
			}
		}

		return strs[0];

	}

	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) return true;
		ListNode *slow = head, *fast = head;
		stack<int> s;
		s.push(head->val);

		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			s.push(slow->val);
		}

		if (!fast->next) s.pop();

		while (slow->next) {
			slow = slow->next;
			int temp = s.top();
			s.pop();
			if (temp != slow->val) return false;
		}

		return true;
	}

	string getHint(string secret, string guess) {
		vector<int> m = vector<int>(256, 0);
		int bull = 0;
		int cow = 0;

		for (size_t i = 0; i < secret.size(); i++) {
			if (secret[i] == guess[i]) bull++;
			else {
				if (m[secret[i]]++ < 0) cow++;
				if (m[guess[i]]-- > 0) cow++;
			}
		}

		return std::to_string(bull) + "A" + std::to_string(cow) + "B";
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result = vector<string>();
		if (!root) return result;

		string s = "";
		dfsBinaryTreePath(root, s, result);

		return result;
	}

	void dfsBinaryTreePath(TreeNode* root, string s, vector<string>& result) {
		if (!root->left && !root->right) {
			s = s + std::to_string(root->val);
			result.push_back(s);
		}

		s = s + std::to_string(root->val);
		s = s + "->";

		if (root->left) dfsBinaryTreePath(root->left, s, result);
		if (root->right) dfsBinaryTreePath(root->right, s, result);
	}

	int reverse(int x) {
		long rev = 0;
		while (x != 0)
		{
			rev = rev * 10 + x % 10;
			x = x / 10;
		}

		if (rev > std::pow(2, 31) - 1 || rev < -std::pow(2, 31)) return 0;
		else return static_cast<int>(rev);

	}

	int strStr(string haystack, string needle) {
		int n = static_cast<int>(needle.size());
		if (n == 0) return 0;
		int m = static_cast<int>(haystack.size());
		if (m == 0) return -1;

		for (int i = 0; i <= m - n; i++) {
			for (int j = 0; j < n; j++) {
				char c1 = haystack[i + j];
				char c2 = needle[j];

				if (c1 == c2 && j == n - 1) return i;
				if (c1 != c2) break;
			}
		}
		return -1;
	}

	

	bool isPalindrome(string s) {
		int len = static_cast<int>(s.size());
		if (len <= 1) return true;
		int i = 0;
		int j = len - 1;
		while (i <= j) {
			if (!isAlphanumeric(s[i])) i++;
			else if (!isAlphanumeric(s[j])) j--;
			else if (isSameChar(s[i], s[j])) {
				i++;
				j--;
			}
			else return false;
		}
		return true;
	}

	bool isAlphanumeric(char c) {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isSameChar(char a, char b) {
		return toupper(a) == toupper(b);
	}


	/*
	Given a string s, partition s such that every substring of the partition is a palindrome.
	Return all possible palindrome partitioning of s.
	*/
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		if(s.empty()) return result;
		
		vector<string> onePartition;
		dfsPartition(s, 0, result, onePartition);
		return result;
	}

	void dfsPartition(string s, int start, vector<vector<string>>& result, vector<string>& onePartition) {
		// stop condition
		if(start == static_cast<int>(s.size())) {
			result.push_back(onePartition);
			return;
		}

		//dfs search
		for(int len = 1; len + start <= static_cast<int>(s.size()); len++) {
			string temp = s.substr(start, len);
			if(isPalindrome(temp)) {
				onePartition.push_back(temp);
				dfsPartition(s, start+len, result, onePartition);
				onePartition.pop_back();
			}
		}
	}

	/*
	Given a string s, partition s such that every substring of the partition is a palindrome.
	Return the minimum cuts needed for a palindrome partitioning of s.
	For example, given s = "aab",
	Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
	*/
	int minCut(string s) {
		int len = static_cast<int>(s.size());
		if (len <= 1) return 0;
		vector<vector<bool>> dp(len, vector<bool>(len, false));
		vector<int> cut(len, INT_MAX);
		
		for (int right = 0; right < len; right++) {
			for (int left = 0; left <= right; left++) {
				if (s[left] == s[right] && (right - left <= 1 || dp[left + 1][right - 1])) {
					dp[left][right] = true;
					
					if (left > 0) {
						cut[right] = min(cut[right], cut[left - 1] + 1);
					}
					else {
						cut[right] = 0;
					}
				}
			}
		}

		return cut.back();
	}

	/*
	Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, 
	so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
	*/
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> result;
		map<string, int> myMap;
		set<int> mySet;

		for (int i = 0; i < static_cast<int>(words.size()); i++) {
			myMap[words[i]] = i;
			mySet.insert(static_cast<int>(words[i].size()));
		}

		for (int i = 0; i < static_cast<int>(words.size()); i++) {
			string part = string(words[i].rbegin(), words[i].rend());
			if (myMap.count(part) && myMap[part] != i) {
				vector<int> onePair;
				onePair.push_back(i);
				onePair.push_back(myMap[part]);
				result.push_back(onePair);
			}

			int len = static_cast<int>(part.size());
			auto lenLim = mySet.find(len);
			for (set<int>::iterator it = mySet.begin(); it != lenLim; it++) {
				int counterpartLen = *it;
				if (isPartPalindrome(part, 0, len - counterpartLen - 1) && myMap.count(part.substr(len - counterpartLen, string::npos))) {
					vector<int> onePair;
					onePair.push_back(i);
					onePair.push_back(myMap[part.substr(len - counterpartLen, string::npos)]);
					result.push_back(onePair);
				}
				
				if (isPartPalindrome(part, counterpartLen, len - 1) && myMap.count(part.substr(0, counterpartLen))) {
					vector<int> onePair;
					onePair.push_back(myMap[part.substr(0, counterpartLen)]);
					onePair.push_back(i);
					result.push_back(onePair);
				}
				
			}
		}
		return result;
	}

	bool isPartPalindrome(string s, int left, int right) {
		while (left < right) {
			if (s[left] == s[right]) {
				left++;
				right--;
			}
			else {
				return false;
			}
		}
		return true;
	}

	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		string result = "";
		vector<string> flag = vector<string>(numRows, "");
		int direction = 1;
		int i = 0;
		for (size_t k = 0; k < s.size(); k++) {
			flag[i] = flag[i] + s[k];
			if ((i == 0 && k != 0) || (i == numRows - 1)) direction = -direction;
			i = i + direction;
		}

		for (int j = 0; j < numRows; j++) {
			result = result + flag[j];
		}

		return result;
	}

	int countPrimes(int n) {
		if (n < 2) return 0;

		vector<bool> flag = vector<bool>(n, true);
		flag[0] = false;
		flag[1] = false;
		int i = 2;
		while (i*i < n) {
			if (flag[i]) {
				int j = i + i;
				while (j < n) {
					flag[j] = false;
					j = j + i;
				}
			}
			i = i + 1;
		}

		int count = 0;
		for (bool f : flag) {
			if (f) count++;
		}
		return count;
	}

	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result = vector<string>();
		if (nums.empty()) return result;
		string s;
		int start = nums[0];
		int end = nums[0];
		for (size_t i = 1; i <= nums.size(); i++) {
			if ((i < nums.size()) && (nums[i] == end + 1)) {
				end = nums[i];
			}
			else {
				if (start == end) s = std::to_string(start);
				else s = std::to_string(start) + "->" + std::to_string(end);
				result.push_back(s);

				if (i < nums.size()) {
					start = nums[i];
					end = nums[i];
				}
			}
		}
		return result;
	}

	string convertToTitle(int n) {
		string result;
		while (n > 0) {
			char current = static_cast<char>('A' + (n - 1) % 26);
			result = current + result;
			n = (n - 1) / 26;
		}
		return result;
	}

	void rotate(vector<int>& nums, int k) {
		int length = static_cast<int>(nums.size());
		k = k%length;
		reverseNum(nums, 0, length - k);
		reverseNum(nums, length - k, length);
		reverseNum(nums, 0, length);
	}

	void reverseNum(vector<int>& nums, int start, int end) {
		for (int i = start; i < (start + end) / 2; i++) {
			int temp = nums[i];
			nums[i] = nums[end + start - 1 - i];
			nums[end + start - 1 - i] = temp;
		}
	}

	int myAtoi(string str) {
		return 0;
	}

	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int num : nums) {
			result = result^num;
		}
		return result;
	}

	vector<int> singleNumberIII(vector<int>& nums) {
		int AxorB = 0;
		for (int num : nums) {
			AxorB = AxorB^num;
		}

		int lastBit = AxorB&(~(AxorB - 1));
		int A = 0;
		int B = 0;
		for (int num : nums) {
			if (lastBit&num) A = A^num;
			else B = B^num;
		}

		vector<int> result = vector<int>(A, B);
		return result;
	}

	int maxProfitII(vector<int>& prices) {
		if (prices.size() < 2) return 0;
		int profit = 0;
		for (size_t i = 0; i < prices.size() - 1; i++) {
			if (prices[i + 1] - prices[i] > 0) profit = profit + prices[i + 1] - prices[i];
		}
		return profit;
	}

	vector<int> productExceptSelf(vector<int>& nums) {
		int len = static_cast<int>(nums.size());
		vector<int> left = vector<int>(len, 0);
		vector<int> right = vector<int>(len, 0);
		vector<int> result = vector<int>(len, 0);

		left[0] = 1;
		right[len - 1] = 1;
		for (int i = 0; i < len - 1; i++) {
			left[i + 1] = nums[i] * left[i];
			right[len - 2 - i] = nums[len - 1 - i] * right[len - 1 - i];
		}

		for (int i = 0; i < len; i++) result[i] = left[i] * right[i];
		return result;
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result = vector<int>();
		recursivePreorder(root, result);
		return result;
	}

	void recursivePreorder(TreeNode* root, vector<int>& l) {
		if (root) {
			l.push_back(root->val);
			recursivePreorder(root->left, l);
			recursivePreorder(root->right, l);
		}
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result = vector<int>();
		recursiveInorder(root, result);
		return result;
	}

	void recursiveInorder(TreeNode* root, vector<int>& l) {
		if (root) {
			recursiveInorder(root->left, l);
			l.push_back(root->val);
			recursiveInorder(root->right, l);
		}
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result = vector<int>();
		recursivePostorder(root, result);
		return result;
	}

	void recursivePostorder(TreeNode* root, vector<int>& l) {
		if (root) {
			recursivePostorder(root->left, l);
			recursivePostorder(root->right, l);
			l.push_back(root->val);
		}
	}

	int missingNumber(vector<int>& nums) {
		int sum = 0;
		for (int num : nums) {
			sum = sum + num;
		}

		int n = static_cast<int>(nums.size());
		return (n + 1)*n / 2 - sum;
	}

	bool hasCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;

			if (fast == slow) return true;
		}
		return false;
	}

	void connect(TreeLinkNode *root) {
		if (!root) return;
		if (root->left) root->left->next = root->right;
		if (root->right && root->next) root->right->next = root->next->left;

		connect(root->left);
		connect(root->right);
	}

	int searchInsert(vector<int>& nums, int target) {
		int len = static_cast<int>(nums.size());
		if (target <= nums[0]) return 0;
		if (target > nums[len - 1]) return len;
		int i = 0;
		while (i < len - 1) {
			if (target > nums[i] && target <= nums[i + 1]) return i + 1;
			else i = i + 1;
		}
	}

	int numTrees(int n) {
		vector<int> count = vector<int>(n + 1, 0);
		count[0] = 1;
		count[1] = 1;
		for (int i = 2; i < n + 1; i++) {
			for (int j = 0; j < i; j++) {
				count[i] = count[i] + count[j] * count[i - j - 1];
			}
		}
		return count[n];
	}

	string intToRoman(int num) {
		unordered_map<int, string> myMap = unordered_map<int, string>();
		myMap[1000] = "M";
		myMap[900] = "CM";
		myMap[500] = "D";
		myMap[400] = "CD";
		myMap[100] = "C";
		myMap[90] = "XC";
		myMap[50] = "L";
		myMap[40] = "XL";
		myMap[10] = "X";
		myMap[9] = "IX";
		myMap[5] = "V";
		myMap[4] = "IV";
		myMap[1] = "I";
		vector<int> myArray;
		myArray.push_back(1000);
		myArray.push_back(900);
		myArray.push_back(500);
		myArray.push_back(400);
		myArray.push_back(100);
		myArray.push_back(90);
		myArray.push_back(50);
		myArray.push_back(40);
		myArray.push_back(10);
		myArray.push_back(9);
		myArray.push_back(5);
		myArray.push_back(4);
		myArray.push_back(1);
		//myArray = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

		string romeNum;
		for (size_t i = 0; i < myArray.size(); i++) {
			int currLim = myArray[i];
			while (num >= currLim) {
				num = num - currLim;
				romeNum = romeNum + myMap[currLim];
			}
		}
		return romeNum;
	}

	int maxSubArray(vector<int>& nums) {
		int thissum = 0;
		int maxsum = INT_MIN;
		for (int num : nums) {
			if (thissum < 0) thissum = 0;
			thissum = thissum + num;
			maxsum = std::max(thissum, maxsum);
		}
		return maxsum;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() < 1) return NULL;
		return sortedArrayToBST(nums, 0, static_cast<int>(nums.size() - 1));
	}

	TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
		if (start > end) return NULL;
		int mid = (start + end) / 2;
		TreeNode* root = new TreeNode(nums[mid]);

		root->left = sortedArrayToBST(nums, start, mid - 1);
		root->right = sortedArrayToBST(nums, mid + 1, end);
		return root;
	}

	int findMin(vector<int>& nums) {
		int left = 0;
		int right = static_cast<int>(nums.size()) - 1;
		int mid = 0;
		int min = nums[0];

		while (left < right - 1) {
			mid = (right + left) / 2;
			if (nums[mid] > nums[left]) {
				min = std::min(min, nums[left]);
				left = mid + 1;
			}
			else if (nums[mid] < nums[left]) {
				min = std::min(min, nums[mid]);
				right = mid - 1;
			}
		}

		min = std::min(min, nums[left]);
		min = std::min(min, nums[right]);

		return min;
	}

	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;

		int minPrice = prices[0];
		int profit = 0;
		for (int price : prices) {
			minPrice = std::min(minPrice, price);
			profit = std::max(profit, price - minPrice);
		}
		return profit;
	}

	int uniquePaths(int m, int n) {
		if (m == 0 || n == 0) return 0;
		if (m == 1 || n == 1) return 1;

		vector<vector<int>> dp(m, vector<int>(n));

		for (int i = 0; i < m; i++) {
			dp[i][0] = 1;
		}

		for (int j = 0; j < n; j++) {
			dp[0][j] = 1;
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[m - 1][n - 1];
	}

	vector<int> grayCode(int n) {
		vector<int> result = vector<int>();
		result.push_back(0);
		for (int i = 0; i < n; i++) {
			int highestBit = 1 << i;
			for (int j = static_cast<int>(result.size()) - 1; j >= 0; j--) {
				result.push_back(result[j] + highestBit);
			}
		}
		return result;
	}

	vector<string> generateParenthesis(int n) {
		vector<string> result = vector<string>();
		string s;
		generateParenthesis(result, s, n, n);
		return result;
	}

	void generateParenthesis(vector<string>& result, string s, int left, int right) {
		if (left > right) return;

		if (left == 0 && right == 0) {
			result.push_back(s);
			return;
		}

		if (left > 0) generateParenthesis(result, s + "(", left - 1, right);
		if (right > 0) generateParenthesis(result, s + ")", left, right - 1);

	}

	int kthSmallest(TreeNode* root, int k) {
		TreeNode* p = root;
		stack<TreeNode*> s = stack<TreeNode*>();
		int ks = 0;

		while (p || !s.empty()) {
			if (p) {
				s.push(p);
				p = p->left;
			}
			else {
				TreeNode* t = s.top();
				s.pop();
				k--;
				if (k == 0) ks = t->val;;
				p = t->right;
			}
		}
		return ks;
	}

	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;

		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* p = dummy;
		while (p->next && p->next->next) {
			ListNode* temp = p->next->next;
			p->next->next = temp->next;
			temp->next = p->next;
			p->next = temp;
			p = p->next->next;
		}
		return dummy->next;
	}


	void sortColors(vector<int>& nums) {
		int n = (int)nums.size();
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - 1 - i; j++) {
				if (nums[j] > nums[j + 1]) {
					int temp = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = temp;
				}
			}
		}
	}

	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0) return 0;
		int m = (int)grid.size();
		int n = (int)grid[0].size();

		vector<vector<int>> dp(m, vector<int>(n));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
		for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (dp[i - 1][j] < dp[i][j - 1]) dp[i][j] = dp[i - 1][j] + grid[i][j];
				else dp[i][j] = dp[i][j - 1] + grid[i][j];
			}
		}
		return dp[m - 1][n - 1];
	}

	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> smatrix(n, vector<int>(n));
		int top = 0;
		int bottom = n - 1;
		int left = 0;
		int right = n - 1;

		int direction = 1;
		int elem = 0;
		while (elem < n*n) {
			if (direction == 1) {
				for (int i = left; i <= right; i++) {
					elem++;
					smatrix[top][i] = elem;
				}
				top++;
			}

			if (direction == 2) {
				for (int i = top; i <= bottom; i++) {
					elem++;
					smatrix[i][right] = elem;
				}
				right--;
			}

			if (direction == 3) {
				for (int i = right; i >= left; i--) {
					elem++;
					smatrix[bottom][i] = elem;
				}
				bottom--;
			}

			if (direction == 0) {
				for (int i = bottom; i >= top; i--) {
					elem++;
					smatrix[i][left] = elem;
				}
				left++;
			}

			direction = (direction + 1) % 4;
		}
		return smatrix;
	}

	int maxArea(vector<int>& height) {
		int left = 0;
		int right = (int)height.size() - 1;
		int curWater = 0;
		int maxWater = 0;
		while (left < right) {
			curWater = (right - left)*std::min(height[left], height[right]);
			maxWater = std::max(curWater, maxWater);
			if (height[left] < height[right]) left++;
			else right--;
		}
		return maxWater;
	}

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int numRows = (int)matrix.size();
		int numCols = (int)matrix[0].size();
		int i = 0;
		int j = numCols - 1;
		while (i < numRows && j >= 0) {
			if (matrix[i][j] == target) return true;
			else if (matrix[i][j] > target) j--;
			else i++;
		}
		return false;
	}

	void setZeroes(vector<vector<int>>& matrix) {
		int numRows = (int)matrix.size();
		int numCols = (int)matrix[0].size();

		vector<bool> zeroRows = vector<bool>(numRows, false);
		vector<bool> zeroCols = vector<bool>(numCols, false);

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				if (matrix[i][j] == 0) {
					zeroRows[i] = true;
					zeroCols[j] = true;
				}
			}
		}

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				if (zeroRows[i] || zeroCols[j]) matrix[i][j] = 0;
			}
		}
	}

	int maxProfitCool(vector<int>& prices) {
		int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
		for (int price : prices) {
			pre_buy = buy;
			buy = max(pre_sell - price, pre_buy);
			pre_sell = sell;
			sell = max(pre_buy + price, pre_sell);
		}
		return sell;
	}

	bool isBadVersion(int version) {
		if (version > 100) return false;
		else return true;
	}

	int firstBadVersion(int n) {
		if (n == 1) return 1;

		int left = 1;
		int right = n;
		while (left + 1 < right) {
			int mid = left + (right - left) / 2;
			if (isBadVersion(mid)) right = mid;
			else left = mid;
		}

		if (isBadVersion(left)) return left;

		return right;
	}

	int bulbSwitch(int n) {
		return static_cast<int>(std::sqrt(n));
	}

	int maxProduct(vector<string>& words) {
		int n = static_cast<int>(words.size());
		vector<vector<int>> elements(n, vector<int>(26, 0));
		for (int i = 0; i < n; i++) {
			for (size_t j = 0; j < words[i].size(); j++) {
				elements[i][words[i][j] - 'a']++;
			}
		}

		size_t ans = 0;
		bool noDuplicate;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				noDuplicate = true;
				for (int k = 0; k < 26; k++) {
					if (elements[i][k] != 0 && elements[j][k] != 0) {
						noDuplicate = false;
						break;
					}
				}
				if (noDuplicate && ans < words[i].length()*words[j].length()) {
					ans = static_cast<int>(words[i].length()*words[j].length());
				}
			}
		}
		return static_cast<int>(ans);
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int> list;
		dfsCombinationSum3(result, 1, n, list, k);
		return result;
	}

	void dfsCombinationSum3(vector<vector<int>>& result, int start, int sum, vector<int>& list, int k) {
		if (sum == 0 && list.size() == k) result.push_back(list);

		for (int i = start; i <= 9; i++) {
			if (sum - i < 0) break;
			if (static_cast<int>(list.size()) > k) break;

			list.push_back(i);
			dfsCombinationSum3(result, i + 1, sum - i, list, k);
			list.erase(list.end() - 1);
		}
	}

	/*
	Given an integer array with all positive numbers and no duplicates, 
	find the number of possible combinations that add up to a positive integer target.
	*/
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= target; i++) {
			for (int num : nums) {
				if (i >= num) dp[i] += dp[i - num];
			}
		}
		return dp[target];
	}

	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> list;
		dfsCombine(result, list, n, k, 1);
		return result;
	}

	void dfsCombine(vector<vector<int>>& result, vector<int>& list, int n, int k, int level) {
		if (list.size() == k) {
			result.push_back(list);
			return;
		}

		for (int i = level; i <= n; i++) {
			list.push_back(i);
			dfsCombine(result, list, n, k, i + 1);
			list.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> list;
		std::sort(candidates.begin(), candidates.end());
		dfsCombinationSum(result, list, candidates, target, 0);
		return result;
	}

	void dfsCombinationSum(vector<vector<int>>& result, vector<int>& list, vector<int> candidates, int target, int level) {
		if (target == 0 && list.size() > 0) {
			result.push_back(list);
			return;
		}

		for (int i = level; i < static_cast<int>(candidates.size()); i++) {
			if (target - candidates[i] < 0) break;
			list.push_back(candidates[i]);
			dfsCombinationSum(result, list, candidates, target - candidates[i], i);
			list.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> list;
		std::sort(candidates.begin(), candidates.end());
		dfsCombinationSum2(result, list, candidates, target, 0);
		return result;
	}

	void dfsCombinationSum2(vector<vector<int>>& result, vector<int>& list, vector<int> candidates, int target, int level) {
		if (target == 0) {
			result.push_back(list);
			return;
		}

		for (int i = level; i < static_cast<int>(candidates.size()); i++) {
			if (i > level && candidates[i] == candidates[i - 1]) continue;
			if (target - candidates[i] < 0) break;
			list.push_back(candidates[i]);
			dfsCombinationSum2(result, list, candidates, target - candidates[i], i + 1);
			list.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		string trans[] = { "", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> result;
		string oneComb;
		if (digits.size() < 1) return result;
		dfsLetterCombinations(result, oneComb, trans, digits, 0);
		return result;
	}

	void dfsLetterCombinations(vector<string>& result, string& oneComb, string trans[], string digits, int dialed) {
		if (dialed == digits.size()) {
			result.push_back(oneComb);
			return;
		}

		int curDigit = static_cast<int>(digits[dialed] - 48);
		for (size_t i = 0; i < trans[curDigit].size(); i++) {
			oneComb.push_back(trans[curDigit][i]);
			dfsLetterCombinations(result, oneComb, trans, digits, dialed + 1);
			oneComb.pop_back();
		}
	}

	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		int len = static_cast<int>(nums.size());
		vector<int> list(len, 1);

		for (int i = 1; i < len; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) list[i] = max(list[i], list[j] + 1);
			}
		}

		return *std::max_element(list.begin(), list.end());
	}

	vector<int> rightSideView(TreeNode* root) {
		vector<vector<int>> levelOrderTraversal = levelOrder(root);
		vector<int> result;
		int level = static_cast<int>(levelOrderTraversal.size());
		for (int i = 0; i < level; i++) {
			int rightView = levelOrderTraversal[i][levelOrderTraversal[i].size() - 1];
			result.push_back(rightView);
		}
		return result;
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> list;
		if (nums.empty()) return result;
		result.push_back(list);
		std::sort(nums.begin(), nums.end());
		dfsSubsets(result, list, nums, 0);
		return result;
	}

	void dfsSubsets(vector<vector<int>>& result, vector<int>& list, vector<int> nums, int level) {
		for (int i = level; i < static_cast<int>(nums.size()); i++) {
			list.push_back(nums[i]);
			result.push_back(list);
			dfsSubsets(result, list, nums, i + 1);
			list.pop_back();
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> list;
		if (nums.empty()) return result;
		result.push_back(list);
		std::sort(nums.begin(), nums.end());
		dfsSubsetsWithDup(result, list, nums, 0);
		return result;
	}

	void dfsSubsetsWithDup(vector<vector<int>>& result, vector<int>& list, vector<int> nums, int level) {
		for (int i = level; i < static_cast<int>(nums.size()); i++) {
			if (i > level && nums[i] == nums[i - 1]) continue;
			list.push_back(nums[i]);
			result.push_back(list);
			dfsSubsetsWithDup(result, list, nums, i + 1);
			list.pop_back();
		}
	}

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
		int m = static_cast<int>(obstacleGrid.size());
		int n = static_cast<int>(obstacleGrid[0].size());
		if (obstacleGrid[m - 1][n - 1] == 1) return 0;

		vector<vector<int>> dp(m, vector<int>(n));
		dp[0][0] = 1;
		for (int i = 1; i < m; i++) {
			if (obstacleGrid[i][0] == 1) {
				dp[i][0] = 0;
			}
			else {
				dp[i][0] = dp[i - 1][0];
			}
		}

		for (int j = 1; j < n; j++) {
			if (obstacleGrid[0][j] == 1) {
				dp[0][j] = 0;
			}
			else {
				dp[0][j] = dp[0][j - 1];
			}
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) {
					dp[i][j] = 0;
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}

			}
		}
		return dp[m - 1][n - 1];
	}

	int maxProduct(vector<int>& nums) {
		if (nums.size() <= 0) return 0;
		int recordMax = nums[0];
		int currentMax = nums[0];
		int currentMin = nums[0];

		for (size_t i = 1; i < nums.size(); i++) {
			int temp = currentMax;
			currentMax = max(max(currentMax*nums[i], currentMin*nums[i]), nums[i]);
			currentMin = min(min(temp*nums[i], currentMin*nums[i]), nums[i]);
			recordMax = max(recordMax, currentMax);
		}
		return recordMax;
	}

	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid.size() == 0 || grid[0].size() == 0) return 0;
		int count = 0;
		for (int i = 0; i < static_cast<int>(grid.size()); i++) {
			for (int j = 0; j < static_cast<int>(grid[0].size()); j++) {
				if (grid[i][j] != '1') continue; // either water or visited
				else {
					count++;
					dfsIslands(grid, i, j);
				}
			}
		}
		return count;
	}

	void dfsIslands(vector<vector<char>>& grid, int i, int j) {
		if (i < 0 || i >= static_cast<int>(grid.size()) || j < 0 || j >= static_cast<int>(grid[0].size()))  return;
		if (grid[i][j] != '1') return;  //either water or visited
		grid[i][j] = '2';	// makr as visited
		dfsIslands(grid, i - 1, j);
		dfsIslands(grid, i + 1, j);
		dfsIslands(grid, i, j - 1);
		dfsIslands(grid, i, j + 1);
	}

	double myPow(double x, int n) {
		if (n < 0) return 1.0 / helpPow(x, -n);
		else return helpPow(x, n);
	}

	double helpPow(double x, int n) {
		if (n == 0) return 1;
		double v = helpPow(x, n / 2);
		if (n % 2 == 0) {
			return v*v;
		}
		else {
			return v*v*x;
		}
	}

	int hIndex(vector<int>& citations) {
		std::sort(citations.begin(), citations.end(), std::greater<int>());
		for (int i = 0; i < static_cast<int>(citations.size()); i++) {
			if (i >= citations[i]) return i;
		}
		return static_cast<int>(citations.size());
	}

	string reverseString(string s) {
		string result = "";
		int i = static_cast<int>(s.length()) - 1;
		while (i >= 0) {
			result = result + s.at(i);
			i--;
		}
		return result;
	}

	int getSum(int a, int b) {
		if (b == 0) return a;
		int sum = a^b;
		int carry = (a&b) << 1;
		return getSum(sum, carry);
	}

	bool canConstruct(string ransomNote, string magazine) {
		int letter[26];
		for (int k = 0; k < 26; k++) letter[k] = 0;
		for (size_t i = 0; i < magazine.size(); i++) {
			letter[magazine.at(i) - 'a']++;
		}

		for (size_t j = 0; j < ransomNote.size(); j++) {
			if (--letter[ransomNote.at(j) - 'a'] < 0) return false;
		}
		return true;
	}

	string reverseVowels(string s) {
		set<char> vowels;
		vowels.insert('a');
		vowels.insert('e');
		vowels.insert('i');
		vowels.insert('o');
		vowels.insert('u');
		vowels.insert('A');
		vowels.insert('E');
		vowels.insert('I');
		vowels.insert('O');
		vowels.insert('U');

		int left = 0;
		int right = static_cast<int>(s.size()) - 1;
		while (left <= right) {
			if ((vowels.find(s[left]) == vowels.end())) {
				left++;
				continue;
			}

			if ((vowels.find(s[right]) == vowels.end())) {
				right--;
				continue;
			}

			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			left++;
			right--;
		}
		return s;
	}

	bool isPowerOfFour(int num) {
		if (num == 0) return false;
		int power = static_cast<int>(log(num) / log(4));
		if (pow(4, power) == num) return true;
		else return false;
	}

	bool isPowerOfThree(int n) {
		if (n == 0) return false;
		int power = static_cast<int>(floor(log(n) / log(3) + 0.5));
		if (pow(3, power) == n) return true;
		else return false;
	}

	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s1(nums1.begin(), nums1.end());
		set<int> s2;
		for (int element : nums2) {
			if (s1.count(element) > 0) s2.insert(element);
		}
		vector<int> result(s2.begin(), s2.end());
		return result;
	}

	vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
		std::sort(nums1.begin(), nums1.end());
		std::sort(nums2.begin(), nums2.end());
		vector<int> result;
		vector<int>::iterator iter1 = nums1.begin();
		vector<int>::iterator iter2 = nums2.begin();
		while (iter1 != nums1.end() && iter2 != nums2.end()) {
			if (*iter1 > *iter2) iter2++;
			else if (*iter1 < *iter2) iter1++;
			else {
				result.push_back(*iter1);
				iter1++;
				iter2++;
			}
		}
		return result;
	}

	// This is a pre-defined API
	int guess(int num);

	int guessNumber(int n) {
		int L = 1;
		int R = n;
		while (L <= R) {
			int mid = L + ((R - L) >> 1);
			int res = guess(mid);
			if (res == 0) return mid;
			else if (res == 1)  L = mid + 1;
			else R = mid - 1;
		}
		return L;
	}

	vector<int> countBits(int num) {
		vector<int> result(num + 1, 0);
		for (int i = 0; i <= num; i++) {
			result[i] = result[i >> 1] + (i & 1);
		}
		return result;
	}

	int countNumbersWithUniqueDigits(int n) {
		n = min(n, 10);
		vector<int> dp(n + 1, 9);
		dp[0] = 1;
		for (int i = 2; i < n + 1; i++) {
			for (int k = 9; k >= 9 - i + 2; k--) {
				dp[i] = dp[i] * k;
			}
		}
		int ans = 0;
		for (int j = 0; j < n + 1; j++) ans = ans + dp[j];
		return ans;
	}

	bool increasingTriplet(vector<int>& nums) {
		int num1 = INT_MAX;
		int num2 = INT_MAX;
		for (int num : nums) {
			if (num <= num1) num1 = num;
			else if (num <= num2) num2 = num;
			else return true;
		}
		return false;
	}

	int integerBreak(int n) {
		if (n == 2 || n == 3) return n - 1;
		int result = 1;
		while (n > 4) {
			result = result * 3;
			n = n - 3;
		}
		return result*n;
	}

	bool isPerfectSquare(int num) {
		long long low = 1;
		long long high = num / 2 + 1;
		long long mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (num == mid*mid) return true;
			else if (num > mid*mid) low = mid + 1;
			else high = mid - 1;
		}
		return false;
	}

	vector<int> majorityElementII(vector<int>& nums) {
		vector<int> result;
		int m1 = NULL;
		int m2 = NULL;
		int c1 = 0;
		int c2 = 0;
		for (int i : nums) {
			if (i == m1) c1++;
			else if (i == m2) c2++;
			else if (c1 == 0) {
				m1 = i;
				c1 = 1;
			}
			else if (c2 == 0) {
				m2 = i;
				c2 = 1;
			}
			else {
				c1--;
				c2--;
			}
		}
		c1 = 0;
		c2 = 0;
		for (int i : nums) {
			if (i == m1) c1++;
			else if (i == m2) c2++;
		}
		if (c1 > static_cast<int>(nums.size()) / 3) result.push_back(m1);
		if (c2 > static_cast<int>(nums.size()) / 3) result.push_back(m2);
		return result;
	}

	vector<int> twoSum2(vector<int>& numbers, int target) {
		int left = 0;
		int right = static_cast<int>(numbers.size()) - 1;
		long long tempSum = 0;
		vector<int> result;
		while (left <= right) {
			tempSum = numbers[left] + numbers[right];
			if (tempSum == static_cast<long long>(target)) {
				result.push_back(left + 1);
				result.push_back(right + 1);
				return result;
			}
			else if (tempSum < static_cast<long long>(target)) {
				left++;
			}
			else right--;
		}
		return result;
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> myMap;
		vector<int> result;
		for (int i = 0; i < static_cast<int>(nums.size()); i++) {
			int diff = target - nums[i];
			if (myMap.find(diff) != myMap.end()) {
				result.push_back(myMap[diff]);
				result.push_back(i);
				return result;
			}
			myMap.emplace(nums[i], i);
		}
		return result;
	}

	int rangeBitwiseAnd(int m, int n) {
		int d = INT_MAX;
		while ((m&d) != (n&d)) {
			d = d << 1;
		}
		return m&d;
	}

	int wiggleMaxLength(vector<int>& nums) {
		if (nums.empty()) return 0;
		int ans = 1;
		int n = static_cast<int>(nums.size());
		for (int cur = 1, prev = 0; cur < n; prev = cur, cur++) {
			if (nums[cur] > nums[prev]) {
				ans++;
				while ((cur + 1 < n) && (nums[cur + 1] >= nums[cur])) cur++;
			}
			else if (nums[cur] < nums[prev]) {
				ans++;
				while ((cur + 1 < n) && (nums[cur + 1] <= nums[cur])) cur++;
			}
		}
		return ans;
	}

	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* fakeHead = new ListNode(0);
		ListNode* cur = head;
		while (cur != NULL) {
			ListNode* next = cur->next;
			ListNode* pre = fakeHead;
			while (pre->next != NULL && pre->next->val < cur->val) {
				pre = pre->next;
			}
			cur->next = pre->next;
			pre->next = cur;
			cur = next;
		}
		return fakeHead->next;
	}

	int findDuplicate(vector<int>& nums) {
		int low = 1;
		int high = static_cast<int>(nums.size()) - 1;
		while (low < high) {
			int mid = (low + high) / 2;
			int c = 0;

			for (int i : nums) {
				if (i <= mid) c++;
			}

			if (c > mid) high = mid;
			else low = mid + 1;
		}
		return low;
	}

	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX - 1);
		dp[0] = 0;
		for (int i = 1; i < amount + 1; i++) {
			for (size_t j = 0; j < coins.size(); j++) {
				if (coins[j] <= i) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}

	bool canJump(vector<int>& nums) {
		int maxDist = 0;
		int n = static_cast<int>(nums.size());
		for (int i = 0; i <= maxDist && maxDist < n - 1; i++) {
			if (maxDist < i + nums[i]) maxDist = i + nums[i];
		}
		return maxDist >= n - 1;
	}

	int lengthOfLongestSubstring(string s) {
		int maxLen = 0;
		unordered_set<char> myMap;
		int start = 0;
		for (int i = 0; i < static_cast<int>(s.size()); i++) {
			if (myMap.find(s[i]) == myMap.end()) myMap.insert(s[i]);
			else {
				maxLen = max(maxLen, static_cast<int>(myMap.size()));
				while (start < i && s[start] != s[i]) {
					myMap.erase(s[start]);
					start++;
				}
				start++;
			}
		}
		return max(maxLen, static_cast<int>(myMap.size()));
	}

	
	vector<string> generatePossibleNextMoves(string s) {
		vector<string> result;
		for (int i = 0; i + 1 < static_cast<int>(s.size()); i++) {
			if (s[i] == '+' && s[i + 1] == '+') {
				s[i] = '-';
				s[i + 1] = '-';
				result.push_back(s);
				s[i] = '+';
				s[i + 1] = '+';
			}
		}
		return result;
	}

	int shortestDistance(vector<string>& words, string word1, string word2) {
		int dist = INT_MAX;
		int pos1 = -1;
		for (int i = 0; i < static_cast<int>(words.size()); i++) {
			if (words[i].compare(word1) == 0 || words[i].compare(word2) == 0) {
				if (pos1 == -1) {
					pos1 = i;
				}
				else {
					if (words[i].compare(words[pos1]) != 0) {
						dist = min(abs(i - pos1), dist);
						pos1 = i;
					}
					else pos1 = i;
				}
			}
		}
		return dist;
	}

	bool canAttendMeetings(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), compareInterval);
		for (int i = 0; i < static_cast<int>(intervals.size()) - 1; i++) {
			if (intervals[i].end > intervals[i + 1].start) return false;
		}
		return true;
	}

	static bool compareInterval(Interval& interval1, Interval& interval2) {
		if (interval1.start == interval2.start) {
			return interval1.end < interval2.end;
		}
		else {
			return interval1.start < interval2.start;
		}

	}

	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> result;
		sort(intervals.begin(), intervals.end(), compareInterval);
		int i = 0;
		while (i < static_cast<int>(intervals.size())) {
			Interval currItv = intervals[i];
			int j = i + 1;
			while (j < static_cast<int>(intervals.size())) {
				Interval nextItv = intervals[j];
				if (nextItv.start <= currItv.end) {
					currItv.end = max(currItv.end, nextItv.end);
					j++;
				}
				else {
					i = j;
					if (j == static_cast<int>(intervals.size()) - 1) {
						result.push_back(currItv);
						result.push_back(nextItv);
						return result;
					}
					break;
				}
			}
			result.push_back(currItv);
			i = j;
		}
		return result;
	}

	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end(), compareInterval);
		return merge(intervals);
	}

	int closestValue(TreeNode* root, double target) {
		if (!root) return INT_MAX;
		if (!root->left && !root->right) return root->val;
		int left = closestValue(root->left, target);
		int right = closestValue(root->right, target);
		double od = abs(root->val - target);
		double ld = abs(left - target);
		double rd = abs(right - target);
		if (od < rd) return od < ld ? root->val : left;
		else return rd < ld ? right : left;
	}

	bool isStrobogrammatic(string num) {
		map<char, char> myRule;
		myRule.emplace('0', '0');
		myRule.emplace('1', '1');
		myRule.emplace('6', '9');
		myRule.emplace('8', '8');
		myRule.emplace('9', '6');
		int n = static_cast<int>(num.size());
		if ((n / 2 * 2 == n) || (n / 2 * 2 != n && (num[n / 2] == '0' || num[n / 2] == '1' || num[n / 2] == '8')))
		{
			for (int i = n / 2 - 1; i >= 0; i--) {
				if (myRule.find(num[i]) != myRule.end()) {
					if (myRule[num[i]] == num[n - 1 - i]) continue;
					else return false;
				}
				else return false;
			}
		}
		else return false;
		return true;
	}

	vector<vector<int>> findLeaves(TreeNode* root) {
		vector<vector<int>> result;
		vector<int> leaves;
		while (root) {
			root = removeLeaves(root, leaves);
			result.push_back(leaves);
		}
		return result;
	}

	TreeNode* removeLeaves(TreeNode* root, vector<int>& leaves) {
		if (!root) return NULL;
		if (!root->left && !root->right) {
			leaves.push_back(root->val);
			root = NULL;
			return root;
		}
		root->left = removeLeaves(root->left, leaves);
		root->right = removeLeaves(root->right, leaves);
		return root;
	}

	void wiggleSort(vector<int>& nums) {
		int n = static_cast<int>(nums.size());
		for (int i = 1; i < n; i++) {
			if ((i % 2 == 1 && nums[i] < nums[i - 1]) || (i % 2 == 0 && nums[i] > nums[i - 1])) {
				int temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
			}
		}
	}

	ListNode* plusOne(ListNode* head) {
		stack<ListNode*> myStack;
		ListNode* cur = head;
		while (cur) {
			myStack.push(cur);
			cur = cur->next;
		}
		int carry = 1;
		while (!myStack.empty() && carry > 0) {
			ListNode* t = myStack.top();
			myStack.pop();
			int sum = t->val + carry;
			t->val = sum % 10;
			carry = sum / 10;
		}

		if (carry) {
			ListNode* fakeHead = new ListNode(1);
			fakeHead->next = head;
			head = fakeHead;
		}
		return head;
	}

	vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
		int l = static_cast<int>(A.size());
		int m = static_cast<int>(B.size());
		int n = static_cast<int>(B[0].size());
		vector<vector<int>> C(l, vector<int>(n, 0));
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < m; j++) {
				if (A[i][j]) {
					for (int k = 0; k < n; k++) C[i][k] += A[i][j] * B[j][k];
				}
			}
		}
		return C;
	}

	int shortestDistance3(vector<string>& words, string word1, string word2) {
		int dist = INT_MAX;
		int pos1 = -1;
		for (int i = 0; i < static_cast<int>(words.size()); i++) {
			if (words[i].compare(word1) == 0 || words[i].compare(word2) == 0) {
				if (pos1 == -1) {
					pos1 = i;
				}
				else {
					if (words[i].compare(words[pos1]) != 0 && word1.compare(word2) != 0) {
						dist = min(abs(i - pos1), dist);
						pos1 = i;
					}
					else if (words[i].compare(words[pos1]) == 0 && word1.compare(word2) == 0) {
						dist = min(abs(i - pos1), dist);
						pos1 = i;
					}
					pos1 = i;
				}
			}
		}
		return dist;
	}

	int countComponents(int n, vector<pair<int, int>>& edges) {
		vector<set<int>> g;
		for (pair<int, int> edge : edges) {
			if (g.empty()) {
				set<int> tempGraph;
				tempGraph.emplace(edge.first);
				tempGraph.emplace(edge.second);
				g.push_back(tempGraph);
			}
			else {
				for (set<int>& curGraph : g) {
					if (curGraph.find(edge.first) == curGraph.end() && curGraph.find(edge.second) == curGraph.end()) {
						set<int> tempGraph;
						tempGraph.emplace(edge.first);
						tempGraph.emplace(edge.second);
						g.push_back(tempGraph);
					}
					else {
						if (curGraph.find(edge.first) == curGraph.end()) curGraph.emplace(edge.first);
						if (curGraph.find(edge.second) == curGraph.end()) curGraph.emplace(edge.second);
					}
				}
			}
		}
		return static_cast<int>(g.size());
	}

	int threeSumClosest(vector<int>& nums, int target) {
		int result;
		sort(nums.begin(), nums.end());
		int minDiff = INT_MAX;
		int n = static_cast<int>(nums.size());
		for (int i = 0; i < n - 2; i++) {
			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				int diff = abs(target - sum);
				if (sum == target) {
					return sum;
				}
				else if (sum > target) {
					k--;
				}
				else {
					j++;
				}
				if (diff < minDiff) {
					minDiff = diff;
					result = sum;
				}
			}
		}
		return result;
	}

	vector<vector<int>> threeSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		vector<int> oneSolution;
		sort(nums.begin(), nums.end());
		int n = static_cast<int>(nums.size());
		for (int i = 0; i < n - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] == target) {
					oneSolution.push_back(nums[i]);
					oneSolution.push_back(nums[j]);
					oneSolution.push_back(nums[k]);
					result.push_back(oneSolution);
					oneSolution.clear();
					while (j < k && nums[j] == nums[j + 1]) j++;
					while (j < k && nums[k] == nums[k - 1]) k--;
					k--;
					j++;
				}
				else if (nums[i] + nums[j] + nums[k] > target) {
					k--;
				}
				else {
					j++;
				}
			}
		}
		return result;
	}

	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		vector<int> comb;
		sort(nums.begin(), nums.end());
		nSum(nums, target, 4, comb, result);
		return result;
	}

	void nSum(vector<int>& nums, int target, int N, vector<int>& comb, vector<vector<int>>& result) {
		if (static_cast<int>(nums.size()) < N || target < nums[0] * N || target > nums.back()*N) {
			return;		// early termination
		}
		if (N == 2) {
			int left = 0;
			int right = static_cast<int>(nums.size());
			while (left < right) {
				int s = nums[left] + nums[right];
				if (s == target) {
					comb.push_back(nums[left]);
					comb.push_back(nums[right]);
					result.push_back(comb);
					comb.clear();
					while (left < right && nums[left + 1] == nums[left]) {
						left++;
					}
					left++;
					right--;
				}
				else if (s < target) {
					left++;
				}
				else {
					right--;
				}
			}
		}
		else {
			for (int i = 0; i < static_cast<int>(nums.size()) - N + 1; i++) {
				if (i != 0 && nums[i] == nums[i - 1]) continue;
				vector<int> nums_new;
				nums_new.assign(nums.begin() + i + 1, nums.end());
				comb.push_back(nums[i]);
				nSum(nums_new, target - nums[i], N - 1, comb, result);
			}
		}
	}

	int threeSumSmaller(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int cnt = 0;
		int n = static_cast<int>(nums.size());
		for (int i = 0; i < n - 2; i++) {
			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] >= target) k--;
				else {
					cnt = cnt + (k - j);
					j++;
				}
			}
		}
		return cnt;
	}

	vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
		int n = static_cast<int>(nums.size());
		vector<int> result(n, 0);
		int i = 0;
		int j = n - 1;
		int idx = a >= 0 ? n - 1 : 0;
		while (i <= j) {
			if (a >= 0) {
				result[idx--] = helpTransformedArray(nums[i], a, b, c) >= helpTransformedArray(nums[j], a, b, c) ? helpTransformedArray(nums[i++], a, b, c) : helpTransformedArray(nums[j--], a, b, c);
			}
			else {
				result[idx++] = helpTransformedArray(nums[i], a, b, c) <= helpTransformedArray(nums[j], a, b, c) ? helpTransformedArray(nums[i++], a, b, c) : helpTransformedArray(nums[j--], a, b, c);
			}
		}
		return result;
	}

	int helpTransformedArray(int x, int a, int b, int c) {
		return a*x*x + b*x + c;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		int len1 = 0;
		int len2 = 0;
		while (p1) {
			len1++;
			p1 = p1->next;
		}
		while (p2) {
			len2++;
			p2 = p2->next;
		}
		if (len1 < len2) {
			p1 = l2;
			p2 = l1;
		}
		else {
			p1 = l1;
			p2 = l2;
		}
		int a;
		int b;
		while (p1 || p2) {
			if (p2) {
				a = p1->val;
				b = p2->val;
				p1->val = (a + b + carry) % 10;
				carry = (a + b + carry) / 10;
				p1 = p1->next;
				p2 = p2->next;
			}
			else {
				a = p1->val;
				p1->val = (a + carry) % 10;
				carry = (a + carry) / 10;
				p1 = p1->next;
			}
		}
		if (carry == 1) {
			if (len1 < len2) p1 = l2;
			else p1 = l1;
			while (p1->next) {
				p1 = p1->next;
			}
			p1->next = new ListNode(1);
		}
		if (len1 < len2) return l2;
		else return l1;
	}

	bool knows(int a, int b);

	int findCelebrity(int n) {
		int celebrity = 0;
		for (int i = 1; i < n; i++) {
			if (knows(celebrity, i)) celebrity = i;
		}

		for (int i = 0; i < n; i++) {
			if (i != celebrity && (knows(celebrity, i) || !knows(i, celebrity))) return -1;
		}
		return celebrity;
	}

	void reverseWords(string &s) {
		int i = 0;
		int j = 0;
		int l = 0;
		int len = static_cast<int>(s.length());
		int wordCount = 0;
		while (true) {
			while (i < len && s[i] == ' ') {
				i++;
			}
			if (i == len) break;
			if (wordCount > 0) {
				s[j] = ' ';
				j++;
			}
			l = j;
			while (i < len && s[i] != ' ') {
				s[j] = s[i];
				i++;
				j++;
			}
			reverseWord(s, l, j - 1);
			wordCount++;
		}
		s.resize(j);
		reverseWord(s, 0, j - 1);
	}

	void reverseWord(string &s, int i, int j) {
		while (i < j) {
			char t = s[i];
			s[i++] = s[j];
			s[j--] = t;
		}
	}

	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* cur = head;
		stack<ListNode*> myStack;
		int a = 1;
		while (a < m)
		{
			cur = cur->next;
			a++;
		}
		while (a <= n) {
			myStack.push(cur);
			cur = cur->next;
			a++;
		}
		ListNode* rest = cur;
		a = 1;
		ListNode* fakeHead = new ListNode(0);
		fakeHead->next = head;
		cur = fakeHead;
		while (a < m) {
			cur = cur->next;
			a++;
		}
		while (!myStack.empty()) {
			ListNode* t = myStack.top();
			myStack.pop();
			cur->next = t;
			cur = cur->next;
		}
		cur->next = rest;
		return fakeHead->next;
	}

	char findTheDifference(string s, string t) {
		unordered_map<char, int> dic;
		for (int i = 0; i < static_cast<int>(s.length()); i++) {
			if (dic.find(s[i]) == dic.end()) {
				dic.emplace(s[i], 1);
			}
			else dic[s[i]]++;
		}
		int j;
		for (j = 0; j < static_cast<int>(t.length()); j++) {
			if (dic.find(t[j]) == dic.end()) {
				return t[j];
			}
			else if (--dic[t[j]] < 0) {
				return t[j];
			}
		}
		return t[j];
	}

	int integerReplacement(int n) {
		if (n == 1) return 0;
		if (n % 2 == 0) return integerReplacement(n / 2) + 1;
		else return min(integerReplacement(n + 1) + 1, integerReplacement(n - 1) + 1);
	}

	int maxRotateFunction(vector<int>& A) {
		int len = static_cast<int>(A.size());
		int sum = 0;
		int temp = 0;
		for (int i = 0; i < len; i++) {
			sum = sum + A[i];
			temp = temp + i*A[i];
		}
		int result = temp;
		for (int i = 1; i < len; i++) {
			temp = temp + sum - len*A[len - i];
			result = max(temp, result);
		}
		return result;
	}

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> myMap;
		for (int elem : nums) {
			if (myMap.find(elem) != myMap.end()) {
				myMap[elem]++;
			}
			else {
				myMap.emplace(elem, 1);
			}
		}
		int maxCount = 0;
		for (auto onePair : myMap) {
			int count = onePair.second;
			maxCount = max(maxCount, count);
		}
		vector<vector<int>> myArray(maxCount + 1, vector<int>());
		for (auto onePair : myMap) {
			myArray[onePair.second].push_back(onePair.first);
		}

		vector<int> result;
		for (int i = maxCount; i >= 0; i--) {
			if (!myArray[i].empty()) {
				for (int elem : myArray[i]) {
					result.push_back(elem);
				}
			}
		}
		result.resize(k);
		return result;
	}

	bool isSubsequence(string s, string t) {
		int len = static_cast<int>(s.length());
		size_t pFound = 0;
		size_t cFound;
		for (int i = 0; i < len; i++) {
			if (i == 0) {
				cFound = t.find(s[i]);
			}
			else {
				cFound = t.find(s[i], pFound + 1);
			}
			if (cFound == string::npos) {
				return false;
			}
			else {
				pFound = cFound;
			}
		}
		return true;
	}

	int maxPoints(vector<Point>& points) {
		int result = 0;
		int num = static_cast<int>(points.size());
		for (int i = 0; i < num; i++) {
			int samePoint = 1;
			unordered_map<double, int> map;
			for (int j = i + 1; j < num; j++) {
				if (points[i].x == points[j].x && points[i].y == points[j].y) {
					samePoint++;
				}
				else if (points[i].x == points[j].x) {
					map[INT_MAX]++;
				}
				else {
					double slope = double(points[i].y - points[j].y) / double(points[i].x - points[j].x);
					map[slope]++;
				}
			}
			int localMax = 0;
			for (auto it = map.begin(); it != map.end(); it++) {
				localMax = max(localMax, it->second);
			}
			localMax += samePoint;
			result = max(result, localMax);
		}
		return result;
	}

	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return NULL;
		unordered_map<RandomListNode*, RandomListNode*> myMap;
		RandomListNode* p = head;
		RandomListNode* newHead = new RandomListNode(head->label);
		RandomListNode* q = newHead;
		myMap.emplace(p, q);
		p = p->next;
		while (p) {
			RandomListNode* temp = new RandomListNode(p->label);
			q->next = temp;
			q = q->next;
			myMap.emplace(p, q);
			p = p->next;
		}

		p = head;
		q = newHead;
		while (p) {
			if (p->random) {
				q->random = myMap[p->random];
			}
			else {
				q->random = NULL;
			}
			q = q->next;
			p = p->next;
		}
		return newHead;
	}

	string largestNumber(vector<int>& nums) {
		string result = "";
		sort(nums.begin(), nums.end(), compare);
		for (int i = 0; i < static_cast<int>(nums.size()); i++) {
			result = result + to_string(nums[i]);
		}
		if (result[0] == '0') {
			return "0";
		}
		return result;
	}

	static bool compare(int a, int b) {
		string x = to_string(a);
		string y = to_string(b);
		return x + y > y + x;
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = static_cast<int>(nums1.size());
		int n = static_cast<int>(nums2.size());
		int total = m + n;
		if (total % 2 == 0) {
			return (findKth(total / 2, nums1, nums2, 0, 0) + findKth(total / 2 + 1, nums1, nums2, 0, 0)) / 2;
		}
		else {
			return findKth(total / 2 + 1, nums1, nums2, 0, 0);
		}
	}

	double findKth(int k, vector<int> nums1, vector<int> nums2, int start1, int start2) {
		if (start1 >= static_cast<int>(nums1.size())) {
			return nums2[start2 + k - 1];
		}
		if (start2 >= static_cast<int>(nums2.size())) {
			return nums1[start1 + k - 1];
		}
		if (k == 1) {
			return min(nums1[start1], nums2[start2]);
		}
		int m1 = start1 + k / 2 - 1;
		int m2 = start2 + k / 2 - 1;
		int mid1;
		int mid2;
		if (m1 < static_cast<int>(nums1.size())) {
			mid1 = nums1[m1];
		}
		else {
			mid2 = INT_MAX;
		}
		if (m2 < static_cast<int>(nums2.size())) {
			mid2 = nums2[m2];
		}
		else {
			mid2 = INT_MAX;
		}
		if (mid1 < mid2) {
			return findKth(k - k / 2, nums1, nums2, m1 + 1, start2);
		}
		else {
			return findKth(k - k / 2, nums1, nums2, start1, m2 + 1);
		}
	}

	bool isMatch(string s, string p) {
		int lenS = static_cast<int>(s.length());
		int lenP = static_cast<int>(p.length());
		int sid = 0;
		int pid = 0;
		int starIdx = -1;
		int savedSid = -1;
		while (sid < lenS) {
			if (s[sid] == p[pid] || p[pid] == '?') {
				sid++;
				pid++;
			}
			else if (p[pid] == '*') {
				starIdx = pid;
				pid++;
				savedSid = sid;
			}
			else {
				if (starIdx > -1) {
					pid = starIdx + 1;
					savedSid++;
					sid = savedSid;
				}
				else {
					return false;
				}
			}
		}
		while (p[pid] == '*') pid++;
		return pid == lenP;
	}

	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int len = static_cast<int>(s.length());
		vector<bool> dp(len + 1, false);
		dp[0] = true;
		for (int i = 1; i <= len; i++) {
			for (int j = 0; j < i; j++) {
				if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[len];
	}

	vector<string> wordBreak2(string s, unordered_set<string>& wordDict) {
		int len = static_cast<int>(s.length());
		vector<bool> dp(len + 1, false);
		dp[0] = true;
		vector<string> path;
		vector<string> result;
		for (int i = 1; i <= len; i++) {
			for (int j = 0; j < i; j++) {
				if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
					dp[i] = true;
					break;
				}
			}
		}
		dfsWordBreak(s, wordDict, path, result, 0, dp);

		return result;
	}

	void dfsWordBreak(string s, unordered_set<string> wordDict, vector<string>& path, vector<string>& result, int index, vector<bool>& canBreak) {
		int len = static_cast<int>(s.length());
		if (len == index) {
			string oneSentence = "";
			for (string w : path) {
				oneSentence = oneSentence + w;
				oneSentence = oneSentence + " ";
			}
			oneSentence.erase(oneSentence.length() - 1);
			result.push_back(oneSentence);
			return;
		}

		if (!canBreak[index]) {
			return;
		}

		for (int i = index; i < len; i++) {
			string remain = s.substr(index, i + 1 - index);
			if (wordDict.find(remain) != wordDict.end()) {
				path.push_back(remain);
				dfsWordBreak(s, wordDict, path, result, i + 1, canBreak);
				path.pop_back();
			}
		}
	}

	int sumOfLeftLeaves(TreeNode* root) {
		int sum = 0;
		if (root) {
			TreeNode* left = root->left;
			TreeNode* right = root->right;
			if (left && (left->left == NULL) && (left->right == NULL)) {
				sum = sum + left->val + sumOfLeftLeaves(right);
			}
			else {
				sum = sum + sumOfLeftLeaves(left) + sumOfLeftLeaves(right);
			}
		}
		return sum;
	}

	int findNthDigit(int n) {
		int i = 0;
		while (n > 0) {
			i++;
			int minusDigits = static_cast<int>(i*(pow(10, i) - pow(10, i - 1)));
			if (n - minusDigits > 0) {
				n = n - minusDigits;
			}
			else {
				break;
			}
		}
		int number = static_cast<int>(pow(10, i - 1) + (n - 1) / i);
		string numberStr = to_string(number);
		return numberStr[(n - 1) % i] - '0';
	}

	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		unordered_map<string, int> sampleMap;
		int index = 0;
		for (auto equation : equations) {
			if (sampleMap.find(equation.first) == sampleMap.end()) {
				sampleMap.emplace(equation.first, index++);
			}
			if (sampleMap.find(equation.second) == sampleMap.end()) {
				sampleMap.emplace(equation.second, index++);
			}
		}
		vector<vector<double>> graph(sampleMap.size(), vector<double>(sampleMap.size(), INT_MAX));
		for (size_t i = 0; i < values.size(); i++) {
			int idx1 = sampleMap[equations[i].first];
			int idx2 = sampleMap[equations[i].second];
			graph[idx1][idx2] = values[i];
			graph[idx2][idx1] = 1.0 / values[i];
		}

		for (size_t k = 0; k < sampleMap.size(); k++) {
			for (size_t i = 0; i < sampleMap.size(); i++) {
				for (size_t j = 0; j < sampleMap.size(); j++) {
					if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX) {
						graph[i][j] = min(graph[i][k] * graph[k][j], graph[i][j]);
					}
				}
			}
		}

		vector<double> result;
		for (auto query : queries) {
			if (sampleMap.find(query.first) == sampleMap.end() || sampleMap.find(query.second) == sampleMap.end()) {
				result.push_back(-1.0);
			}
			else {
				int idx1 = sampleMap[query.first];
				int idx2 = sampleMap[query.second];
				double calc = graph[idx1][idx2] == INT_MAX ? -1 : graph[idx1][idx2];
				result.push_back(calc);
			}
		}
		return result;
	}

	vector<int> lexicalOrder(int n) {
		vector<int> result;
		for (int i = 1; i <= 9; i++) {
			lexicalOrderDfs(i, n, result);
		}
		return result;
	}

	void lexicalOrderDfs(int cur, int n, vector<int>& result) {
		if (cur > n) return;
		result.push_back(cur);
		for (int i = 0; i < 10; i++) {
			if (cur * 10 + i > n) {
				return;
			}
			else {
				lexicalOrderDfs(cur * 10 + i, n, result);
			}
		}
	}


	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> path;
		pathSum(root, sum, path, result);
		return result;
	}

	void pathSum(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& result) {
		if (!root) return;
		if (sum - root->val == 0 && root->left == NULL && root->right == NULL) {
			path.push_back(root->val);
			result.push_back(path);
			path.pop_back();
			return;
		}
		path.push_back(root->val);
		sum = sum - root->val;
		pathSum(root->left, sum, path, result);
		pathSum(root->right, sum, path, result);
		path.pop_back();
	}

	/*
	You are given a binary tree in which each node contains an integer value.
	Find the number of paths that sum to a given value.
	The path does not need to start or end at the root or a leaf,
	but it must go downwards (traveling only from parent nodes to child nodes).
	*/
	int pathSumIII(TreeNode* root, int sum) {
		if (!root) return 0;
		vector<int> path;
		vector<vector<int>> paths;
		dfsPathSum(root, sum, path, paths);
		return static_cast<int>(paths.size());
	}

	void dfsPathSum(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& paths) {
		if (!root) return;
		if (root->val == sum) {
			path.push_back(root->val);
			paths.push_back(path);
			path.pop_back();
			return;
		}

		if (path.empty()) {
			dfsPathSum(root->left, sum, path, paths);
			dfsPathSum(root->right, sum, path, paths);
		}

		path.push_back(root->val);
		sum = sum -  root->val;
		dfsPathSum(root->left, sum, path, paths);
		dfsPathSum(root->right, sum, path, paths);
		path.pop_back();
		return;
	}

	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph(numCourses);
		for (auto prereq : prerequisites) {
			graph[prereq.first].insert(prereq.second);
		}
		vector<bool> visitedGlobal(numCourses, false);
		vector<bool> visitedCurrent(numCourses, false);
		for (int i = 0; i < numCourses; i++) {
			if (!visitedGlobal[i] && graphCycleDfs(graph, i, visitedGlobal, visitedCurrent)) return false;
		}
		return true;
	}

	bool graphCycleDfs(vector<unordered_set<int>> graph, int curNode, vector<bool>& visitedGlobal, vector<bool>& visitedCurrent) {
		if (visitedCurrent[curNode]) return false;
		visitedGlobal[curNode] = true;
		visitedCurrent[curNode] = true;
		for (int neighbor : graph[curNode]) {
			if (visitedCurrent[neighbor] || graphCycleDfs(graph, neighbor, visitedGlobal, visitedCurrent)) {
				return true;
			}
		}
		visitedCurrent[curNode] = false;
		return false;
	}

	vector<string> readBinaryWatch(int num) {
		vector<string> result;
		for (int hour = 0; hour < 12; hour++) {
			for (int minute = 0; minute < 60; minute++) {
				if (bitset<10>(hour).count() + bitset<10>(minute).count() == num) {
					string time = to_string(hour) + ":";
					if (minute < 10) {
						time = time + "0" + to_string(minute);
					}
					else {
						time = time + to_string(minute);
					}
					result.push_back(time);
				}
			}
		}
		return result;
	}

	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		string curSeq = "";
		unordered_map<string, int> dnaMap;
		for (size_t i = 0; i < s.length(); i++) {
			if (curSeq.length() == 10) {
				curSeq.erase(0, 1);
				curSeq = curSeq + s[i];
			}
			else {
				curSeq = curSeq + s[i];
			}

			if (curSeq.length() == 10) {
				if (dnaMap.find(curSeq) == dnaMap.end()) {
					dnaMap[curSeq] = 1;
				}
				else {
					dnaMap[curSeq]++;
				}
			}
		}

		for (auto seq : dnaMap) {
			if (seq.second > 1) {
				result.push_back(seq.first);
			}
		}

		return result;
	}

	int lastRemaining(int n) {
		int start = 1;
		int gap = 1;
		int cnt = 0;
		while (n > 1) {
			n = n / 2;
			gap = gap * 2;
			cnt++;
			if (cnt % 2) {
				start = start + gap / 2 + (n - 1)*gap;
			}
			else {
				start = start - gap / 2 - (n - 1)*gap;
			}
		}
		return start;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int start = 0;
		int end = static_cast<int>(nums.size()) - 1;
		bool isFind = false;
		int findIdx = 0;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (nums[mid] > target) {
				end = mid - 1;
			}
			else if (nums[mid] < target) {
				start = mid + 1;
			}
			else {
				isFind = true;
				findIdx = mid;
				break;
			}
		}
		int rangeStart = -1;
		int rangeEnd = -1;
		vector<int> result;
		if (isFind) {
			rangeStart = findIdx;
			rangeEnd = findIdx;
			while (nums[rangeStart] == target && rangeStart >= 0 && rangeStart < static_cast<int>(nums.size())) {
				rangeStart--;
			}
			rangeStart++;
			while (nums[rangeEnd] == target && rangeEnd >= 0 && rangeEnd < static_cast<int>(nums.size())) {
				rangeEnd++;
			}
			rangeEnd--;
			result.push_back(rangeStart);
			result.push_back(rangeEnd);
		}
		else {
			result.push_back(rangeStart);
			result.push_back(rangeEnd);
		}
		return result;
	}

	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int>> result;
		for (int num1 : nums1) {
			for (int num2 : nums2) {
				pair<int, int> p(num1, num2);
				result.push_back(p);
			}
		}
		sort(result.begin(), result.end(), comparePair);
		vector<pair<int, int>> ret;
		k = std::min(k, static_cast<int>(result.size()));
		for (int i = 0; i < k; i++) {
			ret.push_back(result[i]);
		}
		return ret;
	}

	static bool comparePair(pair<int, int>& p1, pair<int, int>& p2) {
		return p1.first + p1.second < p2.first + p2.second;
	}

	vector<string> fizzBuzz(int n) {
		vector<string> result(n);
		int j;
		for (int i = 0; i < n; i++) {
			j = i + 1;
			if (j % 15 == 0) {
				result[i] = "FizzBuzz";
			}
			else if (j % 3 == 0) {
				result[i] = "Fizz";
			}
			else if (j % 5 == 0) {
				result[i] = "Buzz";
			}
			else {
				result[i] = to_string(j);
			}
		}
		return result;
	}

	int longestPalindrome(string s) {
		int maxLen = 0;
		int oddCnt = 0;
		vector<int> myTable(58, 0);
		for (char c : s) {
			myTable[c - 'A']++;
		}
		for (int i : myTable) {
			if (i % 2 == 0) {
				maxLen = maxLen + i;
			}
			else {
				maxLen = maxLen + i - 1;
				oddCnt++;
			}
		}
		if (oddCnt > 0) maxLen++;
		return maxLen;
	}

	int lengthLongestPath(string input) {
		int result = 0;
		istringstream ss(input);
		unordered_map<int, int> myMap;
		myMap.emplace(0, 0);
		string line = "";
		while (getline(ss, line)) {
			int level = static_cast<int>(line.find_last_of('\t')) + 1;
			int len = static_cast<int>(line.substr(level).length());
			if (level == 0) {
				myMap[level] = len + 1;
			}
			else {
				myMap[level] = myMap[level - 1] + len + 1;
			}
			if (line.find('.') != string::npos) {
				result = max(result, myMap[level] - 1);
			}

		}
		return result;
	}

	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> result;
		int start = lower;
		int end = lower;
		string missingRange;
		for (int i : nums) {
			if (i > start) {
				end = i - 1;
				if (start == end) {
					result.push_back(to_string(start));
				}
				else {
					result.push_back(to_string(start) + "->" + to_string(end));
				}
				start = i + 1;
				end = start;
			}
			else {
				start = i + 1;
			}
		}
		if (nums.size() >= 1 && nums.back() < upper) {
			start = nums.back() + 1;
			end = upper;
			if (start == end) {
				result.push_back(to_string(start));
			}
			else {
				result.push_back(to_string(start) + "->" + to_string(end));
			}
		}
		else if (nums.size() == 0) {
			if (lower == upper) {
				result.push_back(to_string(lower));
			}
			else {
				result.push_back(to_string(lower) + "->" + to_string(upper));
			}
		}
		return result;
	}

	int longestConsecutive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int maxLen = 0;
		int curLen = 0;
		int prevNum = INT_MIN;
		for (int i : nums) {
			if (prevNum == INT_MIN) {
				curLen = 1;
			}
			else if (i - prevNum == 1) {
				curLen++;
			}
			else if (i - prevNum == 0) {
				continue;
			}
			else {
				maxLen = max(maxLen, curLen);
				curLen = 1;
			}
			prevNum = i;
		}
		return max(maxLen, curLen);
	}

	//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		deque<int> myWindow;

		for (int i = 0; i < static_cast<int>(nums.size()); i++) {
			if (!myWindow.empty() && myWindow.front() == i - k) myWindow.pop_front();
			while (!myWindow.empty() && nums[myWindow.back()] < nums[i]) myWindow.pop_back();
			myWindow.push_back(i);
			if (i >= k - 1) result.push_back(nums[myWindow.front()]);
		}
		return result;
	}

	//Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
	string shortestPalindrome(string s) {
		int i = 0;
		if (static_cast<int>(s.size()) == 0) return "";
		for (int j = static_cast<int>(s.size()) - 1; j >= i; j--) {
			if (s[i] == s[j]) i++;
		}

		if (i == static_cast<int>(s.size())) return s;

		string suffix = s.substr(i, string::npos);
		string prefix = string(suffix.rbegin(), suffix.rend());
		string middle = s.substr(0, i);
		return prefix + middle + suffix;
	}

	string frequencySort(string s) {
		map<char, pair<char, int>> myMap;
		vector<pair<char, int>> myVec;
		for (char c : s) {
			if (myMap.find(c) == myMap.end()) {
				pair<char, int> p(c, 1);
				myMap.emplace(c, p);
			}
			else {
				myMap[c].second++;
			}
		}

		for (auto it = myMap.begin(); it != myMap.end(); it++) {
			myVec.push_back(it->second);
		}

		sort(myVec.begin(), myVec.end(), compareCharFreq);
		string result = "";
		for (auto p : myVec) {
			result = result + string(p.second, p.first);
		}
		return result;
	}

	static bool compareCharFreq(pair<char, int> p1, pair<char, int> p2) {
		return p1.second > p2.second;
	}


	/*
	Given a 2D board and a list of words from the dictionary, find all words in the board.
	Each word must be constructed from letters of sequentially adjacent cell,
	where "adjacent" cells are those horizontally or vertically neighboring.
	The same letter cell may not be used more than once in a word.
	*/
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> result;
		set<string> tempResult;
		int numRow = static_cast<int>(board.size());
		if (numRow == 0) return result;
		int numCol = static_cast<int>(board[0].size());
		if (numCol == 0) return result;

		Trie myTrie;
		for (string word : words) {
			myTrie.insert(word);
		}

		vector<vector<bool>> visited(numRow, vector<bool>(numCol, false));
		for (int x = 0; x < numRow; x++) {
			for (int y = 0; y < numCol; y++) {
				string s = "";
				dfsWordBoard(board, visited, s, x, y, myTrie, tempResult);
			}
		}
		result = vector<string>(tempResult.begin(), tempResult.end());
		return result;

	}

	void dfsWordBoard(vector<vector<char>> board, vector<vector<bool>> visited, string& s, int x, int y, Trie myTrie, set<string>& result) {
		if (x < 0 || x >= static_cast<int>(board.size()) || y < 0 || y >= static_cast<int>(board[0].size())) {

			return;
		}
		if (visited[x][y]) {
			return;
		}
		s = s + string(1, board[x][y]);

		
		if (!myTrie.startsWith(s)) {
			s.pop_back();
			return;
		}
		if (myTrie.search(s)) {
			result.insert(s);
		}
		visited[x][y] = true;
		dfsWordBoard(board, visited, s, x + 1, y, myTrie, result);
		dfsWordBoard(board, visited, s, x - 1, y, myTrie, result);
		dfsWordBoard(board, visited, s, x, y + 1, myTrie, result);
		dfsWordBoard(board, visited, s, x, y - 1, myTrie, result);
		s.pop_back();
		visited[x][y] = false;
		return;
	}

	/*
	A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
	For 1-byte character, the first bit is a 0, followed by its unicode code.
	For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, 
	followed by n-1 bytes with most significant 2 bits being 10.
	*/
	bool validUtf8(vector<int>& data) {
		for (int i = 0; i < static_cast<int>(data.size()); ++i) {
			if (data[i] < 128) {
				continue;
			}
			else {
				int cnt = 0, val = data[i];
				for (int j = 7; j >= 1; --j) {
					if (val >= pow(2, j)) ++cnt;
					else break;
					val -= static_cast<int>(pow(2, j));
				}
				if (cnt == 1) return false;
				for (int j = i + 1; j < i + cnt; ++j) {
					if (data[j] > 191 || data[j] < 128) return false;
				}
				i += cnt - 1;
			}
		}
		return true;
	}

	string addStrings(string num1, string num2) {
		int len1 = static_cast<int>(num1.size());
		int len2 = static_cast<int>(num2.size());
		if (len1 == 0) return num2;
		if (len2 == 0) return num1;
		string result;
		string adder;
		if (len1 >= len2) {
			result = num1;
			adder = num2;
		}
		else {
			result = num2;
			adder = num1;
			int temp = len1;
			len1 = len2;
			len2 = temp;
		}

		int i = len1 - 1;
		int j = len2 - 1;
		int carry = 0;
		while (i >= 0 && j >= 0) {
			int val = result[i] - '0' + adder[j] - '0' + carry;
			carry = val / 10;
			result[i] = static_cast<char>(val % 10 + '0');
			i--;
			j--;
		}
		while (i >= 0 && carry == 1) {
			int val = result[i] - '0' + carry;
			carry = val / 10;
			result[i] = static_cast<char>(val % 10 + '0');
			i--;
		}

		if (carry == 1) {
			return "1" + result;
		}

		return result;
	}

	int arrangeCoins(int n) {
		int k = static_cast<long>(sqrt(n)*sqrt(2)) + 1;
		while (k*k + k > 2 * n) {
			k--;
		}
		return k;
	} 

	/*
	Given a sequence of words, check whether it forms a valid word square.
	*/
	bool validWordSquare(vector<string>& words) {
		int i = 0;
		for(string word : words) {
			string vert;
			for(string temp : words) {
				if(i < static_cast<int>(temp.size())) {
					vert = vert + string(1, temp[i]);
				}
			}
			if(word != vert) return false;
			i++;
		}
		return true;
	}

	/*
	Given a binary tree, find the length of the longest consecutive sequence path.
	The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
	The longest consecutive path need to be from parent to child (cannot be the reverse).
	*/
	int longestConsecutive(TreeNode* root) {
		if(!root) return 0;
		queue<TreeNode*> currLevel;
		queue<int> currSize;
		currLevel.push(root);
		currSize.push(1);
		int maxSize = 1;

		while(!currLevel.empty()) {
			TreeNode* temp = currLevel.front();
			currLevel.pop();
			int currMax = currSize.front();
			currSize.pop();

			if(temp->left != NULL) {
				int leftSize = currMax;
				if(temp->left->val - temp->val == 1) {
					leftSize++;
					maxSize = max(maxSize, leftSize);
				}
				else {
					leftSize = 1;
				}
				currLevel.push(temp->left);
				currSize.push(leftSize);
			}

			if(temp->right != NULL) {
				int rightSize = currMax;
				if(temp->right->val - temp->val == 1) {
					rightSize++;
					maxSize = max(maxSize, rightSize);
				}
				else {
					rightSize = 1;
				}
				currLevel.push(temp->right);
				currSize.push(rightSize);
			}
		}
		return maxSize;
	}

	/*
	iven a list of airline tickets represented by pairs of departure and arrival airports [from, to], 
	reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. 
	Thus, the itinerary must begin with JFK.
	*/
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		vector<string> itineray;
		if(tickets.empty()) return itineray;
		unordered_map<string, multiset<string>> fromToMap;
		for(auto ticket : tickets) {
			fromToMap[ticket.first].insert(ticket.second);
		}

		dfsItineray("JFK", fromToMap, itineray);
		vector<string> result(itineray.rbegin(), itineray.rend());
		return result;
	}

	void dfsItineray(string departure, unordered_map<string, multiset<string>>& fromtToMap, vector<string>& itineray) {
		while (!fromtToMap[departure].empty()) {
			string dest = *fromtToMap[departure].begin();
			fromtToMap[departure].erase(fromtToMap[departure].begin());
			dfsItineray(dest, fromtToMap, itineray);
		}
		itineray.push_back(departure);
	}

	/*
	Given a binary tree, return the vertical order traversal of its nodes' values. 
	(ie, from top to bottom, column by column).
	*/
	vector<vector<int>> verticalOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		map<int, vector<int>> m;
		queue<pair<int, TreeNode*>> q;
		q.push({ 0, root });
		while (!q.empty()) {
			auto a = q.front(); q.pop();
			m[a.first].push_back(a.second->val);
			if (a.second->left) q.push({ a.first - 1, a.second->left });
			if (a.second->right) q.push({ a.first + 1, a.second->right });
		}
		for (auto a : m) {
			res.push_back(a.second);
		}
		return res;
	}


};

#endif
