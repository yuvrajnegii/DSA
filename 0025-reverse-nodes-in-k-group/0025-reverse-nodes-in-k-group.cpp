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
    ListNode*rev(ListNode* head, int k){
        ListNode* prev=nullptr;
        ListNode*curr=head;
        while(k){
            ListNode*next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            k--;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* newhead=nullptr;
        ListNode* prevend=nullptr;
        while(temp){
            bool enough=true;
            ListNode* start=temp;
            for(int i = 0; i < k; i++) {
                if(temp == nullptr){
                    enough=false;
                    break;
                }
                temp=temp->next;
                }
            if(enough){
                ListNode* reverseHead = rev(start, k);
                if(!newhead)
                   newhead=reverseHead;
                 
                else
                    prevend->next=reverseHead;
                prevend=start;
            }
            else{
                prevend->next=start;
                prevend=start;
                }
        }
        return newhead;
    }
};