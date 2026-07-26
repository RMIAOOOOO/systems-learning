#include <iostream>
#include <array>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    string sort_string(string str) {
        array<int, 26> alphabet_count = {};
        for (char s: str){
            int index = s - 'a';
            alphabet_count[index]++;            
        }
        int insert_index = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < alphabet_count[i]; ++j){
                char c = 'a' + i;
                str[insert_index] = c;
                insert_index++;
            }
        }

        return str;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result = {};
        unordered_map<string, vector<string>> sorted_map;

        for (string str: strs) {
            string sorted_string = sort_string(str);
            sorted_map[sorted_string].emplace_back(str);
        }

        for (auto& [key, value]: sorted_map) {
            result.emplace_back(move(value));
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<string> sample_input_1 = {"eat","tea","tan","ate","nat","bat"};
    vector<string> sample_input_2 = {};
    vector<string> sample_input_3 = {"a"};

    vector<vector<string>> testcases = {
        sample_input_1,
        sample_input_2,
        sample_input_3,
    };

    for (auto& input : testcases) {
        vector<vector<string>> result = s.groupAnagrams(input);
        for (auto& group : result) {
            for (auto& string: group) {
                cout << string << " ";
            }
            cout << endl;
        }
    }
}

/*
LeetCode 49. Group Anagrams

- Iterate through each string
  - Create a "sorted" version of string, insert to hash map.
- Dump the sorted hash map

Time: O(N) for iterateing through n elements * average O(1) for hash insertion
Space: O(N) for hashmap of size nums

Learning Notes:
1. string is pass by value by default, vector is also pass by value by default
2. Use move() to move object out of local copy to save time and space,
   ownership is passed to caller.
*/