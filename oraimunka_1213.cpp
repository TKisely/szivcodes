
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Termek {
private:
	int beszerzesiAr;
	int nettoEladasiAr;
	string nev;
	unsigned int cikkszam;

public:
	Termek() {}
	Termek(int _beszerAr, int _nettoElAr, string _nev,unsigned int _cikksz) {
		beszerzesiAr = _beszerAr;
		nettoEladasiAr = _nettoElAr;
		nev = _nev;
		cikkszam = _cikksz;
	}

	int getBeszerAr() {
		return beszerzesiAr;
	}

	int getNettoElAr() {
		return nettoEladasiAr;
	}

	string getNev() { return nev; }

	unsigned int getCikksz() {
		return cikkszam;
	}

	int getBruttoElAr() {
		return (nettoEladasiAr*1.27);
	}

	int getHaszon() {
		return (nettoEladasiAr - beszerzesiAr);
	}

	void kiiratas() {
		cout << "Nev: " << getNev() << "Brutto ar: " << getBruttoElAr() << endl;
	}

};

class Kisbolt {
private:
	string nev;
	string varos;
	vector<Termek> termekek;
public:
	Kisbolt() {}
	Kisbolt(string _nev, string _varos) {
		nev = _nev;
		varos = _varos;
	}

	string getNev() {
		return nev;
	}
	string getVaros() {
		return varos;
	}

	Termek legnagyobbBeveteltHozoTermek() {
		int maxHaszon = termekek[0].getHaszon();
		Termek ideiglenes;

		for (int i = 0; i < termekek.size(); i++) {
			if (termekek[i].getHaszon() > maxHaszon) {
				maxHaszon = termekek[i].getHaszon();
				ideiglenes = termekek[i];
			}
		}

		return ideiglenes;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
