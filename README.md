# Cody

### Sort
```cpp
vector<int> nums{ 40, 100, 1, 5, 25, 10 };
// sort nums in ascending order
sort(nums.begin(), nums.end());    // nums = { 1, 5, 10, 25, 40, 100 }
// sort nums in descending order with standard library compare function
sort(nums.begin(), nums.end(), greater<int>());    // nums = { 100, 40, 25, 10, 5, 1 }
// sort nums in descending order with lambda expression
sort(nums.begin(), nums.end(), [](int a, int b) {      // nums = { 100, 40, 25, 10, 5, 1 }
      return a > b;
});
```

### Vector
vec.erase(vec.begin() + index);

// Deletes the second through third elements (vec[1], vec[2])
```cpp
vec.erase(next(vec.begin(), 1), next(vec.begin(), 3));
```

// Vector find
```cpp
#include <algorithm>
#include <vector>
if ( find(vec.begin(), vec.end(), item) != vec.end() )
   do_this();
else
   do_that();
```

### Map
```cpp
#include <iostream>
#include <map>

int main (void) {
    map<char,char> mymap;
    map<char,char>::iterator it;

    mymap['a'] = 'A'; mymap['b'] = 'B'; mymap['c'] = 'C';
    mymap['d'] = 'D'; mymap['e'] = 'E'; mymap['f'] = 'F';
    mymap['g'] = 'G'; mymap['h'] = 'H'; mymap['i'] = 'I';

    it = mymap.find ('b');             // by iterator (b), leaves acdefghi.
    mymap.erase (it);

    it = mymap.find ('e');             // by range (e-i), leaves acd.
    mymap.erase (it, mymap.end());

    mymap.erase ('a');                 // by key (a), leaves cd.

    mymap.erase ('z');                 // invalid key (none), leaves cd.

    for (it = mymap.begin(); it != mymap.end(); it++)
        cout << (*it).first << " => " << (*it).second << '\n';

    return 0;
}
```

### Binary search
##### When you feel a sense of monotonicity...
```cpp
int binary_search(vector<int>& arr, int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        }
    }
    
    return -1;
}
```

```cpp
int binary_search(vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) { // <= here because left and right could point to the same element, < would miss it
        int mid = left + (right - left) / 2; // use `(right - left) / 2` to prevent `left + right` potential overflow
        // left + floor((right-left) / 2)
        // found target, return its index
        if (arr.at(mid) == target) return mid;
        if (arr.at(mid) < target) {
            // middle less than target, discard left half by making left search boundary `mid + 1`
            left = mid + 1;
        } else {
            // middle greater than target, discard right half by making right search boundary `mid - 1`
            right = mid - 1;
        }
    }
    return -1; // if we get here we didn't hit above return so we didn't find target
}
```

* Find the first true
    ```cpp
    int find_boundary(vector<bool> arr) {
        int left = 0;
        int right = arr.size() - 1;
        int boundary_index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr.at(mid)) {
                boundary_index = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return boundary_index;
    }
    ```
We keep a variable boundary_index that represents the currently recorded leftmost true's index. If the current element is true, then we update boundary_index with its index and discard everything to the right including the current element itself since its index has been recorded by the variable.

##### Let the problem be Feasible or not to solve
```cpp
    int binary_search(vector<int> arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        int firstTrueIndex = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (feasible(mid)) {
                firstTrueIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return firstTrueIndex;
    }
```

舉例：
* <b> First Element Not Smaller Than Target </b>
  * `feasible = (arr[mid] >= target)`
  * Time Complexity: \( O(log(n)) \)
  * Space Complexity: \( O(1) \)
* <b> Find Element in Sorted Array with Duplicates </b>
  * `feasible = (arr[mid] == target)`
* <b> Square Root Estimation </b>

```cpp
    int square_root(int n) {
        if (n == 0) return 0;
        int left = 1;
        int right = n;
        int res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == n / mid) {
                return mid;
            } else if (mid * mid > n) {
                right = mid - 1;
                res = mid;
            } else {
                left = mid + 1;
            }
        }
        return res - 1;
    }
```
  If there is no element in the array whose square equals n, then we want to return the largest element that is smaller than the square root of n. In this case, we are actually looking for the last false. We can subtract 1 from the index after we find the first true from binary search.

