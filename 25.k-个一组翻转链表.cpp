/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reserve(ListNode* head,ListNode* tail) {
        ListNode* prev = nullptr;
        ListNode* cur;

        while(head != tail) {
            cur = head->next;
            head->next = prev;
            prev = head;
            head = cur;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyhead = head;
        ListNode* tail = head;
        for (int i = 0; i < k; i++) {
            if (!tail) {
                return head;
            }
            tail = tail->next; // 遍历到最后
        }
        dummyhead = reserve(head, tail);
        head->next = reverseKGroup(tail, k);
        return dummyhead;

    }
};
// @lc code=end

