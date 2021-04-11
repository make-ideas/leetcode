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

        if(s.length() != t.length()) return false;
#if 0
        map<char, int> mps;
        map<char, int> mpt;
        for (int i = 0; i < s.length(); i++) {
            mps[s[i]]++;
            mpt[t[i]]++;
        } 
        for (int i = 0; i < mps.size(); i++) {
            auto key = mpt.find(s[i]);
            if (key == mpt.end() || (key != mpt.end() && key->second != mps[s[i]]) ) {
                return false;
            }
            ///cout << mps[s[i]] << " " << mpt[t[i]] << endl;
        }
        return true;
#else
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
       
        return s == t;
#endif
    }
};
// @lc code=end

