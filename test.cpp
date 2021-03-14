#include <iostream>
using namespace std;



  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur =  dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* node1 = cur->next;
            ListNode* node2 = cur->next->next;
            cur->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            cur = node1; 
        }
        return dummyHead->next;   
    }
};

int main()
{
    Solution solution;
    ListNode* mylist = new ListNode(1);
    mylist->next = new ListNode(2);
    mylist->next = new ListNode(3);
    mylist->next = new ListNode(4);
    cout << mylist << endl;
    solution.swapPairs(mylist);

    return 0;

}