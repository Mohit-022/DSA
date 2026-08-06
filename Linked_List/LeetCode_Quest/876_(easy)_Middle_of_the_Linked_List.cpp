
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       /* ListNode* temp=head;             // hume 2 bar loop chlana pad rha hai 
        int len=0;                         // hame ek iteration me hi agr krna hua to
        while(temp!=NULL){  // finding length
            len++;
            temp=temp->next;
            
        }
        ListNode * mid=head;
        int midIdx=len/2;
        
        for(int i=1;i<=midIdx;i++){
                mid=mid->next;
        }
        return mid;*/

        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL /* fast->next!=NULL || fast!=NULL */){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow; 
    }
};