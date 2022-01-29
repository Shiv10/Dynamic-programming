#include<bits/stdc++.h>
using namespace std;

int maxMoney(vector<int> &houses, int n,vector<int> &memo)
{
    if (n<=0) return 0;
	if(memo[n]!=-1) return memo[n];
    int money = 0;
    money = max(houses[n-1]+maxMoney(houses, n-2, memo), maxMoney(houses, n-1, memo));
    memo[n] = money;
    return money;
}

int maxMoneyLooted(vector<int> &houses, int n){
    vector<int> memo(n+1, -1);
    int m = maxMoney(houses, n, memo);
    cout<<endl;
    return m;
}