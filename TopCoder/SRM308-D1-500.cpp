/*
  Idea:
    - BFS.
    - Imagine a graph each vertix in it represent state in the
      board, then using BFS we can try to move between these
      states and find the shortest path between the first
      and the last one.
*/

#include <bits/stdc++.h>

using namespace std;

struct node {
  int x[4], y[4];
  node() {}
  node(int x0, int x1, int x2, int x3,
    int y0, int y1, int y2, int y3) {
    x[0] = x0, x[1] = x1, x[2] = x2, x[3] = x3;
    y[0] = y0, y[1] = y1, y[2] = y2, y[3] = y3;
  }
};

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int endx[] = { 0, 0, 1, 1 };
int endy[] = { 1, 0, 1, 0 };
int vis[6][6][6][6][6][6][6][6];
queue<node> q;

bool free(node fr, int nx, int ny) {
  for(int i = 0; i < 4; ++i)
    if(fr.x[i] == nx && fr.y[i] == ny)
      return false;
  return true;
}

bool end(node fr) {
  int cnt = 0;
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j)
      if(fr.x[j] == endx[i] && fr.y[j] == endy[i]) {
        ++cnt;
        break;
      }
  return cnt == 4;
}

class CornersGame {
public:
  int countMoves(vector<string> board) {
    q.push(node(4, 4, 5, 5, 4, 5, 4, 5));
    vis[4][4][5][5][4][5][4][5] = true;

    int cost = 0;
    while(!q.empty()) {
      int size = q.size();
      
      while(size-- != 0) {
        node fr = q.front();
        q.pop();
        
        if(end(fr))
          return cost;
        
        for(int i = 0; i < 4; ++i) {
          int curx = fr.x[i], cury = fr.y[i];
          
          for(int j = 0; j < 4; ++j) {
            int nx = curx + dx[j];
            int ny = cury + dy[j];
            
            if(nx < 0 || nx >= 6 || ny < 0 || ny >= 6 || board[nx][ny] == 'r')
              continue;
            
            if(board[nx][ny] == '.' && free(fr, nx, ny)) {
              fr.x[i] += dx[j], fr.y[i] += dy[j];
              if(vis[fr.x[0]][fr.x[1]][fr.x[2]][fr.x[3]][fr.y[0]][fr.y[1]][fr.y[2]][fr.y[3]]) {
                fr.x[i] -= dx[j], fr.y[i] -= dy[j];
                continue;
              }
              q.push(fr);
              vis[fr.x[0]][fr.x[1]][fr.x[2]][fr.x[3]][fr.y[0]][fr.y[1]][fr.y[2]][fr.y[3]] = true;
              fr.x[i] -= dx[j], fr.y[i] -= dy[j];
            } else if(board[nx][ny] == 's' || !free(fr, nx, ny)) {
              int tmpx = curx + dx[j] * 2;
              int tmpy = cury + dy[j] * 2;
              if(tmpx < 0 || tmpx >= 6 || tmpy < 0 || tmpy >= 6 || board[tmpx][tmpy] == 'r')
                continue;
              
              if(board[tmpx][tmpy] != 's' && free(fr, tmpx, tmpy)) {
                fr.x[i] += dx[j] * 2, fr.y[i] += dy[j] * 2;
                if(vis[fr.x[0]][fr.x[1]][fr.x[2]][fr.x[3]][fr.y[0]][fr.y[1]][fr.y[2]][fr.y[3]]) {
                  fr.x[i] -= dx[j] * 2, fr.y[i] -= dy[j] * 2;
                  continue;
                }
                q.push(fr);
                vis[fr.x[0]][fr.x[1]][fr.x[2]][fr.x[3]][fr.y[0]][fr.y[1]][fr.y[2]][fr.y[3]] = true;
                fr.x[i] -= dx[j] * 2, fr.y[i] -= dy[j] * 2;
              }
            }
          }
        }
      }
      
      ++cost;
    }
    
    return -1;
  }
};
