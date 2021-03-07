/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include<ctype.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long result = 0; //最终结果
        int sign = 1;
        if(s.empty()){
            return 0;
        }

        for(int i = 0; i < s.length(); i++)
        {
            if(isspace(s[i])){
                continue;
            }
            else if((s[i] >= '0') && (s[i] <= '9')){
                result = s[i] - '0';
                for(int j = 1; j < s.length() - i; j++)
                {
                    if((s[i+j] >= '0') && (s[i+j] <= '9')){
                        
                        if ((sign == 1) && (result > INT_MAX/10)){
                            result = INT_MAX;
                            return result;
                        }
                        else if ((sign == -1) && (result > INT_MAX/10)){
                            result = INT_MIN;
                            return result;
                        }
                        else if ((sign == 1) && (result <= INT_MAX/10)){
                            if( s[i+j] - '0' <= INT_MAX - 10 * result)
                            {
                                result = 10 * result + s[i+j] - '0';
                            }
                            else
                            {
                                result = INT_MAX;
                                return result;
                            }
                            
                        }
                        else if ((sign == -1) && (result <= INT_MAX/10)){
                            if( s[i+j] - '0' <= INT_MAX - 10 * result)
                            {
                                result = 10 * result + s[i+j] - '0';
                            }
                            else
                            {
                                result = INT_MIN;
                                return result;
                            }
                        }
                    }
                    else{
                        break;
                    }
                }
                break;  //已经取到数字了
            }
            else if((s[i] == '-') && (i < s.length() -1)){
                if((s[i+1] == '+') || (s[i+1] < '0') || (s[i+1] > '9')){
                    return 0;
                }
                sign = -1;
            }
            else if((s[i] == '+') && (i < s.length() -1)){
                if((s[i+1] == '-') || (s[i+1] < '0') || (s[i+1] > '9')){
                    return 0;
                }
                continue;
            }
            else{
                break;
            }
        }
        
        //判断数字溢出问题

            
       // cout <<  (int)(result * sign) << endl;
        return  (int)(result * sign);
    }
};
// @lc code=end

