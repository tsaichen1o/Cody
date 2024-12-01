### Tips

Using `const + pass by reference` has several benefits:

1. **Avoiding Unnecessary Copies**: When passing large objects, using a reference prevents copying the entire object, which improves performance, especially for large containers like `vector` or `map`.

2. **Ensuring Parameters Are Not Modified**: `const` ensures that the passed parameter cannot be modified within the function, enhancing code safety and readability, making the function's intention more clear.

This approach helps boost performance while ensuring parameter safety and function purity.

---

`if` 和 `else if` 的差別在於條件的檢查順序：

1. **`if` 條件：** 當 `if` 條件為真時，程式會執行 `if` 中的代碼。若條件不成立，程式會繼續往下檢查。

2. **`else if` 條件：** 當 `if` 條件不成立時，程式會檢查下一個 `else if` 條件。若這個條件成立，則執行其內的代碼。如果有多個 `else if`，程式會一個接一個依序檢查。

3. **唯一執行：** 只有第一個條件成立的 `if` 或 `else if` 的代碼會執行，其餘條件不再檢查。

舉例：
```cpp
int x = 10;

if (x > 15) {
    // 不執行
} else if (x > 5) {
    // 執行這裡，因為 x > 5
} else {
    // 不執行，因為上面的 else if 條件成立了
}
```
當 `else if` 成立後，後續的條件都會被跳過。

---

`i++` and `++i` are both increment operators in C++, but they differ in when the increment takes place and how they are used:

1. **`i++` (Post-Increment)**: The value of `i` is used in the expression first, and then `i` is incremented. For example:
   ```cpp
   int i = 5;
   int j = i++;  // j is assigned 5, then i is incremented to 6
   ```

2. **`++i` (Pre-Increment)**: `i` is incremented first, and then the new value is used in the expression. For example:
   ```cpp
   int i = 5;
   int j = ++i;  // i is incremented to 6, then j is assigned 6
   ```

In practice, `++i` can be slightly more efficient than `i++` because post-increment requires a temporary copy of the original value to be made, especially with complex types.

---

Lambda 函式（Lambda Function），也稱為匿名函式（Anonymous Function），是一種未命名的短小函式，主要用於簡化代碼中的即時性操作。在 C++ 中，lambda 函式的語法如下：

```cpp
auto lambda = [](參數列表) -> 返回類型 {
    // 函式主體
};
```

例如，以下是一個 lambda 函式示範用於計算兩數相加：

```cpp
auto sum = [](int a, int b) -> int {
    return a + b;
};
int result = sum(3, 4); // result 為 7
```

Lambda 函式可以簡化代碼、避免重複定義函式，常見於 STL 算法中作為回呼函式（如 `sort` 的比較器）。

---

在記憶體中，**Stack Overflow** 是指程式在呼叫過多的函數或分配太多局部變數時，超過了預分配的堆疊空間，導致溢位。通常是由於無窮遞迴或過多的函數呼叫所引起的，這會使得程序崩潰。

**Array Overflow** 是指訪問陣列超出其宣告的邊界，這可能會造成未定義的行為或程序崩潰。這是由於訪問了記憶體中不應該被訪問的部分。

**大數 Overflow** 是指數值超出資料型別所能表示的最大值。例如，當一個 `int` 類型變數超過 32 位元整數的最大值時，結果會出現溢位並導致不正確的計算結果。

**Stack Overflow** 和 **Heap** 是電腦記憶體管理中不同的部分，但它們之間確實有某些間接的關聯：

1. **Stack** 和 **Heap** 都是記憶體區域，負責處理程式執行期間的動態記憶體分配。
  
2. **Stack Overflow** 發生在呼叫過多函數或創建過多局部變數時，超出了堆疊的限制。

3. **Heap** 則是用於手動分配記憶體（例如使用 `new` 或 `malloc`），如果程序不合理地分配太多記憶體，也可能導致缺乏記憶體（Heap Overflow），間接增加 Stack 的壓力。

它們各自管理不同的記憶體區域，錯誤的記憶體管理可能造成互相影響。

