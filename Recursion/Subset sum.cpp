vector<int> subsetSum(vector<int> &num){
	int n = num.size();
	vector<int> ans;
	for(int i=0;i<(1<<n);i++){
		int sm =0;
		for(int j = 0;j<n;j++){
			if(i&(1<<j))
				sm+=num[j];
		}
		ans.push_back(sm);
	}
	sort(ans.begin(), ans.end());
	return ans;
}