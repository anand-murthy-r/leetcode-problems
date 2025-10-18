#include <iostream>
#include <bits/stdc++.h>


using namespace std;


class Solution {
private:
    unordered_map<int, vector<int>> graph;
public:
    void setupGraph(const int& n, const vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++) this->graph.insert({edges[i][0], {}});
        for(int i = 0; i < edges.size(); i++) {
            this->graph[edges[i][0]].emplace_back(edges[i][1]);
            this->graph[edges[i][1]].emplace_back(edges[i][0]);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        this->setupGraph(n, edges);
        int result = 0;
        vector<int> visited(n, 0);
        // implement a dfs function and get the result
        for(int i = 0; i < n; i++)
            dfs(i, edges, visited, result, true);

        return result;
    }

    void dfs(const int& node, const vector<vector<int>>& edges, vector<int>& visited, int& result, bool isNew) {
        if (visited[node]) {
            return;
        }
        visited[node] = 1;
        for(int adj_node : this->graph[node]) {
            dfs(adj_node, edges, visited, result, false);
        }
        if(isNew) result++;
        this->graph[node] = {};
        return;
    }

};

int main() {
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {4,5}};
    int n = 6;
    Solution sln = Solution();
    int result = sln.countComponents(n, edges);
    cout << result << endl;
}
