#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int n,q;
    cin>>n>>q;
    vector<int>v[n];
    for(int i=0;i<n;i++){
        long long int k;
        cin>>k;
        for(int j=0;j<k;j++){
           long long  int a;
            cin>>a;
            v[i].push_back(a);
        }
    }
    while (q--)
    {
       long long int i,j;
        cin>>i>>j;
        cout<<v[i][j]<<"\n";
    }
    
    return 0;
}