/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string S) {
        int index = -1; //栈顶索引 初始化为-1
       // vector<string> stack;
       const int len = S.length();
       char stack[len];  // VS编译器不支持，gcc支持  don't care 
        string result="";
        for(int i = 0; i < S.length(); i++){
            if(S[i] == '('){
                if(index > -1){
                    result += S[i]; //栈为空才拼接
                }
                stack[++index] = S[i]; //模拟入栈操作 
            }
            else{
                index--;   // 模拟出栈操作 
                if(index > -1){
                    result += S[i]; //栈为空才拼接
                }
            }
        }
        return result;
    }
};
// @lc code=end

