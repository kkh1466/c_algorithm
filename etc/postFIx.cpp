// 후위 표기식
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string result;  // 후위 표기식을 저장할 결과 string
    stack<char> s;  // 변환에 사용할 스택
    string str;     // 중위표기식을 받을 string

    cin >> str;     // 중위 표기식 입력

    for (int i = 0; i < str.length(); i++){   // 중위->후위 표기식 변환 알고리즘

        if ('A' <= str[i] && str[i] <= 'Z') result += str[i];   // 피연산자(숫자)가 나올 때

        else{  // 연산자가 나올 때
            switch (str[i]){
                case '(':
                    s.push(str[i]);
                    break;

                case '*':
                case '/':    //우선순위 제일 높으므로 같은 기호들 pop
                    if (!s.empty() && (s.top() == '*' || s.top() == '/')){
                        result += s.top();
                        s.pop();         
                    }
                    s.push(str[i]);
                    break;

                case '+':
                case '-':
                    while (!s.empty() && s.top() != '('){  //우선순위 같거나 높은 기호들 pop
                        result += s.top();
                        s.pop();
                    }
                    s.push(str[i]);
                    break;

                case ')':    //'('가 나올 때까지 pop
                    while (!s.empty() && s.top() != '('){ // 스택의 끝까지 혹은 '('가 나올때 까지 pop
                        result += s.top();
                        s.pop();
                    }
                    s.pop();
                    break;
            }
        }
    }

    while (!s.empty()){         // 수식이 끝났을 때 스택에 남아있는 것들을 결과에 추가
        result += s.top();
        s.pop();
    }

    cout << result << "\n";     // 결과 출력
    return 0;
}
