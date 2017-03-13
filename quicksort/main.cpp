#include <vector>
#include <iostream>
#include "../utils.h"
#include "quicksort.h"

using namespace std;

int main(void) {
    vector<int> nums = {12,18,44,33,121,2,5,1,72,3,6,6,23,451,55};
    PrintVec(nums);
    QuickSort(nums, 0, nums.size()-1);
    cout << endl;
    PrintVec(nums);
}
