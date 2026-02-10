/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1021                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1021                           #+#        #+#      #+#    */
/*   Solved: 2026/02/09 18:32:50 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

const int MX=25;
int dat[2*MX+1]={0,};
int tail=MX, head=MX;

int N,M;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    while(N--) dat[tail++]=1;
    int head_cnt, tail_cnt;
    
}