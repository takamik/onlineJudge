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

int calcCycleLength(int input, int req1, int req2) {
  int num, i;
  for (i=1,num=input;num!=1;i++) {
    num = calc(num);
//    if(num > req1-1 && num < i ) {return 0;}
  }
  return i;
}

int calcMaxCycleLength (int s, int e) {
  int i, num;
  for (i=s,num=0; i<=e; i++) {
    int cmpnum = calcCycleLength(i, s, e);
    num = num > cmpnum ? num : cmpnum;
  }
  return num;
}

int main () {
  ios::sync_with_stdio(false);
//  int min,max;
//  cin >> min >> max; cin.ignore();

  while (1) {
    int num1,num2;
    cin >> num1 >> num2;
//cout << min(num1, num2);

    int num = calcMaxCycleLength(min(num1, num2), max(num1, num2));
    cout << num1 << ' ' << num2 << ' ' << num << endl;
//    cout << min << ' ' << max << ' ' << endl;
    if (cin.eof()) { break; }
  }

//  cout << min << ' ' << max << endl;
//  int num = calcMaxCycleLength(min, max);
//  cout << s << ' ' << e << ' ' << num << '\n';
  return 0;
}	






