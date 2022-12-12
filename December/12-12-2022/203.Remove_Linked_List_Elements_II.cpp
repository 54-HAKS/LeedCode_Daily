class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode pseudo_head(0);
        pseudo_head.next = head;
        ListNode *prev = &pseudo_head;
        ListNode *cur = prev->next;
        while(cur){
            if(cur->val == val)   prev->next = cur->next;
            else    prev = prev->next;
            cur = cur->next;
        }
        return pseudo_head.next;
    }
};