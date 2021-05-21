#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <random>
#include <ctime>

using namespace std;

class Talia
{
protected:

	enum class Karty{
		S2, S3, S4, S5, S6, S7, S8, S9, S10, JS, QS, KS, SA,
		H2, H3, H4, H5, H6, H7, H8, H9, H10, JH, QH, KH, HA,
		D2, D3, D4, D5, D6, D7, D8, D9, D10, JD, QD, KD, DA,
		C2, C3, C4, C5, C6, C7, C8, C9, C10, JC, QC, KC, CA,
	};

	vector <string> karty_vector =
	{
		"2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AS",
		"2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AH",
		"2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AD",
		"2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC", "AC"
	};

	vector <Karty> karty_stos;
	vector <Karty> karty_gracze;
	vector <Karty> karty_odrzucone;
	vector <Karty> karty_river;
	
	short int ilosc_graczy;
	short int ilosc_kart;



public:

	void stworz();
	void zbierz();
	void tasuj();
	void wyswietl_wszystko();
	void wyswietl_river();
	void wyswietl_graczy();
	void rozdaj();
	void dodaj_river(int ilosc_kart);
	void daj_rozdanie();

	void sprawdz_uklad();

	Talia();
	Talia(int ilosc_g, int ilosc_k);
};


// TODO: Usun¹c poni¿sz¹ implementacjê

template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
{
	return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "{";
	size_t last = v.size() - 1;
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i];
		if (i != last)
			out << ", ";
	}
	out << "}";
	return out;
}

