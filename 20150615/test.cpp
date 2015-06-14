#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
//    cout << "test" << endl;

    string str;

/*
//   while(cin.eof()){
    while(cin >> str) {
//        cin >> str;
        if(cin.eof()){break;}
        if(str == "a") {break;}
        cout << str << endl;
    }
*/

    while(getline(cin, str)) {
        if(str == "a") {break;}
        cout << str << endl;

        char delimiter = ' ';
        vector<int> num_list;
        stringstream ss(str);
        string num;

        while (getline(ss, num, ' ')) {
          if (!num.empty()) {
            num_list.push_back(stoi(num));
            //cout << '>' << num << '<'; 
          }
        }
        for (int i=0; i<num_list.size();i++ ) {
          cout << num_list[i] << ' ';
        }
    }



    cout << "end" << endl;
 
    
    
    
    
    
    return 0;
}