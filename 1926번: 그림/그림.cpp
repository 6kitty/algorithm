/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1926                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1926                           #+#        #+#      #+#    */
/*   Solved: 2026/02/09 14:57:33 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[501][501];
bool vis[501][501];

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>board[i][j];
    }

    int max_paint=0;
    queue<int> paint;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0 || vis[i][j]==1) continue;
            vis[i][j]=1;
            queue<pair<int,int>> Q;
            Q.push({i,j});
            int vis_sum=1;

            while(!Q.empty()){
                pair<int,int> cur=Q.front(); Q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx=cur.X+dx[dir];
                    int ny=cur.Y+dy[dir];

                    if(nx<0 || nx >(n-1) || ny<0 || ny > m-1) continue;
                    if(board[nx][ny]==0) continue;
                    if(vis[nx][ny]==1) continue;
                    
                    vis[nx][ny]=1;
                    Q.push({nx,ny});
                    vis_sum++;
                }
            }
            paint.push(vis_sum);
            if(max_paint<vis_sum) max_paint=vis_sum;
        }
    }
    cout<<paint.size()<<'\n'<<max_paint;

}