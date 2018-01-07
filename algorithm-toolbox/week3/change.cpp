#include <iostream>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;

int get_change(int m) {
  //write your code here
	int number_coins = 0;

	if (m == 0) {
		return 0;
	}

	int ten = m - 10;
	while (ten >= 0) {
		ten = ten - 10;
		++number_coins;
	}

	// cout<<"ten is "<<number_coins<<endl;

	int five = m%10;
	if (five >= 5) {
		++number_coins;
	}

	// cout<<"ten and five is "<<number_coins<<endl;

	int ones = m % 5 -1;
	while (ones >= 0) {
		--ones;
		++number_coins;
	}

	return number_coins;
}

void test_solution() {
	assert(get_change(2) == 2);
	cout<<"28 is "<<get_change(28)<<endl;
	assert(get_change(28) == 6);
	assert(get_change(100) == 10);
	assert(get_change(155) == 16);
}

int main() {
	int m;
	//test_solution();
	cin >> m;
	cout << get_change(m) << '\n';
}
