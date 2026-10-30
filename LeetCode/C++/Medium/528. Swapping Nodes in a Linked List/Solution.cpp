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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode*temp=head;
        ListNode*left=head;
        while(temp){
            n+=1;
            if(n==k)left=temp;
            temp=temp->next;
        }
        temp=head;
        ListNode*right;
        int r=0;
        while(temp){
            r+=1;
            if(r==n-k+1){
                swap(left->val,temp->val);
            }
            temp=temp->next;
        }
        return head;
    }
};