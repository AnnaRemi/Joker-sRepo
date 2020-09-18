#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::swap;

class command{
public:
    int number{};
};

class sort_class{
public:
    bool operator()(command Obj1, command Obj2)const{
        return Obj1.number < Obj2.number;
    }
};

int main() {
    int size;
    cin >> size;

    vector<command> arr;
    arr.reserve(size);

    sort_class sort_object;

    for (int i = 0; i < size; ++i){
        command temp;
        cin >> temp.number;

        arr.push_back(temp);
    }

    sort (arr.begin(), arr.end(), sort_object);

    for (const auto & i : arr)
        cout << i.number << ' ';
}

