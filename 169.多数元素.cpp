/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 摩尔投票法 一样的++ 不一样的-- 等于0 下一个被投票
        int count = 0;
        int master = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (master == nums[i]) {
                count ++;
            } else if (--count == 0) {
                master = nums[i + 1];
            }
        }
        return master;
    }
};
// @lc code=end

