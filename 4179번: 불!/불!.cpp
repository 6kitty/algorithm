/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4179                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4179                           #+#        #+#      #+#    */
/*   Solved: 2026/02/11 14:46:07 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int dis1[1002][1002];
int dis2[1002][1002];

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        fill(dis1[i],dis1[i]+m,-1);
        fill(dis2[i],dis2[i]+m,-1);
    }

    for(int i=0;i<n;i++) cin>>board[i];

    queue<pair<int,int>> Q; 
    queue<pair<int,int>> fire;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='F'){
                fire.push({i,j});
                dis1[i][j]=0;
            }
            if(board[i][j]=='J'){
                Q.push({i,j});
                dis2[i][j]=0;
            }
        }
    }

    while(!fire.empty()){
        auto cur=fire.front(); fire.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dis1[nx][ny]>=0 || board[nx][ny]=='#') continue;

            dis1[nx][ny]=dis1[cur.X][cur.Y]+1;
            fire.push({nx,ny});
        }
    }

    while(!Q.empty()){
        auto cur=Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];

            if(nx<0||nx>=n||ny<0||ny>=m){
                cout<<dis2[cur.X][cur.Y]+1;
                return 0;
            }

            if(dis2[nx][ny]>=0 || board[nx][ny]=='#') continue;
            if(dis1[nx][ny]!=-1&&dis1[nx][ny]<=dis2[cur.X][cur.Y]+1) continue;
            dis2[nx][ny]=dis2[cur.X][cur.Y]+1;
            Q.push({nx,ny});
        }
    }
    cout<<"IMPOSSIBLE"<<'\n';
}