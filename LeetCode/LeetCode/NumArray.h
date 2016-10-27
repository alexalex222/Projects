#pragma once
class NumArrayImu {
public:
	NumArrayImu(vector<int> &nums) {
		this->accum.push_back(0);
		for (int num : nums) {
			this->accum.push_back(this->accum.back() + num);
		}
	}

	int sumRange(int i, int j) {
		return this->accum[j + 1] - this->accum[i];
	}

private:
	vector<int> accum;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);