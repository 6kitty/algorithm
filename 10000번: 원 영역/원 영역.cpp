/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10000                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10000                          #+#        #+#      #+#    */
/*   Solved: 2026/02/15 12:59:41 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;

//stack.pop은 void로 빼기만 함 
//stack.top 먼저하고 pop해야함 

int x[300001];
int r[300001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    stack<int> lef;
    stack<int> rig;

    for(int i=0;i<n;i++){
        //input에서 정렬을 먼저 해줘야 할듯 
        cin>>x[i];
        cin>>r[i];

        int nl=x[i]-r[i];
        int nr=x[i]+r[i];

        if(lef.top()>nl){
            int tmp=lef.pop();
            lef.push(nl);
            lef.push(lef);
        }else{

        }
    }

    //일단 최소 n+1개임 (background 포함)
    int ans=n+1;
    //TC: 큰 원의 지름을 두 원이 채웠을 때 
    //2R=2r_1+2r_2일 때를 체크해야함 
    //이때는 +1을 해줘야함 (기존 n개에서 큰 원이 두 개로 쪼개짐)
    //수평선에서 지나가는 부분을 다 자료구조에 넣고 
    
    for(int i=0;i<n;i++){
        



        if(lef.pop()+rig.pop()+nl+nr==lef.top()+rig.top())
        lef.push(nl);//왼쪽 점
        rig.push(nr);//오른쪽 점 


    }
}