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
    ListNode* swapPairs(ListNode* head) {
        ListNode* first=head;
        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;
        prev->next=head;
        while(first && first->next)
        {
            ListNode* future=first->next->next;
            ListNode* sec=first->next;
            sec->next=first;
            first->next=future;
            prev->next=sec;
            prev=first;
            first=future;
        }
        return dummy->next;
    }
};