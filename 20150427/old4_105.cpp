// 100.cpp //
#include <iostream>
#include <cstdlib> //<stdlib.h>
#include <cstring> //<string.t>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
  int in_left,in_height,in_right,out_size,max_right;
  vector<int> left(10000),height(10000),right(10000),out_vector(10000);
  max_right = 0;


  //construction of building
  int i = 0;
  while (1) {
//    cin >> in_left >> in_height >> in_right;
    cin >> left[i] >> height[i] >> right[i];

    if(cin.fail()) {
break;
      cin.clear();
      cin.ignore();
    } else {
      for(out_size=left[i]; out_size<right[i]+1; out_size++){

////        out_vector[out_size] = (out_size > 0 && out_vector[out_size-1] < in_height) ? in_height : out_vector[out_size-1];
        if(out_size > 0){
/*
          if(out_vector[out_size-1] < in_height){
            out_vector[out_size] = in_height;
          } else 
*/

/*
          if (out_vector[out_size-1] > height[i]){
            if(max_right > left[i]){
              out_vector[out_size] = height[i];
            }
          } else {
*/
          if(right[i-1] > left[i]){
//////            out_vector[out_size] = (out_vector[out_size-1] < height[i]) ? height[i] : out_vector[out_size-1];
          }
        } else {
//////          out_vector[out_size] = height[i];
        }

/*
        if(max_right < left[i]){ 
          out_vector[max_right] = 0;
        }
        if(max_right < right[i]) { max_right = right[i]; }
*/
//cout << in_height << ' ';
        //out_vector[out_size] = (out_vector[out_size-1] > in_height)in_height;

//        out_vector[out_size] = height[i];
        if(out_vector[out_size] < height[i]) {
          out_vector[out_size] = height[i];
        } else {
          //out_vector[out_size] = out_vector[out_size];
          //out_vector[out_size] = 0;
        }
      }
      out_vector[out_size-1] = 0;
    }
    if(cin.eof()){ break; }
//    if(in_right == 10){ break; }
    i = i++;
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
