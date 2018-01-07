#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <map>  
 
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::map;
 
int get_majority_element(vector<int> &a, int left, int right) {
 
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int mid = (left + right) / 2;
  int left_result = get_majority_element(a, left, mid); //[left, mid]
  int right_result = get_majority_element(a, mid, right);//len=
  //left = 2,right = 5
  //mid = 3
  //[2, 3-1], [3, 5]
 
  //mid-1 + (x-1-mid) = right
 
  //total_len = right 
  //second_len = right-mid
  //mid=1, [0,1] [1, 2]
 
  //left = 0, right=1, mid=0, [0, 0]
  //[0, 1-0=1] [0,1]
  //left = 0, right = 2, mid=1, [0,1]
  //[1,2-1]
  if (left_result == -1 && right_result == -1) {
    return -1;
  }
 
  else if(left_result == -1 && right_result != -1) {
    vector<int>::iterator it;
    int right_result_sum = 0;
    for(it=a.begin() + left; it!=a.begin() + right; ++it) {
      if (*it == right_result) {
        ++right_result_sum;
      }
    }
 
    if (right_result_sum / (double)(right-left) > 0.5) {
     
      return right_result;
    }
 
    else {
     
      return -1;
    }
 
  }
 
  else if(left_result != -1 && right_result == -1) {
    vector<int>::iterator it;
    int left_result_sum = 0;
 
    for(it=a.begin() + left; it!=a.begin() + right; ++it) {
      if (*it == left_result) {
        ++left_result_sum;
      }
 
    }
 
    if (left_result_sum / (double)(right-left) > 0.5) {
      return left_result;
    }
 
 
    else {
      return -1;
    }
  }
 
  else {
    //count left_result in total > 1/2
    vector<int>::iterator it;
    int left_result_sum = 0;
    int right_result_sum = 0;
    for(it=a.begin() + left; it!=a.begin() + right; ++it) {
      if (*it == left_result) {
        ++left_result_sum;
      }
 
      if (*it == right_result) {
        ++right_result_sum;
      }
    }
 
    if (left_result_sum / (double)(right-left) > 0.5) {
      return left_result;
    }
 
    else if (right_result_sum / (double)(right-left) > 0.5) {
      return right_result;
    }
 
    else {
      return -1;
    }
  }
}
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
 