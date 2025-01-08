/**
 * @file [BFS]1197.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1197. Minimum Knight Moves
 * @version 0.1
 * @date 2024-12-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <queue>
#include <unordered_set>

class Solution {
public:
    int minKnightMoves(int x, int y) {
        // Use BFS to explore all possible moves
        x = abs(x);
        y = abs(y); // Reduce problem to first quadrant since it is symmetric

        // Define possible knight moves
        vector<pair<int, int>> moves = {
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
        };

        // Define a queue to store current position and steps taken
        queue<pair<int, int>> q;
        q.push({0, 0});
        int steps = 0;

        // Use a set to keep track of visited nodes
        unordered_set<string> visited;
        visited.insert("0,0");

        // Perform BFS
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [current_x, current_y] = q.front();
                q.pop();

                // If we have reached the target
                if (current_x == x && current_y == y) {
                    return steps;
                }

                // Explore all possible knight moves
                for (auto move : moves) {
                    int new_x = current_x + move.first;
                    int new_y = current_y + move.second;

                    // Encode the new position to track if it has been visited
                    string pos = to_string(new_x) + "," + to_string(new_y);

                    if (visited.find(pos) == visited.end() && new_x >= -2 && new_y >= -2) {
                        q.push({new_x, new_y});
                        visited.insert(pos);
                    }
                }
            }
            steps++;
        }

        return -1; // Should never reach here since the answer is guaranteed to exist
    }
};

struct Coordinate {
    int r;
    int c;
    Coordinate(int r, int c) : r{r}, c{c} {}

    bool operator==(const Coordinate& coord) const noexcept {
        return r == coord.r && c == coord.c;
    }
};

template<>
struct std::hash<Coordinate> {
    std::size_t operator()(const Coordinate& coord) const noexcept {
        std::size_t r_hash = std::hash<int>{}(coord.r);
        std::size_t c_hash = std::hash<int>{}(coord.c);
        return r_hash ^ c_hash;
    }
};

std::vector<Coordinate> get_neighbors(Coordinate coord) {
    std::vector<Coordinate> neighbors;
    std::array<int, 8> delta_row{-2, -2, -1, 1, 2, 2, 1, -1};
    std::array<int, 8> delta_col{-1, 1, 2, 2, 1, -1, -2, -2};
    for (int i = 0; i < delta_row.size(); i++) {
        int neighbor_row = coord.r + delta_row[i];
        int neighbor_col = coord.c + delta_col[i];
        neighbors.emplace_back(neighbor_row, neighbor_col);
    }
    return neighbors;
}

int bfs(Coordinate start, int x, int y) {
    std::unordered_set<Coordinate> visited{{start}};
    int steps = 0;
    std::deque<Coordinate> q{{start}};
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Coordinate node = q.front();
            q.pop_front();
            if (node.c == x && node.r == y) return steps;
            std::vector<Coordinate> neighbors = get_neighbors(node);
            for (Coordinate neighbor : neighbors) {
                if (visited.count(neighbor)) continue;
                q.emplace_back(neighbor);
                visited.emplace(neighbor);
            }
        }
        steps++;
    }
    return steps;
}

int get_knight_shortest_path(int x, int y) {
    return bfs({0, 0}, x, y);
}

// Time Complexity: O(8 * |x - 0| * |y - 0|) = O(|x| * |y|)
// Space Complexity: O(|x| * |y|)