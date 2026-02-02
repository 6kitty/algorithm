/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2577                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2577                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 10:27:48 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int A,B,C;

int main(void){
    cin>>A>>B>>C;
    int cnt=A*B*C;
    string str=to_string(cnt);
    int ans[10]={0,}; //0,1,2,3,4,5,6,7,8,9
    for(int i=0;i<str.size();i++){
        ans[int(str[i])-48]++;
    }
    for(int i=0;i<10;i++){
        cout<<ans[i]<<'\n';
    }
}