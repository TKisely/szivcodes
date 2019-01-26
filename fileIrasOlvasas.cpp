#include <iostream>
#include <string>
#include <fstream>

#define MERET 3

using namespace std;


class Tanulo{
public:
    string nev;
    string osztaly;
    int kor;

    Tanulo(){}

    Tanulo(string _nev, string _osztaly, int _kor){
        nev=_nev;
        osztaly=_osztaly;
        kor=_kor;
    }

};

int main() {

    //mivel kesobb be szeretnenk olvasni adatokat
    //igy kellenek ezekhez megfelelo tarolok
    string nev;
    string osztaly;
    int kor;

    //tovabba kell egy tomb, amiben el tudjuk tarolni a tanulokat
    //mivel TANULOkat tarol, igy Tanulo lesz a tipusa
    //neve ertelem szeruen tanulok
    Tanulo tanulok[MERET];

    //mivel egy tombot szeretnenk feltolteni, igy vegig kell menni a tomb elemein
    //ehhez tomb eseteben (fix merete miatt) a legmegfelelobb a FOR ciklus
    for (int i = 0; i < MERET; ++i) {

        //beolvassuk konzolrol az adatokat a megfelelo valtozokba
        //barmilyen sorrendben szabad
        //en most a nevvel kezdek
        cout<<"Kerem adja meg a diak nevet"<<endl;
        cin>>nev;

        cout<<"Kerem adja meg a diak osztalyat"<<endl;
        cin>>osztaly;

        cout<<"Kerem adja meg a diak korat"<<endl;
        cin>>kor;

        //minden adat el van tarolva az ideiglenes valtozoinkban az adott tanulohoz
        //kovetkezo lepes, hogy ezeket az adatokat egyesitsuk egy tanulo peldanyban
        //ezt a tombbe toltessel egyutt tesszuk meg sorokat sporolva

        tanulok[i]=Tanulo(nev,osztaly,kor);
        //tehat a tanulok jelenlegi eleme legyen egy tanulo
        //a megadott nevvel, osztallyal es korral


    }
    //mire a FOR ciklus a vegere er biztosak lehetunk benne
    //(ha megfeleloen dolgoztunk)
    //hogy minden eleme egy megfelelo parameterekkel rendelkezo tanulo

    //ezek utan megkezdhetjuk a fajlunkba valo kiirast
    //mivel eddig nem dolgoztunk a fajlon, ezert nem is volt nyitva
    //igy az elso lepesunk a program es a fajl kozotti kapcsolat megteremtese
    //majd pedig a kapcsolat letrejottenek vizsgalata

    //a tipusa ofstream, mig a neve jelen esetunkben irasFajl
    //jegyezzuk meg, hogy ez a modszer ketfele modon is mukodhet
    //elso verzio, hogy nem letezik meg ilyen nevu fajl, ekkor letrehozza
    //masodik verzi, hogy letezik mar a fajl, ekkor felulirja
    ofstream irasFajl("tanuloi_nyilvantartas.txt");

    //ekkor mi mindent megtettunk, hogy legyen kapcsolat a fajl es a program kozott
    //viszont vizsgalnunk kell, hogy letre is jott-e
    //.is_open() ezt vizsgalja, igazzal ter vissza, ha van kapcsolat
    if(irasFajl.is_open()){
        cout<<"Sikerult megnyitni a fajlt..."<<endl;


        //megkezdhetjuk a tanuloi adatok kiirasat a fajlba
        for (int i = 0; i < MERET; ++i) {

            //irasFajlba bele az i-edik tanulo neve, majd tab
            irasFajl<<tanulok[i].nev;
            irasFajl<<"\t";

            irasFajl<<tanulok[i].osztaly;
            irasFajl<<"\t";

            irasFajl<<tanulok[i].kor;
            //tanulo utolso adata utan sortores a kovetkezo tanulo miatt
            irasFajl<<"\n";
        }

    }else{
        cout<<"Nem sikerult megnyitni a fajlt"<<endl;
    }


    irasFajl.close();
    cout<<"A fajl bezarva!"<<endl;

    ifstream olvasasFajl("tanuloi_nyilvantartas.txt");

    if(olvasasFajl.is_open()){
        cout<<"Sikerult megnyitni a faljt olvasasra..."<<endl;

        //tarolo letrehozasa, amibe a beolvasott sorokat tudjuk tarolni
        string beolvasottSor;

        //amig van mit beolvasni, addig olvassunk
        //olvasasFajlbol a beolvasottSorba olvasunk
        while(getline(olvasasFajl,beolvasottSor)){
            //majd kiirjuk, hogy eppen mit olvastunk be
            cout<<beolvasottSor<<endl;
        }


    }else{cout<<"Nem sikerult megnyitni olvasasra a fajlt"<<endl;}

    //ha mar nem olvasunk, akkor lezarjuk a kapcsolatot
    olvasasFajl.close();





    std::cout << "A kod a vegehez ert." << std::endl;
    return 0;
}
