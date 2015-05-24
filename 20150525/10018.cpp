// Problem 10018
// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

unsigned long reverseNum(const unsigned long& original_num) {
  unsigned long max_num = 4294967295;
  unsigned long reverse_num = original_num;

  ostringstream os;
  os << original_num;
  string str = os.str();

  reverse(str.begin(), str.end());

  try {
    reverse_num = stol(str);
    if(max_num < reverse_num) { return 0; }
  } catch(std::exception const &exc) {
    cout << "Error!" << endl;
    return 0;
  }

  return reverse_num;
}

struct Number {
  unsigned long orig_num, rev_num;
  int isPalindrome;
  
  Number() { orig_num = 0; rev_num = 0; isPalindrome = true;}

  void setNumber(unsigned long num) {
    orig_num = num;
    rev_num = reverseNum(orig_num);

    if(rev_num == 0 && orig_num !=0) {
      isPalindrome = -1;
    } else {
      isPalindrome = (orig_num == rev_num) ? 1 : 0;
    }
  }

  unsigned long add(){
    return orig_num + rev_num;
  }
};

bool culc(unsigned long& orig_num, int& cnt, unsigned long& palindrome) {
  cnt = 0;
  palindrome = 0;
  int max_cnt = 1000;
  Number num = Number();

  while(cnt < max_cnt) {
    num.setNumber(orig_num);

    if(num.isPalindrome == 1) {
      palindrome = num.orig_num;
      return true;
    } else if (num.isPalindrome == -1) {
      return false;
    }

    orig_num = num.add();
    ++cnt;
  }
  return false;
}

void printAnswer(const int& cnt, const unsigned long& palindrome) {
  cout << cnt << " " << palindrome << endl;
}

int main() {
  int nums_size, cnt;
  unsigned long num, palindrome;
  bool culc_result;

  cin >> nums_size;

  for (int i=0; i<nums_size; ++i) {
    culc_result = false;
    
    cin >> num;
    
    culc_result = culc(num, cnt, palindrome);
    
    if(culc_result){
      printAnswer(cnt, palindrome);
    }
  }

  return 0;
}
