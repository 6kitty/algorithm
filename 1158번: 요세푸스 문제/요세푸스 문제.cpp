/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1158                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1158                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 13:37:17 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

int N,K,len=0;

int pre[5001];
int nxt[5001];
vector<int> v;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K;

    //원형 리스트 생성 
    for(int i=1;i<=N;++i){
        pre[i]=(i==1)?N:i-1;
        nxt[i]=(i==N)?1:i+1;
        ++len;
    }

    int i=1;
    //len이 0이 되기 전까지 
    //cur=1부터 다음 주소까지 순회 
    for(int cur=1;len!=0;cur=nxt[cur]){
        if(i==K){
            pre[nxt[cur]]=pre[cur];
            nxt[pre[cur]]=nxt[cur];
            v.push_back(cur);
            i=1;
            --len;
        }else i++;
    }

    cout<<"<";
    for(size_t i=0;i<v.size();i++){
        cout<<v[i];
        if(i!=v.size()-1) cout<<", ";
    }
    cout<<">";
}