沒有 sorted，舉例：
* Find Minimum in Rotated Sorted Array
  ```cpp
    int find_min_rotated(vector<int> arr) {
        int left = 0;
        int right = arr.size() - 1;
        int boundary_index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // if arr[mid] <= last element, then it belongs to the lower half
            if (arr[mid] <= arr[arr.size() - 1]) {
                boundary_index = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return boundary_index;
    }
    ```
* The Peak of a Mountain Array
  ```cpp
    int peak_of_mountain_array(vector<int> arr) {
        int alen = arr.size();
        int left = 0;
        int right = alen - 1;
        int boundary_index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                boundary_index = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return boundary_index;
    }
    ```
* <b> Minimum Largest Sum: Newspapers </b>
  
  ```cpp
  bool feasible(vector<int>& newspapers_read_times, int num_coworkers, int limit) {
    // time to keep track of the current worker's time spent, num_workers to keep track of the number of coworkers used
    int time = 0;
    int num_workers = 0;
    for (int read_time : newspapers_read_times) {
        // check if current time exceeds the given time limit
        if (time + read_time > limit) {
            time = 0;
            num_workers++;
        }
        time += read_time;
    }
    // edge case to check if we needed an extra worker at the end
    if (time != 0) {
        num_workers++;
    }
    // check if the number of workers we need is more than what we have
    return num_workers <= num_coworkers;
    }

    int newspapers_split(vector<int>& newspapers_read_times, int num_coworkers) {
        int low = *max_element(newspapers_read_times.begin(), newspapers_read_times.end());
        int high = accumulate(newspapers_read_times.begin(), newspapers_read_times.end(), 0);
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (feasible(newspapers_read_times, num_coworkers, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
  ```

* <b>Find target index</b>
    Example 1:

    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

    Example 2:

    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]

  ```cpp
  def searchRange(self, nums, target):
    left, right = 0, len(nums)-1
    first_pos, last_pos = -1, -1
    
    # find first pos
    while left <= right:
      mid = (left + right) // 2
      if nums[mid] == target:
          first_pos = mid
          right = mid - 1
      elif nums[mid] > target:
          right = mid - 1
      else:
          left = mid + 1
    
    #find last pos
    left, right = 0, len(nums)-1
    while left <= right:
      mid = (left + right) // 2
      if nums[mid] == target:
          last_pos = mid
          left = mid+1
      elif nums[mid] > target:
          right = mid - 1
      else:
          left = mid + 1
    return (first_pos, last_pos)
  ```

### Trees
##### Binary Tree
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
```

##### Build Tree
```cpp
template<typename T>
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

// this function builds a tree from input
// learn more about how trees are encoded in https://algo.monster/problems/serializing_tree
template<typename T, typename Iter, typename F>
Node<T>* build_tree(Iter& it, F f) {
    string val = *it;
    ++it;
    if (val == "x") return nullptr;
    Node<T>* left = build_tree<T>(it, f);
    Node<T>* right = build_tree<T>(it, f);
    return new Node<T>{f(val), left, right};
}

template<typename T>
vector<T> get_words() {
    string line;
    getline(cin, line);
    istringstream ss{line};
    ss >> boolalpha;
    vector<T> v;
    copy(istream_iterator<T>{ss}, istream_iterator<T>{}, back_inserter(v));
    return v;
}

int main() {
    vector<string> root_vec = get_words<string>();
    auto root_it = root_vec.begin();
    Node<int>* root = build_tree<int>(root_it, [](auto s) { return stoi(s); });
    in_order_traversal(root);
}


```

##### In-order Traversal
```cpp
template<typename T>
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

