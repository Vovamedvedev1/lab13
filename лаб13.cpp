#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cctype>
using namespace std;

bool checkPalind(const string& str)
{
    stack<char>st;
    queue<char>qu;
    for (int i=0; i<str.size();i++)
    {
        if (isalpha(str[i]))
        {
            st.push(toupper(str[i]));
            qu.push(toupper(str[i]));

        }        
    }
    bool flag = true;
    while (flag == true && !st.empty() && !qu.empty())
    {
        if (st.top() != qu.front())
            flag = false;
        st.pop();
        qu.pop();
    }
    return flag;
}

bool checkBallance(const string& str)
{
    stack<char>st;
    map<char, int>skobki{ {'{', 0}, {'}', 1}, {'[', 2}, {']', 3}, {'<', 4}, {'>', 5}, {'(', 6}, {')', 7} };
    map<char, int>::iterator iter;
    for (int i = 0; i < str.size(); i++)
    {
        iter = skobki.find(str[i]);
        if (iter != skobki.end())
        {
            if (skobki[str[i]] % 2 == 0)
                st.push(str[i]);
            else if (!st.empty() && st.top() == (--iter)->first)
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}



int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    cout << "Введите строку:  ";
    getline(cin, str);
    if (checkPalind(str))
        cout << "Палиндром" << endl;
    else
        cout << "Не палиндром" << endl;
    string str1;
    cout << "Введите строку: ";
    getline(cin, str1);
    if (checkBallance(str1))
        cout << "Есть балланс скобок" << endl;
    else
        cout << "Нет балланса скобок" << endl;
    return 0;
}
