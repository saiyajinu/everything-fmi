#include <iostream>

using namespace std;

int main(){
    int i, j, n, aux, v[100];
    cin>>n;
    for(i = 0; i < n; i++)
        cin>>v[i];

    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    for(i = 0; i < n; i++)
        cout<<v[i]<<" ";

    return 0;
}
