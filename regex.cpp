// CPPConsoleApplication.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

/*
ESRE: extended simple regular expression
case 1: Length-0 ESRE, matches everything
case 2: AN ESRE startting with ^ or ending with $
case 3: AN ESRE starting with alphanumeric char or dot (.)
case 4 AN ESRE starting with a * match, eg., a*WXy or .*WA

Attention: "a pure * is just a char, it has no special meanings".
*/

bool is_match_here(const string &r, const string &s)
{
	//case 1
	if (r.empty())
		return true;
	//case 2
	if (r.front() == '$' && r.size() == 1)
		return s.empty();

	//case 4
	if (r.size() >= 2 && r[1] == '*')
	{
		for (int i = 0; i < s.size() && (r.front() == '.' || r.front() == s[i]); ++i)
		{
			if (is_match_here(r.substr(2), s.substr(i + 1)))
				return true;
		}
		return is_match_here(r.substr(2), s); //r[0] shows 0 times
	}

	//case 3
	return !s.empty() && (r.front() == '.' || r.front() == s.front()) && is_match_here(r.substr(1), s.substr(1));
}

bool is_match(const string &r, const string &s)
{
	//case 2, starts with ^
	if (r.front() == '^')
	{
		return is_match_here(r.substr(1), s);
	}
	for (int i = 0; i < s.size(); ++i)
	{
		if (is_match_here(r, s.substr(i)))
		{
			return true;
		}
	}
	return false;
}


int main(int argc, char* argv[])
{

	string reg = "*bc";

	string s = "ceda124545bc";

	cout << is_match(reg, s) << endl;


	char c;
	cout << "hello"<<endl;
	cin >> c;
	return 0;
}


