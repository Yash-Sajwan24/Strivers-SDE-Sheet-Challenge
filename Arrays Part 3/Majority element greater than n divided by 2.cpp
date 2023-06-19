#include <bits/stdc++.h>

//moore voting algorithm
int findMajorityElement(int arr[], int n) {
	int ele = arr[0];
	int count = 0;
	for(int i=0;i<n;i++){
		if(count == 0) {
			ele = arr[i];
			count++;
		}
		else if(arr[i] == ele)count++;
		else count--;
	}
	count = 0;
	for(int i=0;i<n;i++){
		if(arr[i] == ele)count++;
	}
	
	if(count > n/2) return ele;
	return -1;
}