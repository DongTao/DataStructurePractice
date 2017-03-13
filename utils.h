#ifndef _UTILS_H_
#define _UTILS_H_

#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

//打印数组元素
template<typename _Tp>
void PrintVec(const vector<_Tp>& vec) {
    copy(vec.cbegin(), vec.cend(), ostream_iterator<_Tp>(cout, " "));
    cout << endl;
}

#endif
