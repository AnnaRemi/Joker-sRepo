
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
    int summ{};
}Student;

typedef vector<Student>::iterator Iter;

void merge(Iter first_beg, Iter first_end,
           Iter second_beg, Iter second_end) {

    size_t c_size = first_end - first_beg + second_end - second_beg;
    vector<Student> merged;
    merged.reserve(c_size);

    auto first_beg = first_beg;
    auto second_beg = second_beg;
    while (first_beg != first_end && second_beg != second_end) {
        if (first_beg->summ >= second_beg->summ) {
            merged.emplace_back(*first_beg);
            first_beg = next(first_beg);
        } else {
            merged.emplace_back(*second_beg);
            second_beg = next(second_beg);
        }
    }
    for (; first_beg != first_end; first_beg = next(first_beg))
        merged.emplace_back(*first_beg);

    for (; second_beg != second_end; second_beg = next(second_beg))
        merged.emplace_back(*second_beg);

    auto m_beg = merged.begin();

    for (first_beg = first_beg; first_beg != first_end; first_beg = next(first_beg)) {
        *first_beg = *m_beg;
        m_beg = next(m_beg);
    }
    for (second_beg = second_beg; second_beg != second_end; second_beg = next(second_beg)) {
        *second_beg = *m_beg;
        m_beg = next(m_beg);
    }
}

void merge_sort(vector<Student>::iterator beg, vector<Student>::iterator end) {
    size_t shift = distance(beg, end);
    if (shift <= 1)
        return;
    auto mid = next(beg, shift / 2);
    merge_sort(beg, mid);
    merge_sort(mid, end);
    merge(beg, mid, mid, end);
}


int main() {
    size_t size;
    int inf, maths, rus;
    cin >> size;

    vector<Student> arr(size);

    for (int i = 0; i < size; ++i){
        Student temp;
        cin >> temp.surname >> temp.name >> inf >> maths >> rus;
        temp.summ = inf + maths + rus;
        arr.push_back(temp);
    }

    merge_sort(arr.begin(), arr.end());

    for (const auto & i : arr)
        cout << i.surname << ' ' << i.name << std::endl;

    return (0);
}


