#include <bits/stdc++.h>
using namespace std;

int main(){
    int i, n;
    cin>>n;
    int arr[10000];
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;

    for(i=3;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }

    cout<<arr[n];
    return 0;
}