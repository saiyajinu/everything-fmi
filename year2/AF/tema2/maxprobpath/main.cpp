#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph;
        graph.resize(n);

        vector<bool> visited;
        visited.resize(n);

        vector<double> prob;
        prob.resize(n);

        prob[start] = 1;

        priority_queue<pair<double, int>> maxDistances;
        maxDistances.emplace(1.0, start);

        for(int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        while(!maxDistances.empty()) {
            pair<double, int> x = maxDistances.top();
            maxDistances.pop();
            if(!visited[x.second]){
                visited[x.second] = true;
                if(x.second == end) {
                    return prob[x.second];
                }
                for(auto &it: graph[x.second]) {
                    if(!visited[it.first] && prob[it.first] < prob[x.second] * it.second) {
                        prob[it.first] = prob[x.second] * it.second;
                        maxDistances.emplace(prob[it.first], it.first);
                    }
                }
            }

        }
        return 0;
    }
}sol;

int main(){
    vector<vector<int>> edges{{0,1},{1,2},{0,2}};
    vector<double> succ{0.5,0.5,0.3};
    cout<<sol.maxProbability(3, edges, succ, 0, 2);
    return 0;
}
