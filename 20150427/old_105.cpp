// 100.cpp //
#include <iostream>
#include <cstdlib> //<stdlib.h>
#include <cstring> //<string.t>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
  int in_left,in_height,in_right,i;
  i=0;
//  int output[50]; 
  vector<int> output;

  //construction of building
  while (1) {
    cin >> in_left >> in_height >> in_right;
    if(cin.fail()) {
      cin.clear();
      cin.ignore();
    } else {
//      output[i++] = in_left;
      output[i++] = in_left;
    }
    if(cin.eof()){ break; }
    if(cin == 100){ break; }
  }

//  cout << left << ' ' << height << ' ' << right << endl;

//  for_each(bigin(output), end(output), cout);
  for(auto itr = output.bigin(); itr != output.end(); ++itr){
    cout << *itr;
  }
  cout << endl;

  return 0;
}
