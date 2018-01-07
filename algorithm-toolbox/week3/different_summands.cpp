#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

vector<int> optimal_summands(int n) {
  vector<int> summands;

  int remain = n;
  int mini = 1;
  while(remain > 0 && remain > 2*mini) {  
    summands.push_back(mini);
    remain = remain - mini;
    ++mini;
  }

  if (remain > 0) {
    summands.push_back(remain);
  }

  return summands;
}

int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}
