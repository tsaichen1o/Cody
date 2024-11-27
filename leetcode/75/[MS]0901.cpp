/**
 * @file [MS]0901.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 901. Online Stock Span
 * @version 0.1
 * @date 2024-11-25
 * https://leetcode.com/problems/online-stock-span
 * @copyright Copyright (c) 2024
 * 
 */

class StockSpanner {
public:
    // Stack to keep track of pairs (price, span).
    stack<pair<int, int>> st;

    StockSpanner() {
        // No initialization needed as stack is default empty.
    }

    int next(int price) {
        int span = 1; // Start with a span of 1 for the current day.

        // While the stack is not empty and the top price is less than or equal to the current price,
        // we pop the stack and add its span to the current span.
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push the current price and its span onto the stack.
        st.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
