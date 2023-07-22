#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());

    int count = 0;
    int max_count = 0;
    int prev_smaller = INT_MIN;
    for(int i=0;i<n;i++){
        if(i> 0 and arr[i] == arr[i-1])continue;
        if(arr[i]-1 == prev_smaller) count++;
        else count = 1;

        prev_smaller = arr[i];
        max_count = max(max_count , count);
    }

    return max_count;
}