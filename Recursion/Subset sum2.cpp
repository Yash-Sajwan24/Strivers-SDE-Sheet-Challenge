#include <bits/stdc++.h> 
void solve(int n, vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, int idx){
    ans.push_back(temp);
    for(int i=idx;i<n;i++){
        if(i!=idx and arr[i] == arr[i-1])continue;
        temp.push_back(arr[i]);
        solve(n, arr, ans, temp, i+1);
        temp.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{   
    vector<vector<int>> ans;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    solve(n, arr, ans, temp, 0);
    return ans;
}