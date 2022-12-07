#include <iostream>
#include <vector>
#include <utility>   // For std::pair
#include <numeric>   // For std::iota

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    os << '{';
    int n = vec.size();
    if (n > 0) {
        os << vec[0];
        for (int i = 1; i < n; i++)
            os << ", " << vec[i];
    }
    os << '}';
    return os;
}

// Finds the index of the minimum value in vector vec.
// Behavior is undefined if the vector is empty.
int find_min(const std::vector<int>& vec) {
    int min_index = 0, n = vec.size();
    for (int i = 1; i < n; i++) {
        if (vec[i] < vec[min_index])
            min_index = i;
    }
    return min_index;
}

// Solves the PAIR problem: Pair the least element of s1 with
// the least element of s2, the next least element of s1 with
// the next least element from s2, etc.
// Result is undefined if s1 and s2 have equal lengths.
// Returns the vector of pairs.
std::vector<std::pair<int, int>> compute_pairs(std::vector<int> s1, 
                                               std::vector<int> s2) {
    std::vector<std::pair<int, int>> result;

    // Loop until the sequences are empty.
    while (s1.size() > 0) {
        // Find locations of the least elements in s1 and s2.
        int min_index1 = find_min(s1);
        int min_index2 = find_min(s2);

        // Add the pairs to the result.
        result.push_back({s1[min_index1], s2[min_index2]});

        // Remove the pairs from the sequences
        std::swap(s1[min_index1], s1[s1.size() - 1]);
        s1.pop_back();
        std::swap(s2[min_index2], s2[s2.size() - 1]);
        s2.pop_back();
    }

    return result;
}

void pair_sort(std::vector<int>& vec) {
    // Determine size of sequence
    int n = vec.size();

    // Make an indexing vector the same size as the vector 
    // to sort: {0, 1, 2, 3, 4, ...}
    std::vector<int> indices(n);
    std::iota(std::begin(indices), std::end(indices), 0);

    // Use the compute_pairs function to pair the elements of the 
    // indexing vector up with elements of the vector to sort 
    auto pairs = compute_pairs(indices, vec);

    // Now each the index within the pairs corresponds to 
    // the location within the original sequence where its 
    // partner should be stored.  Update the original 
    // sequence accordingly.
    for (int i = 0; i < n; i++)
        vec[pairs[i].first] = pairs[i].second; 
}

int main() {
    std::vector<int> list {34, 12, 19, 4, 11, 2, 7, 24};
    std::cout << list << '\n'; 
    pair_sort(list);
    std::cout << list << '\n'; 
}
