#include <bits/stdc++.h>
using namespace std;

long long arr[1000000];

int fib(int n){
    if(arr[n-1]!=0) return arr[n-1];
    arr[n-1] = fib(n-1) + fib(n-2);
    return arr[n-1];
}

int main(){
    memset(arr, 0, sizeof(arr));
    arr[0]=1;
    arr[1] = 1;
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}