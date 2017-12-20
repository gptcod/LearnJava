#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int maxPairwiseProduct(const vector<int> &numbers) {
	int n = numbers.size();
	int result = 0;

	for (int i=0; i<n-1; ++i) {
		for (int j=i+1; j<n; ++j) {
			if (numbers[i] * numbers [j] > result) {
				result = numbers[i] * numbers[j];
			}
		}
	}

	return result;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> numbers(n);

	for (int i=0; i<n; ++i) {
		cin >> numbers[i];
	}
	cout<<maxPairwiseProduct(numbers)<<endl;
	return 0;
}