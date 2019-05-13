#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

/* The helper function for MergeSortTD */
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

/* Merge sort Top-Down */
void MergeSortTD (std::vector<int>& input, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int begin = lo;
    int end = hi;
    int mid = lo + (hi - lo) / 2;

    MergeSortTD(input, begin, mid);
    MergeSortTD(input, mid + 1, end);
    Merge(input, begin, mid, end);

}

/* Merge sort Bottom-Up */ 
void MergeSortBU (std::vector<int>& input) {
    int len = input.size();

    for (int sz = 2; sz < len * 2; sz *= 2) {
        std::vector<int> aux(sz);    // aux vector for temporary copy
        for (int i = 0; i < ceil(len / sz); ++i) {
            /* for input */
            int lo = i * sz;
            int hi = lo + sz - 1;
            int mid = lo + (hi - lo) / 2;
            /* for aux */
            int idx1 = 0;
            int idx2 = mid + 1 - lo;

            std::copy(input.begin() + lo, input.begin() + hi + 1, aux.begin());

            for (int k = lo; k <= hi; ++k) {
                if (idx1 > mid - lo) {
                    input[k] = aux[idx2++];
                } else if (idx2 > hi - lo) {
                    input[k] = aux[idx1++];
                } else {
                    if (aux[idx1] < aux[idx2]) {
                        input[k] = aux[idx1++];
                    } else {
                        input[k] = aux[idx2++];
                    }
                }
            }
        }
    }
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
    

    std::vector<int> test({3,2,1});
    //MergeSortTD(input, 0, input.size() - 1);
    MergeSortBU(test);

    for (int& x : test)
        std::cout << "-->" << x << std::endl;

    //assert(std::is_sorted(input.begin(), input.end()));

    return 0;
}


