#include <iostream>
#include <fstream>
#include <string>
#define TOMBMERET 4
using namespace std;

class Ember {
public:
	int kor;
	string nev;

	Ember() {}
	Ember(string _nev, int _kor) {
		nev = _nev;
		kor = _kor;
	}
};

int main() {
	int kor;
	string nev;

	Ember tomb[TOMBMERET];

	for (int i = 0; i < TOMBMERET; i++)
	{
		cout << "Kerem adja meg az " << i + 1 << ". ember nevet" << endl;
		cin >> nev;
		cout << "Kerem adja meg az " << i + 1 << ". ember korat" << endl;
		cin >> kor;
		tomb[i] = Ember(nev, kor);
	}


	ofstream megnyitandoFile("fajl.txt");
	if (megnyitandoFile.is_open())
	{
		for (int i = 0; i <TOMBMERET; i++)
		{
			megnyitandoFile << tomb[i].nev;
			megnyitandoFile << '\t';
			megnyitandoFile << tomb[i].kor;
			megnyitandoFile << endl;
		}
		megnyitandoFile.close();
	}
	else cout << "Nem tudom megnyitni a fajlt";
	return 0;
}
