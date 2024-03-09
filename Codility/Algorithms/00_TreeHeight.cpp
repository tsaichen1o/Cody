/**
 * @file 00_TreeHeight.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief https://app.codility.com/programmers/trainings/4/
 * @version 0.1
 * @date 2024-03-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <algorithm>

int solution(tree * T) {
    
    int leftHeight = 0, rightHeight = 0, maxHeight = 0;

    // height = 0
    if (!T) {
        return -1;
    }
    else {
        leftHeight = solution(T -> l);
        rightHeight = solution(T -> r);
        maxHeight = max(leftHeight, rightHeight) + 1;
        return maxHeight;
    }
}