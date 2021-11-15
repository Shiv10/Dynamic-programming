#include <bits/stdc++.h>
using namespace std;

int arr[10000];
int main(){

    memset(arr, 0, sizeof(arr));
    arr[0]=1;
    arr[1]=1;
    int n;
    cin>>n;
    int i;
    for(i=2;i<n;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }

    cout<<arr[n-1];
}