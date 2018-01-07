#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using std::vector;
using std::string;
using std::stringstream;
using std::greater;
using std::sort;
using std::min;
using std::max;

struct number_struct
{
  string number;
  int index;
};

bool compare(const number_struct &s1, const number_struct &s2) {
  string number_one = s1.number;
  string number_two = s2.number;

  int n1 = number_one.size();
  int n2 = number_two.size();

  int i = 0;
  int j = 0;
  int real_number_one;
  int real_number_two;
  while (i < n1 || j < n2) {
    real_number_one = number_one[i] - '0';
    real_number_two = number_two[j] - '0';
    if ( real_number_one > real_number_two ) {
      return real_number_one > real_number_two;
    }

    else if (real_number_one < real_number_two) {
      return real_number_one > real_number_two;
    }

    else if (i == n1-1 && j== n2-1 && real_number_one == real_number_two) {
    	return real_number_one > real_number_two;
    }

    else {
      if (i+1 != n1) {
        ++i;
      }

      if (j+1 != n2) {
        ++j;
      }

      continue;
    }
  }
    
}

string largest_number_test(vector<string> a) {
	long long number_first = atoi((a[0] + a[1]).c_str());
  	long long number_second = atoi((a[1] + a[0]).c_str());
  
  	return max(number_first, number_second)
}

string largest_number(vector<string> a) {
  string result;
  int n = a.size();
  vector<struct number_struct> first_numbers(n);
  

  for (int i=0; i<n; ++i) {
    first_numbers[i].number = a[i];
    first_numbers[i].index = i;
  }

  sort(first_numbers.begin(), first_numbers.end(), compare);

  //write your code here
  stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[first_numbers[i].index];
  }
  
  ret >> result;
  return result;
}

int main() {
  int n = 2;
   
    
   string s1 = ss.str();

  while(true) {
  	vector<string> a(n);
  	stringstream ss1;
  	stringstream ss2;
  	int t1 = rand() % 10000000;
  	ss1<<t1;
  	a[0] = ss1.str();

  	int t2 = rand() % 10000000;
  	ss2<<t2;
  	a[1] = ss2.str();

  	assert(largest_number_test(a) == largest_number(a));
  }
  
  // std::cout << largest_number(a);
}
