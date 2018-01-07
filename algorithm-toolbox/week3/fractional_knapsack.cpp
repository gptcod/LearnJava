#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::greater;
using std::min;

struct  per_value_struct
{
  double per_value;
  int index;
};

bool compare(per_value_struct s1, per_value_struct s2) {
    return (s1.per_value > s2.per_value);
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  if (capacity == 0) {
      return value;
  }

  int n = weights.size();
  vector<int> new_weights(n);
  vector<int> new_values(n);

  vector<struct per_value_struct> per_value(n);
  for (int i=0; i<n; ++i) {
    per_value[i].per_value = (double)values[i] / weights[i];
    per_value[i].index = i;
  }

  sort(per_value.begin(), per_value.end(), compare);
  //rearrange
  for (int i=0; i<n; ++i) {
    new_weights[i] = weights[per_value[i].index];
    new_values[i] = values[per_value[i].index];
  }

  for (int i=0; i<n; ++i) {
    if (capacity == 0) {
      return value;
    }

    // cout<<per_value[i].per_value<<endl;
    int exist_capacity = min(capacity, new_weights[i]);
    // cout<<"real_number "<<i<<" is "<<exist_capacity<<endl;
    value += (double)(exist_capacity * per_value[i].per_value);
    // cout<<"value "<<i<<" is "<<value<<endl;
    capacity = capacity - exist_capacity;
    // cout<<"capacity "<<i<<" is "<<capacity<<endl;

  }
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
