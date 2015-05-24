// Problem 10018
// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int reverseNum(const int& original_num) {
  int reverse_num = original_num;;

  ostringstream os;
  os << original_num;
  string str = os.str();

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

void culc(int& orig_num, int& cnt, int& palindrome) {
  cnt = 0;
  palindrome = 0;
  int max_cnt = 1000;
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

}

void printAnswer(const int& cnt, const int& palindrome) {
  cout << cnt << " " << palindrome << endl;
}

int main() {
  int nums_size, num, cnt, palindrome;

  cin >> nums_size;

  for (int i=0; i<nums_size; ++i) {
    cin >> num;
    culc(num, cnt, palindrome);
    printAnswer(cnt, palindrome);
  }

  return 0;
}
