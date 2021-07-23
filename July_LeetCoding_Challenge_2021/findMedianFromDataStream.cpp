#include <bits/stdc++.h>
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;
class MedianFinder {
public:
  ordered_set q;
  int size = 0;
  /** initialize your data structure here. */
  MedianFinder() {
    if (size() % 2 == 1) {
    }
  }

  void addNum(int num) {}

  double findMedian() {}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
