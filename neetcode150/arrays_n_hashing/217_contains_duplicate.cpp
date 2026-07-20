#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> seen_nums;

        for (const auto& num : nums) {
            auto [it, inserted] = seen_nums.insert(num);
            if (!inserted) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;

    vector<int> sample_input_1 = {1,2,3,1};
    vector<int> sample_input_2 = {1,2,3,4};
    vector<int> sample_input_3 = {1,1,1,3,3,4,3,2,4,2};

    cout << boolalpha
         << s.containsDuplicate(sample_input_1)
         << endl
         << s.containsDuplicate(sample_input_2)
         << endl
         << s.containsDuplicate(sample_input_3)
         << endl;
}

/*
LeetCode 217. Contains Duplicate

- Iterate through the array, try to insert to unorderd_set:
   - If insertion failed (item already exists) return true.
   - If finishing iteration without failure, return false.

Time: O(N) for iterateing through n elements * average O(1) for hash insertion
Space: O(N) for hashmap of size nums

Learning Notes:
1. use auto to reduce code complexity
  - unordered_set<int>::const_iterator num_iter = seen_nums.find(num);
  - auto num_iter = seen_nums.find(num);
2. use directly use != seen_nums.end() for simplicity
3. use auto [it, inserted] to directly retrieve return value
  - auto for getting result from return pair
  - _ is a variable name (unlike python), use it for readability
4. use `const auto& item` for iterating withhout copy
*/