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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head ||k==1) return head;
        ListNode*temp=head;
        int n=0;
        while(temp){
            temp=temp->next;
            n++;
        }
        if(k>n) return head;
        ListNode*end=new ListNode();
        ListNode*newhead=end;
        ListNode*front=NULL;
        ListNode*st=head;
        ListNode*curr=head;
        ListNode*prev=NULL;

        for (int groups = n/k; groups > 0; groups--){
            st=curr;
            prev=NULL;
            for(int i=0;i<k;i++){
                front=curr->next;
                curr->next=prev;
                prev=curr;
                curr=front;  
                }
            end->next=prev;
            end=st;
            
        }
        end->next = curr;
        return newhead->next;
    }
};