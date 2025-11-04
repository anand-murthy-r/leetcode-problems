#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> frequency;
    for(const char& ch : tasks) {
        if (frequency.find(ch) != frequency.end()) frequency[ch] += 1;
        else frequency[ch] = 1;
    }
    vector<int> maxHeap;
    maxHeap.reserve(tasks.size());
    for(auto& p : frequency) maxHeap.emplace_back(p.second);
    make_heap(maxHeap.begin(), maxHeap.end()); // make max_heap
    queue<pair<int, int>> q; // {count, time_of_availability}
    int time = 0;
    while(!maxHeap.empty() || !q.empty()) {
        time += 1;
        if (!maxHeap.empty()) {
            int count = maxHeap.front() - 1;
            pop_heap(maxHeap.begin(), maxHeap.end());
            maxHeap.pop_back();
            if (count)
                q.push({count, time + n});
        }

        if (!q.empty()) {
            pair<int, int> data = q.front();
            if (data.second == time) {
                maxHeap.push_back(data.first);
                push_heap(maxHeap.begin(), maxHeap.end());
                q.pop();
            }
        }
    }
    return time;
}


int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'C'};
    int n = 3;
    int time_taken = leastInterval(tasks, n);
    cout << time_taken << endl;
}
