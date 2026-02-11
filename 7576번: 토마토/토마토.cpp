/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7576                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7576                           #+#        #+#      #+#    */
/*   Solved: 2026/02/11 10:51:09 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1001][1001];
int vis[1001][1001];

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    queue<pair<int,int>> Q;
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for (int j=0; j<m;j++){
            cin>>board[i][j];
            if(board[i][j]==1) Q.push({i,j});
            if(board[i][j]==0) vis[i][j]=-1;
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];

            if(nx<0||nx>n-1||ny<0||ny>m-1) continue;
            if(vis[nx][ny]>=0) continue;

            vis[nx][ny]=vis[cur.X][cur.Y]+1;
            Q.push({nx,ny});
        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==-1){
                cout<<-1;
                return 0;
            }
            ans=max(ans,vis[i][j]);
        }
    }
    cout<<ans;
}