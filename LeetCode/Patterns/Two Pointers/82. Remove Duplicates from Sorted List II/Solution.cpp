/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || ! head->next)return head;
        ListNode* temp=head;
        ListNode*prev=nullptr;
        while(temp->next){
            int val=temp->val;
            if(val==temp->next->val){
                while(temp->next  && temp->next->val==val){
                    ListNode*del=temp->next;
                    temp->next=del->next;
                    delete del;
                }
                
                ListNode*del=temp;
                temp=temp->next;
                if(prev)prev->next=temp;
                else head=temp;
                delete del;
                continue;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};