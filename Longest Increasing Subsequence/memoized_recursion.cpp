#include <bits/stdc++.h>
using namespace std;

int memo[100][100];
int longestIncreasingSequence(int prev, int curr, int arr[], int n){

    if(curr==n) return 0;

    if(prev != -1 && memo[prev][curr]!=0) return memo[prev][curr];

    int a1 = 0;
    if(prev == -1 || arr[curr] > arr[prev]){
        a1 = 1+longestIncreasingSequence(curr, curr+1, arr, n);
    }

    int a2 = longestIncreasingSequence(prev, curr+1, arr, n);

    if(prev!=-1){
        memo[prev][curr] = max(a1, a2);
    }
    
    return max(a1, a2);
}

int main(){
    int len;
    int arr[] = {1,2,3,4,5};
    memset(memo, 0, sizeof(memo));
    len = longestIncreasingSequence(-1, 0, arr, 5);
    cout<<len;
}