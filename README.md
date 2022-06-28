## PS
#### BOJ [Profile](https://www.acmicpc.net/user/mo0nlight0)   
#### Solved.ac
#### [![Solved.ac 프로필](http://mazassumnida.wtf/api/v2/generate_badge?boj=mo0nlight0)](https://solved.ac/mo0nlight0)
------------------------------------------------------
### 소개
풀었던 문제들을 저장해두고, 복기하기 위해 만든 저장소이다.

기본적으로 C++를 사용하며, 푸는 문제들의 티어대는 G3 이하가 대부분이다.

🔜
문제 풀이와 관련된 내용은 추후 따로 블로그나 velog 등에 작성될 것 같다.


### 기대 효과
 
되도록 다양하고 많은 문제들을 풀어보고, 어떠한 아이디어를 바탕으로 문제를 풀었는지 서술할 수 있도록 한다.

### 구성

* Code 폴더: 푼 문제의 코드가 저장되는 폴더이다.
* base : 작성할 코드의 템플릿이다.
--- 

### 코드 템플릿 설명

구현 전 디버깅 단계에서는 전처리기 지시어를 활용하여 파일 입출력으로 in.txt과 out.txt을 사용한다.

그 코드는 `base.cpp`에서 볼 수 있는 다음의 코드와 같다.
```
#define _LUNAR

#ifdef _LUNAR
    freopen("_run/in.txt", "r", stdin), freopen("_run/out.txt", "w", stdout);
#endif
```
코드를 온라인 저지 사이트에 제출할 땐, 맨 윗 줄에 정의된 `#define _LUNAR`를 제외하고 제출하면 표준 입출력을 사용하게 된다.