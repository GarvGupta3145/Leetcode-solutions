class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)return list2;
        if(!list2)return list1;
        if(list1->val>list2->val)swap(list1,list2);
        ListNode* head= list1;
        ListNode* prev= nullptr;
        ListNode* curr1= list1;
        ListNode* curr2= list2;
        while(curr1 && curr2){
            if(curr1->val <= curr2->val){
                prev=curr1;
                curr1=curr1->next;
            }
            else{
                ListNode*nxt = curr2->next;
                prev->next=curr2;
                curr2->next=curr1;
                prev=curr2;
                curr2=nxt;
            }
        }
        if(curr2)prev->next=curr2;
        return head;
    }
};