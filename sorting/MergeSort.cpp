#include <iostream>
#include <vector>

void Merge(std::vector<int>& input, int &lo,  int& mid, int& end) {

    std::vector<int> aux(input);
    int idx1 = lo;
    int idx2 = mid + 1;

    for (int i = lo; i <= end; ++i) {
        if (idx2 <= end && idx1 <= mid){
            if (aux[idx1] < aux[idx2]) {
                input[i] = aux[idx1++];
            } else {
                input[i] = aux[idx2++];
            }
        } else if (idx2 <= end || idx1 <= mid){
            if (idx1 > mid) {
                input[i] = aux[idx2++];
            } else if (idx2 > end) {
                input[i] = aux[idx1++];
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
    std::vector<int> list1 = {7, 5, 16, 8, 1};
    //std::vector<int> list1 = {4,3,2,1};
    std::vector<int> aux(list1);
    Sort(list1, 0, list1.size() - 1);

    for (auto& x : list1) {
        std::cout << x << std::endl;
    }

    return 0;
}


