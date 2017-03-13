#include <vector>

using namespace std;

void HeapifyMax(vector<int>& vec, int index) {
    int left = 2*index + 1;
    int right = 2*(index + 1);
    int max = index;
    if (left < vec.size() && vec[left] < vec[max]) max = left;
    if (right < vec.size() && vec[right] < vec[max]) max = right;

    if (max != index) {
        swap(vec[max], vec[index]);
        HeapifyMax(vec, max);
    }
}

void BuildHeap(vector<int>& vec) {
    int last_parent = ((vec.size()-1)-1)/2;
    for(int i = last_parent; i >= 0; --i)
        HeapifyMax(vec, i);
}

bool PopHeap(vector<int>& vec, int& out) {
    if (vec.empty()) return false;
    out = vec.front();
    swap(vec.front(), vec.back());
    vec.pop_back();
    if (vec.empty()) return true;
    HeapifyMax(vec, 0);
    return true;
}

vector<int> HeapSort(vector<int>& vec) {
    vector<int> result;
    result.reserve(vec.size());
    BuildHeap(vec);
    int out = 0;
    while (true) {
        if (!PopHeap(vec, out)) {
            break;
        }
        result.push_back(out);
    }
    return result;
}
