#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::min;
using std::endl;
//get from n to 1

vector<int> optimal_sequence(int n) {
  vector<int> all_steps(n + 1);

  all_steps[0] = 0;
  all_steps[1] = 0;

  for (int i=2; i<=n; ++i) {  
    int result = i;
    int result_mul_3 = i;
    int result_mul_2 = i;
    int result_add = i;


    if (i % 3 == 0) {
      result_mul_3 = all_steps[i / 3] + 1;
    } 

    if (i % 2 == 0) {
      result_mul_2 = all_steps[i / 2] + 1;
    } 

    if(i - 1 >= 1){
      result_add = all_steps[i - 1] + 1;
    }

    result = min(min(result_mul_3, result_mul_2), result_add);

    all_steps[i] = result;    
  }

  vector<int> sequence;

  while (n >= 1) {
    sequence.push_back(n);

    if (n % 3 == 0) {
      n /= 3;
    }

    else if (n % 2 == 0) {
      if (all_steps[n] == all_steps[n/2] + 1) {
        n /= 2;
      }

      else {
        n -= 1;
      }
    }

    else {
      n = n - 1;
    }

  }
  
  reverse(sequence.begin(), sequence.end());
  return sequence;
}



int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