**Stack Overflow 和 Heap 的區別與圖示說明**：

### 圖示說明
1. **記憶體結構**：可以想像記憶體被分為幾個區域，主要分為**堆疊 (Stack)** 和 **堆積 (Heap)** 兩部分。
   - **Stack**：是一個自頂向下生長的記憶體區域，用來存放局部變數和函數呼叫資訊。當函數呼叫時，會往 Stack 中推入資料，當函數返回時，從 Stack 中彈出資料。
   - **Heap**：是一個較大的記憶體區域，主要用於動態分配記憶體。程式可以在 Heap 上創建並釋放物件，通常是自下而上增長的。

以下是簡單的圖示：

```
  高位址
  +-------------------------+
  |      Heap (堆積區)      |
  |  手動分配 (如 new, malloc) |
  |     -> 從下往上增長      |
  +-------------------------+
  |      Stack (堆疊區)      |
  |  自動分配 (局部變數)     |
  |     -> 從上往下增長      |
  +-------------------------+
  低位址
```

2. **Stack Overflow**：當呼叫過多的函數或遞迴次數過多，或創建過大的局部變數時，超過 Stack 的記憶體容量，會造成 **Stack Overflow**，通常會導致程式崩潰。

3. **Heap 和 Stack 的關聯**：
   - **Stack** 主要用來處理函數的呼叫和返回、局部變數的分配，所有的運行時框架在 Stack 中進行。
   - **Heap** 主要用於處理動態的記憶體分配，如 `new` 或 `malloc`，應用場景包括動態創建物件、儲存資料結構等。
   - 當程式在 Heap 中分配記憶體時，可能導致可用記憶體減少，最終導致 Stack 或 Heap 的空間不足，這種情況下，Stack 和 Heap 之間的間接競爭會相互影響。

### 與資料結構中的 Stack 和 Heap 的關聯：
- **資料結構中的 Stack**：是一種 **LIFO**（後進先出）結構，用於處理如函數呼叫的情境。這與記憶體管理中的 Stack 類似，用來保存函數的局部變數和返回地址。
  
- **資料結構中的 Heap**：通常是指 **優先隊列 (Priority Queue)**，它是基於堆排序的資料結構，允許在常數時間內找到最大或最小值。這與記憶體管理中的 Heap 不同，儘管它們名稱相同，但用途完全不同。

圖示中表現的記憶體結構與資料結構中的概念相似之處在於它們的處理方式，但 Stack 和 Heap 在記憶體管理中的作用和具體實現方式上有明顯差異。

---

## `[MS]` Monotonic Stack
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
## `[UF]` Union Find
## `[SS]` Substring / Subsequence
## `[HT]` Hash Table
## `[SD]` Sliding Window
## `[SS]` Substring / Subsequence
## `[BST]` Binary Search Tree
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
## `[BFS]` Breadth First Search
<b>DFS</b> is better at: finding nodes far away from the root
<b>BFS</b> is better for: finding nodes close/closest to the root

```cpp
    vector<vector<int>> level_order_traversal(Node<int>* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<Node<int>*> level;
        level.push(root);
        while (!level.empty()) {
            int n = level.size();
            vector<int> new_level;
            for (int i = 0; i < n; i++) {
                Node<int>* node = level.front();
                new_level.emplace_back(node->val);
                if (node->left) level.push(node->left);
                if (node->right) level.push(node->right);
                level.pop();
            }
            res.emplace_back(new_level);
        }
        return res;
    }
```
在這段 BFS 的演算法中，他是透過 `level.size()` 來確定每一層的節點數量，以此來確定 level 是否有增加。`queue<Node<int>*> level` 儲存了當前層的所有節點，每次進入 while 迴圈時，它代表一個新的 level。

- `int n = level.size();` 紀錄了當前層有多少節點。
- 然後在 for 迴圈中迭代 `n` 次，每次從佇列中取出節點並加入到 `new_level` 中。
- 處理完所有節點後，將 `new_level` 加入結果 `res`，表示完成了一層的遍歷。

這樣每次都確保了 BFS 在遍歷每一層時，都是逐層向下的。

