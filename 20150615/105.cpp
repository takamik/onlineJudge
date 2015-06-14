// 105.cpp
// https://uva.onlinejudge.org/external/1/105.pdf
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
  int left,height,right;
  vector<int> vertical(10000);
  int horizontal, max_horizontal;
  max_horizontal = 0;

  //construction of building
  while (cin >> left >> height >> right) {
      for(horizontal=left; horizontal<right; horizontal++){
        vertical[horizontal] = max(vertical[horizontal], height);
      }
    max_horizontal = max(horizontal, max_horizontal);
  }

  vertical[max_horizontal+1] = -1;

  // output line
  horizontal = 0;
  int prev_v = 0;
  while(vertical[horizontal]!=-1) {
    if(prev_v != vertical[horizontal]){
      cout << horizontal << ' ' << vertical[horizontal];
      if(horizontal < max_horizontal) cout << ' ';
    }
    prev_v = vertical[horizontal];

    horizontal++;
  }
  cout << endl;

  return 0;
}





