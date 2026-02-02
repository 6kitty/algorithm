/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1475                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1475                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 10:42:49 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

int N;
int main(void){
    cin>>N;
    int occur[10]={0,}; //0,1,2,3,4,5,6,7,8,9
    string s=to_string(N);
    for(int i=0;i<s.size();i++){
        occur[int(s[i])-'0']++;
    }

    //6번,9번 정렬 
    occur[6]+=occur[9];
    if(occur[6]%2==1) occur[6]++;
    occur[6]=occur[6]/2;
    occur[9]=0;

    //최댓값 구하기 
    int max = *max_element(occur, occur + 10);
    cout<<max;
}