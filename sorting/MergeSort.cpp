#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void Merge(std::vector<int>& input, int &lo,  int& mid, int& hi) {
    int aux_sz = hi - lo + 1;
    std::vector<int> aux(aux_sz);
    std::copy(input.begin() + lo, input.begin() + hi + 1, aux.begin());
    int idx1 = 0;
    int idx2 = mid + 1 - lo;

    for (int i = lo; i <= hi; ++i) {
        if (idx1 > mid - lo) {
            input[i] = aux[idx2++];
        } else if (idx2 > hi - lo) {
            input[i] = aux[idx1++];
        }
        else {
            if (aux[idx1] < aux[idx2]) {
                input[i] = aux[idx1++];
            } else {
                input[i] = aux[idx2++];
            }
        }
    }
}

void Sort (std::vector<int>& input, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int begin = lo;
    int end = hi;
    int mid = lo + (hi - lo) / 2;

    Sort(input, begin, mid);
    Sort(input, mid + 1, end);
    Merge(input, begin, mid, end);

}

int main (int argc, const char * argv[]) {
    u_int input_sz = 1000;
    std::vector<int> input(input_sz);
    
    
    /* generating a vector with random number range(0,input_sz) */
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,input_sz);
    for (size_t i = 0; i < input_sz; ++i) {
        input[i] = dist(rng);
    }
    
    Sort(input, 0, input.size() - 1);

    assert(std::is_sorted(input.begin(), input.end()));

    return 0;
}


