// 100.cpp //
#include <iostream>
#include <cstdlib> //<stdlib.h>
#include <cstring> //<string.t>
using namespace std;

int calc(int num) {
  if (num == 1) { return 1; }
  else if (num % 2 == 1) { return (3 * num) + 1; }
  else { return num/2; }
}

int getCycleNum(int input, int req1, int req2) {
  int num, i;
  int flg1 = 0;
  int flg2 = 0;
  for (i=1,num=input;num!=1;i++) {
cout << num << ' ';
    if (num == req1) { flg1 = 1; }
    if (num == req2) { flg2 = 1; }
    num = calc(num);
  }
cout << '\n';
  return flg1 == 1 && flg2 == 1  ? i : 0;
}

int getMaxCycleNum (int s, int e) {
  int i, num;
  for (i=s,num=0; i<=e; i++) {
    int cmpnum = getCycleNum(i, s, e);
    num = num > cmpnum ? num : cmpnum;
  }
  return num;
}

int main ( int argc, char* argv[] ) {
  char* s = argv[1];
  char* e = argv[2];
  
  int num = getMaxCycleNum(atoi(s), atoi(e));
  cout << s << ' ' << e << ' ' << num << '\n';
  return 0;
}	




