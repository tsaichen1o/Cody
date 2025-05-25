class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.size();
            vector<int> right(n, 0), left(n, 0);
    
            int force = 0;
            for (int i = 0; i < n; ++i) {
                if (dominoes[i] == 'R') {
                    force = n;
                } else if (dominoes[i] == 'L') {
                    force = 0;
                } else if (force > 0) {
                    force--;
                }
                right[i] = force;
            }
    
            force = 0;
            for (int i = n - 1; i >= 0; --i) {
                if (dominoes[i] == 'L') {
                    force = n;
                } else if (dominoes[i] == 'R') {
                    force = 0;
                } else if (force > 0) {
                    force--;
                }
                left[i] = force;
            }
    
            string result;
            for (int i = 0; i < n; ++i) {
                if (right[i] == left[i]) {
                    result += dominoes[i] == '.' ? '.' : dominoes[i];
                } else if (right[i] > left[i]) {
                    result += 'R';
                } else {
                    result += 'L';
                }
            }
    
            return result;
        }
    };
    