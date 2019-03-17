#include<cstdio>
#include<algorithm>

int card[500000] = {};
int comp[500000] = {};
int res[500000] = {};

using namespace std;

int main(){

  int n,m,presNum,cnt = 0,l,r;
  scanf("%d", &n);

  for(int i = 0 ; i < n; i++){
    scanf("%d", &card[i]);
  }
  sort(card,card+n);
  for(int i = 0 ; i < n; i++){
  }


  scanf("%d", &m);
  for(int i = 0 ; i < m; i++){
    scanf("%d", &comp[i]);
  }

  while(cnt != m){
    l = 0;
    r = n-1;
    while(l <= r){
      if(card[(l+r)/2] < comp[cnt]){
        l = (l+r)/2;
      }
      else if(card[(l+r)/2] > comp[cnt]){
        r = (l+r)/2;
      }
      else if(card[(l+r)/2] == comp[cnt]){
        res[cnt] = 1;
        break;
      }

      if(l == r-1){
        if(card[r] == comp[cnt] || card[l] == comp[cnt]) res[cnt] = 1;
          break;
        }
      }
    cnt++;
  }

  for(int i = 0 ; i < m; i++){
    printf("%d ", res[i]);
  }

  return 0;
}
