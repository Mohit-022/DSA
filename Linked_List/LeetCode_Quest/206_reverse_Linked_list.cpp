
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=new ListNode(10);
        ListNode* crr=head; // crr= current node pointer
        ListNode* pre=temp;  // pre= previous node
        ListNode* nrr= NULL;  // nrr = next node
        while(crr!=NULL){
            nrr=crr->next;
            crr->next=pre;
            pre=crr;
            crr=nrr;
        }
        head->next=NULL;
        return pre;
    }
};
