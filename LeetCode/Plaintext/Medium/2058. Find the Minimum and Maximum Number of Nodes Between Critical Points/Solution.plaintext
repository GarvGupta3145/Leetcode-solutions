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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*prev=head;
        ListNode*curr=head->next;
        vector<int>ans(2,-1);
        int mn=INT_MAX;
        int first=-1;
        int last=-1;
        int count=1;
        while(curr->next){

            if(curr->val>prev->val && curr->val>curr->next->val){
                if(first!=-1){
                    mn=min(mn,count-last);
                }
                if(first==-1)first=count;
                last=count;
            }
            else if(curr->val<prev->val && curr->val<curr->next->val){
                if(first!=-1){
                    mn=min(mn,count-last);
                }
                if(first==-1)first=count;
                last=count;
            }
            prev=curr;
            curr=curr->next;
            count++;
        }
        if(first!=last){
            ans[1]=last-first;
            ans[0]=mn;
        }
        return ans;
    }
};