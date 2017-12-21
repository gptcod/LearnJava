#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  int n = numbers.size();
  int index1 = -1;
  for (int i = 0; i < n; ++i) {
    if ( (index1 == -1) || (numbers[i] > numbers[index1]) ) {
      index1 = i;
    }
  }

  int index2 = -1;
  for (int j = 0; j < n; ++j) {
    if ( (j != index1) && ((-1 == index2) || (numbers[j] > numbers[index2]) )) {
      index2 = j;
    }
  }

  return ((long long) (numbers[index1])) * (numbers[index2]);
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    cout << result << endl;
    return 0;
}
