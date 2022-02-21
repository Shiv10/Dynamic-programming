#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string str, int i, int j) {
    while(i<=j){
        if(str[i++]!=str[j--]) return false;
    }
    
    return true;
}


int ppHelper(string s, int i, int j, vector<vector<int>> &memo) {
    
    if(memo[i][j]!=-1) return memo[i][j];
    
    if(i==j || isPalindrome(s, i, j)){
        return 0;
    }
    
    int m = INT_MAX;
    
    for( int k = i;k<=j-1;k++) {
        int count = 1 + ppHelper(s, i, k, memo) + ppHelper(s, k+1, j, memo);
        if(count<m) {
            m = count;
        }
    }
    memo[i][j] = m;
    return m;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n = str.length();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    int ans = ppHelper(str, 0, n-1, memo);
    return ans;
}
