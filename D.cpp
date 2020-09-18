#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::greater;
using std::make_heap;
using std::sort_heap;

void mergeArrays(int* a, int n, int* b, int m){

    make_heap(b, b + m, greater<int>());

    for (int i = 0; i < n; i++) {
        if (a[i] > b[0]) {
            pop_heap(b, b + m, greater<int>());

            int tmp = a[i];
            a[i] = b[m - 1];
            b[m - 1] = tmp;

            push_heap(b, b + m, greater<int>());
        }
    }

    make_heap(b, b + m); // It's a max_heap
    sort_heap(b, b + m);
}


int main(){
    int size_one, size_two;

    cin >> size_one;
    int* arr_first = new int[size_one];
    for (int i = 0; i < size_one; ++i)
        cin >> arr_first[i];

    cin >> size_two;
    int* arr_second = new int[size_two];
    for (int i = 0; i < size_two; ++i)
        cin >> arr_second[i];

    mergeArrays(arr_first, size_one, arr_second, size_two);

    for (int i = 0; i < size_one; ++i)
        cout << arr_first[i] << ' ';

    for (int j = 0; j < size_two; ++j)
        cout << arr_second[j] << ' ';

    delete [] arr_first;
    delete [] arr_second;
    return 0;
}