// 100.cpp //
#include <iostream>
#include <cstdlib> //<stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
  vector<int> left(10000),height(10000),right(10000),out_vector(10000);
  int out_size,max_right;
  max_right = 0;

  //construction of building
  int i = 0;
  while (1) {
    cin >> left[i] >> height[i] >> right[i];

    if(cin.fail()) {
break;
      cin.clear();
      cin.ignore();
    } else {
      for(out_size=left[i]; out_size<right[i]+1; out_size++){
        out_vector[out_size] = max(out_vector[out_size], height[i]);
      }

      if(out_vector[out_size] < out_vector[out_size-1]){
        out_vector[out_size-1] = out_vector[out_size];
      } else if(max_right < right[i]) {
        out_vector[out_size-1] = 0;
      }
    }

    max_right = (right[i] < max_right) ? max_right: right[i];

    if(cin.eof()){ break; }
    i = i++;
  }

  out_vector[max_right-1] = out_vector[max_right-2];

  out_vector.resize(max_right+1);

/****/
  for(int i=0; i<max_right+1; i++){
    cout << out_vector[i] << ' ';
  }
  cout << endl;
/****/

//output vector
  int prev_v = 0;
  for(int i=0; i<max_right+1; i++){
    if(prev_v != out_vector[i]){
      cout << i << ' ' << out_vector[i] << ' ';
    }
    prev_v = out_vector[i];
  }
  cout << endl;

  return 0;
}
