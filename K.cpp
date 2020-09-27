#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::sort;
using std::endl;

bool check(int x, int k, vector<int> coords) {
    int students = 1;
    int last_student = coords[0];
    for (int c : coords) {
        if (c - last_student >= x) {
            students++;
            last_student = c;
        }
    }
    return students >= k;
}

int solve(vector<int> coords, int k) {
    int left = 0;
    int right = coords.back() - coords[0] + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (check(mid, k, coords)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

int main(){
    int n, k, num;
    cin >> n >> k;

    vector<int> coords;
    coords.reserve(n);

    for (int i = 0; i < n; ++i){
        cin >> num;
        coords.emplace_back(num);
    }

    cout << solve(coords, k);
}