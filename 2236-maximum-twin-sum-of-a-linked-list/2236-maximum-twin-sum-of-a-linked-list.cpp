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
    int pairSum(ListNode* head) {
        vector<int> values;
        ListNode* current = head;
        
        // Step 1: Store values in a vector
        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }

        int n = values.size();
        int maxTwinSum = 0;

        // Step 2: Calculate maximum twin sum
        for (int i = 0; i < n / 2; ++i) {
            int twinSum = values[i] + values[n - 1 - i];
            maxTwinSum = max(maxTwinSum, twinSum);
        }

        return maxTwinSum;
    }
};