class Solution {
public:
 ListNode* deleteMiddle(ListNode* head) {
    
    if(head==NULL || head->next==NULL) return NULL;       //if 0 or 1 node is present, return NULL
    
    ListNode *prev=NULL, * slow=head, * fast=head;        //Maintain 3 Pointers; prev, slow, fast
    
    while(fast!=NULL and fast->next!=NULL){                  
        prev=slow;                                        //update prev = slow
        slow=slow->next;                                  //increment slow once, slow = slow->next; 
        fast=fast->next->next;                            //increment fast twice, fast = fast->next->next;
    }
    
    prev->next=slow->next;                                //update connection 
    delete slow;                                          //deleting middle node
    return head;                                          //return head;
}
};