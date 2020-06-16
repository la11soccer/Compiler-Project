#include "Scanner.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		cout << "Usage: <executable name> <filename>";
	}

	Scanner scan(argv[1]);


	//this code is merely to test the scanner
	while (scan.currentTokenType() != NONE)
	{
		cout << scan.toString(scan.currentTokenType()) << " " << scan.currentTokenString() << /*scan.getLine() << */ "\n" ;
		scan.advance();
	}
	cout << "\n";
}


