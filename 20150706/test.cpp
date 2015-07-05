#include <iostream>
#include <vector>
//#include <string>
//#include <cctype>
//#include <locale>
#include <algorithm>
using namespace std;

int main () {

  int target = 5;
  vector<int> v_list{0, 1, 2, 3, 4};

//v_list.push_back(300);
  vector<int>::iterator cIter = find( v_list.begin(), v_list.end() , target );

//vector<int>::iterator cIter;
//cIter = find( v_list.begin(), v_list.end() , 2 );

  if( cIter != v_list.end() ){
    cout << target << "は存在します";
  } else {
    cout << target << "は存在しない";
  }

  return 0;
}