```cpp
vector<vector<int>> zig_zag_traversal(Node<int>* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;
    queue<Node<int>*> level;
    level.push(root);
    bool left_to_right = true;
    while (!level.empty()) {
        int n = level.size();
        list<int> new_level;
        for (int i = 0; i < n; i++) {
            Node<int>* node = level.front();
            if (left_to_right) {
                new_level.emplace_back(node->val);
            } else {
                new_level.emplace_front(node->val);
            }
            if (node->left) level.push(node->left);
            if (node->right) level.push(node->right);
            level.pop();
        }
        res.emplace_back(new_level.begin(), new_level.end());
        left_to_right = !left_to_right; // flip flag
    }
    return res;
}
```
用圖示來解釋 `level.size()` 的變化：

假設我們有一棵二元樹，結構如下：

```
        1
       / \
      2   3
     / \   \
    4   5   6
```

在每次 while 迴圈中，佇列 `level` 的變化如下：

1. **初始**：`level` 中只有根節點 `1`。  
   - `level.size()` = 1
   - 新增節點 `2` 和 `3` 到 `level`，這是下一層的節點。
   - `res = [[1]]`

2. **第二層**：`level` 中包含節點 `2` 和 `3`。  
   - `level.size()` = 2
   - 新增節點 `4`、`5`（從節點 `2` 來的）和 `6`（從節點 `3` 來的）到 `level`，這是下一層的節點。
   - `res = [[1], [2, 3]]`

3. **第三層**：`level` 中包含節點 `4`、`5` 和 `6`。  
   - `level.size()` = 3
   - 這些節點都沒有子節點，所以 `level` 在處理完這一層後就變空。
   - `res = [[1], [2, 3], [4, 5, 6]]`

在每一層，`level.size()` 表示當前層節點的數量，而每次都會處理該層的所有節點，並將它們的子節點加入佇列中，代表下一層的節點。因此，`level.size()` 可以用來確認當前層的節點數目，也幫助我們確定何時結束一層的遍歷並進入下一層。

當遍歷某一層的節點時，每個節點的子節點都會被儲存在佇列中，這些子節點代表下一層的節點。這樣一來，當我們完成當前層的所有節點的遍歷後，佇列中就會擁有下一層的所有節點。我們再繼續處理這些節點，並重複這個過程。這樣的方式使得 BFS 可以層層深入地遍歷樹中的每個節點。

```cpp
vector<int> binary_tree_right_side_view(Node<int>* root) {
    // Correct the type for res from vector<vector<int>> to vector<int>
    vector<int> res;
    if (root == nullptr) return res;
    queue<Node<int>*> level;
    level.push(root);
    while (!level.empty()) {
        int n = level.size();
        // Only capture the rightmost node of this level
        for (int i = 0; i < n; i++) {
            Node<int>* node = level.front();
            // When i is equal to level size - 1, we're at the rightmost node
            if (i == n - 1) {
                res.push_back(node->val);
            }
            if (node->left) level.push(node->left);
            if (node->right) level.push(node->right);
            level.pop();
        }
    }
    return res;
}
```

這段程式碼是用來計算二元樹中每層的最右邊節點，從而得到樹的 "右視圖"。以下用圖示來說明這段程式碼如何工作。

假設有一個二元樹如下：

```
       1
     /   \
    2     3
     \   / \
      5 4   6
```

### 每層處理情況：
1. **初始狀態**：
   - `level` 佇列中包含根節點 `1`。
   - `res` 為空。

2. **第一層**：
   - `level` 佇列中只有節點 `1`。
   - `n = 1`，遍歷這一層節點。
     - `i = 0`，這是這一層的最後一個節點（也是唯一的節點），因此將 `1` 加入 `res`。
   - 新增節點 `1` 的左子節點 `2` 和右子節點 `3` 到佇列。

3. **第二層**：
   - `level` 佇列中有節點 `2` 和節點 `3`。
   - `n = 2`，遍歷這一層節點。
     - `i = 0`，節點為 `2`，但不是最右邊的節點。
     - `i = 1`，節點為 `3`，這是這一層的最右邊節點，因此將 `3` 加入 `res`。
   - 新增節點 `2` 的右子節點 `5` 到佇列。
   - 新增節點 `3` 的左子節點 `4` 和右子節點 `6` 到佇列。

