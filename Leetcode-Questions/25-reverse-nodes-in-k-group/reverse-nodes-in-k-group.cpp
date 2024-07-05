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
        if (!head || k == 1) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *root = dummy, *nex, *pre = dummy;
        
        int len = 0;
        while(root->next!=nullptr){
            root = root->next;
            len++;
        }

        while(len>=k){
            root = pre->next;
            nex = root->next;

            for(int i=1; i<k; ++i){
                root->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = root->next;
            }
            pre = root;
            len-=k;
        }
        return dummy->next;
    }
};