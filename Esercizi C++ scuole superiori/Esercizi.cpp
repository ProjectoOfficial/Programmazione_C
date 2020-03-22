/*Creare nel main un ciclo while in cui viene chiesto di inserire l'anno di nascita.
Passare il numero ad una funzione che calcola l'età a partire dall'anno di nascita e 
la stampa a schermo. Il ciclo while del main deve essere strutturato come un  menù con
2 opzioni:
1) richiede l'anno di nascita
2) se si vuole uscire*/


#include <iostream>
#define data_attuale 2020


void calcola_eta(short data_nascita) {
	std::cout <<"eta calcolata: " << data_attuale - data_nascita << '\n' ;
}

int main(int argc, char **argv) {

	short valore_inserito = 1;

	while (true) {

		std::cout << "Inserire data di nascita \n";
		std::cin >> valore_inserito;

		if (valore_inserito < 0) {
			std::cout << "Runtime Error";
			std::exit(1);
		}

		switch (valore_inserito) {
		case 0: std::exit(0);
		default: calcola_eta(valore_inserito);
		}

	}

}




/*Fare lo stesso esercizio, ma invece di stampare il risultato della funzione,
ritornare il risultato della somma nel main (come numero intero) e stampare il risultato nel main*/


#define data_attuale 2020


short calcola_eta2(short data_nascita) {
	return data_attuale - data_nascita;
}

int main(int argc, char** argv) {

	short valore_inserito = 1;

	while (true) {

		std::cout << "Inserire data di nascita \n";
		std::cin >> valore_inserito;

		if (valore_inserito < 0) {
			std::cout << "Runtime Error";
			std::exit(1);
		}

		switch (valore_inserito) {
		case 0: std::exit(0);
		default: 
			std::cout << "eta calcolata: " << calcola_eta2(valore_inserito) << '\n';
		}

	}

}



/*inserire una sequenza di numeri in un array chiamato vettore di 5 numeri
(o  da tastiera o tramite funzione random)
creare un altro vettore, chiamato vettore_opposto e riempirlo
con i numeri di vettore di posizione invertita*/


// vettore = [ ] [ ] [ ] [ ] [ ]
//            0   1   2   3   4

// vettore_opposto = [ ] [ ] [ ] [ ] [ ]
//                    4   3   2   1   0

int main(int argc, char** argv) {
	const int dim = 5;
	float vettore[dim];
	float vettore_opposto[dim];

	for(short i = 0; i < dim; i++) {
		vettore[i] = rand();
		// cin >> vettore[i];
	}

	for(short i = 0; i < dim; i++) {
		vettore_opposto[dim - 1 - i] = vettore[i];
	}

	//output vettore
	for (short i = 0; i < dim; i++) {
		std::cout << "vettore [" << i << "]: " << vettore[i] << '\n';
	}

	//output vettore_opposto
	for (short i = 0; i < dim; i++) {
		std::cout << "vettore_opposto [" << i << "]: " << vettore_opposto[i] << '\n';
	}

}


/*creare nel main un ciclo while in cui viene chiesto il voto. Passare il voto a una funzione che stampa "ammesso" se il voto >=6, altrimenti "non ammesso"
Il ciclo while deve essere strutturato come un menu a 2 opzioni, una per chiedere il prossimo voto, una per uscire*/

int main(int argc, char** argv) {

	int valore_inserito = 1;

	while(true){
		std::cout << "inserire il voto\n";
		std::cin >> valore_inserito;
		
		if (valore_inserito < 0) {
			std::cout << "Valore inserito errato\n";
			std::exit(1);
		}

		switch (valore_inserito)
		{
		case 0: return 0;
		default: 
			if (valore_inserito > 10) {
				std::cout << "valore inserito errato\n";
				std::exit(2);
			}
			if (valore_inserito < 6)
				std::cout << "non ammesso\n";
			else
				std::cout << "ammesso\n";
		}
	}

}


unsigned long fattoriale(int dim) {
	unsigned long box = 1;
	for (int i = 1; i < dim; i++)
		box *= i;
	return box;
}

//dim [4]
//box [ ]

unsigned long fattoriale_ric(int *dim, unsigned long *box) {

	*dim = *dim - 1;
	if (*dim == 0)
		return *box;
	else {
		*box = *box * *dim;
		fattoriale_ric(dim, box);
	}
}
#include <chrono>
using namespace std;
int main(int argc, char **argv){

	int dim;
	unsigned long box=1;
	std::cout << "inserire dimensione\n";
	std::cin >> dim;
	dim++;

	auto begin = chrono::steady_clock::now();
	fattoriale(dim);
	auto end = chrono::steady_clock::now();
	std::cout << "tempo fattoriale = " << chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << "ns\n";

	begin = chrono::steady_clock::now();
	fattoriale_ric(&dim, &box);
	end = chrono::steady_clock::now();
	std::cout << "tempo fattoriale_ric = " << chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns\n";
}