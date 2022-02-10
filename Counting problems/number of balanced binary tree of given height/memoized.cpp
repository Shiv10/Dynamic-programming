#include <bits/stdc++.h>
using namespace std;
int height(int n, vector<int> &memo) {
    
    if(n==0 || n == 1 ) return 1;
    
    if(memo[n]!=-1) return memo[n];
    
    long long mod = 1e9 + 7;
    
    int countOne = height(n-1, memo);
    int countTwo = height(n-2, memo);
    
    int ans = ((2LL * countOne * countTwo)% mod + (1LL * countOne * countOne)% mod)%mod;
    
    return memo[n] = ans;
}

int countBalancedBinaryTree( int n)
{
    //    Write your code here.
    vector<int> memo(n+1, -1);
    return height(n, memo);
}