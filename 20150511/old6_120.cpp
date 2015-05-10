//Problem 120
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=56
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxlen_num_list = 30;

vector<int> createNumList() {
  vector<int> num_list(maxlen_num_list);
  int num;

  int i = 0;
  while (i < maxlen_num_list+1) {
    if(cin.fail()) {
      cin.clear();
      cin.ignore();
break;
    } else {
      cin >> num;
      cout << num << ' ';
      num_list[i++] = num;
    }
    if(cin.eof()){ break; }
  }

  num_list.resize(i-1);

  cout << endl;
  return num_list;
}

int sortNumList(vector<int> num_list) {
  vector<int>::iterator max = max_element(num_list.begin(), num_list.end());
  int num_length = num_list.size();
  int cnt = num_length;
//  int prev_reverse_idx = 0;
  vector<int> sorted_num_list= num_list;
  sort(sorted_num_list.begin(), sorted_num_list.end());
  vector<int> compare_num_list(num_length);

int i=0;

  //while(num_list.size() > 1){
  while(cnt > 0){
/*
    if(equal(sorted_num_list.begin(), sorted_num_list.end(), compare_num_list.begin())) {
      cout << "%%%%%%%%%%";
      break; 
    } 
*/

    max = max_element(num_list.begin(), num_list.end());
//    cnt = num_list.size();
    
    if(*max == num_list.back()){
      //no reverse
      //compare_num_list[cnt-1] = num_list.back();

      num_list.pop_back();
      --cnt;
    }
    else if(*max == num_list.front()){
      if(cnt == num_length){
        cout << "*" << 1 << "*" << ' ';
      }
      else {
        cout << ((num_length+1) - cnt) << ' ';
      }
      reverse(num_list.begin(), num_list.end());
    }
    else {
      cout << (num_length - distance(num_list.begin(), max)) << ' ';
      reverse(num_list.begin(), max+1);
    }
/*
cout <<"***"<<endl;
for(int j=0;j<num_list.size();++j){
cout << num_list[j]  << ' ' ;
}
cout << endl;
cout <<"***"<<endl;
for(int j=0;j<compare_num_list.size();++j){
cout << compare_num_list[j]  << ' ' ;
}
cout << endl;
*/
if(i < 10) { ++i; } else { break; }

  }

  cout << 0 << endl;
  return 0;
}

int main () {
  vector<int> num_list(createNumList());
  sortNumList(num_list);
  return 0;
}
