#include <bits/stdc++.h>
using namespace std;
int minCostPathHelper(int** cost, int n, int m, int x, int y, vector<vector<int>> &memo)
{
    //Write your code here.
    if(y==1 && x==1) return cost[0][0];
    
    if(memo[x][y]!=-1) return memo[x][y];
    
    int min_cost = INT_MAX;
    if(x>1 && y>1) {
        min_cost = min(min_cost, cost[x-1][y-1] + minCostPathHelper(cost, n, m, x-1, y-1, memo)); 
    } 
    if (x > 1) {
        min_cost = min(min_cost, cost[x-1][y-1] + minCostPathHelper(cost, n, m, x-1, y, memo)); 
    } 
    if (y > 1) {
        min_cost = min(min_cost, cost[x-1][y-1] + minCostPathHelper(cost, n, m, x, y-1, memo)); 
    }
    memo[x][y] = min_cost;
    return min_cost;
}

int minCostPath(int **cost, int n, int m, int x, int y) {
    int min_cost;
    vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
    min_cost = minCostPathHelper(cost, n, m, x, y, memo);
    return min_cost;
}