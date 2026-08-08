
class Solution {
public:
    ListNode* reverse(ListNode* head){
        // ListNode* fake= new ListNode(0);
        ListNode* crr=head;
        ListNode* pre=NULL;
        ListNode* nrr=NULL;
        while(crr!=NULL){
            nrr=crr->next;
            crr->next=pre;
            pre=crr;
            crr=nrr;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* Rev=reverse(slow->next); // reversed linked  list( reversing from half of the original list)
        ListNode* tempA=head;
        ListNode* tempB=Rev;
        while(tempB!=NULL){
            if(tempB->val!=tempA->val) return false;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return true;
    }
};