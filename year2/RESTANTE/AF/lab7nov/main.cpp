#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct muchie{
    int x, y, c;
};
muchie a[400001];
int h[200001], t[200001];

bool comp(muchie &a, muchie &b){
    return a.c < b.c;
}

void  Union(int x, int y){
    if (h[x] < h[y]){  //height cred
        t[x] = y;
    }else{
        t[y] = x;
        if (h[x] == h[y]){
            h[y]++;
        }
    }
}

int Find(int x){
    int r = x;
    while (r!=t[r]){
        r = t[r];
    }
    int y = x;
    int p;
    while (x!=r){
        p = t[x];
        t[x] = r;
        x = p;
    }
    return r;
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<= m; i++){
        cin>>a[i].x>>a[i].y>>a[i].c;
    }
    sort(a+1,a+m+1, comp);
    int s = 0;
    vector<muchie>sol;
    for(int i=1; i<=m; i++){
        int p = Find(a[i].x);
        int q = Find(a[i].y);
        if(p!=q){
            s = s +a[i].c;
            sol.push_back(a[i]);
            Union(p,q);
        }
    }
    cout<<s<<'\n';
    for(auto it:sol){
        cout<<it.x<<" "<<it.y<<'\n';
    }
    return 0;
}
