/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15683                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15683                          #+#        #+#      #+#    */
/*   Solved: 2026/03/04 15:19:50 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[8][8]; //n,m은 최대 8이므로 
int minval=64; //n,m이 최댓값일 때 가질 수 있는 최대 크기 64 
int n,m;

vector<pair<int,int>> cctv; // x,y 좌표

//0 계산하는 함수
int cal_val(int tar[8][8]){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tar[i][j]==0) cnt++;
        }
    }
    return cnt;
}

//cctv 경로 탐색 
int dx[4]={1,0,-1,0};//남,서,북,동
int dy[4]={0,-1,0,1};

//dir 전진 함수 
void sol(int x,int y,int dir, int vis[8][8]){
    dir%=4;
    int nx=x+dx[dir];
    int ny=y+dy[dir];

    if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] == 6) return;
    if(vis[nx][ny]==0) vis[nx][ny]=7;
    sol(nx,ny,dir,vis);
}

void sol_backtracking(int k,int tar[8][8]){
    if (k == cctv.size()) {
        minval = min(minval, cal_val(tar));
        return;
    }

    pair<int,int> tmp=cctv[k];
    int type=board[tmp.X][tmp.Y];

    for(int i=0;i<4;i++){
        int tmparr[8][8];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tmparr[i][j]=tar[i][j];
            }
        }

        if(type==1){
            sol(tmp.X,tmp.Y,i,tmparr);
        }else if(type==2){
            sol(tmp.X,tmp.Y,i,tmparr);
            sol(tmp.X,tmp.Y,i+2,tmparr);
        }else if(type==3){
            sol(tmp.X,tmp.Y,i,tmparr);
            sol(tmp.X,tmp.Y,i+1,tmparr);
        }else if(type==4){
            sol(tmp.X,tmp.Y,i+1,tmparr);
            sol(tmp.X,tmp.Y,i+2,tmparr);
            sol(tmp.X,tmp.Y,i+3,tmparr);
        }else if(type==5){
            sol(tmp.X,tmp.Y,i,tmparr);
            sol(tmp.X,tmp.Y,i+1,tmparr);
            sol(tmp.X,tmp.Y,i+2,tmparr);
            sol(tmp.X,tmp.Y,i+3,tmparr);
        }
        
        sol_backtracking(k+1,tmparr);

    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //내 이전 풀이는 greedy 같다고 모든 탐색 다 해봐야 한다고 함.. 
    // 4의 8승이므로 충분히 완전 탐색이 가능함 -> CCTV가 총 8대인데 
    // 가능한 방향 최대 경우의 수가 4가지이므로 
    // 완전 탐색 할 때마다 board 초기화 필요 

    //입력 
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]!=0 && board[i][j]!=6) cctv.push_back({i,j});
        }
    }

    sol_backtracking(0,board);

    cout<<minval;
}