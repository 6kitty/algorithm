/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1406                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1406                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 13:12:02 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin>>n;

    list<char> L;

    for (auto c:n) L.push_back(c);
    auto cursor = L.end();

    int q;
    cin>>q;
    while(q--){
        char op;
        cin>>op;

        if(op=='P'){
           char add;
           cin>>add; //P와 입력 문자 사이 공백이 있어서 
           L.insert(cursor,add); 
        }
        else if (op=='L'){
            if (cursor != L.begin()) cursor--; // 시작인지를 체킹 
        }
        else if (op=='D'){
            if(cursor != L.end()) cursor++; // 끝인지를 체킹 
        }
        else {
            if(cursor!=L.begin()){ //시작만 아니면 
                cursor--; //커서 위치는 하나 줄이고 
                cursor=L.erase(cursor); //하나 삭제 
            }
        }
    }
    for (auto c:L) cout<<c;
}