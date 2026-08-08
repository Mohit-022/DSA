
class Solution {
public:
    ListNode* Reverse(ListNode* head, int left,int right){  
        if(head==NULL ) return head;
        ListNode* crr=head;
        ListNode* nrr=head;
        ListNode* pre=NULL;
        while(nrr!=NULL && left<=right){
            nrr=crr->next;
            crr->next=pre;
            pre=crr;
            crr=nrr;
            left++;
        }
        head->next=nrr;
        return pre;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right ) return head;
        ListNode* temp=head;
        ListNode* head2=head;
        if(left!=1){
            for(int i=1;i<left-1;i++){
                temp=temp->next;
            }
            head2=temp->next;
        }
        
        ListNode* Rev=Reverse(head2,left,right);
        if(left==1) return Rev;
        else if(left!=1){
            temp->next=Rev;
            return head;
        }
        return head;
    }
};