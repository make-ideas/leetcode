#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    void recursion(int& count, vector<int>& diff, vector<int>& perm, vector<int>& arr) {
        if (diff == arr ) {
            return ;
        }
        
        int n = perm.size();
        for (int i = 0; i < n; i++){
            if (i % 2 == 0) {
                arr[i] = perm[i / 2];
            } else {
                arr[i] = perm[n / 2 + (i - 1) / 2];
            }  
            perm[i] = arr[i];
        }
        cout << count << endl;
        recursion(++count, diff, perm, arr);
    }
    
    int reinitializePermutation(int n) {
        vector<int> perm(n, 0), arr(n, 0), diff(n, 0);
        int count = 0;
        for (int i = 0; i < n; i ++) {
            perm[i] = i;
            diff[i] = i;
        }
        recursion(count, diff,perm, arr);
        return count;
    }
};


class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dic;
        for (auto& str : knowledge) {
            dic[str[0]] = str[1];
        }

        string ans = "";
        string k = "";
        bool isKey = false;
        for (auto c : s) {
            if (c == '(') {
                isKey = true;
            }
            else if (c == ')') {
                isKey = false;
                ans += (dic.find(k) != dic.end()) ? dic[k] : "?";
                k = "";
            }
            else if (!isKey) {
                ans += c;
            }
            else {
                k += c;
            }
        }
        return ans;
    }
};



class Solution {
public:
    int numDecodings(string s) 
    {
        if (s[0] == '0') 
    	return 0;
        int pre = 1, curr = 1;//初始化
    
        for (int i = 1; i < s.size(); i++) 
        {
            int tmp = curr;
            if (s[i] == '0')
            {
                if (s[i - 1] == '1' || s[i - 1] == '2') 
                    curr = pre;
                else return 0;
            }
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))//十几到26之间
            { 
                curr = curr + pre;
            }
            pre = tmp;
        }
        return curr;
    }
};


class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        
        vector<int> dp(s.size()+1, 1);
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i] == '0')
            {
                if(s[i-1] != '1' && s[i-1] != '2') return 0;
                dp[i+1] = dp[i-1];
                continue;
            }

            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7'))
                dp[i+1] = dp[i] + dp[i-1];
            else
                dp[i+1] = dp[i];
        }
        return dp[s.size()];
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
};



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



int main()
{
    Solution solution;
    //string s = "(()())(())";
    int num = 4;
    solution.reinitializePermutation(num);

    return 0;

}