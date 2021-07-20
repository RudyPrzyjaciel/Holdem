//TODO: ochrona przed wykorzytaniem wszystkich kart
//		usun¹c implementacje overload operatora <<
//		funkcja tasowania nie dziala poprawnie
//		zaimplementowaæ system sprawdzania ukladow graczy


#include <iostream>
#include "Talia.h"

using namespace std;

int main()
{
	Talia test;
	Talia kart;

	//test.stworz();
	//test.tasuj();
	//test.rozdaj();
	//test.dodaj_river(5);
	//test.wyswietl_river();
	//test.wyswietl_graczy();
	//test.zbierz();

	kart.stworz();
	kart.daj_rozdanie();

	return 0;
}
