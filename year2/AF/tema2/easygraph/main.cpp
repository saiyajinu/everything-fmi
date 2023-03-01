#include <bits/stdc++.h>
using namespace std;

ifstream fin("easygraph.in");
ofstream fout("easygraph.out");

int N, M, T, x, y;

int v[15000], nodeValues[15000];
vector<int> nodeGraph[15000];
bool visited[15000];

void DFS(int node, int sum){
    visited[node] = true;
    sum += v[node-1];
    cout<<sum<<" ";
    for (auto i : nodeGraph[node]) {
        if (visited[i] == false) {
            DFS(i, sum);
        }
    }
}

void compute(){
    int maxSum = INT_MIN;

    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            int sum = 0;
            DFS(i, sum);

            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    cout<<maxSum;
}

void readFile(){
    fin>>T;
    fin>>N>>M;

    for(int i = 1; i <= N; i++)
        fin>>nodeValues[i];

    for(int i = 1; i <= M; i++){
        fin>>x>>y;
        nodeGraph[x].push_back(y);
    }
}

int main(){
    readFile();
    compute();



    return 0;
}
