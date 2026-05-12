#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;

    queue<int> q;
    q.push(0);
    for(int i=0;i<numbers.size();i++){
        int size=q.size();
        for(int j=0;j<size;j++){
            int cur=q.front(); q.pop();
            q.push(cur+numbers[i]); //+ 한 번 
            q.push(cur-numbers[i]); //- 한 번 
        }
    }
    while(!q.empty()){
        if(q.front()==target) answer++;
        q.pop();
    }
    
    return answer;
}