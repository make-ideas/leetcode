#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int target = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[target] != nums[i]) {
                if (++target != i) {
                    nums[target] = nums[i];
                }
            }
        }
        return target + 1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    solution.removeDuplicates(nums);

    return 0;

}