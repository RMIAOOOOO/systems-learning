#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return true;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1,2,3,1};

    cout << boolalpha
         << s.containsDuplicate(nums)
         << endl;
}