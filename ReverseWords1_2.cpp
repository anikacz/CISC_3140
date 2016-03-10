//
// 
//  CISC3150proj1
//
//  Created by Anika Czander on 3/4/16.
//  Copyright (c) 2016 Anika Czander. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
using namespace std;
typedef basic_stringstream<char> stringstream;

stack<string> reverseWords(string str)
{
    stack<string> temp;
    queue<char> character;
    long length = str.length();
    for(int i = 0; i <= length; i++)
    {
        if(str[i] != ' ')
        {
            character.push(str[i]);
        }
        if((str[i] == ' ') || (i == length))
        {
            string strng;
            long size = character.size();
            for (int i = 0; i < size; i++)
            {
                strng.insert(i,1,character.front());
                character.pop();
            }
            temp.push(strng);
            while (!character.empty())
            {
                character.pop();
            }
        }
        
    }
    return temp;
}


int main() {
    cout<<"Enter your sentence."<<endl;
    string ss;
    getline(cin,ss);
    stack<string> stack;
    stack = reverseWords(ss);
    while(!stack.empty())
    {
        cout<<stack.top();
        cout<<" ";
        stack.pop();
    }
}