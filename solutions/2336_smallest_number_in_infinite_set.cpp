// https://leetcode.com/problems/smallest-number-in-infinite-set/description/
// Difficulty: Medium
//
// You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].
//
// Implement the SmallestInfiniteSet class:
//   - SmallestInfiniteSet() Initializes the object to contain all positive integers.
//   - int popSmallest() Removes and returns the smallest integer in the infinite set.
//   - void addBack(int num) Adds a positive integer num back into the infinite set,
//     if it is not already in the infinite set.
//
// Example 1:
//   Input:
//     ["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest",
//      "addBack", "popSmallest", "popSmallest", "popSmallest"]
//     [[], [2], [], [], [], [1], [], [], []]
//   Output:
//     [null, null, 1, 2, 3, null, 1, 4, 5]
//   Explanation:
//     SmallestInfiniteSet obj = new SmallestInfiniteSet();
//     obj.addBack(2);    // 2 is already in the set, so no change is made.
//     obj.popSmallest(); // return 1, remove it from the set.
//     obj.popSmallest(); // return 2, remove it from the set.
//     obj.popSmallest(); // return 3, remove it from the set.
//     obj.addBack(1);    // 1 is added back to the set.
//     obj.popSmallest(); // return 1, since 1 was added back.
//     obj.popSmallest(); // return 4, remove it from the set.
//     obj.popSmallest(); // return 5, remove it from the set.
//
// Constraints:
//   - 1 <= num <= 1000
//   - At most 1000 calls will be made in total to popSmallest and addBack.

#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class SmallestInfiniteSet {
public:
    int frontier = 1;
    std::unordered_set<int> added;
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    
    SmallestInfiniteSet() {

    }

    int popSmallest() {
        if (!heap.empty() && heap.top() < frontier) {
            int ret = heap.top();
            heap.pop();
            added.erase(added.find(ret));
            return ret;
        }
        
        return frontier++;
    }

    void addBack(int num) {
        if (!added.contains(num) && num < frontier) {
            heap.push(num);
            added.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main() { return 0; }
