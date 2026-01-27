/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2439                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2439                           #+#        #+#      #+#    */
/*   Solved: 2026/01/27 16:04:31 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int n;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<n-i;j++) cout<<' ';
        for(int j=0;j<i;j++) cout<<'*';
        cout<<'\n';
    }
}