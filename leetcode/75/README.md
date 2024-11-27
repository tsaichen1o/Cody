### Tips
Using `const + pass by reference` has several benefits:

1. **Avoiding Unnecessary Copies**: When passing large objects, using a reference prevents copying the entire object, which improves performance, especially for large containers like `vector` or `map`.

2. **Ensuring Parameters Are Not Modified**: `const` ensures that the passed parameter cannot be modified within the function, enhancing code safety and readability, making the function's intention more clear.

This approach helps boost performance while ensuring parameter safety and function purity.

### Name Abbreviation
##### `[MS]` Monotonic Stack
  This method is effective when you need to determine the next larger or smaller member for each element in a list, as it can naturally be determined when you insert element into the stack in order.
  If there are other restrictions, such as the next larger/smaller member must be within a certain distance, then we can use a deque instead, and pop from the end of the deque when the range is exceeded.
  ```cpp
    void mono_stack(vector<int> insert_entries) {
        vector<int> stack;
        for (int entry : insert_entries) {
            // The monotonic property can only break if and only if the container
            // is not empty and the last item, compared to the entry, breaks
            // the property. While that is true, we pop the top item.
            while (!stack.empty() && stack.back() <= entry) {
                // Do something with the top item in stack here
                stack.pop_back();
            }
            stack.push_back(entry);
        }
    }
  ```
##### `[UF]` Union Find
##### `[SS]` Substring / Subsequence
##### `[HT]` Hash Table
##### `[SD]` Sliding Window
##### `[SS]` Substring / Subsequence
##### `[BST]` Binary Search Tree
```cpp
  template <typename T>
  struct Node {
      T val;
      Node<T>* left;
      Node<T>* right;

      explicit Node(T val, Node<T>* left = nullptr, Node<T>* right = nullptr)
          : val{val}, left{left}, right{right} {}

      ~Node() {
          delete left;
          delete right;
      }
  };

  bool find(Node<int>* tree, int val) {
      if (tree == nullptr) return false;
      if (tree->val == val) return true;
      else if (tree->val < val) return find(tree->right, val);
      else {
          return find(tree->left, val);
      }
  }

  Node<int>* insert(Node<int>* tree, int val) {
      if (tree == nullptr) return new Node<int>(val);
      if (tree->val < val) {
          tree->right = insert(tree->right, val);
      } else if (tree->val > val) {
          tree->left = insert(tree->left, val);
      }
      return tree;
  }
```
If we insert each item from an already sorted list into the binary tree, it is going to form a linked list, and the time complexity of each operation becomes `O(n)`.

Time Complexity: `O(h)` where `h` is the height of the tree, but in the worst case `h` is in `O(n)`.

Space Complexity: `O(h)` stack memory which is `O(n)` in the worst case.

```cpp
  int lca_on_bst(Node<int>* bst, int p, int q) {
      if (p < bst->val && q < bst->val) {
          return lca_on_bst(bst->left, p, q);
      } else if (p > bst->val && q > bst->val) {
          return lca_on_bst(bst->right, p, q);
      } else {
          return bst->val;
      }
  }
```


