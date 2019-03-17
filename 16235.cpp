#include<cstdio>
#include<algorithm>

using namespace std;

int main(){

  int N, M, K;
  int dir[8][2] = {{-1,0}, {-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
  scanf("%d%d%d", &N, &M, &K);


  int treeBoard[11][11][10000];
  int treeNum[11][11] = {};
  int resource[11][11];
  int addRsc[11][11];
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      scanf("%d", &addRsc[i][j]);
      resource[i][j] = 5;
      for(int k = 0; k < 100; k++) treeBoard[i][j][k] = 0;
    }
  }

  int x, y, z;
  for(int i = 0; i < M; i++){
    scanf("%d%d%d", &x, &y, &z);
    treeBoard[x][y][treeNum[x][y]] = z;
    treeNum[x][y]++;
    // printf("%d",treeNum[x][y]);
  }

  while(K--){

    //봄
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){

        int tmpNum = treeNum[i][j];
        int sum = 0;
        sort(treeBoard[i][j], treeBoard[i][j] + treeNum[i][j]);
        // printf("%d",treeNum[i][j]);
        for(int k = 0; k < treeNum[i][j]; k++){
          if(treeBoard[i][j][k] <= resource[i][j]){
            resource[i][j] -= treeBoard[i][j][k];
            treeBoard[i][j][k] += 1;
          }

          //여름
          else if(treeBoard[i][j][k] > resource[i][j]){
            tmpNum -= 1;
            sum += treeBoard[i][j][k] / 2;
            treeBoard[i][j][k] = 0;
          }
        }
        treeNum[i][j] = tmpNum;
        resource[i][j] += sum;

        }
      }


      //가을
      for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <= N; j++){
          int spread = 0;
          for(int k = 0; k < treeNum[i][j]; k++){
            if(treeBoard[i][j][k] % 5 == 0 && treeBoard[i][j][k] > 0){
              // printf("%d %d", i, j);
              spread++;
            }

          }

          if(spread != 0){
            for(int d = 0 ; d < 8; d++){
              if(i + dir[d][0] >= 1 && j + dir[d][1] >= 1 && i + dir[d][0] <= N && j + dir[d][1] <= N){
                for(int sp = treeNum[i+dir[d][0]][j+dir[d][1]]; sp < treeNum[i+dir[d][0]][j+dir[d][1]]+spread; sp++){
                  treeBoard[i+dir[d][0]][j+dir[d][1]][sp] = 1;
                }
                treeNum[i+dir[d][0]][j+dir[d][1]] += spread;
              }
            }
          }
        }
      }

      //겨울
      for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <= N; j++){
          resource[i][j] += addRsc[i][j];
        }
      }

    }

    int res = 0;
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        res += treeNum[i][j];
      }
    }

    printf("%d\n", res);
  return 0;
}
