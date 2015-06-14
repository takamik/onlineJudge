#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector<string> createCharGrid(int height, int width) {
  vector<string> grid(height+1);

  for(int i=0; i<height+1; i++) {
    getline(cin, grid[i]);
  }
  grid.erase(grid.begin());

  return grid;  
}

void search_first_char_location(vector<string> grid, char first_char, 
    int& height, int& width) {
  for(int i=0; i<grid.size(); i++) {
    //string line = grid[i];
    for(int k=0; k<grid[i].size(); k++) {
//      if(!strcmp(grid[i][k], first_char)) {
      if(grid[i][k] == first_char) {
        height = (int)i;
        width = (int)k;
        //cout << i << " " << k << endl;
        return;
      }
    }
  }
}

void search_next_char_location(vector<string> grid, char target_char, 
    int& height, int& width) {
cout << grid[height][width] << endl;
  
  //right
//  if() {
    
//  }


}

void search_name_location(vector<string> grid, string target_name) {
  vector<string>::iterator it;
  int height[target_name.size()];
  int width[target_name.size()];

  search_first_char_location(grid, target_name[0], height[0], width[0]);
  search_next_char_location(grid, target_name[1], height[0], width[0]);
/*
  for(int j=0; j<target_name.size(); j++) {
    for(int i=0; i<grid.size(); i++) {
      string line = grid[i];
      for(int k=0; k<line.size(); k++) {
        if(line[k] == target_name[j]) {
          height[j] = i;
          width[j] = k;
          cout << i << " " << k << endl;
          return;
        }
      }
    }
  }
*/
  cout << height[0] << " " << width[0] << endl;
  
}

int main() {
  int max_grids_count;
  cin >> max_grids_count;
  while(max_grids_count--) {
    int height, width;
    cin >> height >> width;
    vector<string> grid = createCharGrid(height, width);
/*
    for(int i=0; i<grid.size(); i++) {
      cout << grid[i] << endl;
    }
*/
    int max_names_count;  
    cin >> max_names_count;


    string target_name;
    getline(cin, target_name);

    while(max_names_count--) {
      getline(cin, target_name);
      search_name_location(grid, target_name);

break;
    }
    getline(cin, target_name);
    cout << "######################" << endl;
break;

  }

  return 0;
}


/*
4

3 2
we
ra
sd
2
wrs
dae

5 3
rty
uis
dfh
jxc
ncg
3
cfu
uis
gcn

6 4
kbls
robg
dnys
fblt
bhnm
virg
1
obg

4 3
hgs
rnd
sss
djn
1
sns
*/

/*
we
ra
sd
***-1
&&&2
%%%wrs
%%%dae
%%%
%%%5 3
%%%rty
%%%uis
%%%dfh
%%%jxc
%%%ncg
%%%4
%%%cfu
%%%uis
%%%gcn
%%%ifx
%%%
%%%
%%%
*/

/*
0 0
2 1
######################
3 2
1 0
4 2
1 1
*/












