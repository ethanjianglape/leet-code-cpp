// https://leetcode.com/problems/merge-k-sorted-lists/
// Difficulty: Hard
//
// You are given an array of k linked-lists `lists`, each linked-list is sorted
// in ascending order.
//
// Merge all the linked-lists into one sorted linked-list and return it.
//
// Example 1:
//   Input:  lists = [[1,4,5],[1,3,4],[2,6]]
//   Output: [1,1,2,3,4,4,5,6]
//   Explanation: The linked-lists are:
//     1->4->5
//     1->3->4
//     2->6
//   Merging them into one sorted list: 1->1->2->3->4->4->5->6
//
// Example 2:
//   Input:  lists = []
//   Output: []
//
// Example 3:
//   Input:  lists = [[]]
//   Output: []
//
// Constraints:
//   k == lists.length
//   0 <= k <= 10^4
//   0 <= lists[i].length <= 500
//   -10^4 <= lists[i][j] <= 10^4
//   lists[i] is sorted in ascending order
//   The sum of lists[i].length will not exceed 10^4

#include <queue>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }

        auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comp)> heap{comp};

        for (ListNode* list : lists) {
            if (list == nullptr) {
                continue;
            }

            heap.push(list);
        }

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (!heap.empty()) {
            ListNode* top = heap.top();

            if (head == nullptr) {
                head = new ListNode{top->val};
                tail = head;
            } else {
                ListNode* n = new ListNode{top->val};
                tail->next = n;
                tail = n;
            }

            heap.pop();

            if (top->next != nullptr) { 
                heap.push(top->next);
            }
        }

        return head;
    }
};

int main() { return 0; }
