// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
// Difficulty: Medium
//
// You are given the head of a linked list. Delete the middle node, and return
// the head of the modified linked list.
//
// The middle node of a linked list of size n is the floor(n/2)th node from the
// start using 0-based indexing, where floor(x) denotes the largest integer less
// than or equal to x.
//
// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2,
// respectively.
//
// Example 1:
//   Input: head = [1,3,4,7,1,2,6]
//   Output: [1,3,4,1,2,6]
//   Explanation: n = 7, node 3 (value 7) is the middle node (index 3).
//
// Example 2:
//   Input: head = [1,2,3,4]
//   Output: [1,2,4]
//   Explanation: n = 4, node 2 (value 3) is the middle node (index 2).
//
// Example 3:
//   Input: head = [2,1]
//   Output: [2]
//   Explanation: n = 2, node 1 (value 1) is the middle node (index 1).
//
// Constraints:
//   - The number of nodes in the list is in the range [1, 10^5].
//   - 1 <= Node.val <= 10^5

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (true) {
            fast = fast->next;

            if (fast != nullptr) {
                fast = fast->next;
            }
            
            if (fast == nullptr || fast->next == nullptr) {
                break;
            }
            
            slow = slow->next;
        }

        if (slow->next != nullptr) {
            slow->next = slow->next->next;            
        }

        return head;

        /*
        ListNode* node = head;
        int len = 0;

        while (node != nullptr) {
            len++;
            node = node->next;
        }

        int middle = len / 2;
        node = head;

        for (int i = 0; i < middle - 1; i++) {
            node = node->next;
        }

        if (node->next != nullptr) {
            node->next = node->next->next;            
        }

        return head;
        */
    }
};

int main() { return 0; }
