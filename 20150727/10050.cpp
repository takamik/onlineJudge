// Problem 10050
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=991
#include <iostream>
#include <vector>
using namespace std;

int setHartal(const vector<int>& hartals, const int& day) {
  for(int i=0; i<hartals.size(); i++) {
    if(day%hartals[i] == 0) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int tests, parties, hartal, days, working_days, day_of_week;
  vector<int> period, hartals;

  cin >> tests;
  while(tests--) {

    // INPUT
    cin >> days;
    period.resize(days, 0);

    cin >> parties;
    hartals.resize(parties, 0);

    for(int i=0; i<parties; i++) {
      cin >> hartal;
      hartals[i] = hartal;
    }

    // OUTPUT
    working_days = 0;
    for(int i=1; i<period.size()+1; i++) {
      period[i-1] = setHartal(hartals, i);

      day_of_week = i % 7;
      if((day_of_week != 0 & day_of_week != 6) && period[i-1] == 1){
        ++working_days;
      }
    }
    cout << working_days << endl;
  }
  return 0; 
}