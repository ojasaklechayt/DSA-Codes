class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        ListNode* root = head->next;

        int sum = 0;
        while(root!=nullptr){
            if(root->val == 0){
                current->next = new ListNode(sum);
                current = current->next;
                sum = 0;
            } else {
                sum += root->val;
            }
            root = root->next;
        }

        return dummy->next;
    }
};