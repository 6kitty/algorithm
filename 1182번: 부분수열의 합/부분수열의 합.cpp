/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1182                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1182                           #+#        #+#      #+#    */
/*   Solved: 2026/03/03 01:29:41 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;
int n,s;
int cnt;
int arr[25];

void sol(int cur, int total){
    //cur이 n이면 모든 원소 확인한 것 
    if(cur==n){
        if(total==s) cnt++;
        return;
    }

    //현재 원소를 선택했을 때는 total에 현재 arr 값 더하기 
    sol(cur+1,total+arr[cur]);
    //선택하지 않았을 때 
    sol(cur+1,total);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>s;

    for(int i=0;i<n;i++) cin>>arr[i];

    sol(0,0);
    if(s==0) cnt--; // 크기가 양수인 부분수열 조건이 있음 

    cout<<cnt;
}