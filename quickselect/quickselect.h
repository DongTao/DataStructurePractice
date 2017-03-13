#include <vector>
#include "../partition/partition.h"
#include "../quicksort/quicksort.h"

using namespace std;

void QuickSelect(vector<int>& vec, int num, int start, int end) {
    if (vec.empty() || num > end) return;
    int index = Partition(vec, start, end, start);
    if (index > num) {
        QuickSelect(vec, num, start, index-1);
    } else if (index < num) {
        QuickSelect(vec, num, index+1, end);
    }
}

void QuickSelectSort(vector<int>& vec, int num) {
    if (num >= vec.size()) return;
    QuickSelect(vec, num, 0, vec.size()-1);
    QuickSort(vec, 0, num);
}

