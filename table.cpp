#include "lista.h"
#include <random>
#include <ctime>

using namespace std;

int fMod20(int num){
	return num%20;
}

int randNumbers(int seed){
	std::mt19937 mt(seed * time(NULL));
	std::uniform_int_distribution<int>linear_i(1, 1000);
	int numero = linear_i(mt);
	return numero;
}

int main(int argc, char const *argv[])
{
	LinkedList<int> vetor[20];

	int numeroGerado;
	int index;

	for(int i = 0; i < 20; i++){
		vetor[i].PushBack(i+1);
	}

	for(int i = 0; i < 15; i++){
		numeroGerado = randNumbers(i);
		index = fMod20(numeroGerado);
		cout << "Numero gerado: " << numeroGerado << endl;
	
		vetor[index].PushBack(numeroGerado);		
	}


	for(int i = 0 ; i < 20; i++){
		cout << ">";
		vetor[i].Print();
	}

	return 0;
}
