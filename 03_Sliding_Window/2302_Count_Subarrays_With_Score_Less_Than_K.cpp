// 題目: Count Subarrays with Score Less Than k
// 類型: Sliding Window, Two Pointers
// 難度: Medium
// 解法:
// - 使用 sliding window 維護一個合法的區間 [l, r]。
// - 當 (區間總和 × 區間長度) >= k 時，縮小左端點 l。
// - 對每個 r，能構成的合法子陣列數量是 (r - l + 1)。
// - 整體時間 O(n)，因為每個元素最多被處理兩次（進入、離開 window）。

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long ans = 0;
            long long sum = 0;
            int l = 0;
            
            for (int r = 0; r < nums.size(); ++r) {
                sum += nums[r];
                while (l <= r && sum * (r - l + 1) >= k) {
                    sum -= nums[l];
                    l++;
                }
                ans += (r - l + 1);
            }
            
            return ans;
        }
    };
    