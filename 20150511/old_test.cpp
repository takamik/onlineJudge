#include <iostream>
using namespace std;

main()
{
  string str;

  while(true){
    //getline(cin, str);
    cin >> str;
    if(str == "."){break;}
    cout << str;
  }

  return 0;
}	
