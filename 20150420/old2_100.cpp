// 100.cpp //
#include <iostream>
using namespace std;

int calc(int num) {
  if (num == 1) { return 1; }
  else if (num % 2 == 1) { return (3 * num) + 1; }
  else { return num/2; }
}

int getCycleNum(int in) {
  int num, i;
  for (i=1,num=in;num!=1;i++) { num = calc(num); }
  return i;
}

int getMaxCycleNum (int s, int e) {
  int i, num;
  for (i=s,num=0; i<=e; i++) {
    int cmpnum = getCycleNum(i);
    num = num > cmpnum ? num : cmpnum;
  }
  return num;
}

int main ( int argc, char *argv[] ) {
  int s = argv[1];
  int e = argv[2];
//  cout << argv[1] << ' ' << argv[2] << '\n'; 
  if (argv[1] > argv[2]) {
    s = argv[2];
    e = argv[1];
  }

  int num = getMaxCycleNum(s, e);
  cout << s << ' ' << e << ' ' << num << '\n';
  return 0;
}	


























