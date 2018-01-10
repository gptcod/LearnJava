#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <cstdlib>
#include <string>

using std::vector;
using std::swap;
using std::pair;
using std::cout;
using std::cin;
using std::string;

/*
no matter j = j+1 or k = k+1,都是为了先扩充自己的地盘（或者先申请空间），然后再把元素交换进来
*/

pair<int,int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j=l, k=l;

  for (int i=l+1; i<=r; ++i) {
    if (a[i] < x && k == j) {
      j = j + 1;
      k = k + 1;
      swap(a[j], a[i]); 
    }
    else if (a[i] < x && k != j) {
      j = j + 1;
      swap(a[j], a[i]);
      k = k + 1;
      swap(a[i], a[k]);
    }
    else if (a[i] == x) {
      k = k + 1;
      swap(a[k], a[i]); 
    }
  }
  swap(a[l], a[j]);


  pair<int,int> start_end(j+1, k);

  return start_end;
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  pair<int,int> start_end;

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  start_end = partition3(a, l, r);
 
  randomized_quick_sort(a, l, start_end.first - 1);
  randomized_quick_sort(a, start_end.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
