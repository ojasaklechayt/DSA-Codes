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
        priority_queue<int, vector<int>, greater<int>> aq;

        for(auto& root: lists){
            while(root!=NULL){
                aq.push(root->val);
                root = root->next;
            }
        }

        if (aq.empty()) {
            return nullptr;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;

        while(!aq.empty()){
            int top = aq.top();
            aq.pop();
            node->next = new ListNode(top);
            node = node->next;
        }

        return dummy->next;
    }
};