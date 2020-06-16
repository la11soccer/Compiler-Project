#ifndef SCANNER

#define SCANNER



#include <iostream>
#include <fstream>
using namespace std;

enum TokenType{ERROR,LBRACE, RBRACE, PRINT, SEMI, NAME, NUMBER, ADD, GR, LT, MULTIPLY, DIVIDE, EQL, LPAREN, RPAREN, CONST, EOL, COMMA, RETURN, MINUS, DOT, FOR, IF, EE, NONE /*this is for if the file is empty*/};

class Scanner
{
public:
	Scanner(string filename);

	TokenType currentTokenType();
	TokenType nextTokenType();
	string currentTokenString();
	string nextTokenString();
	string toString(TokenType t);
	void advance();

	int getLine();
private:
	ifstream filestream;
	string currents;
	string nexts;
	TokenType currenttt;
	TokenType nexttt;

	int linenext;
	int linecurrent;
};

#endif // !