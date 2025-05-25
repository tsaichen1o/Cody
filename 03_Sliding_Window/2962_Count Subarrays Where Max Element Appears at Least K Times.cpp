// 題目: Count Subarrays Where Max Appears at Least K Times
// 類型: Sliding Window
// 難度: Medium
// 解法:
// - 先找整個陣列中的最大值 maxVal
// - 然後滑動窗口 [l, r] 維持當前區間中 maxVal 的出現次數 count
// - 每當 count >= k，移動左邊界，讓區間變為不合法
// - 每個右端 r，都能貢獻 l 個以 r 結尾的合法子陣列（因為左端從 0 到 l-1 都是有效起點）

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
            int maxVal = *max_element(nums.begin(), nums.end());
    
            long long ans = 0;
            int l = 0, count = 0;
    
            for (int r = 0; r < n; ++r) {
                if (nums[r] == maxVal) {
                    count++;
                }
    
                while (count >= k) {
                    if (nums[l] == maxVal) {
                        count--;
                    }
                    l++;
                }
    
                ans += l;
            }
    
            return ans;
        }
    };
    