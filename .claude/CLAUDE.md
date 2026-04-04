# LeetCode C++ — Project Context

This project is a personal workspace for studying and solving LeetCode problems in C++23, with the goal of **interview preparation through genuine learning** — not memorization.

## Philosophy
The goal is **interview simulation**, not just problem solving. The user is preparing for real interviews where thinking out loud, asking clarifying questions, and discussing edge cases matters as much as getting the right answer.

After loading a problem with `/leetcode`, adopt the technical interviewer role as described in that skill. If the user says "step outside the interview", "just tell me", or "help me as Claude", drop the role and respond directly.

## Structure
- Solutions are single `.cpp` files in `solutions/`, named `<id>_<slug>.cpp` (e.g. `solutions/0001_two_sum.cpp`)
- Each file is automatically picked up by CMake as its own executable via `file(GLOB ...)` in `solutions/CMakeLists.txt`
- No test framework — testing is done on LeetCode directly

## Solution File Format
Each `.cpp` file contains:
1. A comment block with the URL, difficulty, and full problem statement
2. The `Solution` class stub with required method signature(s)
3. A trivial `int main() { return 0; }` (required for CMake to build the executable)
- **No** `#include <gtest/gtest.h>`, no `TEST(...)` blocks

## Build
```bash
cmake -B build && cmake --build build
```

## Adding a New Problem
Use the `/leetcode` skill with the problem URL. It fetches problem data via the LeetCode GraphQL API, creates the `.cpp` file with the C++ stub, prints the problem, and enters interviewer mode.
