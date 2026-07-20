#include <iostream>

void basics() {
    // auto assignment
    auto a = 1; // int
    auto b = 2.1; // double

    // array and pointers
    int num_array[3] = {1, 2, 3};
    int* array_1st_pointer = num_array;
    int* array_3rd_pointer = &num_array[2];
    std::cout << "dereference pointer:" << *array_1st_pointer << std::endl;
    std::cout << "dereference pointer:" << *array_3rd_pointer << std::endl;

    // auto through array
    for (auto val : num_array) {
        std::cout << "print by auto through pointer:" << val << std::endl;
    }
    for (auto val : {4, 5, 6}) {
        std::cout << "print by auto through initializer list:" << val << std::endl;
    }

    // auto through reference
    for (auto &val : num_array) {
        val *= 2;
    }
    for (auto val : num_array) {
        std::cout << "print by auto through pointer after reference:" << val << std::endl;
    }
}

int main() {

    basics();

    return 0;
}