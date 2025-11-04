#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<string> partition;
        vector<vector<string>> res;
        dfs(0, s, partition, res);
        return res;
    }

    void dfs(int i, string& s, vector<string>& partition, vector<vector<string>>& res) {
        if (i >= s.size()) {
            vector<string> p_copy = partition;
            res.push_back(p_copy);
            return;
        }
        for(int j = i; j < s.size(); j++) {
            if (this->isPalindrome(s, i, j)) {
                string sub = s.substr(i, j - i + 1);
                partition.push_back(sub);
                dfs(j + 1, s, partition, res); // wtf is this i don't understand WTFFFFF I WANNA KILL MYSELF
                partition.pop_back();
            }
        }
    }
};