void in_order_traversal(Node<int>* root) {
    if (root != nullptr) {
        in_order_traversal(root->left);
        cout << root->val << '\n';
        in_order_traversal(root->right);
    }
}
```
`Input: 1 2 4 x x 5 x x 3 6 x x 7 x x`
`Outpu: 4 2 5 1 6 3 7`


##### Pre-order Traversal
It is just the DFS :)
```cpp
void pre_order_traversal(Node<int>* root) {
    if (root != nullptr) {
        cout << root->val << '\n';
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}
```

`Input: 1 2 4 x x 5 x x 3 6 x x 7 x x`
`Outpu: 1 2 4 5 3 6 7`

##### Post-order Traversal
```cpp
void post_order_traversal(Node<int>* root) {
    if (root != nullptr) {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        cout << root->val << '\n';
    }
}
```

`Input: 1 2 4 x x 5 x x 3 6 x x 7 x x`
`Outpu: 4 5 2 6 7 3 1`

### Depth First Search

```cpp
void dfs(int node) {
    // Base case, or end condition
    if (condition_met) {
        return;
    }

    // Mark the node as visited if needed
    visited[node] = true;

    // Explore all possible children or adjacent nodes
    for (auto nextNode : getNeighbors(node)) {
        if (!visited[nextNode]) {
            dfs(nextNode);
        }
    }

    // Backtracking step if required
    // visited[node] = false;
}

```
```cpp
Node<int>* dfs(Node<int>* root, int target) {
    if (root == nullptr) return nullptr;
    if (root->val == target) return root;
    // return non-null return value from the recursive calls
    Node<int>* left = dfs(root->left, target);
    if (left != nullptr) return left;
    // at this point, we know left is null, and right could be null or non-null
    // we return right child's recursive call result directly because
    // - if it's non-null we should return it
    // - if it's null, then both left and right are null, we want to return null
    return dfs(root->right, target);
}
```
The key to solving tree problems using DFS is to think from the perspective of a node instead of looking at the whole tree. 

When you are a node, the only things you know are 1) your value and 2) how to get to your children. So the recursive function you write manipulates these things.

* Pretty-print
  ```cpp
    #include <iostream>
    #include <string>

    const string indent_per_level = "  ";

    struct TreeNode {
        string val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(string x) : val(x), left(nullptr), right(nullptr) {}
    };

    void dfs(TreeNode* node, const string& indent_level = "") {
        if (node == nullptr) {
            return;
        }
        
        string current_indent_level = indent_level + indent_per_level;
        cout << current_indent_level << node->val << endl;
        
        dfs(node->left, current_indent_level);
        dfs(node->right, current_indent_level);
    }

    int main() {
        // Sample tree for testing
        TreeNode* root = new TreeNode("/");
        root->left = new TreeNode("foo");
        root->right = new TreeNode("bar");
        root->left->left = new TreeNode("baz");

        dfs(root);
        
        // Free the allocated memory
        delete root->left->left;
        delete root->left;
        delete root->right;
        delete root;

        return 0;
    }
  ```
* Return the max value
  ```cpp
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return INT_MIN; // equivalent to MIN_VALUE
        }

        int left_max_val = dfs(node->left);
        int right_max_val = dfs(node->right);

        return max({node->val, left_max_val, right_max_val});
    }
  ```
  ```cpp
    // Global variable to record the current max value
    // Initialize to minimum value possible so any node value will be larger
    int max_val = INT_MIN;

    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        // Update the global variable if the current value is larger
        if (node->val > max_val) {
            max_val = node->val;
        }

        // Recurse
        dfs(node->left);
        dfs(node->right);
    }

    int get_max_val(TreeNode* root) {
        max_val = INT_MIN; // reset max_val for each new call to avoid interference
        dfs(root); // Start DFS from the root node
        return max_val;
    }
    ```
* Tree max depth
    ```cpp
    int dfs(Node<int>* root) {
        // Null node adds no depth
        if (root == nullptr) return 0;
        // num nodes in longest path of current subtree = max num nodes of its two subtrees + 1 current node
        return max(dfs(root->left), dfs(root->right)) + 1;
    }

    int tree_max_depth(Node<int>* root) {
        return root ? dfs(root) - 1 : 0;
    }
    ```
* Visible Tree Node

    ```cpp
    int dfs(Node<int>* root, int max_sofar) {
        if (!root) return 0;
        int total = 0;
        if (root->val >= max_sofar) total++;
        total += dfs(root->left, max(max_sofar, root->val));
        total += dfs(root->right, max(max_sofar, root->val));
        return total;
    }

    int visible_tree_node(Node<int>* root) {
        // start max_sofar with smallest number possible so any value root has is greater than it
        return dfs(root, numeric_limits<int>::min());
    }
    ```

* Balanced Binary Tree
    ```cpp
    // Returns the height of the binary tree or -1 if it is not a balanced binary tree
    int tree_height(Node<int>* tree) {
        if (tree == nullptr) return 0;
        int left_height = tree_height(tree->left);
        int right_height = tree_height(tree->right);
        if (left_height == -1 || right_height == -1) return -1;
        if (abs(left_height - right_height) > 1) return -1;
        return max(left_height, right_height) + 1;
    }

    bool is_balanced(Node<int>* tree) {
        return tree_height(tree) != -1;
    }
    ```
這段程式碼的主要目的是判斷給定的二元樹是否為**平衡二元樹**。平衡二元樹的定義是：對於樹中的每個節點，其左子樹和右子樹的高度差不超過 1。

### 運行步驟解釋與圖像化

1. **遞迴計算高度**：`tree_height` 函數是遞迴計算子樹的高度的函數，並檢查平衡條件。
    - 如果當前節點是空指針 (`nullptr`)，則高度為 0，表示葉節點。
    - 分別遞迴計算左子樹和右子樹的高度。
    - 檢查高度差是否大於 1，如果是，則返回 `-1` 表示該子樹不平衡。
    - 若符合平衡條件，則返回子樹的高度（左右子樹高度的最大值 + 1）。

2. **判斷平衡**：`is_balanced` 函數利用 `tree_height` 來檢查整棵樹的平衡性。
    - 若 `tree_height` 返回值不等於 -1，則表示樹是平衡的，返回 `true`。
    - 若返回值為 -1，則表示樹不平衡，返回 `false`。

### 圖像化

考慮一棵樹的範例：

```
        1
       / \
      2   3
     / \
    4   5
