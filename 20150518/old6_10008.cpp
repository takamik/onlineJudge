// Problem 10008
// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949
#include <iostream>
//#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> pair_type;
char upper_chars_list[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lower_chars_list[] = "abcdefghijklmnopqrstuvwxyz";

// Input String
string readInputLines() {
  int lines_size;
  string str, input;

  cin >> lines_size;

  str = "";
  for (int i=0; i<lines_size+1; ++i) {
    getline(cin, input);
    str = str + input;
  }
  return str;
}

// Max->Min Sorting
bool sort_greater(pair_type left, pair_type right){
    return left.second > right.second;
}

// countChar
vector<pair_type> countChar(string str) {
  vector<pair_type> chars_counter;
  int before_size, after_size;

  for(int i = 0; i<26; ++i) {
    before_size = str.length();
    str.replace(0, str.length(), '');

    //chars_counter.push_back(pair_type(i, i%5));
    chars_counter.push_back(pair_type(i, before_size));
  }



  return chars_counter;
}

// 表示
int display_desc_order(vector<pair_type> chars_counter) {
  vector<pair_type>::iterator chars_counter_it = chars_counter.begin();
  sort(chars_counter.begin(), chars_counter.end(), sort_greater);
  while( chars_counter_it != chars_counter.end() ) {
      if (chars_counter_it->second == 0) { break; }
      cout << upper_chars_list[chars_counter_it->first] << ":" << chars_counter_it->second << endl;
      ++chars_counter_it;
  }
  return 0;
}


int main () {
//NAME:TARO,ID:123
//2\nThis is a test.\nCount me 1 2 3 4 5.\n

  string str = readInputLines();
//  cout << str << endl;

//  string str = "";
  
  vector<pair_type> chars_counter = countChar(str);
  display_desc_order(chars_counter);

  cout << "end" << endl;
  return 0;
}
