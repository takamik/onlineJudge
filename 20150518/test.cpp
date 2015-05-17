// Problem 10008
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {

int lines_size;

int m;
string str,name;
int id;
vector<pair<int,string> > v;

stringstream ss;

//NAME:TARO,ID:123

cin >> lines_size;
cout << lines_size << endl;
if(lines_size == 100) return 0;

for (int i=0; i<lines_size;i++) {
//while(cin>>str){
    cin >> str;
	m = str.find("NAME:");str.replace(m,5,"");
	m = str.find(",ID:");str.replace(m,4," ");
	
	ss.clear();
	ss.str(str);
	ss>>name>>id;
//	v.push_back(pair<int,string>(id,name));
	
	cout << id << "," << name << endl;
	
	
}

  cout << endl << "end" << endl;
  return 0;
}
