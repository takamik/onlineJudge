// Problem 10008
// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949
#include <iostream>
//#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

/*bool sort_greater(const pair<string, int>& left,const pair<string, int>& right){
    return left.second > right.second;
}*/
typedef pair<char, int> ass_arr;
bool sort_greater(const ass_arr& left,const ass_arr& right){
    return left.second > right.second;
}

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

  vector< pair<char,int> > chars_counter;
  vector< pair<char,int> >::iterator chars_counter_it;

  for(int i = 0; i<26; ++i) {
    chars_counter.push_back(pair<char, int>(chars_list[i], i%5));
    //push_back(chars_counter[chars_list[i]] = i%5;
  }
/*  for(int i = 0; i<26; ++i) {
    cout << chars_list[i] << chars_counter[chars_list[i]] << endl;
  } */
//  map<char,int>::iterator it = chars_counter.begin();
  chars_counter_it = chars_counter.begin();
//  sort (chars_counter.begin(), chars_counter.end());
//  sort(chars_counter.begin(), chars_counter.end(), sort_greater);
  sort(chars_counter.begin(), chars_counter.end(), greater<int>());
  while( chars_counter_it != chars_counter.end() ) {
      cout << chars_counter_it->first << ":" << chars_counter_it->second << endl;
      ++chars_counter_it;
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
