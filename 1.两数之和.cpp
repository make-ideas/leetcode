/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

// struct node{
//     int x, y;
// };

// int cmp(node a, node b){
//     return a.x < b.x;
// }

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//        vector<node> v;
//         for(int i = 0; i < nums.size(); i++){
//             v.push_back(node{nums[i], i});
//         }
//         sort(v.begin(), v.end(), cmp);
//         int i = 0, j = nums.size()-1;
//         vector<int> ans;
//         while(i < j){
//             if(v[i].x + v[j].x == target){
//                 ans.push_back(v[i].y);
//                 ans.push_back(v[j].y);
//                 break;
//             }
//             else if(v[i].x + v[j].x < target){
//                 i++;
//             }
//             else{
//                 j--;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> mymap;
      for (int i = 0; i < nums.size(); i++) {
          if ( mymap.find(target - nums[i]) != mymap.end() ) {
              return {mymap.find(target - nums[i])->second, i};
          }
          mymap.insert(pair<int, int>(nums[i], i));
      }
      return {};
    }
};

// @lc code=end

