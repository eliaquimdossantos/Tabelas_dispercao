#include "lista.h"
#include <random>
#include <ctime>

using namespace std;

int sum(string expressao){
	int x = 0;

	for(int i = 0; i < expressao.size(); i++){
		cout << expressao[i] << "  " ;
		x += expressao[i];
	}

	x = x % 53;

	return x;
}


int main(int argc, char const *argv[])
{
	LinkedList<string> vetor[53];

	string texto = "Eai Eai Pois E Pois E ";
	LinkedList<string> sub_str;
	string bloco = "";
	int total_colisao = 0;


	for(int i = 0; i < texto.size(); i++){
		if(texto[i] != ' '){
			bloco += texto[i];			
		}else{
			if(bloco != "")
				sub_str.PushBack(bloco);

			bloco = "";
		}
	}

	sub_str.Print();

	sum(texto);

	LinkedList<string>percorre_list = sub_str;
	int index = 0;

/*
	for(int i = 0; i < sub_str.Length(); i++){				
		index = sum(percorre_list.GetElement(i));		
		vetor[i].PushBack("start_list");		
	}
*/	

	for(int i = 0; i < texto.size()-1; i++){

	}
	/*for(int i = 0; i < 15; i++){
		index = sum(numeroGerado);		
			
		if(vetor[i].Length() > 1){
			cout << "Houve colisão" << endl;
			vetor[index].PushBack(string);	
			total_colisao++;
		}else
			vetor[index].PushBack(string);	
			
	}

	*/



	for(int i = 0 ; i < 20; i++){
		cout << ">";
		vetor[i].Print();
	}

	cout << endl << "++Total de colisões: " << total_colisao << endl;

	return 0;
}
