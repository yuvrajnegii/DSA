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
    // Return the new head of the reversed group
    ListNode* rev(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(k) {
            ListNode* next = curr->next; // Save next node
            curr->next = prev;           // Reverse current node's link
            prev = curr;                 // Move prev forward
            curr = next;                 // Move curr forward
            k--;
        }
        return prev; // New head of reversed group
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        // Head of the final answer
        ListNode* newhead = nullptr;
        // Last node of the previous reversed group
        ListNode* prevend = nullptr;
        while(temp) {
            bool enough = true;
            // Start of the current group
            ListNode* start = temp;
            // Check whether k nodes are available
            for(int i = 0; i < k; i++) {
                if(temp == nullptr) {
                    enough = false;
                    break;
                }
                temp = temp->next;
            }
            // We have exactly k nodes, so reverse this group
            if(enough) {
                ListNode* reverseHead = rev(start, k);
                if(!newhead)
                    newhead = reverseHead;
                // Connect previous reversed group to current group
                else
                    prevend->next = reverseHead;
                // Original start becomes the last node
                // after reversal
                prevend = start;
            }
            // Fewer than k nodes remain
            else {
                prevend->next = start;
                prevend = start;
            }
        }
        return newhead;
    }
};