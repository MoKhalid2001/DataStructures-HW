#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

bool isdigit(char num) {
	int check = num - '1';
	if (check >= 0 && check <= 8) return true;
	return false;
}
int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	return 2;
}
// infix : 1 + 3 * 5 - 8 / 2
string infixtoPosfix(string& infix) {
	stack<char> opertators;
	string posfix = "";

	for (int i = 0; i < infix.length(); i++) {
		if (isdigit(infix[i])) posfix += infix[i];
		else {
			while (!opertators.empty() && precedence(infix[i]) <= precedence(opertators.top())) {
				posfix += opertators.top();
				opertators.pop();
			}
			opertators.push(infix[i]);
		}
		
	}
	//Rule : 5
	while (!opertators.empty()) {
		posfix += opertators.top();
		opertators.pop();
	}
	return posfix;
}
vector<int> NextGreaterElement(vector<int> &numbers) {
	stack<int>values; // for indeces 
	values.push(0);
	for (int i = 1; i < numbers.size(); i++) {
		while (numbers[i] > numbers[values.top()]) {
			numbers[values.top()] = numbers[i];
			values.pop();
			if (values.empty()) break;
		}
		 values.push(i);
	}
	while (!values.empty()) {
		numbers[values.top()] = -1;
		values.pop();
	}
	return numbers;
}
int main()
{
	vector<int> numbers = { 8 , 73 , 74 , 75 , 71 , 69 , 72 , 76 ,73 };
	vector<int> res = NextGreaterElement(numbers);
	for (auto x : res) cout << x << " ";
}

