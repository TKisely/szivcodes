#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class Tanulo
{
private:
	string nev;
	unsigned int eletkor;
	unsigned int igazolvany;

public:
	Tanulo() {}

	Tanulo(string _nev, int _eletkor, int _igazolvany) {
		nev = _nev;
		eletkor = _eletkor;
		igazolvany = _igazolvany;
	}

	int getEletkor() {
		return eletkor;
	}

};

class Osztaly
{
private:
	Tanulo* list;
	int elemSzam;

public:
	Osztaly() {}
	~Osztaly() {
		if (elemSzam != 0 || list != nullptr) {
			delete[]list;
			elemSzam = 0;
		}
	}

	void tanuloFelvetele(Tanulo ujTanulo) {
		Tanulo *tempList = new Tanulo[elemSzam + 1];
		for (int i = 0; i < elemSzam; ++i) {
			tempList[i] = list[i];
		}
		tempList[elemSzam] = ujTanulo;
		if (list) { delete[]list; }
		list = tempList;
		elemSzam++;
	}

	void csere(int elsoIndex, int masodikIndex) {
		Tanulo ideiglenes = list[elsoIndex];
		list[elsoIndex] = list[masodikIndex];
		list[masodikIndex] = ideiglenes;
	}

	int legidosebb() {
		if (elemSzam>0) {
			int maxKor = list[0].getEletkor();
			for (int i = 0; i < elemSzam; i++)
			{
				if (list[i].getEletkor() > maxKor) {
					maxKor = list[i].getEletkor();
				}
			}
			return maxKor;
		}
		else return 0;
	}

	int legfiatalabb(){
		if (elemSzam > 0) {
			int minKor = list[0].getEletkor();
			for (int i = 0; i < elemSzam; i++)
			{
				if (list[i].getEletkor() < minKor) {
					minKor = list[i].getEletkor();
				}
			}
			return minKor;
		}
		else return 0;
	
	}

	void sorbaRendezes() {
		int i, j;
		for (i = 0; i < elemSzam - 1; i++)
			for (j = 0; j < elemSzam - i - 1; j++)
				if (list[j].getEletkor() > list[elemSzam + 1].getEletkor())
					csere(j, j + 1);
	}

	void kiiratas() {
		for (int i = 0; i < elemSzam; i++)
		{
			cout << list[i].getEletkor() << endl;
		}
	}
};



int main()
{
	Osztaly o;
	o.tanuloFelvetele(Tanulo("Berci", 17, 12345678));
	o.tanuloFelvetele(Tanulo("Sanyi", 18, 23456789));
	o.tanuloFelvetele(Tanulo("Joska", 15, 34567891));
	o.tanuloFelvetele(Tanulo("Lujza", 16, 45678912));
	cout << o.legidosebb();
	cout << o.legfiatalabb();

	o.kiiratas();
	o.sorbaRendezes();
	o.kiiratas();

    std::cout << "Lefutottam!\n"; 
}

