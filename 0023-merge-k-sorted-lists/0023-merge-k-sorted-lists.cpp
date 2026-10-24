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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>minheap;
        for(ListNode* temp : lists){
            while(temp){
                minheap.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* root = dummy;
        while(!minheap.empty()){
            ListNode* num = new ListNode(minheap.top());
            minheap.pop();
            root->next=num;
            root=root->next;
        }
        return dummy->next;
    }
};