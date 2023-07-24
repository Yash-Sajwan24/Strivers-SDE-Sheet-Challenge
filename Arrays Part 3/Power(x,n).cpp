double myPow(double x, int n) {
    if(x == 1) return 1;
    long long nn = n;
    if(n<0) nn = -nn;
    double ans = 1;

    while(nn>0){
        if(nn%2==0){
            x = x*x;
            nn/=2;
        }
        else{
            ans = ans*x;
            nn--;
        }
    }
    if(n<0) ans = (double)1/(double) ans;

    return ans;
    
}