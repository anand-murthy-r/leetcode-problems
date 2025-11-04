
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

class Solution {
private:

    unordered_map<int, vector<int>>* graph = new unoredered_map<int, vector<int>>();
    void dfs(const int& node, unordered_set<int>& visited, set<pair<int, int>>& stack) {
        if (visited.find(node) != visited.end()) {

        }
        if (graph[node].empty()) return;

    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_set<int> visited;
        stack<pair<int, int>> stack;
        for(const auto& edge : edges) {
            if(graph.find(edge[0]) != graph.end()) graph[edge[0]].emplace_back(edge[1]);
            else graph.insert({ edge[0], { edge[1] }});
            if(graph.find(edge[1]) != graph.end()) graph[edge[1]].emplace_back(edge[0]);
            else graph.insert({ edge[1], { edge[0] }});
        }
    }

};
