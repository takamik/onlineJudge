// Problem 10038
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=979
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

void disposeLine() {
  string str;
  getline(cin, str); // dispose line
}

bool hasDuplicateNum(vector<int>& diff_nums) {
  int all = diff_nums.size();

  sort(diff_nums.begin(), diff_nums.end());
  diff_nums.erase(unique(diff_nums.begin(), diff_nums.end()), diff_nums.end());

  if(all != diff_nums.size()) {
    return true;
  }
  return false;
}

bool checkNums(int max_nums) {

  // no need to compare.
  if(max_nums == 1) {
    disposeLine();
    return true;
  }

  int original, compared, diff_num, max_diff_num, diff_idx;
  vector<int> diff_nums;

  max_diff_num = max_nums - 1;

  cin >> original;

  while(--max_nums){
    cin >> compared;
    diff_num = abs(original-compared);

    //check difference from original and compared. 
    if( max_diff_num < diff_num ) {
      disposeLine();
      return false;
    }

    diff_idx = max_diff_num - max_nums;
    diff_nums.push_back(diff_num);
    original = compared;
  }

  // check diff_num is not duplicate.
  if(diff_nums.size() > 1 && hasDuplicateNum(diff_nums)) { 
    return false;
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
  }
  return 0; 
}