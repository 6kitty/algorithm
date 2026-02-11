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
int dis[1002][1002];

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q; 
    queue<pair<int,int>> fire;

    int R,C;
    cin>>R>>C;
    for(int i=0;i<R;i++) cin>>board[i];

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(board[i][j]=='J') {
                Q.push({i,j});
                dis[i][j]=1;
            }
            if(board[i][j]=='F'){
                fire.push({i,j});
                dis[i][j]=-1;
            }
            if(board[i][j]=='#') dis[i][j]=-1;
        }
    }

    bool mission=0;
    int ans=0;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        auto fire_cur=fire.front(); fire.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];

            int fnx=fire_cur.X+dx[dir];
            int fny=fire_cur.Y+dy[dir];

            dis[fnx][fny]=-1;
            fire.push({nx,ny});
            if(dis[nx][ny]!=0) continue;

            Q.push({nx,ny});
            dis[nx][ny]=dis[cur.X][cur.Y]+1;
            if(nx==R-1 || nx==0 || ny==0 || ny==C-1){
                mission=1;
                ans=max(ans,dis[nx][ny]);
            }
        }
    }

    if(mission==0) {
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    cout<<ans;
}