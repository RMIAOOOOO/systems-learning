#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b) {
            return a[0] < b[0];
        });


        vector<vector<int>> result;
        result.push_back({intervals[0][0], intervals[0][1]});
        for (const auto& interval: intervals) {
            int curr_start = interval[0];
            int curr_end = interval[1];
            if (curr_start <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], curr_end);
            } else {
                result.push_back(vector<int>{interval[0], interval[1]});
            }
        }
        return result;

    }
};

int main() {
    Solution s;

    vector<vector<int>> sample_input_1 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> sample_input_2 = {{1,4}, {4,5}};
    vector<vector<int>> sample_input_3 = {{4,7}, {1,4}};

    vector<vector<vector<int>>> testcases = {
        sample_input_1,
        sample_input_2,
        sample_input_3,
    };

    for (auto& input : testcases) {
        vector<vector<int>> result = s.merge(input);
        for (auto& group : result) {
            cout << "[" << group[0] << ", "  << group[1] << "] ";
        }
        cout << endl;
    }
}

/*
56. Merge Intervals

- First sort the time by start time. So when we iterate through the intervals, they are by incremental start time.
- Iterate through each start time,
  - If it overlaps with previous interval, merge them,
  - If it does not overlap with previous interval, the previous interval will never be merged,
    so start a new interval as current interval and continue merging.

Time: O(NlogN) for sorting by start time
Space: O(N) for hashmap of size nums

Learning Notes:
1. sorting with lambda function
    sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b) {
            return a[0] < b[0];
        })
2. use vector.back() to access last element
*/