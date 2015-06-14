//Problem 120
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=56
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

int maxlen_num_list = 30;

vector<int> createNumList(string num_line) {

  vector<int> num_list;
  stringstream ss(num_line);
  char delimiter = ' ';
  string num;

  while (getline(ss, num, delimiter)) {
    if (!num.empty()) {
      num_list.push_back(stoi(num));
    }
  }

/*
  vector<int> num_list(maxlen_num_list);
  int num;

  int i = 0;
  while (i < maxlen_num_list) {
    if(cin.fail()) {
      cin.clear();
      cin.ignore();
    } else {
      cin >> num;
      num_list[i++] = num;
    }
    if(cin.eof()){ break; }
  }

  num_list.resize(i-1);
*/
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
  string num_line;
  while(getline(cin, num_line)) {
    vector<int> num_list(createNumList(num_line));
    sortNumList(num_list);
  }
  return 0;
}
