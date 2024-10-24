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
    ListNode* oddEvenList(ListNode* head) {
        // If the list is empty or has only one node, return head
        if (!head || !head->next) return head;

        // Initialize pointers for odd and even nodes
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Store the head of even indexed nodes

        // Traverse the list
        while (even && even->next) {
            odd->next = even->next; // Link current odd to the next odd node
            odd = odd->next; // Move to the next odd node
            even->next = odd->next; // Link current even to the next even node
            even = even->next; // Move to the next even node
        }

        // Connect the last odd node to the head of the even list
        odd->next = evenHead;

        return head; // Return the reordered list
    }
};
