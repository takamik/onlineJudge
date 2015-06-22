#include <iostream>
#include <vector>
#include <string>
//#include <cctype>
//#include <locale>
#include <algorithm>
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

static const int HEIGHT = 0;
static const int WIDTH  = 1;

void createCharGrid(vector<vector<char>> &grid) {
  string line;
  int max_height = grid.size()-1;

  getline(cin, line);
//  transform(line.begin(), line.end(), line.begin(), std::tolower);

  for(int h=1; h<max_height; h++) {
    getline(cin, line);
    int max_line = line.size();
    for(int w=0; w<max_line; w++) {
      grid[h][w+1] = toupper(line[w]);
    }
  }
}

vector<int> getFirstCharPosition(vector<vector<char>> const &grid, vector<int> const &current, char first_char) {
  int max_height = grid.size();
  int max_width  = grid[0].size()-1;
  vector<int> location(2);


  for(int h=current[HEIGHT]; h<max_height; h++) {
    for(int w=0; w<max_width; w++) {

      // already searched
      if(h == current[HEIGHT] && w < current[WIDTH]) continue;

      if(grid[h][w] == first_char) {
        location[HEIGHT] = h;
        location[WIDTH]  = w;
        return location;
      }
    }
  }
}

vector<int> getNextPosition(vector<int> current, int const &idx_direction) {
  current[HEIGHT] = current[HEIGHT] + direction[idx_direction][HEIGHT];
  current[WIDTH]  = current[WIDTH]  + direction[idx_direction][WIDTH];
  return current;
}

bool checkHasChar(vector<vector<char>> const &grid, vector<int> &current, int idx_dir, char search_char) {
  vector<int> next = getNextPosition(current, idx_dir);

  if(grid[next[HEIGHT]][next[WIDTH]] == toupper(search_char)) {
    current = next; //move position
    return true;
  }
  return false;
}

bool checkHasWord(vector<vector<char>> const &grid, vector<int> current, string const &word) {
  int  idx_word, max_word, idx_dir, max_dir;
  max_word = word.size();
  max_dir  = direction.size();

  bool has_char;
  vector<int> next(2);
  char chr;

  // searchSecondChar
  idx_word = 1; //search from second char
  for(idx_dir=0; idx_dir<max_dir; idx_dir++) {
    has_char = checkHasChar(grid, current, idx_dir, word[idx_word]);
    if(has_char) break;
  }
  if(!has_char) return false;

  // searchNextChar
  for(++idx_word; idx_word<max_word; idx_word++) {
    has_char = checkHasChar(grid, current, idx_dir, word[idx_word]);
    if(!has_char) return false;
  }

  return has_char;
}

bool isWordStartingFrom(string word,  const vector<vector<char> > & grid, int row, int col) {
	for ( int i = 0 ; i < 8  ; ++i ) {
		int j;
		for ( j = 0 ; j < word.size() ; j++) {
			int r = row + direction[i][0];
			int c = col + direction[i][1];
			if ( word[j] != grid[r][c] ) {
				break;
			}
		}
		if ( j == word.size()) {
			return true;
		}
	}
	return false;
}

pair<int,itn> getPosition(string word, const vector<vector<char> > & grid) {
	for ( int row = 1 ; row <= height ; row++) {
		for ( int col = 1 ; col <= width ; col++) {
			if ( isWordStartingFrom(word,grid,row,col) ) {
				return make_pair(row,col);
			}
		}
	}
}

int main() {

  int max_grids_count;
  int height, width;
  vector<int> first;
  string word;
  bool has_word;

  cin >> max_grids_count;
  while(max_grids_count--) {
    getline(cin, word);

    // create charGrid
    cin >> height >> width;
    vector<char> init(width+2, '-');
    vector<vector<char>> grid(height+2, init);
    createCharGrid(grid);

    // get count of target words to search
    int max_words_count;  
    cin >> max_words_count;

    getline(cin, word);

    // search target words
    while(max_words_count--) {
      getline(cin, word);
//      transform(word.begin(), word.end(), word.begin(), tolower);

      pair<int,int> position = getPostion(word, grid);

      first = {1, 0};
      has_word = false;

      while(!has_word) {
        first[WIDTH] = first[WIDTH]+1;
        first = getFirstCharPosition(grid, first, toupper(word[0]));
        has_word = checkHasWord(grid, first, word);
      }
      cout << first[0] << ' ' <<first[1] << endl;
    }

    cout << endl;
  }

  return 0;
}