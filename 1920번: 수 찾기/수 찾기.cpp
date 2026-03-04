/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1920                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 6kitty <boj.kr/u/6kitty>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1920                           #+#        #+#      #+#    */
/*   Solved: 2026/02/24 16:12:34 by 6kitty        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 입력 받기
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    // 2. 이분 탐색을 위한 정렬 
    sort(a, a + n);

    cin >> m;
    while (m--) {
        int target;
        cin >> target;

        // 3. binary_search 사용 (존재하면 1, 없으면 0 반환)
        if (binary_search(a, a + n, target)) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}