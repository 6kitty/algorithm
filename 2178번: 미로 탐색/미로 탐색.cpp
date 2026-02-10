/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2178                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2178                           #+#        #+#      #+#    */
/*   Solved: 2026/02/10 21:11:30 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[101][101];
int vis[101][101];

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    int min_sum=n*m;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        for(int j=0;j<m;j++)
            board[i][j]=tmp[j]-'0';
    }

    pair<int,int> goal={n-1,m-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0 || vis[i][j]==1) continue;

            bool flag=0;
            int cnt=1;
            queue<pair<int,int>> Q;
            vis[i][j]=1;
            Q.push({i,j});

            while(!Q.empty()){
                if(Q.front()==goal){
                    flag=1;
                    break;
                }
                pair<int,int> cur=Q.front(); Q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx=cur.X+dx[dir];
                    int ny=cur.Y+dy[dir];

                    if(nx<0||nx>n-1||ny<0||ny>m-1) continue;
                    if(vis[nx][ny]==1 || board[nx][ny]==0) continue;

                    vis[nx][ny]=1;
                    Q.push({nx,ny});
                    cnt++;
                }
            }

            if(flag==1) min_sum= (min_sum>cnt) ? cnt:min_sum;
        }
    }

    cout<<min_sum<<'\n';
}