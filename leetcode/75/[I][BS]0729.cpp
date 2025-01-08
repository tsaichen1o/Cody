/**
 * @file [I]0729.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 729. My Calendar I
 * @version 0.1
 * @date 2024-11-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class MyCalendar {
public:
    // Initialize the calendar as an empty vector of pairs
    vector<pair<int, int>> bookings;

    MyCalendar() {}
    
    bool book(int start, int end) {
        // Iterate through all the existing bookings
        for (const auto& booking : bookings) {
            // Check if the new booking overlaps with any existing booking
            if (max(start, booking.first) < min(end, booking.second)) {
                return false; // Overlapping interval found, return false
            }
        }
        // If no overlaps, add the new booking to the calendar and return true
        bookings.emplace_back(start, end);
        return true;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Binary search
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

// Time Complexity: O(n)
// Space Complexity: O(n)