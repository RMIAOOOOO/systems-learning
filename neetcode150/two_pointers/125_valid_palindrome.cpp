#include <iostream>
#include <cassert>

using namespace std;

class Solution {
private:
    bool isAlphanumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    char toLower(char c) {
        assert(isAlphanumeric(c));

        if (c >= 'A' && c <= 'Z') return c + ('a'-'A');
        return c;
    }

public:
    bool isPalindrome(string s) {
        int start_index = 0;
        int end_index = static_cast<int>(s.size()) - 1;
        while(start_index < end_index) {
            
            while((start_index < end_index) && !isAlphanumeric(s[start_index])) {
                start_index++;
            }
            while((start_index < end_index) && !isAlphanumeric(s[end_index])) {
                end_index--;
            }

            if (start_index >= end_index) break;

            if (toLower(s[start_index]) != toLower(s[end_index])) return false;

            start_index ++;
            end_index --;
        }
        return true;
    }
};

int main() {
    Solution s;

    string sample_input_1 = "A man, a plan, a canal: Panama";
    string sample_input_2 = "race a car";
    string sample_input_3 = " ";

    cout << boolalpha
         << s.isPalindrome(sample_input_1)
         << endl
         << s.isPalindrome(sample_input_2)
         << endl
         << s.isPalindrome(sample_input_3)
         << endl;
}

/*
LeetCode 125. Valid Palindrome

- Iterate through the string with one poiter at front and one at back:
   - Each pointer tries to read until reaching a letter/num, or end condition.
   - Return false if the two char does not match.

Time: O(N)
Space: O(1)

Learning Notes:
1. throw invalid_argument("Message") from stdexcept for error
2. use cassert() to verify assumptions
3. size_t returns unsigned type, static_cast<int>(s.size()) avoid unsigned calculation
4. can use isalnum() and tolower() from c++ <cctype>
*/