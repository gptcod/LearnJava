#include <iostream>
#include <cassert>
#include <vector>

using std::cin;
using std::vector;
using std::cout;
using std::endl;

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:

// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.

    //40 2s
    //45 10s
    //50 115s
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    if (n < 2) {
        return n;
    }

    vector<int> numbers(n+1);
    numbers[0] = 0;
    numbers[1] = 1;
    for (int i=2; i<=n; ++i) {
        numbers[i] = numbers[i-1] + numbers[i-2];
    }

    return numbers[n];
}

int fibonacci_fast(int n) {
    // write your code here
    // 5.1 add by 5th step
    if (n < 2) {
        return n;
    }
    //1.create a new array including n elements,initialize elements to 0
    vector<int> numbers(n+1, 0);
    //2.f(0) = 0, f(1)=1
    numbers[0] = 0;
    numbers[1] = 1;
    //3.loop

    for(int i=2; i<=n; ++i) {
        numbers[i] = numbers[i-1] + numbers[i-2];
    }
    //4.return
    return numbers[n];
    //5.test,don't forget the initial numbers
}
void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n=0; n<20; ++n) {
        assert(fibonacci_naive(n) == fibonacci_fast(n));
    }
}

// void test_solution() {
//     assert(fibonacci_fast(3) == 2);
//     assert(fibonacci_fast(10) == 55);
//     for (int n = 0; n < 20; ++n)
//         assert(fibonacci_fast(n) == fibonacci_naive(n));
// }

int main() {
    int n = 0;
    cin >> n;

    // cout << fibonacci_naive(3) << '\n';
    // cout << fibonacci_naive(10) << '\n';
    // cout << fibonacci_naive(n) << '\n';
    // test_solution();
    cout << fibonacci_fast(n) << '\n';
    return 0;
}
