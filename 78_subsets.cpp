#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			vector<vector<int>> result;
			dfs(0, nums, result, {});
			return result;
		}

		void dfs(int i, vector<int>& nums, vector<vector<int>>& result, vector<int> subset) {
			if (i >= nums.size()) {
				result.push_back(subset);
				return;
			}
				
			dfs(i + 1, nums, result, subset);
			subset.push_back(nums[i]);
			dfs(i + 1, nums, result, subset);
		}

		
};

int main() {
	Solution sln = Solution();
	vector<int> nums = { 1, 2, 3 };
	vector<vector<int>> result = sln.subsets(nums);
	for(vector<int> v : result) {
		for(int num : v) {
			cout << num << "\t";
		}
		cout << endl;
	}
	return 0;
}
