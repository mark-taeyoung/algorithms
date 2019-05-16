#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


int Partition (std::vector<int>& input, int lo, int hi) {
    srand(time(NULL)); 
    int random = lo + rand() % (hi - lo);   // generate random index between lo and hi

    std::swap(input[random], input[hi]);    // move random index to end

    int pivot = hi;     // now pivot is in the end

    int left = lo - 1;  // this will be the most right index in smaller part
  
    for (int i = lo; i <= hi - 1; ++i) { 
        if (input[i] <= input[pivot]) { // if curr i element smaller than or equal to pivot
            ++left;
            std::swap(input[left], input[i]);
        } 
    } 
    std::swap(input[left + 1], input[hi]); 

    return (left + 1); 

}

/* QuickSort */ 
void QuickSort (std::vector<int>& input, int lo, int hi) {
    if (lo < hi ) {
        /* pick random pivot index */
        int pivot = Partition(input, lo, hi);

        QuickSort(input, lo, pivot - 1);
        QuickSort(input, pivot + 1, hi);
    }
}

void QuickSort (std::vector<int>& input) {
    QuickSort(input, 0, input.size() - 1);
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
    
    QuickSort(input);

    // std::vector<int> test = {10,7,8,9,1,5};
    // QuickSort(test);
    // for (int&x : test) {
    //     std::cout << x << std::endl;
    // }



    assert(std::is_sorted(input.begin(), input.end()));

    return 0;
}


