/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1697                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1697                           #+#        #+#      #+#    */
/*   Solved: 2026/02/11 21:50:20 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h> 
using namespace std;

int vis[100001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin>>N>>K;

    fill(vis,vis+100001,-1);
    int d[4]={-1,1,2};
    queue<int> Q;
    Q.push(N);
    vis[N]=0;

    //아래 예외 케이스
    if(N==K){
        cout<<0;
        return 0;
    }

    while(!Q.empty()){
        auto cur=Q.front(); Q.pop();
        for(int dir=0;dir<3;dir++){
            int nx;
            if(d[dir]==2) nx=d[dir]*cur;
            else nx=cur+d[dir];

            if(nx<0 || nx>100000) continue;
            if(vis[nx]>=0) continue;

            if(nx==K){
                cout<<vis[cur]+1;
                return 0;
            }

            Q.push(nx);
            vis[nx]=vis[cur]+1;
            
        }
        
    }
}