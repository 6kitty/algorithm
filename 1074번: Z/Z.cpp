/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1074                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1074                           #+#        #+#      #+#    */
/*   Solved: 2026/02/19 23:24:02 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N,r,c;

int cnt;
pair<int,int> cur;

int vis_recur(int n,int a, int b){
    if(n==0) return 0;
    int half=1<<(n-1); //2의 (n-1)승 
    if(a<half && b<half) return vis_recur(n-1,a,b); //1사분면 
    if(a<half && b>=half) return half*half+vis_recur(n-1,a,b-half);
    if(a>=half && b<half) return 2*half*half+vis_recur(n-1,a-half,b);
    if(a>=half && b>=half) return 3*half*half+ vis_recur(n-1,a-half,b-half);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>r>>c;
    cout<<vis_recur(N,r,c);
}