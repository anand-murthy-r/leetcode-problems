#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        unordered_map<char, vector<char>> mapping;
        mapping['2'] = { 'A', 'B', 'C' };
        mapping['3'] = { 'D', 'E', 'F' };
        mapping['4'] = { 'G', 'H', 'I' };
        mapping['5'] = { 'J', 'K', 'L' };
        mapping['6'] = { 'M', 'N', 'O' };
        mapping['7'] = { 'P', 'Q', 'R', 'S' };
        mapping['8'] = { 'T', 'U', 'V' };
        mapping['9'] = { 'W', 'X', 'Y', 'Z' };

        dfs(0, "", digits, mapping, result);
        return result;
    }

    void dfs(int i, string comb, string& digits, unordered_map<char, vector<char>>& mapping, vector<string>& result) {
        if (i >= digits.size()) {
            result.push_back(comb);
            return;
        }
        vector<char> maps = mapping[digits[i]];
        for(char ch : maps)
            dfs(i + 1, comb + ch, digits, mapping, result);
    }
};


int main() {
    Solution sln = Solution();
    string digits = "345";
    vector<string> result = sln.letterCombinations(digits);
    for(string comb : result) {
        cout << comb << endl;
    }
    return 0;
}