#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

typedef std::pair<char, char> PCC;


char decode (char d)
{
	if (d == ' ') return ' ';
	if (d == 'a') return 'y';
	if (d == 'b') return 'h';
	if (d == 'c') return 'e';
	if (d == 'd') return 's';
	if (d == 'e') return 'o';
	if (d == 'f') return 'c';
	if (d == 'g') return 'v';
	if (d == 'h') return 'x';
	if (d == 'i') return 'd';
	if (d == 'j') return 'u';
	if (d == 'k') return 'i';
	if (d == 'l') return 'g';
	if (d == 'm') return 'l';
	if (d == 'n') return 'b';
	if (d == 'o') return 'k';
	if (d == 'p') return 'r';
	if (d == 'q') return 'z';
	if (d == 'r') return 't';
	if (d == 's') return 'n';
	if (d == 't') return 'w';
	if (d == 'u') return 'j';
	if (d == 'v') return 'p';
	if (d == 'w') return 'f';
	if (d == 'x') return 'm';
	if (d == 'y') return 'a';
	if (d == 'z') return 'q';
}


int main() 
{
	char cl; int T; std::cin >> T; std::cin.ignore (1);
	for (int c = 1; c <= T; ++c) {
		std::string enc;
		std::getline (std::cin, enc);
		std::cout << "Case #" << c << ": ";
		for (int i = 0; i < enc.length(); ++i) {
			std::cout << decode (enc[i]);
		}
		std::cout << '\n';
	}
	
	return 0;
}