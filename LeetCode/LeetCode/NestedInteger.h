#pragma once
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

	/*
	Given a nested list of integers represented as a string, implement a parser to deserialize it.
	Each element is either an integer, or a list -- whose elements may also be integers or other lists.
	*/
	NestedInteger deserialize(string s) {
		NestedInteger result;
		int len = static_cast<int>(s.size());
		if (len < 1) return result;
		stack<NestedInteger> numStack;
		int sign = 1;
		int i = 0;
		while (i < len) {
			if (s[i] >= '0' && s[i] <= '9') {
				int num = 0;
				while (s[i] >= '0' && s[i] <= '9' && i < len) {
					num = num * 10 + s[i] - '0';
					i++;
				}
				num = sign*num;
				sign = 1;
				if (!numStack.empty()) {
					numStack.top().add(NestedInteger(num));
				}
				else {
					NestedInteger nI = NestedInteger(num);
					numStack.push(nI);
				}
			}
			else if (s[i] == '[') {
				numStack.push(NestedInteger());
				i++;
			}
			else if (s[i] == ']') {
				NestedInteger nI = numStack.top();
				numStack.pop();
				if (numStack.empty()) numStack.push(nI);
				else numStack.top().add(nI);
				i++;
			}
			else if (s[i] == '-') {
				sign = -1;
				i++;
			}
			else {
				i++;
			}
		}
		if(!numStack.empty()) return numStack.top();
		else return result;
	}
};

class NestedIterator {
private:
	stack<NestedInteger> nestStack;
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		while (!nestedList.empty()) {
			nestStack.push(nestedList.back());
			nestedList.pop_back();
		}
	}

	int next() {
		int result = nestStack.top().getInteger();
		nestStack.pop();
		return result;
	}

	bool hasNext() {
		while (!nestStack.empty() && !nestStack.top().isInteger()) {
			vector<NestedInteger> vN = nestStack.top().getList();
			nestStack.pop();
			while (!vN.empty()) {
				nestStack.push(vN.back());
				vN.pop_back();
			}
		}
		return !nestStack.empty();
	}
};

/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/