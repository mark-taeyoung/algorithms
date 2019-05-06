#include <iostream>
#include <vector>
#include <algorithm>

void Merge(std::vector<int>& input, std::vector<int>& aux, int &lo,  int& mid, int& end) {

    int idx1 = lo;
    int idx2 = mid + 1;

    std::copy(input.begin() + lo, input.begin() + end + 1, aux.begin() + lo);

    for (int i = lo; i <= end; ++i) {
        if (idx1 > mid) {
            input[i] = aux[idx2++];
        } else if (idx2 > end) {
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

void Sort (std::vector<int>& input, std::vector<int>& aux, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int begin = lo;
    int end = hi;
    int mid = lo + (hi - lo) / 2;

    Sort(input, aux, begin, mid);
    Sort(input, aux, mid + 1, end);
    Merge(input, aux, begin, mid, end);

}

int main (int argc, const char * argv[]) {
    std::vector<int> list1 = {7, 5, 16, 8, 1, 5};
    //std::vector<int> list1 = {4,3,2,1};
    std::vector<int> aux(list1.size());
    Sort(list1, aux, 0, list1.size() - 1);

    for (auto& x : list1) {
        std::cout << x << std::endl;
    }

    return 0;
}


