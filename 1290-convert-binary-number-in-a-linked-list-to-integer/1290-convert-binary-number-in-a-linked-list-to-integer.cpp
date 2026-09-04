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
    int getDecimalValue(ListNode* head) {
        vector<int>bin;
        int b=0;
        while(head){
            bin.push_back(head->val);
            head=head->next;
        }
        int n=bin.size();
        for(int i=0;i<n;i++){
            b+=(bin[i]*pow(2,n-i-1));
        }
        return b;

    }
};