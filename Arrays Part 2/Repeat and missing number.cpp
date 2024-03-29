#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int xr = 0;

    for (int i = 0; i < n; i++) {
        xr = xr ^ arr[i];
        xr = xr ^ (i + 1);
    }

    int number = (xr & ~(xr - 1));

    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        if ((arr[i] & number) != 0) {
            one = one ^ arr[i];
        }
        else {
            zero = zero ^ arr[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if ((i & number) != 0) {
            one = one ^ i;
        }
        else {
            zero = zero ^ i;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == zero) cnt++;
    }

    if (cnt == 0) return {zero, one};
    return {one, zero};
	
	
}
