#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
//get number of inversions of left half and right half, then sort the array a 
//[left, ave) vs [ave, right)
//sort array a
long long merge_and_get_number_of_inversions(vector<int> &a, size_t left,  size_t ave, size_t right) {
  long long number_of_inversions = 0; 

  for (int i=left; i<ave; ++i) {
    for (int j=ave; j<right; ++j) {
      if (a[i] > a[j]) {
        ++number_of_inversions;
      }

      else {
        break;
      }
    }
  }

  vector<int> left_half(ave - left);
  for (int i =0, j=left; j<ave; ++i, ++j) {
    left_half[i] = a[j];
  }

  vector<int> right_half(right - ave);
  for (int i =0, j=ave; j<right; ++i, ++j) {
    right_half[i] = a[j];
  }

  int i = 0, j = 0, index = left;
  while (i < left_half.size() && j< right_half.size()) {
    if (left_half[i] >= right_half[j]) {
      a[index] = right_half[j];
      ++j;
      ++index;
    }

    else {
      a[index] = left_half[i];
      ++i;
      ++index;
    }
  }

  if (i >= left_half.size()) {
    while (j< right_half.size()) {
      a[index] = right_half[j];
      ++j;
      ++index;
    }
  }

  else if (j >= right_half.size()) {
    while (i< left_half.size()) {
      a[index] = left_half[i];
      ++i;
      ++index;
    }
  }
  return number_of_inversions;
}

long long get_number_of_inversions(vector<int> &a, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, left, ave); //[a, b)
  number_of_inversions += get_number_of_inversions(a, ave, right);
  //write your code here
  number_of_inversions += merge_and_get_number_of_inversions(a, left, ave, right);
  return number_of_inversions;
}


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  
  std::cout << get_number_of_inversions(a, 0, a.size()) << '\n';
}