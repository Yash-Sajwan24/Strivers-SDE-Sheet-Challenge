#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int prev_min = prices[0];
    int profit = 0;
    for(int i=1;i<n;i++){
        int curr_profit = prices[i] - prev_min;
        profit = max(profit, curr_profit);
        prev_min = min(prev_min, prices[i]);
    }
    return profit;
}