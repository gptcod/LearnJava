#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::sort;

struct Segment {
  int start, end;
};

bool compare_entry(const Segment &s1,const Segment &s2) {
  return s1.end < s2.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  sort(segments.begin(), segments.end(), compare_entry);
  int i = 0;

  while(i < segments.size()) {
    points.push_back(segments[i].end);
    int j = i+1;

    while(j< segments.size() && segments[i].end >= segments[j].start && segments[i].end <= segments[j].end ) {
      ++j;
    }

    i = j;
  }
  
  return points;
}

int main() {
  int n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";

  for (size_t i = 0; i < points.size(); ++i) {
    cout << points[i] << " ";
  }

}
