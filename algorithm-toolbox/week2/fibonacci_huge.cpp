#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/*
In this file, the solution is to make a new function (new function body, but the same
function name)to replace the existed function called get_fibonacci_huge_naive
*/

void get_fibonacci_period(vector<long long> &vec, long long n, long long m) {
    vec.push_back(0);
    vec.push_back(1);

    long long previous = 0;
    long long current = 1;

    for (int i=2; i ==2 || (previous!= 0) || (current !=1) && i<=n; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;

        vec.push_back(current);
    }//this operation will add 0 1  in the last two postions
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    vector<long long> vec;
    get_fibonacci_period(vec, n, m);
    int period_vec = vec.size() - 2;
    long long reminder = n % period_vec;
    long long result = vec[reminder];

    return result;
}

// long long get_fibonacci_huge_naive(long long n, long long m) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//     }

//     return current % m;
// }

int main() {
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge_naive(n, m) << '\n';
}
