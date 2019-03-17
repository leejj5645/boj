#include<iostream>

using namespace std;

int findRoot(char board[][20], int alphabet[], int curR, int curL);
int r,c;
int preNum = 1, maxNum = 1;
int moved[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int main(){

  char board[20][20];
  int alphabet[26] = {};
  cin >> r >> c;

  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> board[i][j];
    }
  }

  alphabet[board[0][0]-65] = 1;
  findRoot(board, alphabet, 0, 0);
  cout << maxNum << endl;
  return 0;
}

int findRoot(char board[][20], int alphabet[], int curR, int curC){

  int nextR, nextC;
  for(int i = 0 ; i < 4; i++){
    nextR = curR + moved[i][0];
    nextC = curC + moved[i][1];

    if(nextR >= 0 && nextC < c && nextC >= 0 && nextR < r && alphabet[board[nextR][nextC]-65] != 1){
      alphabet[board[nextR][nextC]-65] = 1;
      preNum = preNum + 1;

      if(maxNum < preNum){
        maxNum = preNum;
      }

      findRoot(board, alphabet, nextR, nextC);
      alphabet[board[nextR][nextC]-65] = 0;
      preNum--;
    }
  }

}
