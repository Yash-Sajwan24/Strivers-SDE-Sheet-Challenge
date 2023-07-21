string read(int n, vector<int> book, int target)
{
    int left = 0, right = n-1;
    sort(book.begin(), book.end());

    while(left < right){
        int val = book[left] + book[right];
        if(val == target) return "YES";
        else if (val > target )right--;
        else left ++;
    }
    return "NO";
}
