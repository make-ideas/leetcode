/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

//Definition for singly-linked list.
//   struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* resultHead = new ListNode();
        ListNode* cur = resultHead;  // 结果遍历指针，初始时指向头结点

        int carry = 0; //接收进位

        while(p != nullptr || q != nullptr){

            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = carry + x + y; //对应位置相加

            carry = sum / 10;
            sum = sum % 10; 

            cur->next = new ListNode(sum);
            cur = cur->next;

            p = (p == nullptr) ? p : p->next;
            q = (q == nullptr) ? q : q->next;
        }

        if(carry > 0){
            cur->next = new ListNode(carry);
        }
        return resultHead->next;
    }
};
// @lc code=end

