#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    vector<int> dp(arr.size(), 1);
    int m = 1;
    for(int i = 1; i<arr.size(); i++){
        for(int j = 0; j<i; j++){
            if(arr[i]>arr[j]){
                if(dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
        }
        if(m<dp[i]) m = dp[i];
    }

    cout<<m; 
}