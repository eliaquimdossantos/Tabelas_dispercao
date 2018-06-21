#include "lista.h"
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

int sum(string expressao){
	int x = 0;
	
	for(int i = 0; i < expressao.size(); i++){		
		x += expressao[i];					
	}

	x = x % 53;

	return x;
}


int main(int argc, char const *argv[])
{	
	LinkedList<string> array[53];	
	LinkedList<string> sub_str;
	string word = "";
	int word_indexs = 0;
	int index = 0;

	while(cin >> word){			
		word_indexs = word.size()-1;

		for(int i = 0; i <= word_indexs; i++){			
			word[i] = tolower(word[i]);				
		}
		
		if(word_indexs > 0){
			if((word[0] >= 48 && word[0] <= 57)
					|| (word[0] >= 97 && word[0] <= 122)){		
				
			}else{
				for(int i = 0; i < word_indexs-1; i++){
					word[i] = word[i+1];
				}
					
				word[word_indexs-1] = '\0';																
			} 

			if((word[word_indexs] >= 48 && word[word_indexs] <= 57)
					|| (word[word_indexs] >= 97 && word[word_indexs] <= 122)
					|| (word_indexs == '%')){		
				
			}else{		
				word[word_indexs] = '\0';	
			}
		}		

		index = sum(word);
		
		array[index].PushBack(word);
	}


	for(long i = 0 ; i < 53; i++){		
		cout << "[" << i+1 << "] ";
		array[i].Print();
	}

	cout << endl << endl;

	for(long i = 0 ; i < 53; i++){		
		array[i].PrintRepeats();
	}

	return 0;
}
