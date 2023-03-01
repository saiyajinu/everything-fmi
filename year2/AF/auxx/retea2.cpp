#include <bits/stdc++.h>
using namespace std;
ifstream fin("retea2.in");
ofstream fout("retea2.out");

int N, M, x, y;
bool connected[2000];
double distToPow[2000], distSum=0;

struct Node{
    int x, y;
} powPlants[2000], blocks[2000];

double computeDistance(Node a, Node b){
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

void readFile(){
    fin>>N>>M;
    for(int i = 1; i <= N; i++){
        fin>>powPlants[i].x>>powPlants[i].y;
    }
    for(int j = 1; j <= M; j++){
        fin>>blocks[j].x>>blocks[j].y;
        distToPow[j]=DBL_MAX;
    }
}

void computeDistancesArray(){
    for(int i = 1; i <= M; i++)
        for(int j = 1;j <= N; j++){
            distToPow[i] = min(distToPow[i],computeDistance(powPlants[j],blocks[i]));
        }

    for(int i = 1; i <= M; i++){
        double minDist = DBL_MAX;
        int minNode;
        for(int j = 1;j <= M; j++)
            if(connected[j]==0 && distToPow[j] < minDist){
                minDist = distToPow[j];
                minNode = j;
            }

        distSum = distSum + minDist;
        connected[minNode] = 1;
        for(int j = 1;j <= M; j++)
            distToPow[j] = min(distToPow[j],computeDistance(blocks[minNode],blocks[j]));
    }
}

int main()
{
    readFile();
    computeDistancesArray();
    //cout<<fixed<<setprecision(6)<<distSum;
    fout<<fixed<<setprecision(6)<<distSum;
    fin.close();
    fout.close();
    return 0;
}
