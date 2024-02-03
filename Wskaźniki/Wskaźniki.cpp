

#include <iostream>

int main()
{
	char tC[10];
	long tL[10];

	char* wtC = tC;
	long* wtL = tL;
	wtC += 4;
	wtL += 4;
	int kalibracja[10];

	int* wKalibracja = kalibracja;



	char alfabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char *wskAlf = &alfabet[3];

	for (int i = 0; i < 26; i++) {
		if(i % 4 == 0)
			std::cout << i << " " << *wskAlf << std::endl;

		wskAlf++;
	}
	
	//Wypisz za pomocą pętli co 4 litere output to d h l p t x

}

