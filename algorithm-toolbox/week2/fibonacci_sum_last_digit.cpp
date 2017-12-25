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
function name)to replace the existed function called fibonacci_sum_naive
*/

int get_fibonacci_period(vector<long long> &vec, long long n, long long m) {
    vec.push_back(0);
    vec.push_back(1);

    long long previous = 0;
    long long current = 1;
    int i = 2;

    for (i=2; i ==2 || (previous!= 0) || (current !=1) && (i<=n); ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;

        vec.push_back(current);
    }//this operation will add 0 1  in the last two postions

   
    return vec.size() - 2;
    
}

int fibonacci_sum_naive_part(int n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (int i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

//m=10
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    vector<long long> vec;
    int period_vec = get_fibonacci_period(vec, n, 10);
    // cout<<"period_vec "<<period_vec<<endl;

    if (n <= period_vec) {
        return fibonacci_sum_naive_part((int)(n));
    }

    else {
        long long sum_vector = 0;
        for (int i=0; i<period_vec; ++i){
            sum_vector += vec[i];
        }

        // cout<<"sum_vector "<<sum_vector<<endl;

        int most_part_addition = (n / period_vec * (sum_vector% 10)) % 10;
        // cout<<"most_part_addition "<<most_part_addition<<endl;
        //long long result = vec[reminder];

        long long reminder_number = n % period_vec;
        long long sum_last_ones = 0;
        for (long long i=0; i<=reminder_number; ++i) {
             sum_last_ones += vec[i];
        }


        int result = sum_last_ones % 10 + sum_vector % 10;

        return result;
    }  
}



// int fibonacci_sum_naive(long long n) {
//     if (n <= 1)
//         return n;

//     int previous = 0;
//     int current  = 1;
//     int sum = current;

//     for (long long i = 0; i < n - 1; ++i) {
//         int tmp_previous = previous % 10;
//         previous = current;
//         current = (current + tmp_previous) % 10;
//         sum = (sum + current) % 10;
//     }

//     return sum;
// }

int main() {
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_naive(n);
}
