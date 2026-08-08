
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* even=new ListNode(0);
        ListNode* temp=head->next;
        ListNode* tempA=head;
        ListNode* tempB=even;
        while(temp!=NULL){
            if(temp!=NULL){
                tempB->next=temp;
                tempB=temp;
                temp=temp->next;
            }
            if(temp!=NULL){
                tempA->next=temp;
                tempA=temp;
                temp=temp->next;
            } 
        }
        tempA->next=NULL;
        tempB->next=NULL;
        
        temp=even;
        
        tempA=head;
        tempB=even->next;
        
        
        while(tempA!=NULL || tempB!=NULL){
            if(tempB!=NULL){
                temp->next=tempB;
                temp=tempB;
                tempB=tempB->next;
            }
            if(tempA!=NULL){
                temp->next=tempA;
                temp=tempA;
                tempA=tempA->next;
            }
        }
        return even->next;
    }
};