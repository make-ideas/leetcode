/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> length;
        heights.push_back(0);
        int ans = 0;

        for (int i = 0; i < heights.size(); i++) {
            while ( !length.empty() && heights[length.top()] >= heights[i] ) {
                int h = heights[length.top()];
                length.pop();
                if (length.empty()) {
                    ans = max(ans, i * h);
                } else {
                    ans = max(ans, (i - length.top() - 1) * h);
                }
            }
            length.push(i);
        }

        return ans;
    }
};
// @lc code=end

