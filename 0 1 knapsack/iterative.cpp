#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& values, vector<int>& weights, int n, int w)
{
	vector<vector<int>> result(n + 1, vector<int> (w + 1, 0));

    for(int i = 1; i <= n; i++)
    {
    	for(int j = 1; j <= w; j++)
    	{
            if(weights[i - 1] <= j)
    		{
    			result[i][j] = max(result[i - 1][j], values[i - 1] + result[i - 1][j - weights[i - 1]]);
    		}
    		else
    		{
    			result[i][j] = result[i - 1][j];
    		}
    	}
    }

    return result[n][w];
}

int main(){
    int t, n, w;
    cin>>t;
    cin>>n>>w;
    vector<int> weights;
    vector<int> value;
    int a, i;
    for(i=0;i<n;i++){
        cin>>a;
        weights.push_back(a);
    }

    for(i=0;i<n;i++){
        cin>>a;
        value.push_back(a);
    }

    a = maxProfit(value, weights, n, w);
    cout<<a;
    return 0;
}