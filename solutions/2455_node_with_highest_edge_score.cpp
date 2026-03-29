// URL: https://leetcode.com/problems/node-with-highest-edge-score/description/
// Difficulty: Medium
//
// ============================================================
// 2455. Node With Highest Edge Score
// ============================================================
//
// You are given a directed graph with n nodes labeled from 0 to n - 1, where
// each node has exactly one outgoing edge.
//
// The graph is represented by a 0-indexed integer array edges of length n,
// where edges[i] indicates that there is a directed edge from node i to
// node edges[i].
//
// The edge score of a node i is defined as the sum of the labels of all nodes
// that have an edge pointing to i.
//
// Return the node with the highest edge score. If multiple nodes have the same
// edge score, return the node with the smallest index.
//
// Example 1:
//   Input:  edges = [1,0,0,0,0,7,7,5]
//   Output: 7
//   Explanation:
//     Node 0: score = 1+2+3+4 = 10  (nodes 1,2,3,4 point to it)
//     Node 1: score = 0              (node 0 points to it)
//     Node 5: score = 7              (node 7 points to it)
//     Node 7: score = 5+6 = 11       (nodes 5,6 point to it)
//     Node 7 has the highest score.
//
// Example 2:
//   Input:  edges = [2,0,0,2]
//   Output: 0
//   Explanation:
//     Node 0: score = 1+2 = 3  (nodes 1,2 point to it)
//     Node 2: score = 0+3 = 3  (nodes 0,3 point to it)
//     Tied — return the smaller index: 0.
//
// Constraints:
//   - n == edges.length
//   - 2 <= n <= 10^5
//   - 0 <= edges[i] < n
//   - edges[i] != i
// ============================================================

#include <algorithm>
#include <cstdint>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int edgeScore(std::vector<int>& edges) {
        std::unordered_map<int, std::uint64_t> countByNode{};

        for (int node = 0; node < edges.size(); node++) {
            countByNode[edges[node]] += node;
        }

        bool highestSet = false;
        std::pair<int, std::uint64_t> highest;
        std::vector<int> ties;

        for (std::pair<int, std::uint64_t> pair : countByNode) {
            if (!highestSet || pair.second > highest.second) {
                highest = pair;
                highestSet = true;
            }
        }

        for (auto [node, count] : countByNode) {
            if (count == highest.second) {
                ties.push_back(node);
            }
        }

        std::ranges::sort(ties, std::less{});

        return ties[0];
    }
};

int main() { return 0; }
