#include <iostream>
#include <cassert>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

/*
In this file, the solution is to make a new function (new function body, but the same
function name)to replace the existed function called lcm_naive
*/
// long long lcm_naive(int a, int b) {
//   for (long l = 1; l <= (long long) a * b; ++l)
//     if (l % a == 0 && l % b == 0)
//       return l;

//   return (long long) a * b;
// }


int gcd(int a, int b) {
  if (0 == b) {
    return a;
  }

  return gcd(b, a%b);
}

long long lcm_naive(int a, int b) {
  return (long long) a * b / gcd(a,b);
}

// void test_solution() {
//   assert(lcm_fast(4, 2) == 4);
//   assert(lcm_fast(6, 4) == 12);
//   assert(lcm_fast(6, 12) == 12);

//   int a = 0;
//   int b = 0;

//   for (int i=0; i<100; ++i) {
//     a = rand()%20 + 2;
//     b = rand()%50 + 3;
//     assert(lcm_naive(a, b) == lcm_fast(a, b));
//   }
//   cout<<"OK"<<endl;

// }

int main() {
  int a, b;
  cin >> a >> b;
  cout << lcm_naive(a, b) << endl;
  // test_solution();
  return 0;
}
