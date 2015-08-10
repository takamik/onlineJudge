// Problem 114
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=50

#include <iostream>
#include <vector>
using namespace std;

int m, n, wall_cost, balls;
vector<vector<int> > grid_bump, grid_val, grid_cost;
vector<int> grid_init, ball_x, ball_y, ball_dir, ball_life;
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};


void input() {
  int bumps, bump_x, bump_y,bump_val, bump_cost;

  cin >> m >> n;
  grid_init.assign(n+1, 0);
  grid_bump.assign(m+1, grid_init);
  grid_val.assign(m+1, grid_init);
  grid_cost.assign(m+1, grid_init);

  cin >> wall_cost;

  cin >> bumps;

  for(int i=0;i<bumps;i++) {
    cin >> bump_x >> bump_y >> bump_val >> bump_cost;
    grid_bump[bump_x][bump_y] = 1;
    grid_val[bump_x][bump_y] = bump_val;
    grid_cost[bump_x][bump_y] = bump_cost;
  }

  balls=0;
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
  if(x<=1 || y<=1 || m<=x || n<=y) return true;
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

int goGrid(int& pos_x, int& pos_y, int& pos_dir, int& pos_life, int& point) {
  int x, y;

  //go one grid
  if(isDead(1, pos_life)) {
    return point;
  }

  // next position
  x = pos_x + dir_x[pos_dir];
  y = pos_y + dir_y[pos_dir];

  // hit bump
  if(isBump(x, y)) {
    point = point + grid_val[x][y];
    if(!isDead(grid_cost[x][y], pos_life)) {
      changeDir(pos_dir);
    }
      return point;
  }

  // hit wall
  if(isWall(x, y)) {
    if(!isDead(wall_cost, pos_life)) {
      changeDir(pos_dir);
    }
    return point;
  }

  // go through
  pos_x = x;
  pos_y = y;
  return point;

}

//void playGame(vector<int> points) {
void playGame() {
  int pos_x, pos_y, pos_dir, pos_life;
  int point,total;
  point = 0;
  total = 0;

  // start
  for(int i=0;i<balls;i++) {
    pos_x = ball_x[i];
    pos_y = ball_y[i];
    pos_dir  = ball_dir[i];
    pos_life = ball_life[i];
    point = 0;

    while(pos_life > 0) {
      goGrid(pos_x, pos_y, pos_dir, pos_life, point);
    }
    cout << point << endl;
    total += point;
  }
    cout << total << endl;
}

int main() {
//  vector<int> points;

  // INPUT
  input();

  // CALCULATE and OUTPUT
//  playGame(points);
  playGame();

  return 0;
}
/*
4 4
0
2
2 2 1 0
3 3 1 0
2 3 1 1
2 3 1 2
2 3 1 3
2 3 1 4
2 3 1 5

7 6
2
10
2 2 1 -2
4 5 0 -2
4 2 4 0
5 5 4 2
2 5 1 -3
2 3 2 0
3 3 -3 4
6 4 0 -2
5 3 3 1
3 4 0 0
3 2 2 3


7 3
-3
2
2 2 2 2
6 2 -3 0
4 2 2 4
4 2 3 4
4 2 0 7
4 2 3 4
3 2 3 2
3 2 3 3
5 2 0 7
4 2 1 4
4 2 2 7
5 2 2 5
3 2 3 5
5 2 1 4
4 2 3 7
4 2 1 5
3 2 2 5
4 2 2 7
3 2 2 4
3 2 1 7
3 2 3 2
4 2 3 7
*/
