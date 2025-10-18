#include <iostream>
#include <bits/stdc++.h>




class Solution {
	public:
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> result;
            sort(nums.begin(), nums.end(), [](int& a, int& b) { return a < b; });
            dfs(0, nums, result, {});
            return result;
		}

        void dfs(int i, vector<vector<int>>& nums, vector<vector<int>>& result, vector<int> subset) {
            if (i >= nums.size()) {
                result.push_back(subset);
                return;
            }

            // subset that includes nums[i]
            vector<int> temp = subset;
            temp.push_back(nums[i]);
            dfs(i + 1, nums, result, temp);

            // subset that does not include nums[i]
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
            dfs(i + 1, nums, result, subset);
        }
};
