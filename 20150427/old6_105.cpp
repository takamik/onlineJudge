// 100.cpp //
#include <iostream>
#include <cstdlib> //<stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
  int left,height,right;
  vector<int> vertical(10001);
  int horizontal, max_horizontal;
  max_horizontal = 0;

  //construction of building
//  int i = 0;
  while (1) {
    if(cin.eof()){ break; }
    cin >> left >> height >> right;
    cout << left << ' ' << height << ' ' << right << endl;

      for(horizontal=left; horizontal<right; horizontal++){
        vertical[horizontal] = max(vertical[horizontal], height);
      }
      max_horizontal = max(horizontal, max_horizontal);

/*
      if(out_vector[out_size] < out_vector[out_size-1]){
        out_vector[out_size-1] = out_vector[out_size];
      } else if(max_right < right[i]) {
        out_vector[out_size-1] = 0;
      }
    }

    max_right = (right[i] < max_right) ? max_right: right[i];
*/
//    i = i++;
  }

  vertical[max_horizontal+1] = -1;

/*
vertical.resize(max_horizontal);
for(int i=0; i<max_horizontal; i++) {
  cout << vertical[i] << ' ';
}
*/
/*
int i=0;
while(1) {
  if(vertical[i]==-1) break;
  cout << vertical[i] << ' ';
  i++;
}
cout << endl << max_horizontal << " " << vertical.size() << endl;
*/
//  out_vector[max_right-1] = out_vector[max_right-2];

//  out_vector.resize(max_right+1);

/**** /
  for(int i=0; i<max_right+1; i++){
    cout << out_vector[i] << ' ';
  }
  cout << endl;
/****/

/*
//output vector
  int prev_v = 0;
  for(int i=0; i<max_right+1; i++){
    if(prev_v != out_vector[i]){
      cout << i << ' ' << out_vector[i] << ' ';
    }
    prev_v = out_vector[i];
  }
  cout << endl;
*/

  horizontal = 0;
  int prev_v = 0;
  while(1) {
    if(vertical[horizontal]==-1) {
      //cout << horizontal << ' ' << 0;
      break;
    }

    if(prev_v != vertical[horizontal]){
      cout << horizontal << ' ' << vertical[horizontal] << ' ';
    }
    prev_v = vertical[horizontal];

    horizontal++;
  }
  cout << endl << max_horizontal << " " << vertical.size() << endl;

  return 0;
}





