#include <iostream>
#include <vector>

using namespace std;

template<typename Input, typename Output>
struct TestCase {
    Input input;
    Output expected;
};

template<typename Input, typename Output>
class TestCollection {
public:
    vector<TestCase<Input, Output>> test_cases;
    void add(Input input, Output expected) {
        test_cases.push_back({input, expected});
    }
};

class TestRunner {
public:
    template<typename Func, typename Input, typename Output>
    void run_testcases(const Func& func, TestCollection<Input, Output>& test_collection) {
        for (const auto& [input, expected] : test_collection.test_cases) {
            auto result = func(input);
            if (result != expected) {
                cout << "Test failed for input: " << boolalpha << input << endl;
            } else {
                cout << "Test passed for input: " << boolalpha << input << endl;
            }
        }
    }
};


class SolutionBool {
public:
    bool returnOriginalValue(bool value) {
        return value;
    }
};

class SolutionNegInt {
    public:
    int returnNegativeValue(int value) {
        return -value;
    }
};

int main() {
    TestRunner test_runner;

    TestCollection<bool, bool> test_collection_bool;
    test_collection_bool.add(true, true);
    test_collection_bool.add(false, false);
    SolutionBool solution_bool;
    test_runner.run_testcases([&](bool input) { return solution_bool.returnOriginalValue(input); }, test_collection_bool);


    TestCollection<int, int> test_collection_negative_int;
    test_collection_negative_int.add(1, -1);
    test_collection_negative_int.add(0, 0);
    test_collection_negative_int.add(-3, 3);
    SolutionNegInt solution_negative_int;
    test_runner.run_testcases([&](int input) { return solution_negative_int.returnNegativeValue(input); }, test_collection_negative_int);
}
