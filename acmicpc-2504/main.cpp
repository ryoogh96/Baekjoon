#include <cstdio>
#include <stack>

using namespace std;

// http://wookje.dance/2018/01/25/boj-2504-%EA%B4%84%ED%98%B8%EC%9D%98-%EA%B0%92/
int sum, tmp = 1;
char str[33];
stack<char> stk;

int main()
{
    scanf("%s", str + 1);

    for(int i = 1; str[i]; i++)
    {
        switch(str[i])
        {
        case '(' :
            tmp *= 2, stk.push('('); break;
        case '[' :
            tmp *= 3; stk.push('['); break;
        case ')' :
            if(str[i - 1] == '(') sum += tmp;
            if(stk.top() == '(') stk.pop();
            tmp /= 2; break;
        case ']' :
            if(str[i - 1] == '[') sum += tmp;
            if(stk.top() == '[') stk.pop();
            tmp /= 3;
        }
    }

    printf("%d", stk.empty() ? sum : 0);
}

/*
int bracketValue()
{
    stack<char> bracket;
    char buffer[31];
    char buf;
    int lastVal = 1, ans = 0, combo = 0;

    scanf("%30s", buffer);

    for(int i = 0; i < sizeof(buffer); i++)
    {
        bracket.push(buffer[i]);
    }

    while(!bracket.empty())
    {
        if(bracket.top() == '(' && buffer == ')')
        {
            combo = 2*lastVal;
            lastVal = 2;
            bracket.pop();
        }
        else if(bracket.top() == '[' && buffer == ']')
        {
            combo = 3*lastVal;
            lastVal = 3;
            bracket.pop();
        }
        else
        {
            ans += combo;
            combo = 0;
            lastVal = 1;
        }
    }

    if(bracket.empty()) return 0;
    else return ans;
}

int main()
{
    printf("%d", bracketValue());

    return 0;
}
*/
