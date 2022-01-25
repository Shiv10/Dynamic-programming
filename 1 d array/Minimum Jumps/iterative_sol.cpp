#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr;
    arr.push_back(1);
    // arr.push_back(0);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    vector<int> dp(arr.size(), 999999999);
    int n = arr.size(), i, j;
    dp[n-1] = 0;
    for( i=n-2; i>=0; i--){

        for(j=i+1; j<= min(n-1, i+arr[i]); j++){

            if(dp[j]!=999999999)
                dp[i] = min(dp[i], 1+dp[j]);

        }
    }

    if(dp[0]==999999999){
        cout<<-1;
        return 0;
    } 
    cout<<dp[0];
    return 0;
}