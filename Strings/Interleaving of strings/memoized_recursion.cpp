#include <bits/stdc++.h>
using namespace std;

bool isInterLeaveHelp(string a, string b, string c, int l, int m, int p, vector<vector<vector<int>>>& memo) {
    if(p==0) {
        return (l==0&&m==0)?true:false;
    }
    
    if(memo[l][m][p]!=-1) return memo[l][m][p];
    
    if(l==0) {
        if(b[m-1]==c[p-1]) {
            return memo[l][m][p] = isInterLeaveHelp(a, b, c, l, m-1, p-1, memo);
        } else return memo[l][m][p] = false;
    }
    
    if(m==0) {
        if(a[l-1]==c[p-1]) {
            return memo[l][m][p] = isInterLeaveHelp(a, b, c, l-1, m, p-1, memo);
        } else return memo[l][m][p] = false;
    }
    
    bool one, two;
    one = two = false;
    
    if (a[l-1]==c[p-1]) {
        one = isInterLeaveHelp(a, b, c, l-1, m, p-1, memo);
    }
    
    if (b[m-1]==c[p-1]) {
        two = isInterLeaveHelp(a, b, c, l, m-1, p-1, memo);
    }
    
    return memo[l][m][p] = (one||two);
}
bool isInterleave(string a, string b, string c){
	//Your code goes here
    int l, m, p;
    l = a.length();
    m = b.length();
    p = c.length();
    vector<vector<vector<int>>> memo(l+1, vector<vector<int>>(m+1, vector<int>(p+1, -1)));
    bool ans;
    ans = isInterLeaveHelp(a, b, c, l, m, p, memo);
    return ans;
}