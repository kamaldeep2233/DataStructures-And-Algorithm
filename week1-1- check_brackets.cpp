#include<bits/stdc++.h>
using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};
void print_stack(stack<Bracket> s) {
    char c;
    while (s.size()) {
        c = s.top().type;
        cout << c;
        s.pop();
    }
    cout << endl;
}

int main() {
    std::string text;
    getline(std::cin, text);
     int falseposition=-1;
     
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];


        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket *B=new Bracket(next,position+1);
            opening_brackets_stack.push(*B);
        }


        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.size()==0){
            falseposition=position+1;
            break;
        }
		else if(opening_brackets_stack.top().Matchc(next)){
        	opening_brackets_stack.pop();
		}
		else{
			falseposition=position+1;
			break;
		}
    }
}

    // Printing answer, write your code here
if(opening_brackets_stack.size()==0 && falseposition==-1){
	cout<<"Success"<<endl;
}else
{
if(opening_brackets_stack.size() && falseposition==-1){
	falseposition=opening_brackets_stack.top().position;
}
  cout<<falseposition<<endl;
}
    return 0;
}
