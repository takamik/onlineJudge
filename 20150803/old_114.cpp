// Problem 114
// 
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int m, n, wall_cost;
//vector<vector<int>> grid(m, vector<int>(n));
vector<vector<int>> grid_bump, grid_val, grid_cost;
//int wall_cost;
//int bumps;
//int bump_x[bumps], bump_y[bumps],bump_val[bumps], bump_cost[bumps];
vector<int> grid_init, ball_x, ball_y, ball_dir, ball_life;
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};


void input() {
  int bumps, bump_x, bump_y,bump_val, bump_cost;

  cin >> m >> n;
//  m = m + 2;
//  n = n + 2;
  grid_init.assign(n, 0);
  grid_bump.assign(m, grid_init);
  grid_val.assign(m, grid_init);
  grid_cost.assign(m, grid_init);

  cin >> wall_cost;

//cout << "m:" << m << ", n:" << n << ", wall_cost:" << wall_cost << endl;

//  int x, y, val, cost;
  for(int i=0;i<m;i++) {
    for(int j=0;j<n;j++) {
//cout << i << " " << j << " " << endl;
//      grid_val[i][j] = 0;

      // wall
/*      if(i==0 || j==0 || i==m-1 || j==n-1) {
      if(isWall(i, j)) {
        grid_cost[i][j] = wall_cost;
      }
/**      // grid inside
      else {
        grid_cost[i][j] = 0;
      }
*/
    }
  }
/*
for(int i=0;i<m;i++) {
  for(int j=0;j<n;j++) {
    cout << i << " " << j << " " << grid_val[i][j] << " " << grid_cost[i][j] << " " << endl;;
  }
}*/

  cin >> bumps;
//cout << bumps << endl;

  for(int i=0;i<bumps;i++) {
//    cin >> bump_x[i] >> bump_y[i] >> bump_val[i] >> bump_cost[i];
    cin >> bump_x >> bump_y >> bump_val >> bump_cost;
    grid_bump[bump_x][bump_y] = 1;
    grid_val[bump_x][bump_y] = bump_val;
    grid_cost[bump_x][bump_y] = bump_cost;
  }
//for(int i=0;i<bumps;i++) {
//  cout << bump_x[i] << bump_y[i] << bump_val[i] << bump_cost[i] << endl;;
//}
for(int i=0;i<m;i++) {
  for(int j=0;j<n;j++) {
//    cout << i << " " << j << " " << grid_val[i][j] << " " << grid_cost[i][j] << " " << endl;;
  }
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
/*
cout << balls << endl;
for(int i=0;i<balls;i++) {
  cout << ball_x[i] << ball_y[i] << ball_dir[i] << ball_life[i] << endl;
}*/
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

//--pos_life;
//return 5;

  //go one grid
  if(isDead(1, pos_life)) {
//cout << "too soon." << endl;
    return point;
  }

  // next position
  x = pos_x + dir_x[pos_dir];
  y = pos_y + dir_y[pos_dir];
//  cout << pos_x << " " << pos_y << " -> " << x << " " << y << " : " << pos_life << endl;

  // hit bump
  if(isBump(x, y)) {
    cout << "bump. " << pos_life << endl;

    if(isDead(grid_cost[x][y], pos_life)) {
      //cout << "bDead. " << pos_life << endl;
      return point;
    } else {
      point = point + grid_val[x][y];
//      cout << "bump. " << pos_life << endl;
//      pos_dir = (pos_dir == 0) ? 3 : pos_dir-1;
      x = pos_x;
      y = pos_y;
      changeDir(pos_dir);
      return point;
    }
  } else {
    cout << "not bump. " << endl;
  }

  // hit wall
  if(isWall(x, y)) {
    if(isDead(grid_cost[x][y], pos_life)) {
      //cout << "wDead. " << pos_life << endl;
      return point;
    } else {
      cout << "wall. " << pos_life << endl;
      //pos_dir = (pos_dir == 0) ? 3 : pos_dir-1;
      x = pos_x;
      y = pos_y;
      changeDir(pos_dir);
      return point;
    }
  } else {
    cout << "not wall. " << endl;
  }

  // go through
  pos_x = x;
  pos_y = y;
  return point;

}

void playGame(vector<int> points) {
  int pos_x, pos_y, pos_dir, pos_life;
  int point;
  point = 0;

  // start
//  int tmp = 0;
//  pos_x = ball_x[tmp];
//  pos_y = ball_y[tmp];
//  pos_dir  = ball_dir[tmp];
//  pos_life = ball_life[tmp];

//cout << pos_x << pos_y << dir << life << endl;
  for(int i=0;i<ball_x.size();i++) {
if(i>1) break;
    pos_x = ball_x[i];
    pos_y = ball_y[i];
    pos_dir  = ball_dir[i];
    pos_life = ball_life[i];
    point = 0;

    while(pos_life > 0) {
      point += goGrid(pos_x, pos_y, pos_dir, pos_life);
cout << pos_x << " " <<  pos_y << " " <<  pos_dir << " " <<  pos_life << " " <<  point << endl;
//break;
    }

    
  }

//  cout << x << " " << y << " " << pos_life << endl;
  points.push_back(point);
}

int main() {
  vector<int> points;

  // INPUT
  input();

  playGame(points);

  // OUTPUT
//  output();

  return 0; 


/*
  cin >> tests;
  while(tests--) {
    // INPUT
    cin >> days;
    setHartals(hartals);

    // OUTPUT
    cout << calcLostWorkingDays(hartals, days) << endl;
  }
  return 0;
*/
}