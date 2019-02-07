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

    Szemely(){}
    Szemely(string _nev, int _kor){
        nev=_nev;
        kor=_kor;
    }

};

Szemely szemelyek[MERET];
vector<Szemely> konzolrolSzemelyek;
vector<Szemely> beolvasottSzemelyek;

int main() {
    string nev;
    int kor;
    int db=1;
    char elvalaszto='\t';

    while(nev!="0"){
        cout<<"Kerem adja meg a "<<db<<". szemely nevet: "<<endl;
        cin>>nev;

        if(nev!="0"){
            cout<<"Kerem adja meg a "<<db<<". szemely korat: "<<endl;
            cin>>kor;
            db++;
            konzolrolSzemelyek.push_back(Szemely(nev,kor));
        }
    }

    cout<<"Beolvasott szemelyek szama: "<<konzolrolSzemelyek.size()<<endl;

    ofstream fajlom("lista.txt");

    if(fajlom.is_open()){
        cout<<"A fajl megnyitva irasra."<<endl;

        for (int i = 0; i < konzolrolSzemelyek.size(); ++i) {
            fajlom<<konzolrolSzemelyek[i].nev;
            fajlom<<'\t';
            fajlom<<konzolrolSzemelyek[i].kor;
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

        string kiolvasottNev;
        string kiolvasottKor;

        while (getline(fajlomOlvasasra,beolvasottSor)){
            unsigned long elvalasztoHelye=beolvasottSor.find('\t');
            kiolvasottNev=beolvasottSor.substr(0,elvalasztoHelye);
            kiolvasottKor=beolvasottSor.substr(elvalasztoHelye+1,beolvasottSor.size());

            int kor=stoi(kiolvasottKor);

            beolvasottSzemelyek.push_back(Szemely(kiolvasottNev,kor));
        }

    }else{cout<<"Nem sikerult megnyitni a fajlt!";}

    fajlomOlvasasra.close();
    cout<<"A fajl olvasasa befejezodott."<<endl;

    for (int j = 0; j < beolvasottSzemelyek.size(); ++j) {
        cout<<beolvasottSzemelyek[j].nev<<'\t'<<beolvasottSzemelyek[j].kor<<endl;
    }
    cout<<"Minden tarolt adat kiirva."<<endl;

    int eletkorokOsszege=0;

    for (int k = 0; k < beolvasottSzemelyek.size(); ++k) {
        eletkorokOsszege+=beolvasottSzemelyek[k].kor;
    }

    int atlagEletkor=eletkorokOsszege/beolvasottSzemelyek.size();

    cout<<"Az atlag eletkor: "<<atlagEletkor<<endl;

    int maxEletkor=beolvasottSzemelyek[0].kor;
    int minEletkor=beolvasottSzemelyek[0].kor;

    string legfiatalabbNeve=beolvasottSzemelyek[0].nev;
    string legidosebbNeve=beolvasottSzemelyek[0].nev;

    for (int l = 0; l < beolvasottSzemelyek.size(); ++l) {
        if(beolvasottSzemelyek[l].kor>maxEletkor){
            maxEletkor=beolvasottSzemelyek[l].kor;
            legidosebbNeve=beolvasottSzemelyek[l].nev;
        }

        if(beolvasottSzemelyek[l].kor<minEletkor){
            minEletkor=beolvasottSzemelyek[l].kor;
            legfiatalabbNeve=beolvasottSzemelyek[l].nev;
        }
    }

    cout<<"Legidosebb: "<<legidosebbNeve<<'\t'<<" legfiatalabb: "<<legfiatalabbNeve<<endl;

    std::cout << "A kod a vegehez ert." << std::endl;
    return 0;
}
