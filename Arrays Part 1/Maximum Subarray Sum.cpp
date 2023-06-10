#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sm =0;
    long long res = 0;
    for(int i=0;i<n;i++){
        sm+=arr[i];
        if(sm<0)sm=0;
        res = max(res, sm);
        
    }
    return res;
}