int editDistance(string str1, string str2)
{   
    int n1= str1.size(), n2 = str2.size();
    vector<int> curr(n2+1, 0), prev(n2+1, 0);

    for(int j=0;j<=n2;j++){
        prev[j] = j;
    }

    for(int i=1;i<=n1;i++){
        curr[0] = i;
        for(int j=1;j<=n2;j++){
            int ans = 1e9;
            if(str1[i-1] == str2[j-1]) curr[j] = prev[j-1];
            else{
                int o1 = 1 + curr[j-1];
                int o2 = 1 + prev[j];
                int o3 = 1 + prev[j-1];
                curr[j] = min(o1, min(o2, o3));
            }   
        }
        prev = curr;
    }

    return prev[n2];
}