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

        if (head->next->next == nullptr) {
            return {-1, -1};
        }

        int mini = INT_MAX;
        int first_crit = -1;
        int last_crit = -1;

        ListNode* prev = head;
        ListNode* root = head->next;

        int length = 1;

        while (root->next != nullptr) {
            if ((prev->val < root->val && root->val > root->next->val) ||
                (prev->val > root->val && root->val < root->next->val)) {
                    if(first_crit == -1){
                        first_crit = length;
                    } else {
                        mini = min(mini, length - last_crit);
                    }
                    last_crit = length;
            }
            prev = root;
            root = root->next;
            length++;
        }

        if(first_crit == last_crit){
            return {-1,-1};
        }
        
        return {mini, last_crit - first_crit};
    }
};