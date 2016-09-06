#include <iostream>
#include <vector>

using namespace std;
#include "Answer.h"
#include "QueueStack.h"
#include "StackQueue.h"
#include "RangeSum.h"
#include "RandomizedSet.h"


int main() {
	Solution mySolution = Solution();

	Solution* mySecondSolution;

	mySecondSolution = new Solution;

	int aa = 1;
	int& bb = aa;

	aa = 2;

	

	
	

	std::vector<int> myvector{ 0 };
	
	//int result = mySolution.removeElement(myvector, 1);
	vector<vector<char>> myMap(1, vector<char>(1, '1'));
	mySolution.numIslands(myMap);
	
	string a = "9223372036854775809";
	string* c = new string("abc");
	string b = "a";
	int numr = 28;

	int s = mySolution.myAtoi(a);


	std::cout << s << std::endl;

	return 0;
}