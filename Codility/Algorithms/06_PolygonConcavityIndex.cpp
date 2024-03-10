/**
 * @file 06_PolygonConcavityIndex.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief https://github.com/Anfany/Codility-Lessons-By-Python3/blob/master/L99_Future%20training/99.5%20PolygonConcavityIndex.md
 * @version 0.1
 * @date 2024-03-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <algorithm>

struct Point2D {
    int x;
    int y;
};

int solution(vector<Point2D>& A) {
    if (A.size() == 3)
        return -1;

    vector<pair<int, pair<double, double>>> point_set;

    for (size_t i = 0; i < A.size(); ++i)
        point_set.push_back({i, {A[i].x, A[i].y}});

    sort(point_set.begin(), point_set.end(), [](const auto& a, const auto& b) {
        return (a.second.second < b.second.second) || 
               (a.second.second == b.second.second && a.second.first < b.second.first);
    });

    auto min_y_point = point_set[0];

    vector<pair<int, pair<double, pair<int, int>>>> more_equal_than_zero;
    vector<pair<int, pair<double, pair<int, int>>>> less_than_zero;
    vector<pair<int, pair<double, pair<int, int>>>> positive_infinity;

    for (size_t i = 1; i < point_set.size(); ++i) {
        auto p = point_set[i];
        auto point = make_pair(p.second.first - min_y_point.second.first,
                                     p.second.second - min_y_point.second.second);

        if (point.first != 0) {
            double tan = point.second / point.first;
            if (tan >= 0)
                more_equal_than_zero.push_back({p.first, {tan, point}});
            else
                less_than_zero.push_back({p.first, {tan, point}});
        } else {
            positive_infinity.push_back({p.first, {0, point}});
        }
    }

    sort(more_equal_than_zero.begin(), more_equal_than_zero.end(),
              [](const auto& a, const auto& b) {
                  return (a.second.first < b.second.first) || 
                         (a.second.first == b.second.first && a.second.second.second > b.second.second.second);
              });

    sort(less_than_zero.begin(), less_than_zero.end(),
              [](const auto& a, const auto& b) {
                  return (a.second.first < b.second.first) || 
                         (a.second.first == b.second.first && a.second.second.second > b.second.second.second);
              });

    sort(positive_infinity.begin(), positive_infinity.end(),
              [](const auto& a, const auto& b) {
                  return a.second.second.second > b.second.second.second;
              });

    vector<pair<int, pair<double, pair<int, int>>>> trans_point_angle;
    trans_point_angle.insert(trans_point_angle.end(), more_equal_than_zero.begin(), more_equal_than_zero.end());
    trans_point_angle.insert(trans_point_angle.end(), positive_infinity.begin(), positive_infinity.end());
    trans_point_angle.insert(trans_point_angle.end(), less_than_zero.begin(), less_than_zero.end());

    trans_point_angle.insert(trans_point_angle.begin(), {point_set[0].first, {0, {0, 0}}});
    trans_point_angle.push_back(trans_point_angle[0]);

    auto current = make_pair(trans_point_angle[0], trans_point_angle[1]);

    for (size_t i = 2; i < trans_point_angle.size(); ++i) {
        auto p0 = current.first;
        auto p1 = current.second;
        auto p2 = trans_point_angle[i];

        auto p0_p = p0.second.second;
        auto p1_p = p1.second.second;
        auto p2_p = p2.second.second;

        auto p0p2 = make_pair(p2_p.first - p0_p.first, p2_p.second - p0_p.second);
        auto p0p1 = make_pair(p1_p.first - p0_p.first, p1_p.second - p0_p.second);

        double product = p0p2.first * p0p1.second - p0p2.second * p0p1.first;

        if (product < 0)
            current = make_pair(p1, p2);
        else if (product == 0)
            current = make_pair(p0, p2);
        else
            return current.second.first;
    }
    return -1;
}