/**
 * @file 20241123_1864.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1861. Rotating the Box
 * @version 0.1
 * @date 2024-11-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        // Let the stones fall to the bottom under gravity for each row
        for (int i = 0; i < m; ++i) {
            int emptySlot = n - 1;  // Position where the next stone should fall
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    // Obstacle resets the emptySlot position
                    emptySlot = j - 1;
                } else if (box[i][j] == '#') {
                    // Move stone to the next available slot
                    box[i][j] = '.';
                    box[i][emptySlot] = '#';
                    emptySlot--;
                }
            }
        }
        
        // Create the rotated box
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotatedBox[j][m - 1 - i] = box[i][j];
            }
        }

        return rotatedBox;
    }
};

/*
跟想的一樣先把石頭往下（右邊）掉，再轉90度。
*/
/*
Explanation:
Gravity Simulation:

Iterate through each row of the box.
For each row, start from the rightmost end (j = n - 1).
Use a variable emptySlot to track the position where the next stone should fall.
When encountering an obstacle ('*'), reset emptySlot to the left of the obstacle.
When encountering a stone ('#'), move it to the emptySlot position and decrement emptySlot.
Rotation:

After simulating gravity, create a new matrix rotatedBox with dimensions n x m.
Assign values from box to rotatedBox such that the box is effectively rotated 90 degrees clockwise.
*/