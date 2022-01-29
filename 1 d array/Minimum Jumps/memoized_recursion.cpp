#include <bits/stdc++.h>
using namespace std;

int calcMin(vector<int> &arr, int ci, int n, vector<int> &memo) {
    
    if(ci>=n-1) return 0;
    
    if(memo[ci]!=-1) return memo[ci];
    
    int m = INT_MAX;
    
    for(int i = 1; i <= arr[ci]; i++) {
        int temp = calcMin(arr,ci+i, n, memo);
        if (temp==INT_MAX) continue;
        m = min(1+temp, m);
    }
    
    if(m==INT_MAX) {
        memo[ci] = -1;
    } else {
        memo[ci] = m;
    }
    return m;
}
    
int minJumps(int arr[], int n){
    // Your code here
    vector<int> dest(arr, arr+n);
    int m;
    vector<int> memo(n, -1);
    memo[n-1] = 0;
    m = calcMin(dest, 0, n, memo);
    return memo[0];
}


int main(){
    int arr[]= {1,2,3,4};
    int a = minJumps(arr, 4);
    cout<<a;
}