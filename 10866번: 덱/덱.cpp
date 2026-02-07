/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10866                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10866                          #+#        #+#      #+#    */
/*   Solved: 2026/02/07 11:44:48 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */


#include <bits/stdc++.h>
using namespace std;

const int MX=50000;
int dat[MX*2+1];
int head=MX-1, tail=MX;

int n;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(dat,MX*2+1,-1);
    cin>>n;
    while(n--){
        string inst;
        cin>>inst;
        if(inst=="push_front"){
            int x;
            cin>>x;
            dat[--head]=x;
        }
        else if(inst=="push_back"){
            int x;
            cin>>x;
            dat[tail++]=x;
        }
        else if(inst=="pop_front") cout<<(tail-head==1 ? -1: dat[head++])>>'\n';
        else if(inst=="pop_back") cout<<(tail-head==1 ? -1: dat[--tail])>>'\n';
        else if(inst=="size") cout<<(tail-head==1 ? 1 : 0)<<'\n';
        else if(inst=="empty") cout<<(tail-head==1 ? 1 : 0)<<'\n';
        else if(inst=="front") cout<<(tail-head==1 ? -1 : dat[head]) <<'\n';
        else cout<<(tail-head==1 ? -1 : dat[tail-1]) <<'\n';
    } 
}