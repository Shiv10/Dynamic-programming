#include <bits/stdc++.h>
using namespace std;

int maxHelper(vector<int> &values, vector<int> &weights, int n, int w, vector<vector<int>> &memo) {
    if(n==0) return 0;
    
    if(memo[n][w]!=-1) return memo[n][w];
    int max_profit;
    
    if(weights[n-1]<=w) {
        max_profit = max(maxHelper(values, weights, n-1, w, memo), values[n-1]+maxHelper(values, weights, n-1, w-weights[n-1], memo));
    } else {
        max_profit = maxHelper(values, weights, n-1, w, memo);
    }
    memo[n][w] = max_profit;
    return max_profit;
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<vector<int>> memo(n+1, vector<int>(w+1, -1));
    int max_profit = maxHelper(values, weights, n, w, memo);
    return max_profit;
}