#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    void recursion(int& count, vector<int>& diff, vector<int>& perm, vector<int>& arr) {
        if (diff == arr ) {
            return ;
        }
        
        int n = perm.size();
        for (int i = 0; i < n; i++){
            if (i % 2 == 0) {
                arr[i] = perm[i / 2];
            } else {
                arr[i] = perm[n / 2 + (i - 1) / 2];
            }  
            perm[i] = arr[i];
        }
        cout << count << endl;
        recursion(++count, diff, perm, arr);
    }
    
    int reinitializePermutation(int n) {
        vector<int> perm(n, 0), arr(n, 0), diff(n, 0);
        int count = 0;
        for (int i = 0; i < n; i ++) {
            perm[i] = i;
            diff[i] = i;
        }
        recursion(count, diff,perm, arr);
        return count;
    }
};


int main()
{
    Solution solution;
    //string s = "(()())(())";
    int num = 4;
    solution.reinitializePermutation(num);

    return 0;

}