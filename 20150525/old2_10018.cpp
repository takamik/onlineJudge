// Problem 10018
// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949
#include <iostream>
#include <sstream>
#include <algorithm>
//#include <vector>
//#include <map>
using namespace std;

/*
int readInputNumbers(int& nums) {
  int nums_size;
  string num;

  cin >> nums_size;
  
  nums[nums_size];

  for (int i=0; i<nums_size+1; ++i) {
    getline(cin, num);
    cout << num << endl;
    nums[i] = stoi(num);
  }
  //return nums;
  return 0;
}
*/
int reverseNum(const int& original_num) {
  int reverse_num;
  
  reverse_num = original_num;
  
  
  
  ostringstream os;
  os << original_num;
  string str = os.str();
//  char tmp[10];
//  itoa(original_num, tmp, 10);
//  cout << str << endl;
  reverse(str.begin(), str.end());
  
  reverse_num = stoi(str);
  
  return reverse_num;
}

struct Number {
  int orig_num, rev_num;
  bool isPalindrome;
  
  Number() { orig_num = 0; rev_num = 0; isPalindrome = true;}
  void setNumber(int num) {
    orig_num = num;
    rev_num = reverseNum(orig_num);
    isPalindrome = (orig_num == rev_num);
  }
  int add(){
    return orig_num + rev_num;
  }
};

bool isPalindrome(const int& orig_num, const int& rev_num) {
  if(orig_num == rev_num) {
    return true;
  }
  return false;
}

void add(int& cnt, const int& orig, const int& rev) {
  
}

void culc(int& orig_num, int& cnt, int& palindrome) {

  cnt = 0;
  palindrome = 0;

  int max_cnt = 1000;
//  int max_palindrome = 4294967295;
  Number num = Number();

  while(cnt < max_cnt) {
    num.setNumber(orig_num);

    if(num.isPalindrome) {
      palindrome = num.orig_num;
      return;
    }

    orig_num = num.add();
    ++cnt;
  }

/*
  num.setNumber(orig_num);
  
  if(num.isPalindrome) {
    palindrome = num.orig_num;
    return;
  }
*/

}

void printAnswer(const int& cnt, const int& palindrome) {
  cout << cnt << " " << palindrome << endl;
}

int main() {
/*
  int nums;
  //readInputNumbers(nums);
  int nums_size;
  int num;

  cin >> nums_size;
  for (int i=0; i<nums_size; ++i) {
    cin >> num;
    cout << num << endl;
  }
*/
//  Number num = Number(111);
//  cout << num.orig_num << endl;
//  cout << num.rev_num << endl;
//  cout << (num.isPalindrome ? "true" : "false") << endl;
//  cout << num.add() << endl;

//  int nums_size, cnt, palindrome;
//  culc(786, cnt, palindrome);
//  printAnswer(cnt, palindrome);

  int nums_size, num, cnt, palindrome;

  cin >> nums_size;

  for (int i=0; i<nums_size; ++i) {
    cin >> num;
    culc(num, cnt, palindrome);
    printAnswer(cnt, palindrome);
  }

  return 0;
}

