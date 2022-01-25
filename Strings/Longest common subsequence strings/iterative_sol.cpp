#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t)
{
	//Write your code here
    int n = s.length();
    int m = t.length();
    vector<vector<int>> memo(n+1, vector<int>(m+1, 0));
    int i, j;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                memo[i][j] = 1 + memo[i-1][j-1];
            } else {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }
    int ans = memo[n][m];
    return ans;
}