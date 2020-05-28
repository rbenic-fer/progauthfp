#include <iostream>
#include <vector>

int main()
{
	int T;
	std::cin >> T;
	for (int cases = 1; cases <= T; ++cases) {
		int firstRow, secondRow;
		std::vector<int> rows[8];
		std::cin >> firstRow;
		firstRow -= 1;
		for (int i = 0; i < 16; ++i) {
			int card;
			std::cin >> card;
			rows[i/4].push_back(card);
		}
		std::cin >> secondRow;
		secondRow += 3;
		for (int i = 0; i < 16; ++i) {
			int card;
			std::cin >> card;
			rows[4+i/4].push_back(card);
		}
		int sameCards = 0, pickedCard = 0;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (rows[firstRow][i] == rows[secondRow][j]) {
					++sameCards;
					pickedCard = rows[firstRow][i];
				}
			}
		}
		if (sameCards == 0) { 
			std::cout << "Case #" << cases << ": Volunteer cheated!\n";
		} else if (sameCards == 1) {
			std::cout << "Case #" << cases << ": " << pickedCard << '\n';
		} else {
			std::cout << "Case #" << cases << ": Bad magician!\n";
		}
	}

	return 0;
}