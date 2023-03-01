#include <iostream>

using namespace std;

int main()
{
    int n, v[100], i, j, index, aux;
    cin>>n;
    for(i = 0; i < n; i++)
        cin>>v[i];
    for(i = 0; i < n-1; i++){
        index = i;
        for(j = i+1; j < n; j++)
            if(v[j] < v[index])
                index = j;
        aux = v[index];
        v[index] = v[i];
        v[i] = aux;
    }
    for(i = 0; i < n; i++)
        cout<<v[i]<<" ";
    return 0;
}
