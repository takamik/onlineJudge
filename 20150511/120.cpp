//Problem 120
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=56
#include <iostream>
#include <cstdlib> //<stdlib.h>
#include <cstring> //<string.t>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> createNumList() {
  vector<int> num_list(31);
  int num;

  int i = 0;
  while (i < 31) {
    if(cin.fail()) {
      cin.clear();
      cin.ignore();
break;
    } else {
      cin >> num;
      cout << num << ' ';
      num_list[i++] = num;
    }
    if(cin.eof()){ break; }
  }
  return num_list;
}

int main () {
  vector<int> num_list(createNumList());
  //vector<int> num_list(31);
  //num_list = createNumList();

  auto itr = num_list.begin();
  while(*itr == 0){
    cout << *itr << ' ';
    ++itr;
  }

  cout << endl;
  return 0;
}
