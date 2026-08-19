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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        //finding mid point
        while(fast->next!=nullptr && fast->next->next!= nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        //dividing into halves
        ListNode* second = slow->next;//SECOND HALF VALUE
        slow->next = nullptr; // CUTS THE LIST INTO TWO HALVES
        ListNode* prev = nullptr;
        ListNode* curr = second;
        //reversing second half
        while(curr!=nullptr){
            ListNode* Next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        ListNode* first = head;
        second = prev;
        //merging halves
        while (second != nullptr) {
            // 1. Save
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            // 2. Connect
            first->next = second;
            second->next = temp1;

            // 3. Move
            first = temp1;
            second = temp2;
        }    
  
    }
};