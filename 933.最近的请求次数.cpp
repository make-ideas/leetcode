/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

// 双指针思路
// @lc code=start
#include <queue>
using namespace std;
class RecentCounter {
// public:
//     int arrary[3002] = {0};
//     int start = 0, end = 0;
//     RecentCounter() {
       
//     }
    
//     int ping(int t) {
//         //存放索引 更新起止位置
//         arrary[end++] = t;
//         // end如果等于数组最大长度，置为0，从头开始
//         end = end == 3002 ? 0 : end;
//         //过滤掉不符合要求的数据
//         while(arrary[start] < t - 3000){
//             start++;
//             start = start == 3002 ? 0 : start;
//         }
//         // start 大于 end 说明越界 
//         // 通过start与end之间的差值计算请求次数
//         if(start > end){
//             return 3002 - (start - end);
//         }
//         return end - start;
//     }
public:
    RecentCounter(){

    }

    int ping(int t){
        q.push(t);
        while(q.front() < t -3000){
            q.pop();
        }
        return q.size();
    }
private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

