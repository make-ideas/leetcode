/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        int len = tasks.size();
        // 统计词频
        for(int i = 0; i < len; i ++){
            count[tasks[i] - 'A'] ++;
        }
        // 排序
        sort(count.begin(), count.end());
        // 统计有多少个频率最高的字母
        int num = 1;
        for(int i =24; i >= 0 ; i --){
            if(count[i] != count[25]){
                break;
            }
            num ++;
        }
        return max((count[25] - 1) * (n + 1) + num, len);
    }
};
// @lc code=end

