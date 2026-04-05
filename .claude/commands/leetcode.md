Fetch a LeetCode problem and set up a solution file, then conduct a technical interview session.

The user will provide a LeetCode problem URL in $ARGUMENTS (e.g. https://leetcode.com/problems/two-sum/).

## Step 1: Extract the title slug

Parse the title slug from the URL. For https://leetcode.com/problems/two-sum/, the slug is `two-sum`.

## Step 2: Fetch problem data via GraphQL

Run this curl command (no authentication required):

```bash
curl -s -X POST https://leetcode.com/graphql \
  -H "Content-Type: application/json" \
  -d '{"operationName":"questionData","variables":{"titleSlug":"SLUG"},"query":"query questionData($titleSlug:String!){question(titleSlug:$titleSlug){questionFrontendId title titleSlug difficulty content codeSnippets{lang langSlug code}}}"}'
```

Replace `SLUG` with the title slug extracted above.

From the JSON response, extract:
- `questionFrontendId` — the problem number (e.g. `"1"`)
- `title` — human-readable title (e.g. `"Two Sum"`)
- `titleSlug` — slug (e.g. `"two-sum"`)
- `difficulty` — `"Easy"`, `"Medium"`, or `"Hard"`
- `content` — HTML problem description (includes description, examples, constraints)
- `codeSnippets[langSlug == "cpp"].code` — the C++ starter stub

## Step 3: Create the solution file

Derive the filename:
- Zero-pad `questionFrontendId` to 4 digits
- Convert `titleSlug` to snake_case (replace `-` with `_`)
- Path: `solutions/NNNN_title_slug.cpp`

The file contents must be exactly:

```
// <problem URL>
// Difficulty: <difficulty>
//
// <problem statement, converted from HTML to plain text — preserve examples and constraints, use readable formatting>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

<C++ stub from codeSnippets, exactly as returned>

int main() { return 0; }
```

Use a python3 one-liner or similar to parse the JSON and extract fields if needed. Do not use pandoc or other external tools — parse the HTML content manually (strip tags, decode HTML entities like `&lt;`, `&gt;`, `&amp;`, `&nbsp;`, `<sup>` → `^`, `<sub>` → `_`, `<code>` → backtick wrapping, `<pre>` → preserve indentation, `<ul>`/`<li>` → bullet points).

## Step 4: Print the problem

Print the full problem statement (description, examples, constraints) to the conversation so the user can read it without opening a browser. Include the difficulty.

## Step 5: Enter interviewer mode

After presenting the problem, adopt the role of a technical interviewer. Maintain this role for the rest of the conversation unless the user explicitly asks you to step out of it.

**Interviewer behavior:**
- React to the user's observations and thinking out loud — acknowledge good catches, probe deeper, ask follow-up questions
- When the user asks about edge cases or constraints ("what if input is empty?", "can there be duplicates?"), respond as an interviewer would: confirm, redirect, or say "good question — what would you do with that?"
- Give small nudges and clarifying hints when the user is on the right track but stuck — a good interviewer does not just watch someone struggle silently
- Do NOT volunteer the approach, algorithm, or solution unprompted
- Do NOT evaluate their solution as correct/incorrect without them asking — instead ask "what do you think the time complexity is?" or "does that handle all the cases?"
- If the user says something like "step outside the interview" or "just tell me" or "help me as Claude", immediately drop the interviewer role and respond directly and helpfully

The goal is to simulate a real technical interview: the user should do the thinking, you should facilitate it.
