#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

string zamienNaBinarna(int a) {
	int r = 0;
	string odwroconaLiczbaBinarna = "";

	while (a > 0) {
		r = a % 2;
		a = a / 2;

		odwroconaLiczbaBinarna += to_string(r);
	}

	string liczbaBinarna = "";
	for (int i = odwroconaLiczbaBinarna.length() - 1; i >= 0; i--) {
		liczbaBinarna += odwroconaLiczbaBinarna[i];
	}

	return liczbaBinarna;
}


int policzBloki(int a) {
	string binarna = zamienNaBinarna(a);
	int bloki = 1;

	for (int i = 1; i < binarna.length(); i++) {
		if (binarna[i - 1] != binarna[i]) {
			bloki++;
		}
	}

	return bloki;
}

int policzBloki(string binarna) {
	int bloki = 1;

	for (int i = 1; i < binarna.length(); i++) {
		if (binarna[i - 1] != binarna[i]) {
			bloki++;
		}
	}

	return bloki;
}

int BinNa10(string binarna) {
	int dlugosc = binarna.length();

	int wynik = 0;
	for (int i = dlugosc - 1; i >= 0; i--) {
		int cyfra = binarna[i] - '0';
		int potega = dlugosc - i - 1;

		wynik += (cyfra * pow(2, potega));
	}

	return wynik;
}

void zad2_2() {
	ifstream plik;
	plik.open("../bin.txt");

	if (plik.is_open()) {
		string liczby[100];

		int i = 0;
		while (plik >> liczby[i]) {
			i++;
		}

		int ilosc = 0;
		for (int j = 0; j < 100; j++) {
			int bloki = policzBloki(liczby[j]);

			if (bloki <= 2) {
				ilosc++;
			}
		}

		cout << ilosc << endl;
		plik.close();
	}
	else {
		cout << "nie dziala" << endl;
	}
}

void zad2_3() {
	ifstream plik;
	plik.open("../bin.txt");

	if (plik.is_open()) {
		int i = 0;
		int max = 0;
		string maxBinarnie = "";
		string liczbaBinarna;
		while (plik >> liczbaBinarna) {
			int liczba = BinNa10(liczbaBinarna);
			if (liczba > max) {
				max = liczba;
				maxBinarnie = liczbaBinarna;
			}
		}

		cout << maxBinarnie << endl;
	}
	else {
		cout << "nie dziala" << endl;
	}
}


int main() {

}