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

string S;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>S;

    for(char a='a';a<='z';a++){
        int cnt=0;
        for(auto c: S)
            if(a==c) cnt++;
        cout<<cnt<<' ';
    }
}