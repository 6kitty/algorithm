# 10000번: 원 영역 - <img src="https://static.solved.ac/tier_small/17.svg" style="height:20px" /> Platinum IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10000)

<p>x축 위에 원이 N개 있다. 원은 서로 교차하지 않는다. 하지만, 접할 수는 있다.</p>

<p>원으로 만들어지는 영역이 몇 개인지 구하는 프로그램을 작성하시오.</p>

<p>영역은 점의 집합으로 모든 두 점은 원을 교차하지 않는 연속되는 곡선으로 연결될 수 있어야 한다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/c360da99-845f-4fdb-b1f6-60b809ef640b/-/preview/" style="width: 201px; height: 201px;"></p>

## 입력

<p>첫째 줄에 원의 개수 N(1 ≤ N ≤ 300,000)이 주어진다.</p>

<p>다음 N개 줄에는 각 원의 정보 x<sub>i</sub>와 r<sub>i</sub>가 정수로 주어진다. x<sub>i</sub>는 원의 중심 좌표이며, r<sub>i</sub>는 반지름이다.&nbsp;(-10<sup>9</sup> ≤ x<sub>i</sub> ≤ 10<sup>9</sup>, 1 ≤ r<sub>i</sub> ≤ 10<sup>9</sup>)</p>

<p>입력으로 주어지는 원은 항상 유일하다.</p>

## 출력

<p>첫째 줄에 원으로 인해서 만들어지는 영역의 개수를 출력한다.</p>

## 소스코드

[소스코드 보기](원%20영역.cpp)