#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &arr, int n, int curr, int jumps, vector<int> &memo){
    if(curr>=n-1) return jumps;

    if(memo[curr]!=-1) return memo[curr];

    int i, m=-1, temp;
    for(i=1;i<=arr[curr];i++){
        temp = minJumps(arr, n, curr+i, jumps+1, memo);
        if(m==-1 || m>temp) m = temp;
    }
    memo[curr] = n-m;
    return m;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    vector<int> memo(arr.size(), -1);
    int a = minJumps(arr, arr.size(), 0, 0, memo);
    cout<<a;
}