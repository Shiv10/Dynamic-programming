#include <bits/stdc++.h>
using namespace std;
int editHelper(string s, string t, int n, int m, vector<vector<int>> &memo){
    if(n==0) return m;
    if(m==0) return n;
    
  	if(memo[n][m]!=-1) return memo[n][m];  
    
    int min_dist;
    min_dist = 1 + min({editHelper(s, t, n-1, m, memo), editHelper(s, t, n, m-1, memo), editHelper(s, t, n-1, m-1, memo)});
    if(s[n-1]==t[m-1]) {
        min_dist = min(min_dist, editHelper(s, t, n-1, m-1, memo));
    } 
    memo[n][m] = min_dist;
    return min_dist;
}

int editDistance(string str1, string str2)
{
    //write you code here
    int n, m;
    n = str1.length();
    m = str2.length();
    vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
    int min_dist = editHelper(str1, str2, n, m, memo);
    return min_dist;
}