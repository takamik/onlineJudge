// 100.cpp //
#include <iostream>
#include <cstdlib> //<stdlib.h>
#include <cstring> //<string.t>
#include <algorithm>
using namespace std;

int main () {
  int left,height,right;

  while (1) {
    cin >> left >> height >> right;
    if(cin.fail()) {
      cin.clear();
      cin.ignore();
    } else {
      cout << left << ' ' << height << ' ' << right << endl;
    }
    if(cin.eof()){ break; }
  }

  return 0;
}
