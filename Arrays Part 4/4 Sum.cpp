#include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target) {
   int n= nums.size();
   vector<vector<int>> ans;
   sort(nums.begin(), nums.end());
   
   for(int i=0;i<n;i++){
       if(i>0 and nums[i]==nums[i-1])continue;
       for(int j=i+1;j<n;j++){
           if(j>i+1 and nums[j]==nums[j-1])continue;
           int a = j+1, b=n-1;
           while(a< b){
               long long val = nums[i] + nums[j] + nums[a] + nums[b];
               if(val == target){
                   vector<int> temp = {nums[i], nums[j], nums[a], nums[b]};
                   ans.push_back(temp);
                   a++;
                   b--;
                   while(a<b and nums[a]==nums[a-1])a++;
                   while(a<b and nums[b] == nums[b+1])b--;
               }
               else if(val < target) a++;
               else b--;
           }
       }
   }

   return ans;
}