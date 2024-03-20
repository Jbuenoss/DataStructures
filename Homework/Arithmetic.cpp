#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isNumber(char n){
    return ((n >= '0' && n <= '9') || (n == '.'));
}

double converter(stack<char> &sequence){ //stack<char> in double
    string numb;
    while(!sequence.empty() && isNumber(sequence.top())){ //will read the inverse
        numb += sequence.top();
        sequence.pop();
    }
    reverse(numb.begin(), numb.end()); //original number
    return stod(numb);
}

double calculation(double num1, double num2, char operation){
    if(operation == '+')        return num2+num1;
    if(operation == '-')        return num2-num1;
    if(operation == '*')        return num2*num1;
    if(operation == '/'){
        if(num1 != 0)   return num2/num1;
        return 1.0;
    }
    return 1.0;
}

double solve(stack<char> &sequence){ //solve the preference ()
    sequence.pop(); //erase '('
    double f1 = converter(sequence);
    char opera = sequence.top();
    sequence.pop(); //erase opera
    double f2 = converter(sequence);
    double resp = calculation(f1, f2, opera);
    sequence.pop(); //erase '('

    return resp;
}

double solution(string oper){
    stack<char> sequence;
    stack<char> sec;
    for(int i = 0; i < (int)oper.size(); i++){
        sequence.push(oper[i]);
    }

    while(!sequence.empty()){
        if(sequence.top() == ')'){
            sec.push(sequence.top());
            sequence.pop();

            while(sequence.top() != ')' && sequence.top() != '('){
                sec.push(sequence.top());
                sequence.pop();
            }

            if(sequence.top() == '('){
                while(sec.top() != ')'){
                    sequence.push(sec.top());
                    sec.pop();
                }
                sequence.push(sec.top()); //pass the ')'
                sec.pop();

                double resp = solve(sequence);

                if(sequence.empty() && sec.empty())      return resp;

                string sresp = to_string(resp); //still have calculation to do

                while(sresp.back() == '0'){ //erase the .000 of the double
                    sresp.pop_back();
                }
                if(sresp.back() == '.')     sresp.pop_back();

                for(int i = 0; i < (int)sresp.size(); i++){
                    sequence.push(sresp[i]);
                }
                while(!sec.empty()){
                    sequence.push(sec.top());
                    sec.pop();
                }
            }
        }else{
            double sol = converter(sequence);
            if(sequence.empty()){
                return sol;
            }
            else{
                char opera = sequence.top();
                sequence.pop();
                if(sequence.top() == '(' || sequence.top() == ')'){
                    string aux0 = to_string(sol);
                    while(!aux0.empty()){
                        sec.push(aux0.back());
                        aux0.pop_back();
                    }
                    sec.push(opera);
                    continue;
                }
                double aux = converter(sequence);
                return calculation(sol, aux, opera);
            }
        }
    }
    
    return 0;
}

int main(){
    string operation;
    cout << "type the operation:\n";
    cin >> operation;
    cout << "solution: " << solution(operation) << '\n';

    /*
        solved resolvidos
        bug 1: pass int and not char
        bug 2: not erase .000 of the double
        bug 3: erase '0' before the '.'
    */

    // char in = '0', fin = '9';    //verify the number represetations in char
    // printf("%d %d", in, fin);

    return 0;
}