4. **第三層**：
   - `level` 佇列中有節點 `5`、`4` 和節點 `6`。
   - `n = 3`，遍歷這一層節點。
     - `i = 0`，節點為 `5`，但不是最右邊的節點。
     - `i = 1`，節點為 `4`，但不是最右邊的節點。
     - `i = 2`，節點為 `6`，這是這一層的最右邊節點，因此將 `6` 加入 `res`。

### 最後結果：
- `res` 為 `[1, 3, 6]`，這是這棵樹的右視圖。

### 結論：
- 這段程式碼透過 BFS 層序遍歷二元樹，並在每一層只加入最右邊的節點。這樣就能夠得到二元樹的右視圖。

```cpp
int binary_tree_min_depth(Node<int>* root) {
    queue<Node<int>*> level;
    int depth = -1; // start from -1 because popping root will add 1 depth
    level.push(root);
    while (!level.empty()) {
        depth++;
        int n = level.size();
        for (int i = 0; i < n; i++) {
            Node<int>* node = level.front();
            if (node->left == nullptr && node->right == nullptr) {
                return depth; // found leaf node, early return
            }
            if (node->left) level.push(node->left);
            if (node->right) level.push(node->right);
            level.pop();
        }
    }
    return depth;
}
```
## `[PQ]` Priority Queue (Heap)
Priority Queue is an Abstract Data Type, and Heap is the concrete data structure we use to implement a priority queue.

`priority_queue` 是一個基於堆（heap）的資料結構，元素會根據優先級進行排序。

具體來說，`priority_queue` 預設使用的是**最大堆**，也就是說，每次取出元素時，總是優先取出當前最大的值。因此，可以說 `priority_queue` 是有排序過的，但它只保證堆頂元素是最大的，並不是所有元素都已經完全排好序。

如果需要 `priority_queue` 以**最小值優先**（最小堆）的方式工作，可以使用以下的方式：
```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;
```

這樣每次取出元素時，就會是當前最小的值。

C++ 中實作堆的常用方式之一就是使用 `priority_queue`。`priority_queue` 是基於標準庫中的堆（heap）操作的封裝，可以有效地用於管理一組需要排序並以優先級進行操作的元素。它的底層實現通常使用**二元堆**，這使得插入和取出最大/最小值的操作效率很高，均為 \( O(\log n) \) 時間複雜度。

For node i, its children are stored at `2i+1` and `2i+2`, and its parent is at `floor((i-1)/2)`. So instead of `node.left` we'd do `2*i+1`. (Note that if we are implementing a `k`-ary heap, then the childrens are at `ki+1` to `ki+k`, and its parent is at `floor((i-1)/k)`.)

此外，C++ 標準庫還提供了 `make_heap`、`push_heap`、`pop_heap` 等函數，它們可以直接作用於 `vector` 來進行堆的操作。這些函數也可以用來手動管理堆結構。

在 C++ 中，`queue` 類型不支援範圍 `for` 循環的直接迭代，因為 `queue` 是一個 FIFO（先進先出）容器，它沒有迭代器來遍歷內部的元素。所以你不能用 `for (const auto& item : queue)` 這種方式來進行遍歷。

你可以使用一個標準的 `while` 循環來手動訪問 `queue` 中的每一個元素，例如：

```cpp
queue<pair<int, int>> rottenOrangeSpots;

while (!rottenOrangeSpots.empty()) {
    auto rottenOrangeSpot = rottenOrangeSpots.front();
    cout << rottenOrangeSpot.first << ' ' << rottenOrangeSpot.second << endl;
    rottenOrangeSpots.pop();
}
```

這樣可以依次訪問每個元素並且從隊列中取出它。`queue` 中的元素只能通過 `front()` 和 `pop()` 的方式訪問和移除，而沒有像 `vector` 那樣的迭代器來遍歷整個容器。

## `[I]` Interval

