#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	while(true) {
		int n = rand() % 10 + 2;
		cout<<n<<endl;
		vector<int> a;

		for(int i=0; i<n; ++i) {
			a.push_back(rand() %100000);
		}

		for(int i=0; i<n; ++i) {
			cout<<a[i]<<" ";
		}
		cout<<endl;

		long long res1 = maxPairwiseProduct(a);
		long long res2 = maxPairwiseProductFast(a);

		if (res1 != res2) {
			cout<<"Wrong answer:"<<res1<<" "<<res2<<endl;
			break;
		}
		else {
			cout<<"OK"<<endl;
		}
	}
}
