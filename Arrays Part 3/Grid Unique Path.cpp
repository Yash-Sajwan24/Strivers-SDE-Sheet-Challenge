#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<int> prev(n,1);
	prev[0] = 1;
	for(int i=1;i<m;i++){
		vector<int> curr(n, 1);
		for(int j=1;j<n;j++){
			int up = prev[j];
			int right = curr[j-1];
			curr[j] = up + right;
		}
		prev = curr;
	}

	return prev[n-1];
}