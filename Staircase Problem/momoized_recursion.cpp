#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int numberOfWays(int n){
    if(arr[n]!=-1) return arr[n];

    arr[n] = numberOfWays(n-1)+numberOfWays(n-2);
    return arr[n];
}

int main(){
    memset(arr, -1, sizeof(arr));
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2; 
    int n;
    cin>>n;
    cout<<numberOfWays(n);
}