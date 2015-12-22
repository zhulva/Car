#ifndef AUTICKO_HPP
#define	AUTICKO_HPP

class auticko {
public:
    auticko();
    auticko(const auticko& orig);
    auticko(char *,float,int);
    virtual ~auticko();
    //přistupové metody
    char * getSpz()const;
    float getSpotreba()const;
    int getRok()const;
    bool setSpz(char *);
    bool setSpotreba(float);
    bool setRok(int);
    int stariAuta()const;
private:
    char * spz;
    float spotreba;
    int rokVyroby;
    int aktualniRok()const;
    bool kontrolaSpz(char *)const;
    bool kontrolaSpotreby(float)const;
    bool kontrolaRoku(int)const;    
};

#endif	/* AUTICKO_HPP */

