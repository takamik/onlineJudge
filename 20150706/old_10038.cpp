// Problem 10038
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=979
#include <iostream>
//#include <algorithm>
//#include <vector>
using namespace std;

bool checkNums(int max_nums) {

  int original, compared, max_diff, diff_num;
  max_diff = max_nums;

  cin >> original;

  while(--max_nums){
    cin >> compared;

//    cout << original << " " << compared << " " << diff_num << endl;

    if( !(abs(original-compared) < max_diff) ) {
      return false;
    }
    original = compared;
  }
  return true;
}

int main() {

  int max_nums;
  while(cin >> max_nums) {
    if(checkNums(max_nums)) {
      cout << "Jolly" << endl;
    } else {
      cout << "Not jolly" << endl;
    }
//    cout << max_nums << endl;
  }

  return 0; 
}