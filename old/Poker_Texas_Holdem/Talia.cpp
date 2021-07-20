#include "Talia.h"

Talia::Talia()
{
	ilosc_graczy = 3;
	ilosc_kart = 2;
}
Talia::Talia(int ilosc_g, int ilosc_k)
{	
	ilosc_graczy = ilosc_g;
	ilosc_kart = ilosc_k;
}

void Talia::stworz()
{
	karty_stos.clear();
	karty_stos.resize(52);
	for (int i = 0; i < 52; i++)
	{
		karty_stos[i] = Karty(i);
	}
	cout <<"Stworzono talie kart!" << endl;
}

void Talia::rozdaj()
{	
	cout << "Ilosc graczy: " << ilosc_graczy << endl;
	int rozdanie = ilosc_graczy * ilosc_kart;
	while (rozdanie)
	{
		karty_gracze.push_back(karty_stos[0]);
		karty_stos.erase(karty_stos.begin());
		rozdanie--;
	}
	cout << "Rozdano!" << endl;
}
void Talia::dodaj_river(int ilosc_kart)
{
	cout << "Dodano " << ilosc_kart << " kart na stol" << endl;
	while (ilosc_kart)
	{
		karty_river.push_back(karty_stos[0]);
		karty_stos.erase(karty_stos.begin());
		ilosc_kart--;
	}
}

void Talia::tasuj()
{
	srand(time(0));
	random_shuffle(karty_stos.begin(), karty_stos.end());
	cout << "Przetasowano!" << endl;
}


void Talia::zbierz()
{
	while (karty_gracze.size())
	{
		karty_stos.push_back(karty_gracze[0]);
		karty_gracze.erase(karty_gracze.begin());
	}
	while (karty_odrzucone.size())
	{
		karty_stos.push_back(karty_odrzucone[0]);
		karty_odrzucone.erase(karty_odrzucone.begin());
	}
	while (karty_river.size())
	{
		karty_stos.push_back(karty_river[0]);
		karty_river.erase(karty_river.begin());
	}
	cout << "Zebrano!" << endl;
}

void Talia::daj_rozdanie()
{
	tasuj();
	rozdaj();
	dodaj_river(3);
	wyswietl_river();
	dodaj_river(1);
	wyswietl_river();
	dodaj_river(1);
	wyswietl_river();
	wyswietl_graczy();
	sprawdz_uklad();

}

void Talia::wyswietl_river()
{
	cout << "River [" << karty_river.size() << "]:" << endl;
	for (unsigned int i = 0; i < karty_river.size(); i++)
	{
		cout << karty_vector[int(karty_river[i])];
		if (i < karty_river.size() - 1)
		{
			cout << ", ";
		}
		else
		{
			cout << endl;
		}
	}
	//cout << "River [" << karty_river.size() << "]:\n" << karty_river << endl;
}

void Talia::wyswietl_graczy()
{
	for (int i = 0; i < ilosc_graczy; i++)
	{
		cout << "Gracz #" << i + 1 << ": ";
		for (int j = 0; j < ilosc_kart; j++)
		{
			cout << karty_vector[int(karty_gracze[(i * ilosc_kart) + j])];
			if (j < ilosc_kart - 1)
			{
				cout << ", ";
			}
			else
			{
				cout << endl;
			}
		}
	}
}

void Talia::sprawdz_uklad()
{
	if (karty_river.size() == 5)
	{
		cout << "River ma 5 kart!" << endl;
	}
	else
	{
		cout << "River nie ma 5 kart!" << endl;
	}
}


void Talia::wyswietl_wszystko()
{
	cout << "Karty na stosie ["<<karty_stos.size()<<"]:\n" << karty_stos << endl;
	cout << "Karty u graczy [" << karty_gracze.size() << "]:\n" << karty_gracze << endl;
	cout << "River [" << karty_river.size() << "]:\n" << karty_river << endl;
	cout << "Karty odrzucone [" << karty_odrzucone.size() << "]:\n" << karty_odrzucone << endl;
}
