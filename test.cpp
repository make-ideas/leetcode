#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>

using namespace std;



class Solution {
public:
    void clearStack(stack<int> &s){
        while (!s.empty()){
            s.pop();
        }
    }
    int maxAscendingSum(vector<int>& nums) {
        stack<int> store;
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        store.push(nums[0]);
        int sum_temp = nums[0];
        vector<int> sum;
        
        for (int i = 1; i < nums.size() ; i++) {          
            if (nums[i] > store.top()) {
                sum_temp = sum_temp + nums[i];
                store.push(nums[i]);   
            } else {
                sum.push_back(sum_temp);
                clearStack(store);
                store.push(nums[i]);
                sum_temp = nums[i];
            } 
            if (i == nums.size() - 1) {
                 sum.push_back(sum_temp);
            } 
        }    
        sort(sum.rbegin(),sum.rend());
        return sum[0];
    }
};
int main()
{
    Solution solution;
    //string s = "(()())(())";
    vector<int> nums = {10,20,30,5,10,50};
    solution.maxAscendingSum(nums);

    return 0;

}