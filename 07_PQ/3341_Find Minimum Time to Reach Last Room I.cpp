class Cell {
public:
    int row;
    int col;
    int arrivalTime;
    Cell(int row, int col, int arrivalTime)
        : row(row), col(col), arrivalTime(arrivalTime) {}
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int INF = 0x3f3f3f3f;
        int rows = moveTime.size(), cols = moveTime[0].size();
        vector<vector<int>> minArrival(rows, vector<int>(cols, INF));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        minArrival[0][0] = 0;

        auto cmp = [](const Cell& a, const Cell& b) {
            return a.arrivalTime > b.arrivalTime;
        };

        priority_queue<Cell, vector<Cell>, decltype(cmp)> pq(cmp);
        pq.push(Cell(0, 0, 0));

        while (!pq.empty()) {
            Cell current = pq.top();
            pq.pop();

            int r = current.row, c = current.col;
            if (visited[r][c]) continue;
            visited[r][c] = true;

            for (int i = 0; i < 4; i++) {
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

                // 必須等待 moveTime[nr][nc] 開門，然後才能進去
                int nextTime = max(minArrival[r][c], moveTime[nr][nc]) + 1;
                if (minArrival[nr][nc] > nextTime) {
                    minArrival[nr][nc] = nextTime;
                    pq.push(Cell(nr, nc, nextTime));
                }
            }
        }

        return minArrival[rows - 1][cols - 1];
    }
};
