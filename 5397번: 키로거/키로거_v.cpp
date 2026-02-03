#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    cin>>cnt;

    while(cnt--){
        string n;
        cin>>n;
        list<char> pwd;
        auto cursor = pwd.end();
        for(auto c:n){
            if(c=='>'){
                if(cursor!=pwd.end()) cursor++;
            }
            else if(c=='<'){
                if(cursor!=pwd.begin()) cursor--;
            }
            else if(c=='-'){
                if(cursor!=pwd.begin()){
                    cursor--;
                    // 오른쪽 삭제 후 반환되는 '다음 위치'를 커서에 대입
                    cursor = pwd.erase(cursor);
                }
            }
            else{
                //왼쪽에 삽입하므로 cursor++; 불필요 
                pwd.insert(cursor,c);
            }
        }
        for(auto c:pwd) cout<<c;
        cout<<'\n';
    }
}


/*
초기 상태: A - B - C - (cursor)

현재 cursor는 리스트의 끝(pwd.end())을 가리키고 있습니다.

cursor-- 실행: A - B - (cursor)C

커서를 왼쪽으로 한 칸 옮겨서 삭제할 대상인 C를 가리키게 만듭니다.

pwd.erase(cursor) 실행: A - B - (다음 위치)

cursor가 가리키던 C가 삭제됩니다.

이때 erase 함수는 삭제된 C의 다음 위치(여기서는 다시 리스트의 끝)를 반환합니다.
*/