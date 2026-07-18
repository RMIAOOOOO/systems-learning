#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool foo(bool input) {
        return input;
    }
};

// func is jsut a callable object that takes a bool and returns a bool
template<typename Func>
void run_testcases(Func func)
{
    cout << func(true) << endl;
}

class Magic {
public:
    Solution* solution;

    Magic(Solution* sol) : solution(sol) {}

    bool operator()(bool input)
    {
        return solution->foo(input);
    }

};

int main() {
    Solution solution;

    Magic magic(&solution);
    run_testcases(magic);
    // => magic(true)
    // => magic.operator()(true)
    // => return solution.foo(true)

    // Lambda function wrapped the assigned function pointer to the solution object
    auto lambda_magic = [&](bool input) { return solution.foo(input); };
    run_testcases(lambda_magic);
}