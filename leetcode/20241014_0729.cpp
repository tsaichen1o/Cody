/**
 * @file 20241014_0729.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 729. My Calendar I
 * @version 0.1
 * @date 2024-10-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        int left = 0, right = calendar.size() - 1, idx = calendar.size();
        
        // Perform binary search to find the insertion index `idx`
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (calendar[mid].first > start) {
                idx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // Check for overlap with the interval at `idx-1` and `idx`
        if ((idx > 0 && calendar[idx - 1].second > start) || 
            (idx < calendar.size() && calendar[idx].first < end)) {
            return false;
        }
        
        // Insert the new event at position `idx`
        calendar.insert(calendar.begin() + idx, {start, end});
        return true;
    }

private:
    std::vector<std::pair<int, int>> calendar;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
