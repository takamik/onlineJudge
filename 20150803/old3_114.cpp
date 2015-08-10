// Problem 114
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=50
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int m, n, wall_cost;
vector<vector<int>> grid_bump, grid_val, grid_cost;
vector<int> grid_init, ball_x, ball_y, ball_dir, ball_life;
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};


void input() {
  int bumps, bump_x, bump_y,bump_val, bump_cost;

  cin >> m >> n;
  grid_init.assign(n, 0);
  grid_bump.assign(m, grid_init);
  grid_val.assign(m, grid_init);
  grid_cost.assign(m, grid_init);

  cin >> wall_cost;

  cin >> bumps;

  for(int i=0;i<bumps;i++) {
    cin >> bump_x >> bump_y >> bump_val >> bump_cost;
    grid_bump[bump_x][bump_y] = 1;
    grid_val[bump_x][bump_y] = bump_val;
    grid_cost[bump_x][bump_y] = bump_cost;
  }

  int balls=0;
  int x, y, dir, life;
  while(cin >> x >> y >> dir >> life) {
    ball_x.push_back(x);
    ball_y.push_back(y);
    ball_dir.push_back(dir);
    ball_life.push_back(life);
    ++balls;
    if(cin.eof()) break;
  }
}

bool isBump(const int& x, const int& y) {
  if(grid_bump[x][y]) return true;
  return false;
}

bool isWall(const int& x, const int& y) {
  if(x<0 || y<0 || m<=x || n<=y) return true;
  return false;
}

bool isDead(const int& cost, int& lifetime) {
  lifetime = lifetime - cost;
  if(lifetime < 1) return true;
  return false;
}

void changeDir(int& pos_dir) {
  pos_dir = (pos_dir == 0) ? 3 : pos_dir-1;
}

int goGrid(int& pos_x, int& pos_y, int& pos_dir, int& pos_life) {
  int x, y, point;
  point = 0;

  //go one grid
  if(isDead(1, pos_life)) {
    return point;
  }

  // next position
  x = pos_x + dir_x[pos_dir];
  y = pos_y + dir_y[pos_dir];

  // hit bump
  if(isBump(x, y)) {
    if(isDead(grid_cost[x][y], pos_life)) {
      //cout << "bDead. " << pos_life << endl;
      return point;
    } else {
      point = point + grid_val[x][y];
      x = pos_x;
      y = pos_y;
      changeDir(pos_dir);
      return point;
    }
  }

  // hit wall
  if(isWall(x, y)) {
    if(isDead(grid_cost[x][y], pos_life)) {
      return point;
    } else {
      //pos_dir = (pos_dir == 0) ? 3 : pos_dir-1;
      x = pos_x;
      y = pos_y;
      changeDir(pos_dir);
      return point;
    }
  }

  // go through
  pos_x = x;
  pos_y = y;
  return point;

}

void playGame(vector<int> points) {
  int pos_x, pos_y, pos_dir, pos_life;
  int point,total;
  point = 0;
  total = 0;

  // start
  for(int i=0;i<ball_x.size();i++) {
    pos_x = ball_x[i];
    pos_y = ball_y[i];
    pos_dir  = ball_dir[i];
    pos_life = ball_life[i];
    point = 0;

    while(pos_life > 0) {
      point += goGrid(pos_x, pos_y, pos_dir, pos_life);
    }
    cout << point << endl;
    total += point;
  }
    cout << total;
}

int main() {
  vector<int> points;

  // INPUT
  input();

  playGame(points);

  // OUTPUT
//  output();

  return 0; 

}