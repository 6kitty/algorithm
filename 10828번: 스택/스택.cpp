/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10828                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10828                          #+#        #+#      #+#    */
/*   Solved: 2026/02/04 13:26:49 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

//STL 말고 구현으로 풀어보자 

const int MX=100005;
int dat[MX];
int pos=0;

void push(int val) { dat[pos++]=val; }
int size() { return pos; }
bool empty() { return !pos; }
int top() { return (empty()==1) ? -1 : dat[pos-1]; }
int pop() { return (empty()==1) ? -1 : dat[--pos]; }

int main(void){
    //아래 두 줄 적고 시작하는 거 까먹지 말기 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt;
    cin>>cnt;
    while(cnt--){
        string inst;
        cin>>inst;
        if(inst=="push"){
            int n;
            cin>>n;
            push(n);
        }
        else if(inst=="top") cout<<top()<<'\n';
        else if(inst=="size") cout<<size()<<'\n';
        else if(inst=="pop") cout<<pop()<<'\n';
        else if(inst=="empty") cout<<empty()<<'\n';
        else continue;
    }

}