/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 无向图的广度优先搜索
        //转换成set容器 提高查询效率
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        //endWord 不在字典中 直接return 0
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        // map记录单次是否被访问过及起始位置到这个单词路径长度
        unordered_map<string, int> visitMap; 
        // 队列初始化
        queue<string> que;
        que.push(beginWord);
        visitMap.insert(pair<string, int>(beginWord, 1));

        while(!que.empty()) {
            string word = que.front();
            que.pop();
            int path = visitMap[word]; //该单词的路径长度
            for (int i = 0; i < word.size(); i++) { // 挨个替换该单词的每一位置
                string newword = word;
                for (int j = 0; j < 26; j++) {
                    newword[i] = 'a' + j;
                    if (newword == endWord) {
                        // 结束了
                        return path + 1;
                    }
                    if (wordSet.find(newword) != wordSet.end() && visitMap.find(newword) == visitMap.end()) {   // newword 在字典中存在 没有被访问过
                        visitMap.insert(pair<string, int> (newword, path + 1));
                        que.push(newword);
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

