// 100.cpp //
#include <iostream>
#include <cstdlib> //<stdlib.h>
#include <cstring> //<string.t>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
  int in_left,in_height,in_right,out_size,max_right;
  vector<int> out_vector(10000);
  max_right = 0;

  //construction of building
  while (1) {
    cin >> in_left >> in_height >> in_right;
    if(cin.fail()) {
break;
      cin.clear();
      cin.ignore();
    } else {
      for(out_size=in_left; out_size<in_right+1; out_size++){

//        output.push_back(i);
//        output.push_back(in_height);

////        out_vector[out_size] = in_height;
////        out_vector[out_size] = (out_size > 0 && out_vector[out_size-1] < in_height) ? in_height : out_vector[out_size-1];
        if(out_size > 0){
/*
          if(out_vector[out_size-1] < in_height){
            out_vector[out_size] = in_height;
          } else 
*/
          if (out_vector[out_size-1] > in_height){
            if(max_right > in_left){
              out_vector[out_size] = in_height;
            }
          } else {
            out_vector[out_size] = (out_vector[out_size-1] < in_height) ? in_height : out_vector[out_size-1];
          }
        } else {
          out_vector[out_size] = in_height;
        }

        if(max_right < in_left){ 
          out_vector[max_right] = 0;
        }
        if(max_right < in_right) { max_right = in_right; }

//cout << in_height << ' ';
        //out_vector[out_size] = (out_vector[out_size-1] > in_height)in_height;
      }      
    }
    if(cin.eof()){ break; }
//    if(in_right == 10){ break; }
  }

//  cout << out_size << endl;

//      output.push_back(in_left);

//  cout << left << ' ' << height << ' ' << right << endl;
//  for_each(bigin(output), end(output), cout);
//  for(auto itr = output.bigin(); itr != output.end(); ++itr){ 
//  int output_size = output.size();
  out_vector.resize(out_size);
//  cout << out_size << endl;
//  vector<int>().swap(out_vector); 
  for(int i=0; i<out_size+1; i++){
    //cout << *itr;
//    if(out_vector.empty()) {
//      break;
//    } else {
    cout << out_vector[i] << ' ';
//    }
  }
  cout << endl;


//output vector
  int prev_h,prev_v;
//  prev_h = 0;
  prev_v = 0;
  for(int i=0; i<out_size+1; i++){
    if(prev_v != out_vector[i]){
////////////      cout << i << ' ' << out_vector[i] << ' ';
    }

//    prev_h = i;
    prev_v = out_vector[i];
  }

  cout << endl;


  return 0;
}
