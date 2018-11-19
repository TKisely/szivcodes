#include <iostream>
using namespace std;

class Product{

private:
    unsigned int key;
    string name;
    unsigned int price;

public:
    Product(){}

    Product(unsigned int _key, string _name, unsigned int _price){
        key=_key;
        name=_name;
        price=_price;
    }

    unsigned int getKey() const {
        return key;
    }

    const string &getName() const {
        return name;
    }

    unsigned int getPrice() const {
        return price;
    }

};

Product* list= nullptr;
int elementNum;

bool isEmpty(){
    if(elementNum==0){
        return true;
    }
    return false;
}
void deleteAllElements(){
    if(elementNum!=0||list!= nullptr){
        delete[]list;
        elementNum = 0;
    }
}

void putLast(Product newElement){
    Product *tempList = new Product[elementNum+1];
    for (int i = 0; i < elementNum; ++i) {
        tempList[i]=list[i];
    }
    tempList[elementNum]=newElement;
    if(list){delete[]list;}
    list=tempList;
    elementNum++;

}

void exampleSeparator(){
    cout<<'\n'<<"-----||-----"<<"\n\n";
}

void printListElementsToConsole(){
    cout<<"\t\t KOD \t NEV \t AR"<<endl;
    for (int i = 0; i < elementNum; ++i) {
        cout<<"A(z) "<<i+1<<". termek:\t"<<list[i].getKey()<<'\t'<<list[i].getName()<<'\t'<<list[i].getPrice()<<" Ft"<<endl;
    }
    exampleSeparator();

}

int avgCalc(){
    int sum=0;
    for(int i=0;i<elementNum;i++){
        sum+=list[i].getPrice();
    }
    return sum/elementNum;
}

int maximum(){
    if(elementNum>0){
        int maximum=list[0].getPrice();
        for(int i=0;i<elementNum;i++){
            if(list[i].getPrice()>maximum){
                maximum=list[i].getPrice();
            }
        }
        return maximum;
    }
    else{return 0;}
}

int minimum(){
    if(elementNum>0){
        int minimum=list[0].getPrice();
        for(int i=0;i<elementNum;i++){
            if(list[i].getPrice()<minimum){
                minimum=list[i].getPrice();
            }
        }
        return minimum;
    }
    else{return 0;}
}

int main() {
    int resp=0;
    do{
        cout<<"Kerem valasszon:"<<endl;
        cout<<"\t Termek hozzadasa : (1)"<<endl;
        cout<<"\t Lista megtekintese : (2)"<<endl;
        cout<<"\t Az eladott termekek atlaga : (3)"<<endl;
        cout<<"\t Legolcsobb termek ara: (4)"<<endl;
        cout<<"\t Legdragabb termek ara: (5)"<<endl;
        cout<<"\t Kilepes : (0)"<<endl;

        cin>>resp;

        if(resp==1){
            int pKey;
            string pName;
            int pPrice;

            cout<<"Adja meg a termek kodjat:"<<endl;
            cin>>pKey;
            cout<<"Adja meg a termek nevet:"<<endl;
            cin>>pName;
            cout<<"Adja meg a termek arat:"<<endl;
            cin>>pPrice;

            putLast(Product(pKey,pName,pPrice));

        } else if(resp==2){
            printListElementsToConsole();
        } else if(resp==3) {
            cout<<"Az atlag: "<<avgCalc()<<endl;
        } else if(resp==4){
            cout<<minimum()<<endl;
        } else if(resp==5){
            cout<<maximum()<<endl;
        }

    }while(resp>0);

    cout<<"A vegleges lista:"<<endl;
    printListElementsToConsole();

    cout<<"Kileptel..."<<endl;
    return 0;
}
