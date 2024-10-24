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
    ListNode* deleteMiddle(ListNode* head) {
        // If the list has only one node, return nullptr
        if (!head->next) return nullptr;

        // Calculate the length of the linked list
        ListNode* current = head;
        int length = 0;
        while (current) {
            length++;
            current = current->next;
        }

        // Find the index of the middle node
        int middleIndex = length / 2;

        // Traverse again to find the node before the middle node
        current = head;
        for (int i = 0; i < middleIndex - 1; i++) {
            current = current->next;
        }

        // Delete the middle node
        ListNode* middleNode = current->next; // This is the middle node
        current->next = middleNode->next; // Bypass the middle node
        delete middleNode; // Free the memory of the middle node

        return head; // Return the modified list
    }
};
