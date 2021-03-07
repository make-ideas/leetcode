/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {

        if (x >= INT_MAX || x <= INT_MIN){
           // 溢出时直接返回0
          // cout << x << endl;
            return 0;
        }
        
        int sign = x > 0 ? 1 : -1; //取符号位
        x = x > 0 ? x : -x;  //无论正负均当作正数来处理

        // 不断的对10取模
        int last = 0; //末位
        int result = 0; //返回结果

        while((last = x%10) != x){
            result = 10*result + last;
            x = x/10;
        }

        //乘以10可能会越界，最高位需单独处理
        if(last != 0){
            if(result > INT_MAX/10){
                return 0;
            }
            else{
                result = 10*result + last;
            }
        }

        return result * sign;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    int a = 1463847412;
    solution.reverse(a);
    cout << a << endl;

    return 0;
}