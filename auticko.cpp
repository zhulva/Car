/* 
 * File:   auticko.cpp
 * Author: ucitel
 * 
 * Created on 5. listopadu 2015, 7:47
 */

#include "auticko.hpp"
#include <cstring>
#include <ctime>
#define DELKA 7
#define SPZ "0000000"
#define SPOTREBA 0
#define ROK 1900
auticko::auticko() {
    //vyhrazení paměti pro spz
    this->spz=new char[DELKA+1];
    //testování přidělené paměti
    if(this->spz!=0){
        strcpy(this->spz,SPZ);
    }
    this->spotreba=SPOTREBA;
    this->rokVyroby=ROK;
}

auticko::auticko(char* spz, float spotreba, int rokVyroby){
    //vyhrazení paměti pro spz
    this->spz=new char[DELKA+1];
    //testování přidělené paměti
    if(this->spz!=0){
        if(this->kontrolaSpz(spz))
            strcpy(this->spz,spz);
        else
            strcpy(this->spz,SPZ);
    }
    if(this->kontrolaSpotreby(spotreba))
        this->spotreba=spotreba;
    else
        this->spotreba=SPOTREBA;
    
    if(this->kontrolaRoku(rokVyroby))
        this->rokVyroby=rokVyroby;
    else
        this->rokVyroby=ROK;
    
}
//Kopírovací konstruktor vytvoří kopii objektu předaného v parametru orig
//V metodě můžeme použít pouze konst. metody objektu orig
//const = v metodě nelze objekt orig měnit
//& = odkaz na jiný objekt, tj. jiné jméno objektu
auticko::auticko(const auticko& orig) {  
    this->spz=new char[DELKA+1];
    strcpy(this->spz,orig.getSpz());
    this->rokVyroby=orig.getRok();
    this->spotreba=orig.getSpotreba();
}

auticko::~auticko() {
    //zrušení přidělené paměti
    if(this->spz!=0){
        delete [] this->spz;
        this->spz=0;
    }
}

char * auticko::getSpz()const{
    return this->spz;
}

int auticko:: getRok()const{
    return this->rokVyroby;
}

float auticko:: getSpotreba()const{
    return this->spotreba;
}

int auticko:: aktualniRok()const{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    return timeinfo->tm_year + 1900;
}

bool auticko::kontrolaSpotreby(float spotreba) const{
    if(spotreba > 0)
        return true;
    else
        return false;
} 

bool auticko::kontrolaRoku(int rok) const{
    if(rok > ROK && rok <= this->aktualniRok())
        return true;
    else
        return false;
}

bool auticko::kontrolaSpz(char* spz) const{
    char kraje[]={'A','B','C','E','H','J','K','L','M','P','S','T','U','Z','\0'};
    //kontrola delky spy
    if(strlen(spz)!=7)
        return false;
    //na prvnim miste muzou byt jen cifry 0-9
    if(spz[0]<'0' || spz[0]>'9')
        return false;
    //kontrola kraje, druhy znak musi obsahovat pismeno kraje
    for(int i = 0;i<strlen(kraje);i++){
        if(spz[1]==kraje[i]){
         break;
        }      
        if(i==strlen(kraje)-1)
            return false;
    }
    
    for (int i=2;i<strlen(spz);i++){
        if((spz[i]<'0' || spz[i]>'9') && (spz[i]>'Z' || spz[i]<'A'))
            return false;
    }
    return true;
}

bool auticko::setSpz(char*spz){
    if(this->kontrolaSpz(spz)){
        strcpy(this->spz,spz);
        return true;
    } 
    else
        return false;
}

bool auticko::setRok(int rok){
    if(this->kontrolaRoku(rok)){
        this->rokVyroby=rok;
        return true;
    } 
    else
        return false;
}

bool auticko::setSpotreba(float spotreba){
    if(this->kontrolaSpotreby(spotreba)){
        this->spotreba=spotreba;
        return true;
    } 
    else
        return false;
}
int auticko::stariAuta() const{
    return this->aktualniRok()- this->rokVyroby;
} 
