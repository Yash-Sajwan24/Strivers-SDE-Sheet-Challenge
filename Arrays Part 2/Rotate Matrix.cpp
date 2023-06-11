#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int rs=0,cs=0,re=n-1,ce=m-1;
    while(rs<re and cs<ce){
        int prev = mat[rs+1][cs];

        for(int col=cs;col<=ce;col++){
            int curr= mat[rs][col];
            mat[rs][col] = prev;
            prev= curr;
        }
        rs++;

        for(int row=rs;row<=re;row++){
            int curr= mat[row][ce];
            mat[row][ce] = prev;
            prev= curr;
        }
        ce--;

        for(int col=ce;col>=cs;col--){
            int curr= mat[re][col];
            mat[re][col] = prev;
            prev= curr;
        }
        re--;

        for(int row=re;row>=rs;row--){
            int curr= mat[row][cs];
            mat[row][cs] = prev;
            prev= curr;
        }
        cs++;
    } 

}