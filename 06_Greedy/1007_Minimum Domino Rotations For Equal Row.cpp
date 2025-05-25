class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops[0], tops, bottoms);
        if (result != -1) return result;
        return check(bottoms[0], tops, bottoms);
    }

    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int rotateTop = 0, rotateBottom = 0;

        for (int i = 0; i < n; ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1;  // 無法讓這個數字出現在第 i 位
            } else if (tops[i] != target) {
                rotateTop++;  // 需要將 bottoms[i] 換上去
            } else if (bottoms[i] != target) {
                rotateBottom++;  // 需要將 tops[i] 換下去
            }
        }

        return min(rotateTop, rotateBottom);
    }
};
