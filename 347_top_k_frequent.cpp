#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> map(nums.size() + 1, vector<int> {});
        vector<int> topK;
        for(int num : nums) {
            if(freq.find(num) != freq.end()) freq[num] += 1;
            else freq.insert({num, 1});
        }

        for(auto& p : freq) {
            map[p.second].emplace_back(p.first);
        }

        for(int i = map.size() - 1; i >= 0; i--) {
            for(int j = map[i].size() - 1; j >= 0; j--) {
                topK.emplace_back(map[i][j]);
                if (topK.size() >= k) return topK;
            }
        }
        return topK;
    }
};


int main() {
    vector<int> nums = { 1, 1, 2, 3, 3, 3, 3};
    int k = 2;
    Solution* sln = new Solution();
    vector<int> result = sln->topKFrequent(nums, k);
    for(int num : result) cout << num << endl;

}
