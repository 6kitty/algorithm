/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10845                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10845                          #+#        #+#      #+#    */
/*   Solved: 2026/02/04 15:44:03 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    while(n--){
        string inst;
        cin>>inst;
        if(inst=="push"){
            int nor;
            cin>>nor;
            q.push(nor);
        }
        else if(inst=="front") cout<< ((q.size()==0) ? -1 : q.front())<<'\n';
        else if(inst=="back") cout<< ((q.size()==0) ? -1 : q.back()) << '\n';
        else if(inst=="size") cout<<q.size()<<'\n';
        else if(inst=="empty") cout<<q.empty()<<'\n';
        else if(inst=="pop") {
            cout<< ((q.size()==0) ? -1 : q.front())<<'\n';
            if(q.size()!=0) q.pop();
        }
    }
}