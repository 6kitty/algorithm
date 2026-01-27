/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2441                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2441                           #+#        #+#      #+#    */
/*   Solved: 2026/01/27 16:17:41 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

int n;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=n;i>0;i--){
        for(int j=0;j<n-i;j++) cout<<' ';
        for(int j=0;j<i;j++) cout<<'*';
        cout<<'\n';
    }
}