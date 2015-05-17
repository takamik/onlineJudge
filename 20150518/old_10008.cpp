// Problem 10008
// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <ctype.h>
using namespace std;

int main () {

  int lines_size;

  int m;
  string str, input, name;
  int id;
  vector<pair<int,string> > v;
  stringstream ss;

//NAME:TARO,ID:123
//2\nThis is a test.\nCount me 1 2 3 4 5.\n

  cin >> lines_size;
//  cout << lines_size << endl;
//  if(lines_size == 100) return 0;

  str = "";
  for (int i=0; i<lines_size+1; ++i) {
//  while(cin>>str){
    getline(cin, input);
//    str = toupper(str);
    str = str + input;
//    cout << str << endl;

/*  cin >> str;
//	m = str.find("NAME:");str.replace(m,5,"");
//	m = str.find(",ID:");str.replace(m,4," ");
    ss.clear();
	ss.str(str);
	ss>>name>>id;
//	v.push_back(pair<int,string>(id,name));
	cout << id << "," << name << endl; */	
  }

  cout << str << endl;

  cout << "end" << endl;
  return 0;
}
