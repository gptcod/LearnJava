#include <iostream>
#include <cassert>
#include <vector>
#include <cassert>
#include <cstdlib>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  int mid = 0;

  while (left <= right) {
    mid = left + (right - left) /2 ;

    if (a[mid] < x)
    {
      left = mid + 1;
    }

    else if (a[mid] > x)
    {
      right = mid -1;
    }

    else {
      return mid;
    }
  }

  return -1;

  //write your code here
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    cout << binary_search(a, b[i]) << ' ';
  }
}
