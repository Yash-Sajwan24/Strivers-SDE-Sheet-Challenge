#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n,1), hash(n);
    int mx = 1;
    int lastidx = 0;
    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int prev = 0;prev<i;prev++){
            if(arr[i] > arr[prev] and 1 + dp[prev] > dp[i] ){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i]> mx){
            mx = dp[i];
            lastidx = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastidx]);
    while(hash[lastidx] != lastidx){
        lastidx = hash[lastidx];
        temp.push_back(arr[lastidx]);
    }
    reverse(temp.begin(), temp.end());
    return temp.size();
}
