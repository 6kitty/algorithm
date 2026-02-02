/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10808                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10808                          #+#        #+#      #+#    */
/*   Solved: 2026/01/31 18:31:58 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */


#include <bits/stdc++.h>
using namespace std;

int arr[26];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;
    for(auto c:s) arr[c-'a']++;
    for(int i=0;i<26;i++){
        cout<<arr[i]<<' ';
    }
}