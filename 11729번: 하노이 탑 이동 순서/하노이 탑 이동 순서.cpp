/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11729                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11729                          #+#        #+#      #+#    */
/*   Solved: 2026/02/19 22:19:26 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;

/*
1. n-1개의 원판을 1에서 2로 옮기면 
2. n번째 원판을 1에서 3으로 옮길 수 있고 
3. 나머지 n-1개의 원판을 2에서 3으로 옮기면 된다 
4. 그러면 base conditon은 2(1도 가능은 함)
*/

int N,K;

void move_recur(int a, int b, int n){
    if(n==1){
        cout<<a<<' '<<b<<'\n';
        return;
    }

    //n-1개를 b에서 b+1로 옮기기 
    move_recur(a,6-a-b,n-1); 
    cout<<a<<' '<<b<<'\n';
    move_recur(6-a-b,b,n-1); 
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    K=(1<<N)-1; //-> 이건 대입으로 찾는 게 나을듯 (하노이는 2^n-1 외우기)
    cout<<K<<'\n';
    move_recur(1,3,N);
}
