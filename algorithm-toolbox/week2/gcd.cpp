#include <iostream>
#include <cassert>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

/*
In this file, the solution is to make a new function (new function body, but the same
function name)to replace the existed function called gcd_naive
*/

// int gcd_naive(int a, int b) {
//   int current_gcd = 1;
//   for (int d = 2; d <= a && d <= b; d++) {
//     if (a % d == 0 && b % d == 0) {
//       if (d > current_gcd) {
//         current_gcd = d;
//       }
//     }
//   }
//   return current_gcd;
// }

int gcd_naive(int a, int b) {
  if (0 == b) {
    return a;
  }

  return gcd_naive(b, a%b);
}

// void test_solution() {
//   assert(gcd_fast(4, 2) == 2);
//   assert(gcd_fast(6, 4) == 2);
//   assert(gcd_fast(6, 12) == 6);

//   int a = 0;
//   int b = 0;

//   for (int i=0; i<100; ++i) {
//     a = rand()%20 + 2;
//     b = rand()%50 + 3;
//     assert(gcd_fast(a, b) == gcd_naive(a, b));
//   }
//   printf("OK\n");

// }

int main() {
  int a, b;
  cin >> a >> b;
  cout << gcd_naive(a, b) << endl;
  // test_solution();
  return 0;
}
