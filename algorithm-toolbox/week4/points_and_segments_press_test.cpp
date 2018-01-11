#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <cstdlib>
 
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
 
struct Point {
  int loc;
  int type; //-1 refer to open point, 1 refer to close point, 0 refer to points
  int prior_index;  
};
 
 
bool sort_compare(Point &p1, Point &p2) {
    if (p1.loc == p2.loc) {
        return p1.type < p2.type;
    }
 
    return p1.loc < p2.loc;
}
 
 
 
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  int length_all = 2 * starts.size() + points.size();
  vector<Point> all_points(length_all);
  //write your code here
 
 
  for (int i=0; i<length_all; ++i) {
    if (i<starts.size()) {
       all_points[i].loc = starts[i];
       all_points[i].type = 1;
    }
 
    else if (i>=starts.size() && i<2*starts.size()) {
      all_points[i].loc = ends[i-starts.size()];
      all_points[i].type = 3;
    }
 
    else {
      all_points[i].loc = points[i-2*starts.size()];
      all_points[i].type = 2;
      all_points[i].prior_index = i-2*starts.size();
    }
  }
 
  sort(all_points.begin(), all_points.end(), sort_compare);
 
  cout<<"all the sorted number is:"<<endl;
  for (int i=0; i<all_points.size(); ++i){
    cout<<" "<<all_points[i].loc;
  }
  cout<<endl;
 
  int counter = 0;
 
  for (int i=0; i<all_points.size(); ++i) {
    if(all_points[i].type == 1) {
      ++counter;
    }
 
    else if (all_points[i].type == 3) {
      --counter;
    }
 
    else {
      cnt[all_points[i].prior_index] = counter;
    }
  }
 
  return cnt;
}
 
 
vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}
 
int main() {
  int n, m;
 
  while (true) {
    n = rand() % 10;
    m = rand() % 10;
 
    vector<int> starts(n), ends(n);
 
 
    for (size_t i = 0; i < starts.size(); i++) {
        starts[i] = rand() % 100;
        ends[i] =  starts[i] + 1 + rand() % 100;;
    }
    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        points[i] = rand () % 52;
    }
    //use fast_count_segments
    vector<int> cnt = fast_count_segments(starts, ends, points);
    vector<int> cnt2 = naive_count_segments(starts, ends, points);
    for (size_t i = 0; i < cnt.size(); i++) {
        if (cnt[i] != cnt2[i]) {
            for (size_t i = 0; i < starts.size(); i++) {
                cout<<"("<<starts[i]<<","<<ends[i]<<")";
            }
 
            cout<<"points:";
            for (size_t i = 0; i < points.size(); i++) {
                cout<<" "<<points[i];
            }
 
            cout<<"fast:"<<endl;
            for (size_t i = 0; i < cnt.size(); i++) {
              cout<<" "<<cnt[i];
            }
            cout<<endl;
 
            cout<<"native:"<<endl;
            for (size_t i = 0; i < cnt.size(); i++) {
                cout<<" "<<cnt2[i];
            }
            cout<<endl;
 
        break;
        }
    }
  }
 
  // count = fast_count_segments(starts, ends, point);
  // cout<<"count:"<<count<<endl;
}