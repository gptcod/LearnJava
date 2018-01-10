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

  cout<<"^^^^^"<<endl;
  for (size_t i = 0; i < a.size(); ++i) {
    cout<<" "<<a[i];
  }
  cout<<endl;

  cout<<'l:'<<l<<endl;
  for (int i=l+1; i<=r; ++i) {

    if (a[i] < x && k == j) {
      j = j + 1;
      k = k + 1;
      swap(a[j], a[i]); 
      cout<<"1"<<endl;
      for (size_t ij = 0; ij < a.size(); ++ij) {
        cout<<" "<<a[ij];
      }
      cout<<endl;
  }
    else if (a[i] < x && k != j) {
      j = j + 1;
      swap(a[j], a[i]);
      k = k + 1;
      swap(a[i], a[k]);

      cout<<"2"<<endl;
      for (size_t ij = 0; ij < a.size(); ++ij) {
        cout<<" "<<a[ij];
      }
        cout<<endl;
      }
    }

    //if (a[i] == x) {
    else if (a[i] == x) {
      k = k + 1;
      swap(a[k], a[i]);

       cout<<"3"<<endl;
      for (size_t ij = 0; ij < a.size(); ++ij) {
        cout<<" "<<a[ij];
      }
       cout<<endl;
    }
  }



  swap(a[l], a[j]);

  cout<<"~~~~~"<<endl;
  for (size_t i = 0; i < a.size(); ++i) {
    cout<<" "<<a[i];
  }
  cout<<endl;
 

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
  cout<<"random a pivot is :"<<a[l]<<endl;
  start_end = partition3(a, l, r);
  cout<<"start_end.first:"<<start_end.first<<endl;
  cout<<"start_end.second:"<<start_end.second<<endl;

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

//5 0 1 4 9 9
/*
if pivot = 5
j = k = 0
i = 1, 0 < 5,  j = 1, k = 1, swap(not move)
i = 2, 1 < 5,  j = 2, k = 2, swap(not move)
i = 3,         j = 3, k = 3
i = 4, j = 3, k = 3
i = 5, j = 3, k = 3, swap(a[l], a[j])

//5 9 1 4 5 9
if pivot = 5
j = k = 0
i = 1, j = k = 0
i = 2, 1 < 5,  j = 1, k = 1, swap(a[j], a[i]) 5 1 9 4 5 9
i = 3,         j = 2, k = 2, swap(a[j], a[i]) 5 1 4 9 5 9
i = 4, j = 2, k = 3, swap(a[k], a[i]), 5 1 4 5 9 9

final:swap(a[j], a[l])
// 3 3 3 9 2 3 1
if pivot = 3
j = k = 0
i = 1
i = 2, j = 0, k = 2, swap(not move)
i = 3
i = 4, 2 < 3, j = j+1,swap(a[j], a[i]), 3 2 3 9 3  3 1 , k = k + 1, swap(a[k], a[i])
j=1, k =3, 3 2 3 3 9 3 1

3 2 3 3 3 9 1 j=1, k = 4
final:
3 2 1 3 3 9 3 j=2,swap(a[i], a[j]), k=5, swap(a[k], a[i])

3 2 1 3 3 3 9
1 2 3 3 3 3 9


//4 4 3 0 7 8 6

i = 1, j = 0, k = 1, swap(not move)
i = 2, j = 1, swap(a[j], a[i]), 4 3 4 0 7 8 6, k = 2, swap(not move)
i = 3, 0 < 4, j=2, swap(a[j], a[i]), 4 3 0 4 7 8 6, k = 3 ,
final:swap(a[j], a[l]), 0 3 4 4 7 8 6
l = 2, r = 3

7 2 7 4 1 0

7 2 7 4 1 0

7 2 7 4 1 0, i =3, j=2, 7 2 4 7 1 0, k=2+1=3,   swap(not move)
i = 4, j = 3, 7 2 4 1 7 0, k = 3+1,(not move)
i = 5, j = 4, 7 2 4 1 0 7, 
final:0 2 4 1 7 7 

7 2 7 4 1 0
 2
*/

