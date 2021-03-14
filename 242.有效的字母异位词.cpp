/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())  return false;
        unordered_map<char, int> counts;
        for (int i = 0; i < s.length(); i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        } 
        for (auto count : counts) 
            if ( count.second ) return false;
            return true;
        
    }
};
// @lc code=end

