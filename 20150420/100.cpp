// 100.cpp //
#include <iostream>
#include <cstdlib> //<stdlib.h>
#include <cstring> //<string.t>
#include <algorithm>
using namespace std;


int calc(int num) {
  if (num == 1) { return 1; }
  else if (num % 2 == 1) { return (3 * num) + 1; }
  else { return num/2; }
}

int calcCycleLength(int input) {
  int num, i;
  for (i=1,num=input;num!=1;i++) {
    num = calc(num);
  }
  return i;
/*
  i=1;
  while(num != 1) {
    num = calc(num);
    ++i;
  }
  return i;
*/
}

int calcMaxCycleLength (int min, int max) {
  int i, maxlength, cmpnum;
  maxlength=0;
  for (i=min; i<=max; i++) {
    cmpnum = calcCycleLength(i);
    maxlength = std::max(maxlength,cmpnum);
  }
  return maxlength;
}

int main () {
//  ios::sync_with_stdio(false);
  int in_num1,in_num2,maxlength;

  while (1) {
    cin >> in_num1 >> in_num2;
    if(cin.fail()) {
      cin.clear();
      cin.ignore();
    } else {
      maxlength = calcMaxCycleLength(min(in_num1, in_num2), max(in_num1, in_num2));
      cout << in_num1 << ' ' << in_num2 << ' ' << maxlength << endl;
    }
    if(cin.eof()){ break; }
  }

  return 0;
}
