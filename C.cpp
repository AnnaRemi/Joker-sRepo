/*#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::swap;

class command{
public:
    string surname{};
    string name{};
    int avg{};
};

class sort_class{
public:
    bool operator()(const command& Obj1, const command& Obj2)const{
        return Obj1.avg > Obj2.avg;
    }
};

int main() {
    int size, inf, maths, rus;
    cin >> size;

    vector<command> arr;
    arr.reserve(size);

    sort_class sort_object;

    for (int i = 0; i < size; ++i){
        command temp;
        cin >> temp.surname >> temp.name >> inf >> maths >> rus;
        temp.avg = inf + maths + rus;
        arr.push_back(temp);
    }

    sort (arr.begin(), arr.end(), sort_object);

    for (const auto & i : arr)
        cout << i.surname << ' ' << i.name << endl;
}*/

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::vector;

typedef class Student {
public:
    string surname, name;
    int avg{};
}Student;


void merge(vector<Student>::iterator a_beg, vector<Student>::iterator a_end,
           vector<Student>::iterator b_beg, vector<Student>::iterator b_end) {

    size_t c_size = a_end - a_beg + b_end - b_beg;
    vector<Student> merged;
    merged.reserve(c_size);

    auto first_beg = a_beg;
    auto second_beg = b_beg;
    while (first_beg != a_end && second_beg != b_end) {
        if (first_beg->avg >= second_beg->avg) {
            merged.emplace_back(*first_beg);
            first_beg = next(first_beg);
        } else {
            merged.emplace_back(*second_beg);
            second_beg = next(second_beg);
        }
    }
    for (; first_beg != a_end; first_beg = next(first_beg))
        merged.emplace_back(*first_beg);

    for (; second_beg != b_end; second_beg = next(second_beg))
        merged.emplace_back(*second_beg);

    auto m_beg = merged.begin();

    for (first_beg = a_beg; first_beg != a_end; first_beg = next(first_beg)) {
        *first_beg = *m_beg;
        m_beg = next(m_beg);
    }
    for (second_beg = b_beg; second_beg != b_end; second_beg = next(second_beg)) {
        *second_beg = *m_beg;
        m_beg = next(m_beg);
    }
}

void merge_sort(vector<Student>::iterator beg, vector<Student>::iterator end) {
    int shift = distance(beg, end);
    if (shift <= 1)
        return;
    auto mid = next(beg, shift / 2);
    merge_sort(beg, mid);
    merge_sort(mid, end);
    merge(beg, mid, mid, end);
}


int main() {
    int size, inf, maths, rus;
    cin >> size;

    vector<Student> arr;
    arr.reserve(size);

    for (int i = 0; i < size; ++i){
        Student temp;
        cin >> temp.surname >> temp.name >> inf >> maths >> rus;
        temp.avg = inf + maths + rus;
        arr.push_back(temp);
    }

    merge_sort(arr.begin(), arr.end());
    for (const auto & i : arr)
        cout << i.surname << ' ' << i.name << std::endl;

    return (0);
}


