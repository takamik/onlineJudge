// 100.cpp //
#include <iostream>
#include <cstdlib> //<stdlib.h>
#include <cstring> //<string.t>
#include <algorithm>
#include <vector>
using namespace std;




int main () {
//  int left,height,right;
  vector<int> stack(31);
  string str;
  int cake;

  int i = 0;
  //while (1) {
  //while (cin >> cake) {
  while (i < 31) {
    //cin >> left >> height >> right;
    //getline(cin, str);

    if(cin.fail()) {
      cin.clear();
      cin.ignore();
break;
    } else {
      cin >> cake;
      cout << cake << ' ';
      stack[i++] = cake;

      //cout << left << ' ' << height << ' ' << right << endl;
      //cout << str << endl;
      //cout << cake << ' ';
    }

    //cout << 'a';
    //if(cake.eof()){ break; }
    if(cin.eof()){ break; }

    //++i;
  }
 
  auto itr = stack.begin();
  //while(itr != stack.end()){
  while(*itr == 0){
    cout << *itr << ' ';
    ++itr;
  }

  cout << endl;

  return 0;
}
