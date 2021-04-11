/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // 计数排序思想
        map<int, int> mymap;
        for (auto x : arr1)  mymap[x]++;
        vector<int> res;
        for (auto x : arr2) 
            while (mymap[x] -- > 0)
                res.push_back(x);

        for (auto [x, c] : mymap) 
            while (c -- > 0)
                res.push_back(x);  
        return res;

    }
};
// @lc code=end

