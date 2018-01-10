#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
//Notice:why use 1 3 2,because 1 refer to enter in, 3 refer to enter out


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
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
