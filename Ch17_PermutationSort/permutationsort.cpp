#include <iostream>
#include <vector>

using std::vector;


/*
 * Reverses the elements of vector <code>a</code> in the
 * range <code>i</code> (inclusive) to <code>j</code> (exclusive).
 * a is the vector
 * i is the beginning index of the range, inclusive
 * j is the ending index of the range, exclusive
 */
void reverse_range(vector<int>& a, int i, int j) {
    j--;
    while (i < j) {
        std::swap(a[i], a[j]);
        i++;
        j--;
    }
}

/**
 * Returns the next permutation of a segment of vector
 * <code>a</code> based on code from
 * https://stackoverflow.com/questions/11483060/stdnext-permutation-implementation-explanation,
 * (based on the GNU C++ standard library).
 * a is the vector to permute
 * begin is the beginning index of the vector segment, inclusive
 * end is ending index of the vector segment, exclusive
 * Returns true if the another new permutation is available; otherwise, false
 */
bool next_permutation(vector<int>& a, int begin, int end) {
    if (begin == end || begin + 1 == end) {
        return false;  // An empty or one-element vector has no next permutation
    }
    int i = end - 1;
    while (true) {
        int j = i--;
        if (a[i] < a[j]) {
            int k = end - 1;
            while (!(a[i] < a[k])) {
                k--;
            }
            std::swap(a[i], a[k]); // swap(a, i, k);
            reverse_range(a, j, end);
            return true;
        }
        if (i == begin) {
            reverse_range(a, begin, end);
            return false;
        }
    }
}

/*
 * Returns the next permutation of vector <code>a</code> based on code
 * from https://stackoverflow.com/questions/11483060/stdnext-permutation-implementation-explanation,
 * (based on the GNU C++ standard library).
 * a is the array to permute
 * Returns true if the another new permutation is available; otherwise, false
 */
bool next_permutation(vector<int>& a) {
    return next_permutation(a, 0, a.size());
}

/**
 * Determines if the elements in an array appear in non-descending order.
 * @param a the array to test
 * @return true, if the array's elements appear in non-descending order;
 *         otherwise, false
 */
bool is_ascending(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

/*
 * Sorts the elements of a vector into non-descending order.
 * a is the vector to sort
 */
void permutation_sort(vector<int>& a) {
    while (!is_ascending(a)) {
        next_permutation(a);
    }
}

std::ostream& operator<<(std::ostream& os, const vector<int>& v) {
    os << '{';
    int n = v.size(), i = 0;
    if (n > 0) {
        std::cout << v[i++];
        while (i < n) {
            std::cout << ", " << v[i++];
        }
    }
    os << '}';
    return os;
}

int main() {
    //vector<int> arr{ 1, 2, 3, 4 };
    // Print all permutations
    //std::cout << arr << '\n';
    //while (next_permutation(arr))
    //    std::cout << arr << '\n';

    //std::cout << "-----------------\n";

    vector<int> arr2 = { 34, 2, 18, 43, 19, 88, 5 };
    std::cout << "Before: " << arr2 << '\n';
    permutation_sort(arr2);
    std::cout << "After: " << arr2 << '\n';
}



