/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int bullscnt = 0, cowscnt = 0;
        unordered_map<char, int> secretdiff;
        unordered_map<char, int> guessdiff;
        int len = secret.size();

        for (int i = 0; i < len; i++) {
            if (secret[i] == guess[i]) {
                bullscnt ++;
            }else {
                secretdiff[secret[i]] ++;
                guessdiff[guess[i]] ++;
            }
        }

        for (auto it : secretdiff) {
            cowscnt += min(it.second, guessdiff[it.first]);
        }
         return to_string(bullscnt) + "A" + to_string(cowscnt) + "B";

    }
};
// @lc code=end

