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

int get_majority_element_2(vector<int> &a, int left, int right) {
  map<int, int> number_count;
  map<int, int>::iterator it_map;
  vector<int>::iterator it_vec;
  int max = 0;

  for (it_vec = a.begin(); it_vec != a.begin() + right; ++it_vec) {
    it_map = number_count.find(*it_vec); 
    if (it_map != number_count.end()) {
      number_count[*it_vec] = number_count[*it_vec] + 1;
    }

    else {
      number_count[*it_vec] = 1;
    }
  }

  for (it_map=number_count.begin(); it_map!=number_count.end(); ++it_map) {
    if (it_map -> second > max) {
      max = it_map -> second;
    }
  }

  //cout<<max<<endl;

  if (max > right / 2) {
    return 1;
  }  



  else {
    return -1;
  }

}

int get_majority_element_3(vector<int> &a, int left, int right) {
  cout<<"^^^left:"<<left<<endl;
  cout<<"^^^right:"<<right<<endl;

  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int mid = (left + right) / 2;
  int left_result = get_majority_element_3(a, left, mid); //[left, mid]
  int right_result = get_majority_element_3(a, mid, right);//len=
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
    cout<<"way 1"<<endl;
    cout<<"left:"<<left<<endl;
    cout<<"left_result"<<left_result<<endl;
    cout<<"right:"<<right<<endl;
    cout<<"right_result"<<right_result<<endl;
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
      cout<<"way 4.2"<<endl;
      cout<<"left:"<<left<<endl;
      cout<<"left_result"<<left_result<<endl;
      cout<<"right:"<<right<<endl;
      cout<<"right_result"<<right_result<<endl;
      return right_result_sum;
    }

    else {
      cout<<"way 4.3"<<endl;
      cout<<"left:"<<left<<endl;
      cout<<"left_result"<<left_result<<endl;
      cout<<"right:"<<right<<endl;
      cout<<"right_result"<<right_result<<endl;
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
      cout<<"way 4.1"<<endl;
      cout<<"left:"<<left<<endl;
      cout<<"left_result"<<left_result<<endl;
      cout<<"right:"<<right<<endl;
      cout<<"right_result"<<right_result<<endl;
      return left_result;
    }


    else {
      cout<<"way 4.3"<<endl;
      cout<<"left:"<<left<<endl;
      cout<<"left_result"<<left_result<<endl;
      cout<<"right:"<<right<<endl;
      cout<<"right_result"<<right_result<<endl;
      return -1;
    }
  }

  else {
    cout<<"way 4"<<endl;
    cout<<"left:"<<left<<endl;
    cout<<"left_result"<<left_result<<endl;
    cout<<"right:"<<right<<endl;
    cout<<"right_result"<<right_result<<endl;
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
      cout<<"way 4.1"<<endl;
      cout<<"left:"<<left<<endl;
      cout<<"left_result"<<left_result<<endl;
      cout<<"right:"<<right<<endl;
      cout<<"right_result"<<right_result<<endl;
      return left_result;
    }

    else if (right_result_sum / (double)(right-left) > 0.5) {
      cout<<"way 4.2"<<endl;
      cout<<"left:"<<left<<endl;
      cout<<"left_result"<<left_result<<endl;
      cout<<"right:"<<right<<endl;
      cout<<"right_result"<<right_result<<endl;
      return right_result;
    }

    else {
      cout<<"way 4.3"<<endl;
      cout<<"left:"<<left<<endl;
      cout<<"left_result"<<left_result<<endl;
      cout<<"right:"<<right<<endl;
      cout<<"right_result"<<right_result<<endl;
      return -1;
    }
  }
}

int get_majority_element(vector<int> &a, int left, int right) {
  // cout<<"^^^left:"<<left<<endl;
  // cout<<"^^^right:"<<right<<endl;

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
    // cout<<"way 1"<<endl;
    // cout<<"left:"<<left<<endl;
    // cout<<"left_result"<<left_result<<endl;
    // cout<<"right:"<<right<<endl;
    // cout<<"right_result"<<right_result<<endl;
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
      // cout<<"way 4.2"<<endl;
      // cout<<"left:"<<left<<endl;
      // cout<<"left_result"<<left_result<<endl;
      // cout<<"right:"<<right<<endl;
      // cout<<"right_result"<<right_result<<endl;
      return right_result_sum;
    }

    else {
      // cout<<"way 4.3"<<endl;
      // cout<<"left:"<<left<<endl;
      // cout<<"left_result"<<left_result<<endl;
      // cout<<"right:"<<right<<endl;
      // cout<<"right_result"<<right_result<<endl;
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
      // cout<<"way 4.1"<<endl;
      // cout<<"left:"<<left<<endl;
      // cout<<"left_result"<<left_result<<endl;
      // cout<<"right:"<<right<<endl;
      // cout<<"right_result"<<right_result<<endl;
      return left_result;
    }


    else {
      // cout<<"way 4.3"<<endl;
      // cout<<"left:"<<left<<endl;
      // cout<<"left_result"<<left_result<<endl;
      // cout<<"right:"<<right<<endl;
      // cout<<"right_result"<<right_result<<endl;
      return -1;
    }
  }

  else {
    // cout<<"way 4"<<endl;
    // cout<<"left:"<<left<<endl;
    // cout<<"left_result"<<left_result<<endl;
    // cout<<"right:"<<right<<endl;
    // cout<<"right_result"<<right_result<<endl;
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
      // cout<<"way 4.1"<<endl;
      // cout<<"left:"<<left<<endl;
      // cout<<"left_result"<<left_result<<endl;
      // cout<<"right:"<<right<<endl;
      // cout<<"right_result"<<right_result<<endl;
      return left_result;
    }

    else if (right_result_sum / (double)(right-left) > 0.5) {
      // cout<<"way 4.2"<<endl;
      // cout<<"left:"<<left<<endl;
      // cout<<"left_result"<<left_result<<endl;
      // cout<<"right:"<<right<<endl;
      // cout<<"right_result"<<right_result<<endl;
      return right_result_sum;
    }

    else {
      // cout<<"way 4.3"<<endl;
      // cout<<"left:"<<left<<endl;
      // cout<<"left_result"<<left_result<<endl;
      // cout<<"right:"<<right<<endl;
      // cout<<"right_result"<<right_result<<endl;
      return -1;
    }
  }

}

int main() {
  int n;
  while (true) {
    n = rand() % 200;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
      a[i] = rand() % 5;
    }

    int result_one = get_majority_element(a, 0, a.size());
    int result_two = get_majority_element_2(a, 0, a.size());


    bool flag_one = (get_majority_element(a, 0, a.size()) != -1);
    bool flag_two = (get_majority_element_2(a, 0, a.size()) != -1);
    vector<int>::iterator it;
    // cout<<"len of vector is:"<<a.size()<<endl;
    // cout<<"flag_one:"<<flag_one<<endl;
    // cout<<"flag_two:"<<flag_two<<endl;


    if (flag_one != flag_two) {
      int result_three = get_majority_element_3(a, 0, a.size());

      cout<<"result_three:"<<result_three<<endl;
      cout<<"len of vector is:"<<a.size()<<endl;
      cout<<"flag_one:"<<flag_one<<endl;
      cout<<"flag_two:"<<flag_two<<endl;
      cout<<"result_one:"<<result_one<<endl;
      cout<<"result_two:"<<result_two<<endl;
       cout<<"vector a is:";


      for (it = a.begin(); it!=a.end(); ++it) {
        cout<<*it<<" ";
      }
      cout<<endl;
    }

  }
  // std::cin >> n;
  
  // std::cout << () << '\n';
}
