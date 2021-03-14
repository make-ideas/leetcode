/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        if (s.length() % 2 == 1) {
            return false;
        }
        for (auto c : s) {
           switch (c) {
               case '(' :
               case '[' :
               case '{' : mystack.push(c); break;
               case ')' : if (mystack.empty() || mystack.top() != '(') return false; else mystack.pop(); break; 
               case ']' : if (mystack.empty() || mystack.top() != '[') return false; else mystack.pop(); break; 
               case '}' : if (mystack.empty() || mystack.top() != '{') return false; else mystack.pop(); break; 
               default: ;
           }
        }
        return mystack.empty();
    }
};
// @lc code=end

