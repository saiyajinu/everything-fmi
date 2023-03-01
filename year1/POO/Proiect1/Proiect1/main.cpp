#include <iostream>
#include <string.h>

using namespace std;

class Angajat{
private:
    char* nume;
    string prenume;
    int varsta;
    float salariu;
    const int idAngajat;
    static int contorIdAngajat;

public:
    Angajat():idAngajat(contorIdAngajat++){
        this->nume=new char[strlen("Anonim")+1];
        strcpy(this->nume,"Anonim");
        this->prenume="Anonim";;
        this->varsta=0;
        this->salariu=0;
    }

    Angajat(char* nume, string prenume, int varsta, float salariu):idAngajat(contorIdAngajat++){
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->prenume=prenume;
        this->varsta=varsta;
        this->salariu=salariu;
    }

    Angajat(char* nume, string prenume, int varsta):idAngajat(contorIdAngajat++){
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->prenume=prenume;
        this->varsta=varsta;
        this->salariu=0;
    }

    Angajat(char* nume):idAngajat(contorIdAngajat++){
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->prenume="Anonim";
        this->varsta=0;
        this->salariu=0;
    }

    Angajat(const Angajat& a):idAngajat(a.idAngajat){
        this->nume = new char[strlen(a.nume)+1];
        strcpy(this->nume,a.nume);
        this->prenume=a.prenume;
        this->salariu=a.salariu;
    }

    ~Angajat(){
        if(this->nume!=NULL)
            delete[] this->nume;
    }

    void setNumeAngajat(char* nume){
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
    }

    void setVarstaAngajat(int varsta){
        this->varsta=varsta;
    }

    void setSalariuAngajat(float salariu){
        this->salariu=salariu;
    }

    const char* getNumeAngajat(){
        return this->nume;
    }

    int getVarstaAngajat(){
        return this->varsta;
    }

    float getSalariuAngajat(){
        return this->salariu;
    }

    Angajat& operator=(const Angajat& a){
        if(this!=&a){
            if(this->nume!=NULL)
                delete[] this->nume;
        this->nume=new char[strlen(a.nume)+1];
        strcpy(this->nume,a.nume);

        this->prenume=a.prenume;
        this->varsta=a.varsta;
        this->salariu=a.salariu;
        }

        return *this;
    }

    friend istream& operator>>(istream& in, Angajat& a){
        cout<<"Numele angajatului este: ";
        char auxNume[30];
        in>>auxNume;
        a.nume = new char[strlen(auxNume)+1];
        strcpy(a.nume, auxNume);
        cout<<"Prenumele angajatului este: ";
        in>>a.prenume;
        cout<<"Varsta angajatului este: ";
        in>>a.varsta;
        cout<<"Salariul angajatului este: ";
        in>>a.salariu;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Angajat& a){
        out<<"Numele angajatului este "<<a.nume<<endl;
        out<<"Prenumele angajatului este "<<a.prenume<<endl;
        out<<"Varsta angajatului este "<<a.varsta<<endl;
        out<<"Salariul angajatului este "<<a.salariu<<endl<<endl;
    }

    explicit operator int(){
        return (int)this->salariu;
    }



};
int Angajat::contorIdAngajat=0;

class Produs{
private:
    string numeProdus;
    char categorieProdus;
    float pretProdus;
    bool luminiRGB;
    string codProdus;
    int* dimensiuniProdus;

};

class Comanda{   /////////
    char* nickClient;
    Produs produse[15];
    const int idRezervare;
    static int contorIdRezervare;

};

class Magazin{
    string numeMagazin;
    Angajat manager;
    Produs produse[100];
    string adresaMagazin;
};

int main()
{
    char nume[]="Sefcic";
    Angajat a(nume, "Adrian", 19, 8000);
    Angajat b;
    Angajat c;
    cout<<a<<b;
    return 0;
}
