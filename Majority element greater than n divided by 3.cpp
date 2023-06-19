#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n= arr.size();
    int ele1 = INT_MAX, count1= 0;
    int ele2 = INT_MAX , count2= 0;

    for(int i=0;i<n;i++){
        if(count1==0 and arr[i] != ele2){
            ele1 = arr[i];
            count1++;
        }
        else if(count2 == 0 and arr[i] !=ele1){
            ele2 = arr[i];
            count2++;
        }
        else if(arr[i] == ele1)count1++;
        else if(arr[i] == ele2) count2++;
        else {
            count1--;count2--;
        }
    }

    count1=0, count2=0;
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(arr[i] == ele1)count1++;
        if(arr[i]== ele2) count2++;
    }

    if( count1 > n/3)ans.push_back(ele1);
    if(count2 > n/3) ans.push_back(ele2);

    return ans;


}