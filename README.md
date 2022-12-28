# LeetCode problems solutions

This repository contains my personal solutions to LeetCode problems.

The problems are solved in C++17. The solutions are not guaranteed to be the most efficient ones, but they are guaranteed to be correct.

The directory structure is as follows:

- `problems/` contains the individual solutions to each problem.
  - `XX-problem-name.cc` contains the solution to the problem #XX. For direct access to a problem's description, the following URL template can be used: `https://leetcode.com/problems/<problem-name>/`.
- `lib/` contains the libraries used by the solutions. These are mostly data structures, proposed by LeetCode to model the problems.

A `main.cc` file can be used test the solutions. It should be created in the root of this repository. An example of its content is the following:

```c++
#include <iostream>

// Here, include the solution to the problem you want to test.
#include "problems/XX-problem-name.cc"

int main() {
  Solution s;
  
  // Write the corresponding test cases here.

  return 0;
}
```
