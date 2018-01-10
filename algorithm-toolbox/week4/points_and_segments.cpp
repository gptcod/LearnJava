#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::sort;

struct Segment
{
  int start;
  int end;
  /* data */
};

bool sorted_by_start(const Segment &s1, const Segment &s2) {
  if (s1.start == s2.start) {
    return (s1.end < s2.end);
  }

  return (s1.start < s2.start);
}


//0 2 7


//1 6 11

/*
binary_serach_start_min_upper_index refer to not fu he condition elements
*/
int binary_serach_start_min_upper_index(vector<Segment> segments, int target) {
  int l = 0;
  int r = segments.size()-1;
  int mid = l + (r-l) / 2;

  //l=0, r=0, mid = 0
  //l=0, r=1, mid = 0
  //l=0, r=2, mid = 1

  //[mid, r], r+1-mid
  //[l, mid], l==mid, 
  //if l==mid, 1 elment, if l+1==mid, 2 element
  if (mid == r) {
    // l mid [l, mid]
    if (segments[mid].start > target) {
      // cout<<"u11"<<endl;
      return 1;
    }

    else {
      // cout<<"u12"<<endl;
      return 0;
    }
  }

  //[mid+1, r] [mid+1, r+1)

  while (l<=r && mid <=r-1) {
    if (segments[mid].start <= target && segments[mid+1].start > target) {
      // cout<<"u21"<<endl;
      return r - mid;
    }

    else if (segments[mid].start <= target && segments[mid-1].start <= target) {
      // cout<<"u22"<<endl;
      l = mid + 1;
      mid = l + (r-l) / 2;
    }

    else {
      // cout<<"u23"<<endl;
      r = mid - 1;
      mid = l + (r-l) / 2;
    }
  }

  //  if (mid == r) {
  //   if (segments[mid].start < target) {
  //     cout<<"u31"<<endl;
  //     return 1;
  //   }

  //   else {
  //     cout<<"u32"<<endl;
  //     return 0;
  //   }
  // }

 if (mid == r) {
    // l mid [l, mid]
    if (segments[mid].start > target) {
      // cout<<"u41"<<endl;
      return 1;
    }

    else {
      // cout<<"u42"<<endl;
      return 0;
    }
  }

  // cout<<"u51"<<endl;
  return 0;
} 

/*
binary_serach_end_max_lower_index refer to not fu he condition elements
*/

int binary_serach_end_max_lower_index(vector<Segment> segments, int target) {
  int l = 0;
  int r = segments.size()-1;
  int mid = l + (r-l) / 2;

  //l=0, r=0, mid = 0
  //l=0, r=1, mid = 0

  if (mid == 0) {
    if (l == r) {
      if (segments[mid].end < target) {
        // cout<<"w11"<<endl;
        return 1;
      }

      else {
        // cout<<"w12"<<endl;
        return 0;
      }
    }

    else {//l=0, r=1{
        if (segments[r].end < target) {
          // cout<<"w21"<<endl;
          return 2;
        }

        else if (segments[l].end < target) {
          // cout<<"w22"<<endl;
          return 1;
        }

        else {
          // cout<<"w23"<<endl;
          return 0;
        }
    }
  }

  while (l<=r && mid>=1) {
    if (segments[mid].end >= target && segments[mid-1].end< target) {
      // cout<<"w31"<<endl;
      return mid-l;
    }

    else if (segments[mid].end >= target && segments[mid-1].end >=target) {
      // cout<<"w32"<<endl;
      r = mid - 1;
      mid = l + (r-l) / 2;
    }

    else {
      // cout<<"w33"<<endl;
      l = mid + 1;
      mid = l + (r-l) / 2;
    }
  }

  if (mid == 0) {
    if (l == r) {
      if (segments[mid].end < target) {
        // cout<<"w41"<<endl;
        return 1;
      }

      else {
        // cout<<"w42"<<endl;
        return 0;
      }
    }

    else {//l=0, r=1{
        if (segments[r].end < target) {
          // cout<<"w51"<<endl;
          return 2;
        }

        else if (segments[l].end < target) {
          // cout<<"w52"<<endl;
          return 1;
        }

        else {
          // cout<<"w53"<<endl;
          return 0;
        }
    }
  }

  // cout<<"w61"<<endl;
  return 0;
} 

bool sorted_by_end(Segment &s1, Segment &s2) {
  if (s1.end == s2.end) {
    return (s1.start < s2.start);
  }

  return (s1.end < s2.end);
}

// vector<int> fast_count_segments_by_point(vector<int> starts, vector<int> ends, int point) {
//   vector<int> cnt(points.size());
//   int length_segments = starts.size();
//   //write your code here
//   vecotr<Segment> segments_sorted_start(length_segments);
//   vecotr<Segment> segments_sorted_end(length_segments);

//   for (int i=0; i<length_segments; ++i) {
//     segments_sorted_start[i].start = starts[i];
//     segments_sorted_start[i].end = ends[i];
//     segments_sorted_end[i].starts = starts[i];
//     segments_sorted_end[i].end = ends[i];
//   }

//   sort(segments_sorted_start.begin(), segments_sorted_start.end(), sorted_by_start);
//   int lower_not_index = binary_serach_start_min_upper_index(segments_sorted_start, point);
//   sort(segments_sorted_end.begin(), segments_sorted_end.end(), sorted_by_end);
//   int upper_not_index = binary_serach_end_max_lower_index(segments_sorted_start, point);

//   return length_segments - lower_not_index - upper_not_index;
// }

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  int length_segments = starts.size();
  //write your code here
  vector<Segment> segments_sorted_start(length_segments);
  vector<Segment> segments_sorted_end(length_segments);

  for (int i=0; i<length_segments; ++i) {
    segments_sorted_start[i].start = starts[i];
    segments_sorted_start[i].end = ends[i];
    segments_sorted_end[i].start = starts[i];
    segments_sorted_end[i].end = ends[i];
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
