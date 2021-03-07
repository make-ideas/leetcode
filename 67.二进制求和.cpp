/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int n =  a.length() > b.length()  ?  a.length() : b.length();
        int carry = 0; //处理进位
        for(int i = 0; i < n ; i ++){
             if(((int)a.length() - 1 - i) >= 0){    
                carry += a[a.length() - 1 - i] - '0';
            }
            if(((int)b.length() - 1 - i) >= 0){
                carry += b[b.length() - 1 - i] - '0';
            }
            result.push_back(carry % 2 + '0');
            carry /= 2;
        }
        if(carry > 0){
            result.push_back('1');
        }
        for(size_t i = 0; i < result.length() / 2; i++){
            char c = result[i];
            result[i] = result[result.length() - i - 1];
            result[result.length() - i - 1] = c;
        }
        return result;
    }
};
// @lc code=end

