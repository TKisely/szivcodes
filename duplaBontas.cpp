#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define MERET 3

using namespace std;

class Szemely{
public:
    string nev;
    int kor;
    string varos;

    Szemely(){}
    Szemely(string _nev, int _kor, string _varos){
        nev=_nev;
        kor=_kor;
        varos=_varos;
    }

};

Szemely szemelyek[MERET];
vector<Szemely> beolvasottSzemelyek;

int main() {
    string nev;
    int kor;
    string varos;
    char elvalaszto='\t';

    for (int i = 0; i < MERET; ++i) {
        cout<<"Kerem adja meg a "<<i<<". szemely nevet: "<<endl;
        cin>>nev;
        cout<<"Kerem adja meg a "<<i<<". szemely korat: "<<endl;
        cin>>kor;
        cout<<"Kerem adja meg a "<<i<<". szemely szulovarosat: "<<endl;
        cin>>varos;
        szemelyek[i]=Szemely(nev, kor, varos);
    }

    ofstream fajlom("lista.txt");

    if(fajlom.is_open()){
        cout<<"A fajl megnyitva irasra."<<endl;

        for (int i = 0; i < MERET; ++i) {
            fajlom<<szemelyek[i].nev;
            fajlom<<elvalaszto;
            fajlom<<szemelyek[i].kor;
            fajlom<<elvalaszto;
            fajlom<<szemelyek[i].varos;
            fajlom<<'\n';
        }
        cout<<"A fajl feltoltve."<<endl;

    } else{cout<<"Nem sikerult megnyitni a fajlt!";}

    fajlom.close();
    cout<<"A fajl bezarva."<<endl;

    ifstream fajlomOlvasasra("lista.txt");

    if(fajlomOlvasasra.is_open()){
        cout<<"A fajl megnyitva olvasasra."<<endl;

        string beolvasottSor;
        string bontottDarab;

        string beolvasottNev;
        string beolvasottKor;
        string beolvasottVaros;


        while (getline(fajlomOlvasasra,beolvasottSor)){
            unsigned long elvalasztoHelye=beolvasottSor.find('\t');
            beolvasottNev=beolvasottSor.substr(0,elvalasztoHelye);

            bontottDarab=beolvasottSor.substr(elvalasztoHelye+1,beolvasottSor.size());

            elvalasztoHelye=bontottDarab.find(elvalaszto);
            beolvasottKor=bontottDarab.substr(0,elvalasztoHelye);
            beolvasottVaros=bontottDarab.substr(elvalasztoHelye+1, bontottDarab.size());

            int kor=stoi(beolvasottKor);

            beolvasottSzemelyek.push_back(Szemely(beolvasottNev,kor, beolvasottVaros));
        }

    }else{cout<<"Nem sikerult megnyitni a fajlt!";}

    fajlomOlvasasra.close();
    cout<<"A fajl olvasasa befejezodott."<<endl;

    for (int j = 0; j < beolvasottSzemelyek.size(); ++j) {
        cout<<beolvasottSzemelyek[j].nev<<elvalaszto<<beolvasottSzemelyek[j].kor<<elvalaszto<<beolvasottSzemelyek[j].varos<<endl;
    }
    cout<<"Minden tarolt adat kiirva."<<endl;

    std::cout << "A kod a vegehez ert." << std::endl;
    return 0;
}
