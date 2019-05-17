#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


void InsertionSort (std::vector<int>& input) {

    for (int i = 1; i < input.size(); ++i) {
        int key = input[i];
        int j = i - 1;

        while (j >= 0 && input[j] > key) {
            input[j + 1] = input[j];
            --j;
        }
        input[j + 1] = key;
    }
}


int main (int argc, const char * argv[]) {
    
    srand(time(NULL));
    u_int input_sz = rand() % 10000;
    std::vector<int> input(input_sz);    

    /* generating a vector with random number range(from,to) */
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,input_sz);
    for (size_t i = 0; i < input_sz; ++i) {
        input[i] = dist(rng);
    }
    
    InsertionSort(input);

    assert(std::is_sorted(input.begin(), input.end()));

    return 0;
}


