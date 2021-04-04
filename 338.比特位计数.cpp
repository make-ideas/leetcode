/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        result[0] = 0;
        for (int i = 1; i <= num; i++) {
            if (i & 1 == 1) {
                result[i] = result[i >> 1] + 1;
            } else {
                result[i] = result[i >> 1];
            }
        }
        return result;
    }
};
// @lc code=end

