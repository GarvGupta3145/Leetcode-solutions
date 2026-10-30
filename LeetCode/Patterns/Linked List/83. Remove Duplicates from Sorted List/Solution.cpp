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
        
        if(!head || !head->next)return head;
        ListNode*prev=head;
        ListNode*curr=head->next;
        while(curr){
            while(curr && curr->val==prev->val){
                ListNode*del=curr;
                curr=curr->next;
                prev->next=curr;
                delete del;
                continue;
            }
            prev=curr;
            if(curr)curr=curr->next;
        }
        return head;
    }
};