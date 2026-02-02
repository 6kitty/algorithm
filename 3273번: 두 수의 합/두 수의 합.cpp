/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 3273                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/3273                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 11:19:51 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;

int n, x, a[1000001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x;

    int occur[1000001]={0,};
    int ans=0;
    for(int i=0;i<n;i++){
        if (x - a[i] > 0 && x - a[i] <= 1000000 && occur[x - a[i]] == 1) {
            ans++;
        }
        occur[a[i]]++;
    }
    cout<<ans;
}