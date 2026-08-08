
class Solution {
public:
    int sizeCount (ListNode* head){
        ListNode* temp=head;
        int s=0;
        while(temp!=NULL){
            temp=temp->next;
            s++;
        }
        return s;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int size=sizeCount(head);
        if(k!=0 && size!=0) k=k%size;
        int n=k;
        if(k==0 || head==NULL || head->next==NULL) return head;
        
        ListNode* temp=head;
        for(int i=1;i<size-n;i++){
            temp=temp->next;
        }
        ListNode* head2=temp->next;
        temp->next=NULL;
        temp=head2;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        return head2;

    }
};