/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4949                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4949                           #+#        #+#      #+#    */
/*   Solved: 2026/02/07 21:12:27 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        string lineinput;
        getline(cin, lineinput); // 한 줄 전체를 읽음
        if (lineinput == ".") break;

        stack<char> s;
        string ans = "yes";

        for (int i = 0; i < lineinput.size(); i++) {
            char c = lineinput[i];

            if (c == '(' || c == '[') {
                s.push(c);
            } 
            else if (c == ')') {
                if (s.empty() || s.top() != '(') {
                    ans = "no";
                    break;
                }
                s.pop();
            } 
            else if (c == ']') {
                if (s.empty() || s.top() != '[') {
                    ans = "no";
                    break;
                }
                s.pop();
            }
        }
        //stack에 남은 게 없어야 함 
        if (!s.empty()) ans = "no";

        cout << ans << '\n';
    }
    return 0;
}