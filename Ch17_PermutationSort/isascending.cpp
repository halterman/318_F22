
#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>
#include <thread>

#include "stopwatch.h"


bool is_ascending1(const std::vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                return false;
            }
        }
    }
    return true;
}

bool is_ascending2(const std::vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            return false;
        }
    }
    return true;
}


// Measure how long it takes function f to process vector vec
double time_it(const std::vector<int>& vec, std::function<bool(const std::vector<int>&)> f) {
    Stopwatch timer;
    timer.start();
    f(vec);
    timer.stop();
    return timer.elapsed();
}


// Prints an integer vector to an output stream
std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    int n = vec.size();
    os << '{';
    if (n > 0) {
        os << vec[0];
        for (int i = 1; i < n; i++) {
            os << ", " << vec[i];
        }
    }
    os << '}';
    return os;
}


int main() {
    //std::vector<int> vec1{1, 2, 3, 4},
    //                 vec2{2, 1, 3, 4},
    //                 vec3{30, 40, 40, 50, 80};

    ////  Print bools as false or true instead of 0 or 1
    //std::cout << std::boolalpha << '\n';  
    //std::cout << vec1 << "  " << is_ascending1(vec1) << '\n';
    //std::cout << vec2 << "  " << is_ascending1(vec2) << '\n';
    //std::cout << vec3 << "  " << is_ascending1(vec3) << '\n';

    //std::cout << vec1 << "  " << is_ascending2(vec1) << '\n';
    //std::cout << vec2 << "  " << is_ascending2(vec2) << '\n';
    //std::cout << vec3 << "  " << is_ascending2(vec3) << '\n';

    std::cout << "------------------------------------------\n";
    std::cout << "     Size     is_ascending1  is_ascending2\n";
    std::cout << "------------------------------------------\n";
    for (int i = 0; i < 100000; i += 5000) { 
        // Make a vector containing the elements 0, 1, 2, 3, ..., i - 1
        std::vector<int> v(i);
        std::iota(v.begin(), v.end(), 0);
        std::cout << std::fixed << std::setprecision(7)
                  << std::setw(10) << i
                  << std::setw(15) << time_it(v, is_ascending1)
                  << std::setw(15) << time_it(v, is_ascending2) << '\n';
    }
    std::cout << '\n';
    for (int i = 100000; i < 1000000; i += 10000) { 
        // Make a vector containing the elements 0, 1, 2, 3, ..., i - 1
        std::vector<int> v(i);
        std::iota(v.begin(), v.end(), 0);
        std::cout << std::fixed << std::setprecision(7)
                  << std::setw(10) << i
                  << std::setw(15) << time_it(v, is_ascending1)
                  << std::setw(15) << time_it(v, is_ascending2) << '\n';
    }

}

