#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Tranzakcio{
public:
    int ar;
    string nev;

    Tranzakcio(){}
    Tranzakcio(string _nev, int _ar){
        nev=_nev;
        ar=_ar;
    };
};

vector<Tranzakcio> tranzakciokIrasra;
vector<Tranzakcio> tranzakciokOlvasva;

string legolcsobbNeve(){
    string nev=tranzakciokOlvasva[0].nev;
    int minAr=tranzakciokOlvasva[0].ar;
    for (int i = 0; i < tranzakciokOlvasva.size(); ++i) {
        if(tranzakciokOlvasva[i].ar<minAr){
            nev=tranzakciokOlvasva[i].nev;
            minAr=tranzakciokOlvasva[i].ar;
        }
    }


    return nev;
}

string legdragabbNeve(){
    string nev=tranzakciokOlvasva[0].nev;
    int minAr=tranzakciokOlvasva[0].ar;
    for (int i = 0; i < tranzakciokOlvasva.size(); ++i) {
        if(tranzakciokOlvasva[i].ar>minAr){
            nev=tranzakciokOlvasva[i].nev;
            minAr=tranzakciokOlvasva[i].ar;
        }
    }
    return nev;
}

int osszBevetel(){
   int bevetel=0;
    for (int i = 0; i < tranzakciokOlvasva.size(); ++i) {
        bevetel+=tranzakciokOlvasva[i].ar;
    }
    return bevetel;
}

int main() {
    string nev;
    int ar;
    int db=0;

    while(db<4){
        cout<<"Kerem adja meg a kovetkezo tranzakciot"<<endl;
        cout<<"Nev: "<<endl;
        cin>>nev;
        cout<<"Ar: "<<endl;
        cin>>ar;
        tranzakciokIrasra.push_back(Tranzakcio(nev,ar));
        db++;
    }

    ofstream fajlom("vasarlasok.txt");

    if(fajlom.is_open()){
        for (int i = 0; i < tranzakciokIrasra.size(); ++i) {
            fajlom<<tranzakciokIrasra[i].nev;
            fajlom<<':';
            fajlom<<tranzakciokIrasra[i].ar<<'\n';
        }
    }else{cout<<"Nem sikerult megnyitni/letrehozni a fajlt..."<<endl;}

    fajlom.close();

    ifstream fajlomOlvasasra("vasarlasok.txt");

    if(fajlomOlvasasra.is_open()){
        string beolvasottSor;

        string beolvasottNev;
        string beolvasottAr;
        int veglegesAr;

        while (getline(fajlomOlvasasra,beolvasottSor)){
            unsigned long elvalasztoHelye=beolvasottSor.find(':');
            beolvasottNev=beolvasottSor.substr(0,elvalasztoHelye);
            beolvasottAr=beolvasottSor.substr(elvalasztoHelye+1,beolvasottSor.size());


            veglegesAr=stoi(beolvasottAr);


            tranzakciokOlvasva.push_back(Tranzakcio(beolvasottNev,veglegesAr));
        }

    }else{cout<<"Nem sikerult a beolvasas...";}

    for (int j = 0; j < tranzakciokOlvasva.size(); ++j) {
        cout<<tranzakciokOlvasva[j].nev<<'\t'<<tranzakciokOlvasva[j].ar<<endl;
    }

    cout<<"Legolcsobb: "<<legolcsobbNeve()<<endl;
    cout<<"Legdragabb: "<<legdragabbNeve()<<endl;
    cout<<"Osszbevetel: "<<osszBevetel()<<endl;

    std::cout << "A program a vegehez ert!" << std::endl;
    return 0;
}
