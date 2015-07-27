// Problem 10050
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=991
#include <iostream>
#include <vector>
using namespace std;

void setHartals(vector<int> hartals) {
  int parties, hartal;

  cin >> parties;
  hartals.resize(parties, 0);
  for(int i=0; i<parties; i++) {
    cin >> hartal;
    hartals[i] = hartal;
  }
}

int isHartal(const vector<int>& hartals, const int& day) {
  for(int i=0; i<hartals.size(); i++) {
    if(day%hartals[i] == 0) {
      return 1;
    }
  }
  return 0;
}

int calcLostWorkingDays(const vector<int>& hartals, const int& days) {
  int day_of_week, working_days;

  for(int i=1; i<days+1; i++) {
    day_of_week = i % 7;
    if((day_of_week != 0 & day_of_week != 6)
      && isHartal(hartals, i) == 1){
      ++working_days;
    }
  }
  return working_days;
}

int main() {
  int tests, days;
  vector<int> hartals;

  cin >> tests;
  while(tests--) {

    // INPUT
    cin >> days;
    setHartals(hartals);
/*
    cin >> days;

    cin >> parties;
    hartals.resize(parties, 0);

    for(int i=0; i<parties; i++) {
      cin >> hartal;
      hartals[i] = hartal;
    }
*/
    // OUTPUT
    cout << calcLostWorkingDays(hartals, days) << endl;
/*
    for(int i=1; i<days+1; i++) {
      day_of_week = i % 7;
      if((day_of_week != 0 & day_of_week != 6)
        && setHartal(hartals, i) == 1){
        ++working_days;
      }
    }
    cout << working_days << endl;
*/
  }
  return 0; 
}