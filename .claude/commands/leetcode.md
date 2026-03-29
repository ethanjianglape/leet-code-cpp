Fetch the LeetCode problem at the URL provided in $ARGUMENTS and set it up as a new solution file.

Steps:
1. Use WebFetch to retrieve the problem page at the given URL.
2. Parse out: problem number, title slug, difficulty, full problem description (including examples and constraints).
3. Derive the filename: zero-pad the number to 4 digits, slugify the title to snake_case, e.g. `solutions/0001_two_sum.cpp`.
4. Create the `.cpp` file with only:
   - A comment block at the top containing the problem URL, difficulty, and full problem statement (description, examples, constraints) — formatted readably
   - The standard LeetCode `Solution` class stub with the required method signature(s) left empty
   - A trivial `int main() { return 0; }` (no test framework)
5. Print the full problem statement to the conversation so the user can read it without opening a browser.
6. Do NOT suggest an approach or discuss the solution — just present the problem and ask whether the user wants to start on their own or talk through it first.
