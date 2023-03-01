#include <iostream>

using namespace std;

int main()
{
    int i, n, v[100], x, ok = 0;
    cin>>n;
    for(i = 0; i < n; i++)
        cin>>v[i];
    cout<<"cautam nr "; cin>>x;
    for(i = 0; i < n && ok == 0; i++)
        if (v[i] == x)
            ok = 1;
    if(ok == 1)
        cout<<x<<" a fost gasit";
    else
        cout<<x<<" nu este in sir";
    return 0;
}
