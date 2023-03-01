#include <bits/stdc++.h>

using namespace std;

ifstream fin("disjoint.in");
ofstream fout("disjoint.out");

int N, M, x, y, task, rootArr[100000];

int findRoot(int x){
    while(x != rootArr[x])
        x = rootArr[x];
    return rootArr[x];
}
void initRootArr(int N){
    for (int i = 1; i <= N; ++i){
        rootArr[i] = i;
    }
}

void doTask(int task, int x, int y){
    if (task == 1){
            rootArr[y] = x;
        }
        else{
            if (rootArr[x] == rootArr[y]){
                cout<<"DA"<<endl;
                fout<<"DA"<<endl;
            }
            else{
                cout<<"NU"<<endl;
                fout<<"NU"<<endl;
            }
        }
}

int main()
{
    fin >> N >> M;
    initRootArr(N);
    for (int i = 1; i <= M; ++i){
        fin >> task >> x >> y;
        x = findRoot(x);
        y = findRoot(y);
        doTask(task, x ,y);
    }
    return 0;
}
