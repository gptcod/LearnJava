#include <iostream>
#include <cassert>
using std::cin;
using std::cout;
using std::endl;

/*
In this file, the solution is to make a new function (new function body, but the same
function name)to replace the existed function called get_fibonacci_last_digit_naive

*/
// int get_fibonacci_last_digit_naive(int n) {
//     if (n <= 1)
//         return n;

//     int previous = 0;
//     int current  = 1;

//     for (int i = 0; i < n - 1; ++i) {
//         int tmp_previous = previous;
//         previous = current;
//         current += tmp_previous;
//     }

//     return current % 10;
// }

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous % 10;
        previous = current;
        current = (current + tmp_previous) % 10;
    }

    return current;
}



// void test_solution() {
//     assert(get_fibonacci_last_digit_fast(3) == 2);
//     assert(get_fibonacci_last_digit_fast(10) == 5);
//     for (int n = 0; n < 20; ++n)
//         assert(get_fibonacci_last_digit_naive(n) == get_fibonacci_last_digit_fast(n));
// }

int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    // test_solution();
    cout << c << '\n';
}
