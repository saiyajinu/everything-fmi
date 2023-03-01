#include<bits/stdc++.h>

using namespace std;

ifstream fin("catun.in");
ofstream fout("catun.out");

priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >q;
vector<pair<int,int> >mu[37000];
vector<int> v;
pair<int,int>minn;
int n,m,x,y,c,z,d[37000],finp[37000],finlung[37000],pozmin;

void dijkstra()
{
    for(int i=1;i<=n;i++) d[i]=INT_MAX;
    for(int i=0;i<v.size();i++) d[v[i]]=0;
    for(int i=0;i<v.size();i++)
    {
        q.push({0,v[i]});
        finp[v[i]]=v[i];
    }
    while(!q.empty())
    {
        minn=q.top(); q.pop();
        pozmin=minn.second;
        for(int j=0;j<mu[pozmin].size();j++)
        {
            if(d[mu[pozmin][j].second]>d[pozmin]+mu[pozmin][j].first)
            {
                d[mu[pozmin][j].second]=d[pozmin]+mu[pozmin][j].first;
                finp[mu[pozmin][j].second]=finp[pozmin];
                q.push({d[mu[pozmin][j].second],mu[pozmin][j].second});
            }
            else if(d[mu[pozmin][j].second]==d[pozmin]+mu[pozmin][j].first)
            {
                if(finp[mu[pozmin][j].second]>finp[pozmin])
                {
                    finp[mu[pozmin][j].second]=finp[pozmin];
                }
            }
        }
    }
}
int main()
{
    fin>>n>>m>>z;
    for(int i=1;i<=z;i++)
    {
        fin>>x;
        v.push_back(x);
    }
    for(int i=1;i<=m;i++)
    {
        fin>>x>>y>>c;
        mu[x].push_back({c,y});
        mu[y].push_back({c,x});
    }
    dijkstra();
    for(int i=0;i<v.size();i++) finp[v[i]]=0;
    for(int i=1;i<=n;i++) fout<<finp[i]<<" ";
}
