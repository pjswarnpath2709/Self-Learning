#include <bits/stdc++.h>
using namespace std;
// naive solution
void IntersectionofTwoArrays(int *arr, int *brr, int m, int n)
{
    for(int i=0;i<m;i++){
        if (arr[i] = arr[i - 1] && i > 0)
        {
            continue;
        }
        for(int j=0;i<n;j++){
            if(arr[i]==brr[j]){cout<<arr[i]<<" ";break;}
        }
    }
}
// efficient solution
void Intersection(int *arr, int *brr, int m, int n)
{
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            i++;
            continue;
        }
        if(arr[i]<brr[j]){i++;}
        if(arr[i]>brr[j]){j++;}
        if(arr[i]==brr[j]){cout<<arr[i]<<" ";i++;j++;}
    }
}

int main()
{

    return 0;
}