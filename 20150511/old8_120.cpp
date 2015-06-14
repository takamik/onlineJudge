//Problem 120
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=56
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> createNumList() {
  //vector<int> num_list(maxlen_num_list);
  vector<int> num_list;
  int num;

  int i = 0;
  while (cin >> num) {
    //cin >> num;
    cout << num << ' ';
    num_list[i++] = num;

    //if(cin.eof()){ break; }
    if(num == 0){ break; }
  }

//  num_list.resize(i-1);

  cout << endl;
  return num_list;
}

int sortNumList(vector<int> num_list) {
  vector<int>::iterator max = max_element(num_list.begin(), num_list.end());
  int num_length = num_list.size();
  int cnt = 1;

  while(cnt < num_length+1){
    max = max_element(num_list.begin(), num_list.end());
    
    if(*max == num_list.back()){
      //no reverse
      num_list.pop_back();
      ++cnt;
    }
    else if(*max == num_list.front()){
      cout << cnt << ' ';
      reverse(num_list.begin(), num_list.end());
    }
    else {
      cout << (num_length - distance(num_list.begin(), max)) << ' ';
      reverse(num_list.begin(), max+1);
    }
  }

  cout << 0 << endl;
  return 0;
}

int main () {

//  vector<int> num_list(createNumList());
//  sortNumList(num_list);
createNumList();

  return 0;
}
