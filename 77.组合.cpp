/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res; //存放最终结果
    vector<int> path; // 控制行

    void backtracing(int n, int k, int startIndex) {
        //中止条件
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = startIndex; i <= n - (k - path.size()) + 1; ++i) {
            path.push_back(i);
            backtracing(n, k, i + 1);
            path.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        backtracing(n, k, 1);
        return res;
    }
};
// @lc code=end

