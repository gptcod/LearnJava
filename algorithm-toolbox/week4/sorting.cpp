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
using std::to_string;
using std::endl;

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

pair<int,int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j=l, k=l;


  for (int i=l+1; i<=r; ++i) {
    if (a[i] < x && k == j) {
      j = j + 1;
      k = k + 1;
      swap(a[j], a[i]);
    }

    if (a[i] < x && k != j) {
      j = j + 1;
      swap(a[j], a[i]);
      k = k + 1;
      swap(a[i], a[k]);
    }


    if (a[i] == x) {
      k = k + 1;
      swap(a[k], a[i]);
    }
  }

  swap(a[l], a[j]);

  pair<int,int> start_end(j+1, k);

  return start_end;
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


void randomized_quick_sort_old(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort_old(a, l, m - 1);
  randomized_quick_sort_old(a, m + 1, r);
}

int main() {
  while (true) {
    int n;
    int number;
    n = rand() % 10;
    vector<int> a(n);
    vector<int> b(n);
    string old_result("");
    string a_result("");
    string b_result("");

    for (size_t i = 0; i < a.size(); ++i) {
      number = rand() % 10;
      a[i] = number;
      b[i] = number;
    }

    for (size_t i = 0; i < a.size(); ++i) {
      old_result = old_result + " " + to_string(a[i]);
    }


    randomized_quick_sort(a, 0, a.size() - 1);
    randomized_quick_sort_old(b, 0, b.size() - 1);

    for (size_t i = 0; i < a.size(); ++i) {
      a_result = a_result + " " + to_string(a[i]);
      b_result = b_result + " " + to_string(b[i]);
    }

    if (a_result != b_result) {
      cout<<"old_result:"<<old_result<<endl;
      cout<<"a_result:"<<a_result<<endl;
      cout<<"b_result:"<<b_result<<endl;
    }
   
}
}

5 0 1 4 9 33
