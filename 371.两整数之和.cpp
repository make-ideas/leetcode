/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        if(b != 0){
            int result = a ^ b;
            int carry = (a & b & 0x7fffffff) << 1;  // leetcode不支持负数左移 即最高位为0才能左移 所以需要强制最高位为0
            return getSum(result, carry);
        }
        else{
            return a;
        }
    }
};
// @lc code=end

