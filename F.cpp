#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<int> mergeTwoArrays(vector<int> one, vector<int> two){
    vector<int> ret;

    int left = 0, right = 0;

    while (left + right < one.size() + two.size()) {
        if (left != one.size() && (right == two.size() || one[left] < two[right])) {
            ret.push_back(one[left]);
            left++;
        } else {
            ret.push_back(two[right]);
            right++;
        }
    }

    return ret;
}

vector<int> mergeArrays(vector<vector<int> > arr){
    vector<vector<int> > arr_s;

    while (arr.size() != 1) {
        arr_s.clear();

        for (int i = 0; i < arr.size(); i += 2) {
            if (i == arr.size() - 1)
                arr_s.push_back(arr[i]);

            else
                arr_s.push_back(mergeTwoArrays(arr[i],
                                               arr[i + 1]));
        }

        arr = arr_s;
    }
    return arr[0];
}

int main(){
    int amount, size, num;
    cin >> amount;
    vector<vector<int>> arr;
    arr.reserve(amount);

    for (int j = 0; j <amount; ++j){
        cin >> size;
        vector<int> temp;
        temp.reserve(size);

        for (int i = 0; i < size; ++i){
            cin >> num;
            temp.push_back(num);
        }

        arr.push_back(temp);
    }

    vector<int> output = mergeArrays(arr);

    for (int i : output)
        cout << i << " ";

    return 0;
}



