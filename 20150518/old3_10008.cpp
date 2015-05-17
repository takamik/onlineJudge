// Problem 10008
// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949
#include <iostream>
//#include <sstream>
//#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main () {
//NAME:TARO,ID:123
//2\nThis is a test.\nCount me 1 2 3 4 5.\n
  
  char chars_list[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/*  std::vector<int> chars_counter(26, 0);
  for(int i = 0; i<26; ++i) {
    cout << "key = " << chars_list[i]           // キーを表示
         << ", val = " << chars_counter[i] << endl;    // 値を表示
  }
  return 0; */

  map<char,int> chars_counter;
  for(int i = 0; i<26; ++i) {
    chars_counter[chars_list[i]] = 0;
  }
/*  for(int i = 0; i<26; ++i) {
    cout << chars_list[i] << chars_counter[chars_list[i]] << endl;
  } */
  map<char,int>::iterator it = chars_counter.begin();
  while( it != chars_counter.end() ) {
      cout << it->first << ":" << it->second << endl;
      ++it;
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
