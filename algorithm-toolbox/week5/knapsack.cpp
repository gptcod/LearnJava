#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n = w.size();
  vector<vector<int>> weight_element(W + 1);
  for(int i=0; i<W+1;i++) {
    weight_element[i].resize(n + 1);
  }


  vector<int> w2(n+1);

  w2[0] = 0;

  for (int i=0; i<n; ++i) {
    w2[i+1] = w[i];
  }


  for (int i=0; i<n+1; ++i) {
    weight_element[0][i] = 0;
  }


  for (int i=0; i<W+1; ++i) {
    weight_element[i][0] = 0;
  }


  for (int i=1; i<=n; ++i) {
    for (int w=1; w<=W; ++w) {
      weight_element[w][i] = weight_element[w][i-1];

      if (w - w2[i] >= 0) {
        int value = weight_element[w - w2[i]][i-1] + w2[i];

        // cout<<"i is "<<i<<","<<"w is "<<w<<endl;
        // cout<<"weight_element[w - w2[i]][i] + w2[i]"<<weight_element[w - w2[i]][i] + w2[i]<<endl;
        // cout<<"w2[i]:"<<w2[i]<<endl;
        // cout<<"value is:"<<value<<endl;


        if (value > weight_element[w][i]) {
          weight_element[w][i] = value;
          // cout<<"i is "<<i<<","<<"w is "<<w<<endl;
          //  cout<<"weight_element[w][i]:"<<weight_element[w][i]<<endl;
        }

      }
    }
  }
  
  return weight_element[W][n];
}

int main() {
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  cout << optimal_weight(W, w) << '\n';
}
