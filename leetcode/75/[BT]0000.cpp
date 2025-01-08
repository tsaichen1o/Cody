// 

#include <iostream>
#include <vector>

using namespace std;

// 定義方向 (上下左右)
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// 回溯函數，用來探索所有可能的模式
int backtrack(int r, int c, int R, int C, vector<vector<bool>>& visited, int steps) {
    int count = 1; // 計算目前的模式數量 (當前點也算一個模式)

    // 遍歷所有方向
    for (auto dir : directions) {
        int nr = r + dir.first; // 新的行
        int nc = c + dir.second; // 新的列

        // 檢查是否在範圍內且未被訪問
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc]) {
            visited[nr][nc] = true; // 標記為已訪問
            count += backtrack(nr, nc, R, C, visited, steps + 1); // 繼續探索
            visited[nr][nc] = false; // 回溯：取消標記
        }
    }

    return count; // 回傳當前模式的數量
}

int countPatterns(int R, int C) {
    int totalPatterns = 0;
    vector<vector<bool>> visited(R, vector<bool>(C, false)); // 記錄點是否已被訪問

    // 遍歷每個點作為起始點
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            visited[r][c] = true; // 標記起始點
            totalPatterns += backtrack(r, c, R, C, visited, 1); // 開始回溯
            visited[r][c] = false; // 回溯：取消起始點標記
        }
    }

    return totalPatterns;
}

int main() {
    int R = 2, C = 2; // 輸入 R 和 C
    cout << "Total patterns: " << countPatterns(R, C) << endl;
    return 0;
}


// 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 定義方向 (上下左右)
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// DFS + DP function
int dfs(int r, int c, int R, int C, int visited, vector<vector<bool>>& grid, unordered_map<int, unordered_map<int, int>>& dp) {
    // 如果所有點都已訪問，返回 1 (找到一種模式)
    if (visited == (1 << (R * C)) - 1) return 1;

    // 查詢動態規劃表
    if (dp[r * C + c].count(visited)) return dp[r * C + c][visited];

    int totalPatterns = 0;

    // 遍歷所有方向
    for (auto dir : directions) {
        int nr = r + dir.first;
        int nc = c + dir.second;

        // 檢查是否在範圍內且未訪問
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && !(visited & (1 << (nr * C + nc)))) {
            // 標記當前點為已訪問
            int newVisited = visited | (1 << (nr * C + nc));
            totalPatterns += dfs(nr, nc, R, C, newVisited, grid, dp);
        }
    }

    // 存入動態規劃表
    dp[r * C + c][visited] = totalPatterns;

    return totalPatterns;
}

int countPatterns(int R, int C) {
    vector<vector<bool>> grid(R, vector<bool>(C, false)); // 初始化網格
    unordered_map<int, unordered_map<int, int>> dp;      // 動態規劃表
    int totalPatterns = 0;

    // 遍歷每個點作為起始點
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            int visited = (1 << (r * C + c)); // 標記起始點為已訪問
            totalPatterns += dfs(r, c, R, C, visited, grid, dp); // 開始 DFS
        }
    }

    return totalPatterns;
}

int main() {
    int R = 2, C = 2; // 輸入 R 和 C
    cout << "Total patterns: " << countPatterns(R, C) << endl;
    return 0;
}
