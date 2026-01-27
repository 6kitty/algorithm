/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10871                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10871                          #+#        #+#      #+#    */
/*   Solved: 2026/01/23 16:23:36 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int n,x,a[10005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<n;j++){
        if(a[j]<x) cout<<a[j]<<' ';
    }
}