#include <iostream>
using std::cin;
using std::cout;

void mergeArrays(int arr_first[], int arr_second[], int size_one, int size_two){
    for (int i = size_two - 1; i >= 0; i--){
        int j, last = arr_first[size_one - 1];

        for (j = size_one - 2; j >= 0 && arr_first[j] > arr_second[i]; j--)
            arr_first[j+1] = arr_first[j];

        if (j != size_one - 2 || last > arr_second[i]){
            arr_first[j + 1] = arr_second[i];
            arr_second[i] = last;
        }
    }
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


    mergeArrays(arr_first, arr_second, size_one, size_two);
    for (int j = 0; j < size_one; ++j)
        cout << arr_first[j] << ' ';
    for (int j = 0; j < size_two; ++j)
        cout << arr_second[j] << ' ';

    delete [] arr_first;
    delete [] arr_second;
    return 0;
}
