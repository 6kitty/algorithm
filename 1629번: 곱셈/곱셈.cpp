/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1629                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1629                           #+#        #+#      #+#    */
/*   Solved: 2026/02/15 18:49:06 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll pow_recur(ll a, ll b, ll m){
    if(b==1) return a%m; //b가 1이면 그냥 본인만 
    ll val= pow_recur(a,b/2,m); //b/2로 재귀 호출 
    val=val*val%m; //반절 나눈 지수대로 val*val -> 지수 2n
    if(b%2==0) return val; //짝수이면 그대로 반환 
    return val*a%m; // b가 홀수이면 한 번 더 곱해서(2n+1) 반환 
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c;
    cin>>a>>b>>c;
    cout<<pow_recur(a,b,c);
}