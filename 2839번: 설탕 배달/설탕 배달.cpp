/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2839                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2839                           #+#        #+#      #+#    */
/*   Solved: 2026/03/05 11:39:33 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;


int solve(int a,int b){
    if(a<0){
        return -1; 
    }
    if(a%5==0){
        b+=a/5; 
        return b;
    }
    b++;
    a-=3;
    return solve(a,b);
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,cnt;
    cin>>n;

    int ans=solve(n,0);

    cout<<ans;
}