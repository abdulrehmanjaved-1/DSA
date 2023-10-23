#include <iostream>
using namespace std;

bool Is_Possible1(int mid, int test_array[], int size) {
    int sumPage = 0;
    int student = 1;
    for (int i = 0; i < size; i++) {
        if (sumPage + test_array[i] <= mid) {
            sumPage += test_array[i];
        } else {
            student++;
            if (student > 2 || test_array[i] > mid) {
                return false;
            }
            sumPage = test_array[i];
        }
    }
    return true;
}

int main() {
    int start = 0, sum = 0, ans = -1;
    int test_array[4] = {12, 34, 67, 90};
    for (int i = 0; i < 4; i++) {
        sum += test_array[i];
    }
    int end = sum;
    cout << "sum is " << sum << endl; //sum is done
    int mid = start + (end - start) / 2;
    while (start <= end) {
        if (Is_Possible1(mid, test_array, 4)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    cout << "answer is " << ans << endl;

    return 0;
}
