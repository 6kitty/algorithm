/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11729                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11729                          #+#        #+#      #+#    */
/*   Solved: 2026/02/15 21:24:18 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

queue<pair<int,int>> process;

int cnt=0;

void hanoi(int n, int a, int b){
    if(n==1){
        cnt++;
        process.push({a,b});
    }
    return hanoi(n-1,a,b);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    for(int i=N;i>0;i--) gr1.push(i);

    int cnt=0;
    //1. n-1개의 원판을 기둥2로 옮기고 
    //2. n의 원판을 기둥3으로 옮기고 
    //3. 기둥2에 있던 n-1 원판을 기둥3으로 옮기기 

    hanoi(N-1,1,2);
    hanoi(1,1,3);
    hanoi(N-1,2,3);
    cout<<cnt<<'\n';
}