```

每個節點的高度計算如下：

- 節點 `4` 和 `5` 沒有子節點，`tree_height` 返回高度 `1`。
- 節點 `2` 的左、右子樹高度皆為 `1`，因此其高度為 `2`。
- 節點 `3` 沒有子節點，`tree_height` 返回高度 `1`。
- 根節點 `1` 的左子樹高度為 `2`，右子樹高度為 `1`，高度差為 `1`，符合平衡條件，因此返回高度為 `3`。

### 邊界情況

考慮不平衡的情況：

```
        1
       /
      2
     /
    3
```

- 節點 `3` 沒有子節點，返回高度 `1`。
- 節點 `2` 左子樹高度為 `1`，右子樹為 `0`，返回高度 `2`。
- 根節點 `1` 的左子樹高度為 `2`，右子樹為 `0`，高度差為 `2`，因此 `tree_height` 返回 `-1`，表示不平衡。

### 小結

此算法效率高，因為它在遞迴過程中同時計算高度並檢查平衡性，一旦發現不平衡，就立即停止後續計算，節省時間。

* Subtree of Another Tree
    ```cpp
    bool is_same_tree(Node<int>* tree1, Node<int>* tree2) {
        if (!tree1 && !tree2) return true;
        if (!tree1 || !tree2) return false;
        return tree1->val == tree2->val &&
                is_same_tree(tree1->left, tree2->left) &&
                is_same_tree(tree1->right, tree2->right);
    }

    bool subtree_of_another_tree(Node<int>* root, Node<int>* sub_root) {
        if (!root) return false;
        return is_same_tree(root, sub_root) || subtree_of_another_tree(root->left, sub_root) || subtree_of_another_tree(root->right, sub_root);
    }
    ```
This approach has a time complexity of \( O(m * n) \), where m is the number of nodes in root and n is the number of nodes in subRoot. In the worst case, we might need to compare subRoot with every subtree of root.

The space complexity is \( O(m + n) \) due to the recursive call stack. There are m recursive calls in the worst case for root and n recursive calls for subRoot.

* Invert Binary Tree
    ```cpp
    Node<int>* invert_binary_tree(Node<int>* tree) {
        if (tree == nullptr) return nullptr;
        return new Node<int>(tree->val, invert_binary_tree(tree->right), invert_binary_tree(tree->left));
    }
    ```

* Reconstruct Binary Tree from Preorder and Inorder Traversal
    ```cpp
    Node<int>* build_tree_recursive(std::vector<int>& preorder, std::unordered_map<int, int>& valueToIndex, int preStart, int inStart, int size) {
        if (size <= 0) return nullptr;

        int rootValue = preorder[preStart];
        int inorderIndex = valueToIndex[rootValue];
        int leftSize = inorderIndex - inStart;

        Node<int>* left = build_tree_recursive(preorder, valueToIndex, preStart + 1, inStart, leftSize);
        Node<int>* right = build_tree_recursive(preorder, valueToIndex, preStart + 1 + leftSize, inorderIndex + 1, size - 1 - leftSize);

        return new Node<int>(rootValue, left, right);
    }

    Node<int>* construct_binary_tree(std::vector<int>& preorder, std::vector<int>& inorder) {
        std::unordered_map<int, int> valueToIndex;
        for (int i = 0; i < inorder.size(); ++i) {
            valueToIndex[inorder[i]] = i;
        }

        return build_tree_recursive(preorder, valueToIndex, 0, 0, preorder.size());
    }
    ```