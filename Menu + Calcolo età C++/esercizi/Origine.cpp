#define ANNO_ATTUALE 2020
#include <iostream>

int calcola_eta(int anno) {
	return ANNO_ATTUALE - anno;
}

int main(int argc, char **argv) {
	short a = 0;
	while (true) {
		std::cout << "MENU\n";
		std::cout << "1) inserire anno di nascita, anno di nascita > 0\n";
		std::cout << "2) inserire 0 per uscire\n";

		std::cin >> a;
		if (a < 0) {
			std::cout << "Runtime Error. Interrupting...\n";
			std::exit(1);
		}

		switch (a) {
		case 0: std::exit(0);
		default: std::cout << "età calcolata:\t" << calcola_eta(a) << "\n";
	}
		std::cout << "\n";


	}
}