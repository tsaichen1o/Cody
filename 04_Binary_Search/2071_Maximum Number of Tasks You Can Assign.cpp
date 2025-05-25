// 題目: Max Task Assign
// 類型: Binary Search, Greedy, Multiset
// 難度: Hard
// 解法:
// - 對最多能完成的任務數進行二分查找。
// - 每次檢查是否能完成 k 個任務：
//   - 取最強的 k 個工人（從 workers 最後 k 個）。
//   - 任務從最難的開始嘗試分配。
//   - 優先使用不吃藥也能完成的工人。
//   - 若無法，則嘗試給工人吃藥，看是否能完成。
//   - multiset 幫助我們快速查找 >= 或 <= 的工人。
// - 回傳能完成的最多任務數。

class Solution {
    public:
        // 檢查是否能完成 k 個任務
        bool canComplete(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            multiset<int> s(workers.end() - k, workers.end());  // 取最強 k 個工人
            int p = pills;
    
            for (int i = k - 1; i >= 0; --i) {  // 從最難的任務開始
                int task = tasks[i];
                auto it = s.lower_bound(task);  // 找不吃藥能完成任務的工人
                if (it != s.end()) {
                    s.erase(it);
                } else {
                    if (p == 0) return false;  // 沒藥了
                    it = s.lower_bound(task - strength);  // 吃藥後能完成的最弱工人
                    if (it == s.end()) return false;
                    s.erase(it);
                    --p;
                }
            }
            return true;
        }
    
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
    
            int l = 0, r = min((int)tasks.size(), (int)workers.size());
            int res = 0;
    
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (canComplete(mid, tasks, workers, pills, strength)) {
                    res = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
    
            return res;
        }
    };
    