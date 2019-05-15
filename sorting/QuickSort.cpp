#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


/* QuickSort */ 
void QuickSort (std::vector<int>& input) {

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
    

    //MergeSortTD(input, 0, input.size() - 1);
    QuickSort(input);

    assert(std::is_sorted(input.begin(), input.end()));

    return 0;
}


