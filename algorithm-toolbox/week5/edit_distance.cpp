#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::min;
using std::vector;
using std::cout;
using std::endl;

int edit_distance(const string &str1, const string &str2) {
	int s1 = str1.size();
	int s2 = str2.size();

	vector<vector<int>> distances(s1 + 1);

	for (int i=0; i<=s1; ++i) {
		distances[i].resize(s2 + 1);
	}

	for (int i=0; i<=s1; ++i) {
		distances[i][0] = i;
	}

	for (int i=0; i<=s2; ++i) {
		distances[0][i] = i;
	}

	for (int i=1; i<=s1; ++i) {
		for (int j=1; j<=s2; ++j) {
			int diag = (str1[i-1] == str2[j-1] ? distances[i-1][j-1] : distances[i-1][j-1] + 1);

			int result = min(diag, min(distances[i-1][j] + 1, distances[i][j-1] + 1));

			// cout<<"i:"<<i<<","<<"j:"<<j<<endl;
			// cout<<"result is "<<result<<endl;
			distances[i][j] = result;
		}
	}
  //write your code here
  return distances[s1][s2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
