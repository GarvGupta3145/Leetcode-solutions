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
    ListNode* swapPairs(ListNode* head) {
        int count=1;
        ListNode*temp=head;
        if(!temp)return NULL;
        ListNode*prev=NULL;
        while(temp->next){
            if(count==1)head=temp->next;
            if(count%2==1){
                if(temp->next){
                    ListNode*swap=temp->next;
                    temp->next=swap->next;
                    if(prev)prev->next=swap;
                    swap->next=temp;
                    prev=temp;
                    count++;
                    continue;
                }
            }
            count++;
            temp=temp->next;
        }
        return head;
    }
};