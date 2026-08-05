
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* fake=new ListNode(10);
        ListNode *temp=fake;

        while(list1!=NULL && list2!=NULL ){
            if(list1->val <=list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1==NULL)  temp->next=list2;
        else if(list2==NULL) temp->next=list1;
        
        return fake->next;
    }
};