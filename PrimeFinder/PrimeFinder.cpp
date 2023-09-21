/// PrimeFinder \\\
/// PrimeFinder: "Prime numbers finder"
/// Lavet af: Noah Fink Jensen (Matematikken) og Johan Milter Jakobsen (Programmeringen)
/// Dato: 05-09-2023
/// Disse kommentarer er skrevet af Johan Milter Jakobsen. Dato: 05-09-2023, Kl: 00.03

//Her inkludere vi de enkelse libraies vi behøves for at kunne lave de nødvendige operationer
using namespace std;
#include <iostream>
#include <vector>
#include <time.h>
#include <string>

bool IsPrime(unsigned long long int number)
{
	if (number <= 1)
		return false;
	else if (number <= 3)
		return true;
	else if (number % 2 == 0 || number % 3 == 0)
		return false;
	for (unsigned long long int i = 5; i * i <= number; i += 6)
		if (number % i == 0 || number % (i + 2) == 0)
			return false;
}

int main()
{
	//Vælg her, hvilket intaval der skal tjekkes for primtal
	unsigned long long int start = 0; //Min 0
	unsigned long long int end  =  10000000; //Max = 18.446.744.073.709.551.615

	#pragma region Timer
	int times, timed;
	times = clock();
	#pragma endregion
	vector<unsigned long long int> primes;
	for (unsigned long long int number = start; number <= end; number++)
		if (IsPrime(number))
			primes.push_back(number);
	#pragma region Timer
	timed = clock();
	times = timed - times;
	#pragma endregion


	//Output tallene i consollen
	for (unsigned long long int prime : primes)
		cout << prime << ",";

	//Output mængden og tiden det tog at udregne
	cout << endl << endl << "Fra " << start << " til " << end << " er der " << primes.size() << " primtal. Dette tog " << (float)times / 10000 << " milliseconds";
	return 0;
}

