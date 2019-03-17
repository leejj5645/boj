#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

queue<pair<int,int> > preQ;
queue<pair<int,int> > nextQ;
int arr[101][101] = {};
int inp[20][4];
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int lastY, lastX, ly, lx;
void gen(int x, int y, int d, int g);
void retDragon(int lastY, int lastX);
int main(){

	int N, mx, my, md, mg, res=0;

	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d%d%d%d", &inp[i][0], &inp[i][1], &inp[i][2], &inp[i][3]);
		// gen(mx, my, md, mg);
	}

	for(int i = 0; i < N; i++){
		while( !nextQ.empty() ) nextQ.pop();
		while( !preQ.empty() ) preQ.pop();
		gen(inp[i][0], inp[i][1], inp[i][2], inp[i][3]);
	}

	for(int i = 0 ; i < 100; i++){
		for(int j = 0 ; j < 100; j++){
			if(arr[i][j] == 1 && arr[i][j+1] == 1 && arr[i+1][j] == 1 && arr[i+1][j+1] == 1) res++;
		}
	}

	printf("%d", res);

	return 0;
}

void gen(int x, int y, int d, int g){
		preQ.push(make_pair(y,x));
		preQ.push(make_pair(y+dy[d],x+dx[d]));
		nextQ.push(make_pair(y,x));
		nextQ.push(make_pair(y+dy[d],x+dx[d]));
		arr[y][x] = 1;
		arr[y+dy[d]][x+dx[d]] = 1;
		lastY = preQ.back().first;
		lastX = preQ.back().second;
		for(int i = 0; i < g; i++){
			ly = preQ.front().second - lastX + lastY;
			lx = -preQ.front().first + lastY + lastX;
			retDragon(lastY, lastX);
			lastY = ly;
			lastX = lx;
	}


}

void retDragon(int lastY, int lastX){
	int retY, retX;
	while(!preQ.empty()){
		int preY = preQ.front().first;
		int preX = preQ.front().second;

		retY = preX - lastX + lastY;
		retX = -preY + lastY + lastX;

		arr[retY][retX] = 1;
		preQ.pop();
		nextQ.push(make_pair(retY,retX));
	}
	preQ = nextQ;

}
