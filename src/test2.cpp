#include<iostream>
#include<cstdio>
#include<set>
#include<utility>
#include<vector>
#include <algorithm>

using namespace std;
void CheckSquare(int r, int c, int camIdx, int camDir);
void recurFill(int nowNum);
void FillRoom(int dir, int r, int c);

struct CameraPos{
  int x;
  int y;
  int cameraIdx;
};

int rot[5] = {4, 2, 4, 4, 1};
int room[8][8] = {0};
int maxNum = 0;
int N,M;
int cameraNum = 0;
struct CameraPos camP[8];
set<pair<int,int> > s;
set<pair<int,int> > pre;
set<pair<int,int> >::iterator Pos;

int main(){

  int num6 = 0;
  scanf("%d%d", &N, &M);

  for(int i = 0 ; i < N; i++){
    for(int j = 0; j < M; j++){
      scanf("%d", &room[i][j]);
      if(room[i][j] == 6) num6++;
      if(room[i][j] != 0 && room[i][j] != 6) {
        struct CameraPos cp = {i,j,room[i][j]};
        camP[cameraNum] = cp;
        cameraNum++;
      }
    }
  }

  // printf("cameraNum: %d\n",cameraNum);


  recurFill(0);
  printf("answer: %d", N*M-(maxNum+num6+cameraNum));
  printf("maxNum: %d", maxNum);
  printf("num6: %d", num6);
  printf("cameraNum: %d", cameraNum);
  return 0;
}

void CheckSquare(int r, int c, int camIdx, int camDir){

  // printf("cs of r,c: %d %d\n",r,c);
  //1
  if(camIdx == 1){
    if(camDir == 0) FillRoom(r,c,0);
    else if(camDir == 1) FillRoom(r,c,1);
    else if(camDir == 2) FillRoom(r,c,2);
    else if(camDir == 3) FillRoom(r,c,3);

  }

  //2
  else if(camIdx == 2){
      if(camDir == 0) {
        FillRoom(r,c,0);
        FillRoom(r,c,2);
      }

      else if(camDir == 1){
        FillRoom(r,c,1);
        FillRoom(r,c,3);
      }
    }

  //3
  else if(camIdx == 3){
    if(camDir == 0) {
      FillRoom(r,c,0);
      FillRoom(r,c,1);
    }

    else if(camDir == 1){
      FillRoom(r,c,1);
      FillRoom(r,c,2);
    }

    else if(camDir == 2){
      FillRoom(r,c,2);
      FillRoom(r,c,3);
    }

    else if(camDir == 3){
      FillRoom(r,c,3);
      FillRoom(r,c,1);
    }
  }

  //4
  else if(camIdx == 4){
    if(camDir == 0) {
      FillRoom(r,c,2);
      FillRoom(r,c,3);
      FillRoom(r,c,0);
    }

    else if(camDir == 1){
      FillRoom(r,c,3);
      FillRoom(r,c,0);
      FillRoom(r,c,1);
    }

    else if(camDir == 2){
      FillRoom(r,c,0);
      FillRoom(r,c,1);
      FillRoom(r,c,2);
    }

    else if(camDir == 3){
      FillRoom(r,c,1);
      FillRoom(r,c,2);
      FillRoom(r,c,3);
    }
  }

  //5
  else if(camIdx == 5){
      FillRoom(r,c,0);
      FillRoom(r,c,1);
      FillRoom(r,c,2);
      FillRoom(r,c,3);
  }

}


void FillRoom(int r, int c, int dir){
  // printf("fr of r,c: %d %d\n",r,c);
  if(dir == 0){
    for(int i = c+1 ; i < M; i++){
      if(room[r][i]==6) break;
      else if(room[r][i] != 0) continue;
      pair<int,int> p = make_pair(r, i);
      pre.insert(p);
      // printf("r,c: %d %d\n",r,i);
    }
  }

  else if(dir == 1){
    for(int i = r+1; i < N; i++){
      if(room[i][c]==6) break;
      else if(room[i][c] != 0) continue;
      pair<int,int> p = make_pair(i, c);
      pre.insert(p);
      // printf("r,c: %d %d\n",i,c);
    }
  }

  else if(dir == 2){
    for(int i = c-1; i >= 0; i--){
      if(room[r][i]==6) break;
      else if(room[r][i] != 0) continue;
      pair<int,int> p = make_pair(r, i);
      pre.insert(p);
      // printf("r,c: %d %d\n",r,i);
    }
  }

  else if(dir == 3){
    for(int i = r-1; i >= 0; i--){
      if(room[i][c]==6) break;
      else if(room[i][c] != 0) continue;
      pair<int,int> p = make_pair(i, c);
      pre.insert(p);
      // printf("r,c: %d %d\n",i,c);
    }
  }

}

void recurFill(int nowNum){

  for(int i = 0 ; i < rot[(camP[nowNum].cameraIdx)-1]; i++){
    pre.clear();
    CheckSquare(camP[nowNum].x, camP[nowNum].y, camP[nowNum].cameraIdx, i);

    vector<pair<int, int> > vi;
    set_intersection(s.begin(),s.end(),pre.begin(),pre.end(),back_inserter(vi));
    for(Pos = pre.begin(); Pos != pre.end(); Pos++){
      s.insert(*Pos);
    }
    if(nowNum == cameraNum-1){
      if(s.size() > maxNum) maxNum = s.size();
    }
    else recurFill(nowNum+1);
    for(Pos = pre.begin(); Pos != pre.end(); Pos++) s.erase(*Pos);

    for(int i = 0; i < vi.size(); i++){
      s.insert(vi[i]);
    }
  }
  // printf("nowNum: %d\n", nowNum);

}
