#include <iostream>

using namespace std;

int main()
{
    int v[100], n, i, j, aux;
    cin>>n;
    for(i = 0; i < n; i++)
        cin>>v[i];
    for(i = 1; i < n; i++){
        aux = v[i];
        j = i - 1;
    while(aux < v[j] && j>= 0){
        v[j + 1] = v[j];
        j--;
        }
    v[j+1] = aux;
    }
    for(i = 0; i < n; i++)
        cout<<v[i]<<" ";
    return 0;
}
