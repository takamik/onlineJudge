// Problem 10008
// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949
#include <iostream>
//#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> pair_type;
//char upper_chars_list[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//char lower_chars_list[] = "abcdefghijklmnopqrstuvwxyz";
string upper_chars_list = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string lower_chars_list = "abcdefghijklmnopqrstuvwxyz";

map<char, int> upper_chars_map;
map<char, int> lower_chars_map;

int createCharMap(){
  for (int i = 0; i < 26; i++) {
    upper_chars_map[upper_chars_list[i]] = i;
    lower_chars_map[lower_chars_list[i]] = i;
  }
  return 0;
}

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

// countChar
vector<pair_type> countChar(string str) {
  vector<pair_type> chars_counter;
  for(int i = 0; i<26; ++i) {
    chars_counter.push_back(pair_type(i, 0));
  }

  int str_len = str.length();

  for(int i = 0; i<str_len; ++i) {
    //cout << i << str[i] << endl;
    char tmp_char = str[i];
    
    if(count(upper_chars_list.begin(), upper_chars_list.end(), str[i])) {
      chars_counter[upper_chars_map[str[i]]].second = chars_counter[upper_chars_map[str[i]]].second + 1;
cout << str[i] << " +1 " << upper_chars_map[str[i]] << ' ' << chars_counter[upper_chars_map[str[i]]].second << endl; 
    }
    if(count(lower_chars_list.begin(), lower_chars_list.end(), str[i])) {
      chars_counter[lower_chars_map[str[i]]].second = chars_counter[lower_chars_map[str[i]]].second + 1;
cout << str[i] << " +1 " << lower_chars_map[str[i]] << ' ' << chars_counter[lower_chars_map[str[i]]].second << endl; 
    }


    //chars_counter.push_back(pair_type(i, i%5));
    //chars_counter.push_back(pair_type(i, before_size));
  }
  return chars_counter;
}

// Max->Min Sorting
bool sort_greater(pair_type left, pair_type right){
    return left.second > right.second;
}

// Print display
int display_desc_order(vector<pair_type> chars_counter) {
  vector<pair_type>::iterator chars_counter_it = chars_counter.begin();
  sort(chars_counter.begin(), chars_counter.end(), sort_greater);
  while( chars_counter_it != chars_counter.end() ) {
      if (chars_counter_it->second == 0) { break; }
      cout << upper_chars_list[chars_counter_it->first] << " " << chars_counter_it->second << endl;
      ++chars_counter_it;
  }
  return 0;
}


int main () {
//NAME:TARO,ID:123
//2\nThis is a test.\nCount me 1 2 3 4 5.\n
/*
for(char a = 'A' ; a <= 'Z' ; a++) {
  cout << a;
//  cout << a << tolower(a);
}
for(char a = 'a' ; a <= 'z' ; a++) {
  cout << a;
}
return 0;
*/


  createCharMap();



//  string str = readInputLines();
//  cout << str << endl;
  string str = "This is a test.";
  
  vector<pair_type> chars_counter = countChar(str);
  display_desc_order(chars_counter);

  cout << "end" << endl;
  return 0;
}
