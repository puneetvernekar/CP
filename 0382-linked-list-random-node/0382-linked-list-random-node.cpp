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
    int n=0;
    ListNode* headn;
public:
    Solution(ListNode* head) {
        headn=head;
        ListNode* t=headn;
        while(t)
        {
            n++;
            t=t->next;
        }
    }
    
    int getRandom() {
        int rnum=rand()%n;
        ListNode* t=headn;
        for(int i=0;i<rnum;i++)
        t=t->next;
        return t->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */