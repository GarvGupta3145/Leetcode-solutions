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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count=1;
        ListNode*curr=head;
        ListNode*back=nullptr;
        if(!head || !head->next || left==right)return head;
        while(curr && count!=left){
            count++;
            back=curr;
            curr=curr->next;
        }
        ListNode* temp=curr->next;
        ListNode* prev=curr;
        while(temp && count!=right){
            ListNode* t=temp->next;
            temp->next=prev;
            prev=temp;
            temp=t;
            count++;
        }
        if(back)back->next=prev;
        else head=prev;
        curr->next=temp;
        return head;
    }
};