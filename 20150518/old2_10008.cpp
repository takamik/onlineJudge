// Problem 10008
// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949
#include <iostream>
//#include <sstream>
//#include <algorithm>
//#include <vector>
#include <map>
using namespace std;

/* map initMapStr(){
  map <string, int> mp_str;

  for (string key='A'; key<='Z'; key++) {
    mp_str[key] = 0;
  }
} */

int main () {
//NAME:TARO,ID:123
//2\nThis is a test.\nCount me 1 2 3 4 5.\n
  

  map <string, int> mp_str;

  char key_list[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i=0; i<26; ++i) {
//    string key = key_list[i];
    mp_str[key_list[i]] = 0;
  }

  for(auto itr = mp_str.begin(); itr != mp_str.end(); ++itr) {
    cout << "key = " << itr->first           // キーを表示
         << ", val = " << itr->second << "\n";    // 値を表示
  }

  return 0;

  int lines_size;
  string str, input;

  cin >> lines_size;

  str = "";
  for (int i=0; i<lines_size+1; ++i) {
    getline(cin, input);
    str = str + input;
  }

  cout << str << endl;

  cout << "end" << endl;
  return 0;
}
