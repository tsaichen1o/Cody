/**
 * @file [PQ]2402.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2402. Meeting Rooms III
 * @version 0.1
 * @date 2024-11-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings based on their start times
        sort(meetings.begin(), meetings.end());

        // Priority queues to manage room allocation
        priority_queue<int, vector<int>, greater<int>> availableRooms; // Rooms available
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> ongoingMeetings; // Rooms occupied with their end times

        vector<int> roomUsage(n, 0); // Track how many meetings each room holds

        // Initialize all rooms as available
        for (int i = 0; i < n; ++i) {
            availableRooms.push(i);
        }

        // Iterate through each meeting
        for (const auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];

            // Free up rooms that have completed their meetings
            while (!ongoingMeetings.empty() && ongoingMeetings.top().first <= start) {
                availableRooms.push(ongoingMeetings.top().second);
                ongoingMeetings.pop();
            }

            if (!availableRooms.empty()) {
                // If there's an available room, assign it
                int room = availableRooms.top();
                availableRooms.pop();
                roomUsage[room]++;
                ongoingMeetings.push({end, room});
            } else {
                // No room is currently available, delay the meeting
                auto currentMeeting = ongoingMeetings.top();
                ongoingMeetings.pop();
                int room = currentMeeting.second;
                long long newEndTime = currentMeeting.first + (end - start);
                roomUsage[room]++;
                ongoingMeetings.push({newEndTime, room});
            }
        }

        // Find the room that has been booked the most
        int mostBookedRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (roomUsage[i] > roomUsage[mostBookedRoom]) {
                mostBookedRoom = i;
            }
        }

        return mostBookedRoom;
    }
};
