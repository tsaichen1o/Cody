// 題目: Count Interesting Subarrays
// 類型: Prefix Sum, HashMap, Math
// 難度: Medium
// 解法:
// - 定義 prefix count：cnt，代表前面多少個元素符合 nums[i] % modulo == k。
// - 目標條件是 (cnt[i] - cnt[j]) % modulo == k，推導成 cnt[j] % modulo == (cnt[i] + modulo - k) % modulo。
// - 使用 hash map 統計每種 prefix mod 出現次數。
// - 每次統計時，加上符合條件的過去 prefix 數量。

class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            unordered_map<int, long long> mp;
            mp[0] = 1;
            
            long long ans = 0;
            int cnt = 0;
            
            for (int num : nums) {
                if (num % modulo == k) {
                    cnt++;
                }
                
                int need = (cnt + modulo - k) % modulo;
                if (mp.count(need)) {
                    ans += mp[need];
                }
                
                mp[cnt % modulo]++;
            }
            
            return ans;
        }
    };
    
