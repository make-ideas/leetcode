/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

//左右夹逼 向中间收敛 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;

        for (int i = 0, j = height.size() -1; i < j;) {
            int length = height[i] < height[j] ? height[i++] : height[j--];
            result = max(result, (j - i + 1)*length);
        }
        return result;
    }
};
// @lc code=end

