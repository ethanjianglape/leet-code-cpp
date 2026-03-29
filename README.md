# LeetCode C++ Study Tool

A Claude Code-powered interview preparation workspace for solving LeetCode problems in C++23.

The goal is not memorization — it's **interview simulation**. Claude acts as a technical interviewer: engaging with your observations, probing edge cases, and letting you drive. If you need help, just ask directly.

## Requirements

- [Claude Code](https://github.com/anthropics/claude-code)
- CMake 3.25+
- A C++23 compiler (clang or gcc)

## Usage

### Add a new problem

Use the `/leetcode` slash command with a LeetCode problem URL:

```
/leetcode https://leetcode.com/problems/two-sum/description/
```

This will:
- Fetch the problem statement
- Create a solution stub at `solutions/<id>_<slug>.cpp`
- Print the problem so you can start without opening a browser

### Work through the problem

Claude will respond as a technical interviewer. Ask clarifying questions, voice your observations, and think out loud — that's the point. If you get stuck and want a hint or explanation, just ask Claude directly (not as the interviewer).

### Build

```bash
cmake -B build && cmake --build build
```

Each solution is compiled as its own executable. Testing is done on LeetCode directly.

## Structure

```
solutions/
  0001_two_sum.cpp
  0023_merge_k_sorted_lists.cpp
  ...
.claude/
  CLAUDE.md               # interviewer behavior instructions
  commands/leetcode.md    # /leetcode slash command definition
```
