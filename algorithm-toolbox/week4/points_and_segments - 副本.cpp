#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

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

vector<int> cnt;

bool sort_compare(Point &p1, Point &p2) {
  return p1.loc < p2.loc;
}

vector<int, int, int> points_info;

sort(points_info.begin(), points_info.end(), sort_compare);

for (int i=0; i<points_info.size(); ++i) {
  int counter = 0;
  
  if(points_info[i].type == -1) {
    ++counter;
  }

  else if (points_info[i].type == 1) {
    --counter;
  }

  else {
    cnt[points_info[i].prior_index] = counter;
  }
}



vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  int length_all = 2 * starts.size() + points.size();
  vector<int> cnt(points.size());
  vector<points_info> all_points(length_all);
  //write your code here
 

  for (int i=0; i<length_all; ++i) {
    all_points[i] = 
  }

  sort(segments_sorted_start.begin(), segments_sorted_start.end(), sorted_by_start);
  sort(segments_sorted_end.begin(), segments_sorted_end.end(), sorted_by_end);
  int min_not_index = 0;
  int max_not_index = 0;

  for (int i=0; i<points.size(); ++i) {
    // cout<<"point:"<<points[i]<<endl;
    min_not_index = binary_serach_start_min_upper_index(segments_sorted_start, points[i]);
    max_not_index = binary_serach_end_max_lower_index(segments_sorted_start, points[i]);
    cnt[i] = length_segments - min_not_index - max_not_index;
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
