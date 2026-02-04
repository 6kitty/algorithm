/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10773                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10773                          #+#        #+#      #+#    */
/*   Solved: 2026/02/04 14:36:29 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;

int K;
const int MX=100005;
int dat[MX];
int pos=0;

double sum;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>K;
    for(int i=0;i<K;i++){
        int tmp;
        cin>>tmp;
        if(tmp==0) pos--;
        else dat[pos++]=tmp;
    }
    for(int i=0;i<pos;i++) sum+=dat[i];
    cout<<sum;
}