class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int mx = INT_MIN;
        for(int i=0;i<C;i++){
            vector<int> temp(R, 0); 
            for(int j =i;j<C;j++){
                for(int k = 0;k<R ;k++){
                    temp[k] = M[k][j] + temp[k];
                }
                int curr = 0;
                for(auto x: temp){
                    curr = curr+ x; 
                    mx = max(curr, mx);
                    
                    if(curr< 0) curr = 0;
                }
            }
        }
        return mx; 
    }
};