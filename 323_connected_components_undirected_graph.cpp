#include <iostream>
#include <bits/stdc++.h>


using namespace std;


class DFSApproach {
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

class UFApproach {
    private:
        int find(const int& node, vector<int>& parent) {
            int res = node;
            while (res != parent[res]) {
                parent[res] = parent[parent[res]];
                res = parent[res];
            }
            return res;
        }

        int Union(const int& node1, const int& node2, vector<int>& parent, vector<int>& rank) {
            int root1 = find(node1, parent);
            int root2 = find(node2, parent);
            if (root1 == root2) return 0;

            if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
                rank[root1] += rank[root2];
            }
            else {
                parent[root1] = root2;
                rank[root2] += rank[root1];
            }
            return 1;
        }
    public:
        int countComponents(int n, vector<vector<int>>& edges) {
            vector<int> parent(n), rank(n, 1);
            int result = n;
            for(int i = 0; i < n; i++) parent[i] = i;

            for(vector<int> p : edges) {
                result = result - Union(p[0], p[1], parent, rank);
            }
            return result;
        }
};

int main() {
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {4,5}, {6, 7}};
    int n = 8;
    DFSApproach* sln_DFS = new DFSApproach();
    UFApproach* sln_UF = new UFApproach();
    int result_DFS = sln_DFS->countComponents(n, edges);
    int result_UF = sln_UF->countComponents(n, edges);
    cout << "DFS Approach: " << result_DFS << endl;
    cout << "Union Find Approach: " << result_UF << endl;
}
