#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int first =0, mid =0, last=n-1;
   while(mid <= last){
      if(arr[mid] == 0){
         swap(arr[mid], arr[first]);
         first++;mid++;
      }
      else if(arr[mid] == 1){
         mid++;
      }
      else{
         swap(arr[mid], arr[last]);
         last--;
      }
   }


}