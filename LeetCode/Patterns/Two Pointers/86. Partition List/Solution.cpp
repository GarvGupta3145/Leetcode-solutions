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
    ListNode* partition(ListNode* head, int x) {
        if(!head || ! head->next)return head;
        ListNode*prev=nullptr;
        ListNode*curr=head;
        while(curr && curr->val <x){
            prev=curr;
            curr=curr->next;
        }
        if(!curr)return head;
        ListNode*temp=curr->next;
        ListNode*back=curr;
        while(temp){
            if(temp->val <x){
                ListNode*small=temp;
                back->next=temp->next;
                temp=temp->next;
                if(prev)prev->next=small;
                else head=small;
                small->next=curr;
                prev=small;
                continue;
            }
            else{
                back=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};