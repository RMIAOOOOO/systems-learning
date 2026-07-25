#include <iostream>
#include <vector>
#include <cassert>
#include <cstdint>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int current_sum = 0;
        int left_index = 0;
        int ans = INT_MAX;
        for (int right_index = 0; right_index < nums.size(); ++right_index) {
            current_sum += nums[right_index];

            while (current_sum >= target) {
                ans = min(ans, right_index - left_index + 1);
                current_sum -= nums[left_index];
                left_index++;
            }
        }
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};

int main() {
    Solution s;

    int sample_input_1_target = 7;
    vector<int> sample_input_1_nums = {2,3,1,2,4,3};
    int sample_input_2_target = 4;
    vector<int> sample_input_2_nums = {1,4,4};
    int sample_input_3_target = 11;
    vector<int> sample_input_3_nums = {1,1,1,1,1,1,1,1};

    cout << s.minSubArrayLen(sample_input_1_target, sample_input_1_nums)
         << endl
         << s.minSubArrayLen(sample_input_2_target, sample_input_2_nums)
         << endl
         << s.minSubArrayLen(sample_input_3_target, sample_input_3_nums)
         << endl;
}

/*
LeetCode 209. Minimum Size Subarray Sum

- Start by getting the leftmost subarray that can fulfill the target
  - iterate through array until reach sum
  - if exhausted all array, return 0
- Try to update the right index by 1, when acceptable, shrink the left index while acceptable
  - right index ++
  - while (fulfill_target) left index --;
  - min_res = (right - left);
  - Stop when right index is exhausted

Time: O(N)
Space: O(1)

Learning Notes:
1. don't over over design and modularize functions
2. when passing value, pass by reference for readability
*/