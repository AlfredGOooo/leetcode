# Array Review

### LC27 Remove Element in Array

`solved` 	`easy`

- Conclusion
  - 1. when input an array, always check its size.
    2. when output a length of an array, always check if it is 0. If yes, might return at once.
  - `while` loop in the array: pay attention to **terminating condition**. Comparison of index / index & number. Carefully design the stopping condition, always challenge yourself and test it. Index will increase within the `while` loop.
- Other better solution `simple`
  - simiple, only 1 `for` loop.
  - only increase the counter when `ele != val`. Assign the *counter* pos in vector with *current index* pos , then increase the counter. 是一个小发现，小技巧。
- Bugs
  - Reference binding to null pointer of type 'int':  Manipulating the empty vector, should directly return 0.

