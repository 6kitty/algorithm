/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9663                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9663                           #+#        #+#      #+#    */
/*   Solved: 2026/03/03 00:56:21 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;
bool isused1[40];
bool isused2[40];
bool isused3[40];

int cnt=0;
int n;
void func(int cur){
    if(cur==n){
        cnt++;
        return;
    }

    for(int i=0;i<n;i++){
        if(isused1[i]||isused2[i+cur]||isused3[cur-i+n-1])
            continue;
        isused1[i]=1;
        isused2[i+cur]=1;
        isused3[cur-i+n-1]=1;
        func(cur+1);
        isused1[i]=0;
        isused2[i+cur]=0;
        isused3[cur-i+n-1]=0;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    func(0);
    cout<<cnt;
}