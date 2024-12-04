/**
 * @file [BFS]0733.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 733. Flood Fill
 * @version 0.1
 * @date 2024-12-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int num_rows = image.size();
        int num_cols = image[0].size();
        int original_color = image[sr][sc];
        
        // If the new color is the same as the original color, return the image as is.
        if (original_color == color) {
            return image;
        }
        
        // Initialize the queue for BFS with the starting point.
        std::queue<std::pair<int, int>> q;
        q.push({sr, sc});

        // Change the color of the starting point.
        image[sr][sc] = color;

        // Perform BFS to flood fill the area.
        while (!q.empty()) {
            std::pair<int, int> current = q.front();
            q.pop();

            // Get all the neighbors of the current cell.
            for (std::pair<int, int> neighbor : get_neighbors(current, num_rows, num_cols)) {
                int neighbor_row = neighbor.first;
                int neighbor_col = neighbor.second;

                // If the neighbor has the same color as the original, change it and add to queue.
                if (image[neighbor_row][neighbor_col] == original_color) {
                    image[neighbor_row][neighbor_col] = color;
                    q.push(neighbor);
                }
            }
        }

        return image;
    }

private:
    std::vector<std::pair<int, int>> get_neighbors(std::pair<int, int> coord, int num_rows, int num_cols) {
        int row = coord.first;
        int col = coord.second;
        int delta_row[4] = {-1, 0, 1, 0};
        int delta_col[4] = {0, 1, 0, -1};
        std::vector<std::pair<int, int>> res;
        for (int i = 0; i < 4; i++) {
            int neighbor_row = row + delta_row[i];
            int neighbor_col = col + delta_col[i];

            if (0 <= neighbor_row && neighbor_row < num_rows &&
                0 <= neighbor_col && neighbor_col < num_cols) {
                res.emplace_back(neighbor_row, neighbor_col);
            }
        }
        return res;
    }
};

// DFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int num_rows = image.size();
        int num_cols = image[0].size();
        int original_color = image[sr][sc];
        
        // If the new color is the same as the original color, return the image as is.
        if (original_color == color) {
            return image;
        }
        
        // Start the recursive DFS flood fill.
        dfs(image, sr, sc, original_color, color, num_rows, num_cols);
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int row, int col, int original_color, int new_color, int num_rows, int num_cols) {
        // If the current pixel is out of bounds or its color is not the original color, stop.
        if (row < 0 || row >= num_rows || col < 0 || col >= num_cols || image[row][col] != original_color) {
            return;
        }
        
        // Change the color of the current pixel.
        image[row][col] = new_color;
        
        // Recursively flood fill in all four directions.
        dfs(image, row - 1, col, original_color, new_color, num_rows, num_cols); // up
        dfs(image, row + 1, col, original_color, new_color, num_rows, num_cols); // down
        dfs(image, row, col - 1, original_color, new_color, num_rows, num_cols); // left
        dfs(image, row, col + 1, original_color, new_color, num_rows, num_cols); // right
    }
};
