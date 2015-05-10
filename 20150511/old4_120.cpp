//Problem 120
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=56
#include <iostream>
#include <cstdlib> //<stdlib.h>
//#include <cstring> //<string.t>
#include <algorithm>
//#include <vector>
using namespace std;

int maxlen_num_list = 30;

vector<int> createNumList() {
  vector<int> num_list(maxlen_num_list);
  int num;

  int i = 0;
  while (i < maxlen_num_list+1) {
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

  num_list.resize(i-1);

  cout << endl;
  return num_list;
}

vector<int> reverseNumList(vector<int> num_list) {
  
  
}

int main () {
  vector<int> num_list(createNumList());
  int num_length = num_list.size();

//  max
//  cout << *max_element(num_list.begin(), num_list.end()) << ' ';
//  max_index
//  cout << distance(num_list.begin(), max_element(num_list.begin(), num_list.end())) << ' ';

  //while(num_list.
  vector<int>::iterator max = max_element(num_list.begin(), num_list.end());
  if(*max == num_list.back()){
    num_list.pop_back();
    //no flip
  }
  else if(*max == num_list.front()){
    cout << 1 << ' ';
    reverse(num_list.begin(), num_list.end());
  }
  else {
    cout << num_length - distance(num_list.begin(), max) << ' ';
    reverse(num_list.begin(), max+1);
  }

cout << 0 << "end" << endl;

//* ///////////////////////////////////
  auto itr = num_list.begin();
  while(itr != num_list.end()) {
  //while(*itr != 0) {
    cout << *itr << ' ';
    ++itr;
  }
//*/ //////////////////////////////////



//  cout << endl << num_list.back();
//  num_list.erase(num_list.end()-1);
//  cout << endl << num_list.back();


//  cout << 0;
  cout << endl;
  return 0;
}
