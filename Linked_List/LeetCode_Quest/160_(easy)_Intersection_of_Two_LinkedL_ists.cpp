
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA=0;
        int sizeB=0;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA!=NULL || tempB!=NULL){
            if(tempA!=NULL){
                tempA=tempA->next;
                sizeA++;
            }
            if(tempB!=NULL){
                tempB=tempB->next;
                sizeB++;
            }
        }
        tempA=headA;
        tempB=headB;
        if(sizeA>sizeB){
            for(int i=1;i<=abs(sizeA-sizeB);i++){
                tempA=tempA->next;
            }
        }
        else{
            for(int i=1;i<=abs(sizeA-sizeB);i++){
                tempB=tempB->next;
            }
        }
        while(tempA!=NULL && tempB!=NULL){
            if(tempA==tempB) return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;

    }
};