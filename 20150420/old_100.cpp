// 100.cpp //
#include <iostream>
using namespace std;

int calc(int num) {
  if (num == 1) { return 1; }
  else if (num % 2 == 1) { return (3 * num) + 1; }
  else { return num/2; }
}

int getCycleNum(int in) {
  int num = in;
  int i = 1;

  while (num != 1) {
    i++;
    num = calc(num);
  }

  return i;
}

int getMaxCycleNum (int s, int e) {
  int i = 0;
  int num = 0;
/*
  while (i <= e) {
    int cmpnum = getCycleNum(i);
    num = num > cmpnum ? num : cmpnum;
    i++;
  }
*/
  for (i=s; i<=e; i++) {
    int cmpnum = getCycleNum(i);
    num = num > cmpnum ? num : cmpnum;
  }
  
  return num;
}

int main () {
  int s = 1;
  int e = 10;
  int num = getMaxCycleNum(s, e);
  cout << s << ' ' << e << ' ' << num << '\n';
  return 0;
}


























