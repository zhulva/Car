/* 
 * File:   main.cpp
 * Author: ucitel
 *
 * Created on 5. listopadu 2015, 7:46
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "auticko.hpp"

using std::cout;
using std::cin;
using std::endl;
/*
 * 
 */
int main(int argc, char** argv) {
    char spz[8];
    float spotreba;
    int rokVyroby;
    bool chyba;
    short znovu=0;
    //vytvoření objektu ve volné oblasti paměti
    auticko * vuz1 = new auticko();
    cout <<"objekt vytvoreny vychozim konstruktorem bez parametru"<<endl;
    cout <<"spz: "<<vuz1->getSpz()<<" rok: "<<vuz1->getRok()<<
            " spotreba: "<<vuz1->getSpotreba()<<" Stari auta:"<< vuz1->stariAuta()<<endl;
    //vytvoreni objektu konstruktorem parametrem
    strcpy(spz,"4T63600");
    auticko *vuz2 = new auticko(spz,8.5,2013);
    cout <<"objekt vytvoreny konstruktorem s parametrem"<<endl;
    cout <<"spz: "<<vuz2->getSpz()<<" rok: "<<vuz2->getRok()<<
            " spotreba: "<<vuz2->getSpotreba()<< " Stari auta:"<< vuz2->stariAuta()<<endl;
    auticko *vuz3 = new auticko(*vuz2);
    cout <<"objekt vytvoreny kopirovacim konstruktorem"<<endl;
    cout <<"spz: "<<vuz3->getSpz()<<" rok: "<<vuz3->getRok()<<
            " spotreba: "<<vuz3->getSpotreba()<< " Stari auta:"<< vuz3->stariAuta()<<endl;
    
    cout<<"Zadej spz pro v3:";
    cin>>spz;
    if(vuz3->setSpz(spz))
            cout<<"Zmena spz (vuz 3): "<<vuz3->getSpz()<<endl;
    else
        cout<<"Nepovedlo se.";
    
    do{
        chyba=false;
        znovu=0;
        cout<<"Zadej spz:";
        cin>>spz;
        if(vuz1->setSpz(spz))
            cout<<"Zmena spz "<<vuz1->getSpz()<<endl;
        else{
            cout<<"Spatne zadano "<<endl;
            chyba=true;
        }

        cout<<"Zadej spotrebu:";
        cin>>spotreba;
        if(vuz1->setSpotreba(spotreba))
            cout<<"Zmena spotreby "<<vuz1->getSpotreba()<<endl;
        else{
            cout<<"Spatne zadanoa spotreba "<<endl;
            chyba=true;
        }
        cout<<"Zadej rok vyroby:";
        cin>>rokVyroby;
        if(vuz1->setRok(rokVyroby))
            cout<<"Zmena vyroby roku "<<vuz1->getRok()<<endl;
        else{
            cout<<"Spatne zadan rok vyroby "<<endl;
            chyba=true;
        }
        if (chyba){
            cout<<"Chcete zadat znovu (1)?";
            cin>>znovu;  
        }             
    }while(znovu);    
    
    //zrušní objektu ve volné oblasti paměti
    if(vuz1!=0){
        delete vuz1;
        vuz1=0;
    }
    
    if(vuz2!=0){
        delete vuz2;
        vuz2=0;
    }
    
    return 0;
}

