#include <bits/stdc++.h>
using namespace std;
int lcsHelper(int n, int m, string s, string t, vector<vector<int>> &memo){
    if(n==0 || m==0) return 0;
    
    if(memo[n-1][m-1]!=-1) return memo[n-1][m-1];
    
    if(s[n-1]!=t[m-1]){
        memo[n-1][m-1] = max(lcsHelper(n-1, m, s, t, memo), lcsHelper(n, m-1, s, t, memo));
    } else {
        memo[n-1][m-1] = 1 + lcsHelper(n-1, m-1, s, t, memo);
    }
    
    return memo[n-1][m-1];
}

int lcs(string s, string t)
{
	//Write your code here
    int n = s.length();
    int m = t.length();
    vector<vector<int>> memo(n, vector<int>(m, -1));
    int ans = lcsHelper(n, m, s, t, memo);
    return ans; 
}