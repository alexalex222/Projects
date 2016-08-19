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

using std::vector;
using std::string;
using std::set;
using std::map;
using std::unordered_map;
using std::queue;
using std::stack;
using std::max;
using std::min;

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

class Solution {
public:
	int addDigits(int num) {
		int result = 1 + ((num - 1) % 9);
		return result;
	}

	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		return std::max(leftDepth, rightDepth) + 1;
	}

	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
		return;
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		else if (q && p && p->val == q->val) return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
		else return false;
	}

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

	bool containsDuplicate(vector<int>& nums) {
		set<int> s;
		for (int i : nums) {
			if (s.find(i) == s.end()) s.insert(i);
			else return true;
		}
		return false;
	}

	int titleToNumber(string s) {
		int number = 0;
		for (size_t i = 0; i < s.size(); i++) {
			char c = s.at(i);
			int current_number = static_cast<int> (c - 'A') + 1;
			number = number * 26 + current_number;
		}
		return number;
	}

	int majorityElement(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}

	bool isAnagram(string s, string t) {
		auto lenS = s.length();
		auto lenT = t.length();
		if (lenS != lenT) return false;

		vector<int> count(26, 0);
		for (size_t i = 0; i < lenS; i++) {
			count[s[i] - 'a']++;
		}

		for (size_t i = 0; i < lenT; i++) {
			if(--count[t[i] - 'a'] < 0) return false;

		}
		return true;
	}

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

	bool isUgly(int num) {
		if (num <= 0) return false;
		int factor[] = { 2, 3,5 };
		for (int x : factor) {
			while (num%x == 0) num = num / x;
		}
		return num == 1;
	}

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

	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		size_t i = 0;
		int j = 0;
		auto k = nums.size();
		while (i < nums.size()) {
			if (nums[i] != nums[j]) {
				auto temp = nums[j+1];
				nums[j+1] = nums[i];
				nums[i] = temp;
				j++;
			}
			i++;
		}
		return j + 1;
	}

	bool isPowerOfTwo(int n) {
		int cnt = 0;
		while (n > 0) {
			cnt += (n & 1);
			n = n >> 1;
		}
		return cnt == 1;
	}

	int rob(vector<int>& nums) {
		int odd = 0;
		int even = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			if (i % 2 == 1) odd = std::max(odd + nums[i], even);
			else even = std::max(even + nums[i], odd);
		}
		return std::max(odd, even);
	}

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

	int trailingZeroes(int n) {
		int i = 1;
		int zeros = 0;

		while (n / std::pow(5, 1) >= 1) {
			zeros = static_cast<int>(zeros +n / std::pow(5, 1));
			i++;
		}
		return zeros;
	}

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
		return (hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val));
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
		if(s.size() < 1) return 0;
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
		map<int, int> myMap =map<int, int>();
		for (size_t i = 0; i < nums.size(); i++) {
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
			int digit = static_cast<int> (a[pa] - '0' + b[pb] - '0') +carry;
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
		vector<int> m  = vector<int>(256, 0);
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
		
		if(root->left) dfsBinaryTreePath(root->left, s, result);
		if(root->right) dfsBinaryTreePath(root->right, s, result);
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
			n = (n -1 ) / 26;
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
			nums[i] = nums[end +start -1 - i];
			nums[end + start -1 - i] = temp;
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
		while (i < len-1) {
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
		int right = static_cast<int>(nums.size()) -1;
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

		vector<vector<int>> dp( m, vector<int>(n) );

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

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		std::sort(nums.begin(), nums.end());
		result.push_back(nums);
		while (std::next_permutation(nums.begin(), nums.end())) {
			result.push_back(nums);
		}
		return result;
	}

	void nextPermutation(vector<int>& nums) {
		std::next_permutation(nums.begin(), nums.end());
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
			dfsCombinationSum3(result, i+1, sum - i, list, k);
			list.erase(list.end()-1);
		}
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

		for (size_t i = level; i < candidates.size(); i++) {
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
		for (size_t i = level; i < nums.size(); i++) {
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
		if (obstacleGrid[m-1][n-1] == 1) return 0;
		
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
		for (size_t i = 0; i < grid.size(); i++) {
			for (size_t j = 0; j < grid[0].size(); j++) {
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
		while(i >= 0) {
			result = result + s.at(i);
			i--;
		}
		return result;
    }

	int getSum(int a, int b) {
		if(b == 0) return a;
		int sum = a^b;
		int carry = (a&b)<<1;
		return getSum(sum, carry);
	}

	bool canConstruct(string ransomNote, string magazine) {
		int letter[26];
		for (int k = 0; k < 26; k++) letter[k] = 0;
		for(size_t i = 0; i < magazine.size(); i++) {
			letter[magazine.at(i) - 'a']++;
		}

		for(size_t j = 0; j < ransomNote.size(); j++) {
			if(--letter[ransomNote.at(j)- 'a'] < 0) return false;
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
		int right = s.size() - 1;
		while(left <= right) {
			if( (vowels.find(s[left]) == vowels.end())) {
				left++;
				continue;
			}

			if((vowels.find(s[right]) == vowels.end())) {
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
		if(num == 0) return false;
		int power = static_cast<int>(log(num)/log(4));
		if(pow(4, power) == num) return true;
		else return false;
	}

	bool isPowerOfThree(int n) {
		if(n == 0) return false;
		int power = static_cast<int>(floor(log(n)/log(3)+0.5));
		if(pow(3, power) == n) return true;
		else return false;
	}

	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s1(nums1.begin(), nums1.end());
		set<int> s2;
		for(int element : nums2) {
			if(s1.count(element) > 0) s2.insert(element);
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
		while(iter1 != nums1.end() && iter2 != nums2.end()) {
			if(*iter1 > *iter2) iter2++;
			else if(*iter1 < *iter2) iter1++;
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
        while(L<=R){
            int mid = L + ((R - L) >> 1);
            int res = guess(mid);
            if(res == 0) return mid;
            else if(res == 1)  L = mid + 1;
            else R = mid - 1;
        }
        return L;
	}

	vector<int> countBits(int num) {
		vector<int> result(num+1, 0);
		for(int i = 0; i <= num; i++) {
			result[i] = result[i>>1] + (i&1);
		}
		return result;
	}

	int countNumbersWithUniqueDigits(int n) {
		n = min(n, 10);
		vector<int> dp(n+1, 9);
		dp[0] = 1;
		for(int i = 2; i < n+1; i++) {
			for(int k = 9; k >= 9 - i + 2; k--) {
				dp[i] = dp[i]*k;
			}
		}
		int ans = 0;
		for(int j = 0; j < n+1; j++) ans = ans + dp[j];
		return ans;
	}

	bool increasingTriplet(vector<int>& nums) {
		int num1 = INT_MAX;
		int num2 = INT_MAX;
		for(int num : nums) {
			if(num <= num1) num1 = num;
			else if(num <= num2) num2 = num;
			else return true;
		}
		return false;
	}

	int integerBreak(int n) {
		if( n == 2 || n == 3) return n - 1;
		int result = 1;
		while(n > 4) {
			result = result * 3;
			n = n - 3;
		}
		return result*n;
	}

	bool isPerfectSquare(int num) {
		long long low = 1;
		long long high = num/2 + 1;
		long long mid;
		while(low <= high) {
			mid = (low + high)/2;
			if(num == mid*mid) return true;
			else if(num > mid*mid) low = mid + 1;
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
		for(int i : nums) {
			if(i == m1) c1++;
			else if(i == m2) c2++;
			else if(c1 == 0) {
				m1 = i;
				c1 = 1;
			}
			else if(c2 == 0) {
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
		for(int i : nums) {
			if(i == m1) c1++;
			else if(i == m2) c2++;
		}
		if(c1 > static_cast<int>(nums.size())/3) result.push_back(m1);
		if(c2 > static_cast<int>(nums.size())/3) result.push_back(m2);
		return result;
	}

	vector<int> twoSum2(vector<int>& numbers, int target) {
		int left = 0;
		int right = static_cast<int>(numbers.size()) - 1;
		long long tempSum = 0;
		vector<int> result;
		while(left <= right) {
			tempSum = numbers[left] + numbers[right];
			if(tempSum == static_cast<long long>(target)) {
				result.push_back(left+1);
				result.push_back(right+1);
				return result;
			}
			else if(tempSum < static_cast<long long>(target)) {
				left++;
			}
			else right--;
		}
		return result;
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, size_t> myMap;
		vector<int> result;
		for(size_t i = 0; i < nums.size(); i++) {
			int diff = target - nums[i];
			if(myMap.find(diff) != myMap.end()) {
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
		while((m&d) != (n&d)) {
			d = d<<1;
		}
		return m&d;
	}

	int wiggleMaxLength(vector<int>& nums) {
		if(nums.empty()) return 0;
		int ans = 1;
		int n = static_cast<int>(nums.size());
		for(int cur = 1, prev = 0; cur < n; prev = cur, cur++) {
			if(nums[cur] > nums[prev]) {
				ans++;
				while((cur + 1 < n) && (nums[cur+1] >= nums[cur])) cur++; 
			}
			else if(nums[cur] < nums[prev]) {
				ans++;
				while((cur + 1 < n) && (nums[cur+1] <= nums[cur])) cur++;
			}
		}
		return ans;
	}

	ListNode* insertionSortList(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;
		ListNode* fakeHead = new ListNode(0);
		ListNode* cur = head;
		while(cur != NULL) {
			ListNode* next = cur->next;
			ListNode* pre = fakeHead;
			while(pre->next != NULL && pre->next->val < cur->val) {
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
		while(low < high) {
			int mid = (low+high)/2;
			int c = 0;

			for(int i : nums) {
				if(i <= mid) c++;
			}

			if(c > mid) high = mid;
			else low = mid + 1;
		}
		return low;
	}

	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount+1, INT_MAX -1);
		dp[0] = 0;
		for(int i = 1; i < amount+1; i++) {
			for(size_t j = 0; j < coins.size(); j++) {
				if(coins[j] <= i) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}

	bool canJump(vector<int>& nums) {
		int maxDist = 0;
		int n = static_cast<int>(nums.size());
		for(int i = 0; i <= maxDist && maxDist < n - 1; i++) {
			if(maxDist < i + nums[i]) maxDist = i + nums[i];
		}
		return maxDist >= n-1;
	}

	int lengthOfLongestSubstring(string s) {
		size_t maxLen = 0;
		map<char, size_t> myMap;
		for(size_t i = 0; i < s.size(); i++) {
			if(myMap.find(s[i]) == myMap.end()) myMap.emplace(s[i], i);
			else {
				maxLen = max(maxLen, myMap.size());
				i = myMap[s[i]];
				myMap.clear();
			}
		}
		return max(maxLen, myMap.size());
	}
};

#endif
