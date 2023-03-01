#include <iostream>

using namespace std;
int v[10] = {1, 2, 3, 4, 5, 6, 7, 8 ,9, 10}, i, x, s, d;

int cautareBinara(int v[], int s, int d, int x){
    if (d >= 1){
        int mijloc = (s + d)/2;

        if (v[mijloc] == x)
            return mijloc;

        if (v[mijloc] > x)
            return cautareBinara(v, s, mijloc - 1, x);

        return cautareBinara(v, mijloc + 1, d, x);
    }
    return -1;
}


int main()
{
    int n = 10;
    cin>>x;
    int rez = cautareBinara(v, 0, n-1, x);
    cout<<rez;
    return 0;
}
