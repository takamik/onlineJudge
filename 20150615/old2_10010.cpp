#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<vector<int>> direction {
  { 0, 1},
  { 1, 1},
  { 1, 0},
  { 1,-1},
  { 0,-1},
  {-1,-1},
  {-1, 0},
  {-1, 1}
};
vector<vector<char>> charMap {
  {'-', '-', '-', '-', '-', '-', '-'},
  {'-', 'a', 'b', 'c', 'd', 'e', '-'},
  {'-', 'f', 'g', 'h', 'i', 'j', '-'},
  {'-', 'k', 'l', 'm', 'n', 'o', '-'},
  {'-', 'p', 'q', 'r', 's', 't', '-'},
  {'-', 'u', 'v', 'w', 'x', 'y', '-'},
  {'-', '-', '-', '-', '-', '-', '-'},
};

vector<int> getNextPosition(vector<int> current, int dir) {
  current[0] = current[0] + direction[dir][0];
  current[1] = current[1] + direction[dir][1];
  return current;
}

char getChar(vector<int> current) {
  int v = current[0];
  int h = current[1];
  return charMap[v][h];
}

bool checkHasWord(vector<int> current, string word) {
  int  cnt_word;
  bool has_chr;
  vector<int> next(2);
  char chr;

  for(cnt_word=1; cnt_word<word.size(); cnt_word++) {
    has_chr = false;

    // searchNextChar
    for(int i=0; i<direction.size(); i++) {
      next = getNextPosition(current, i);
      chr = getChar(next);

      if(chr == word[cnt_word]) {
        //cout << '>' << chr << endl;
        has_chr = true;
        break;
      }

    }
    current = next;

    if(!has_chr) {
      return false;
    }
  }
}

int main() {
  vector<int> first(2);
/*
  vector<int> current(2), next(2);
  char chr;
  string word = "xrls";
  int cnt_word;
  bool has_chr = false;
*/
  bool has_word = false;

  //while(cnt_=1; j<word.size(); j++) {

  // searchFirstChar
  // first_position
  first[0] = 5;
  first[1] = 4;
//cout << first[0] << first[1] << endl;
  //current = first;
  has_word = checkHasWord(first, "xrls");

  if(has_word) {
    cout << first[0] << first[1] << endl;
  }
  else{
    cout << "nothing" << endl;
  }


/*
  for(cnt_word=1; cnt_word<word.size(); cnt_word++) {
    // searchNextChar
    for(int i=0; i<direction.size(); i++) {
      //cout << direction[i][0] << " " << direction[i][1] << endl;
      next = getNextPosition(current, i);
      //cout << next[0] << " " << next[1] << endl;
      chr = getChar(next);
      //cout << ch << endl;
      if(chr == word[cnt_word]) {
        cout << '>' << chr << endl;
        current = next;
        // check
        if(cnt_word == word.size()-1) {
          has_chr = true;
        }
        break;
      }
    }
  }
*/









  return 0;
}