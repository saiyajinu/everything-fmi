#include <iostream>
#include <string.h>
using namespace std;

class IOInterface {
public:
    virtual istream& read(istream& in) = 0;
    virtual ostream& write(ostream& out) = 0;
};

class Produs: public virtual IOInterface{
protected:
    string nume;
    float pret;
    string culoare;

public:
    Produs(){
        this->nume = "Anonim";
        this->pret = 0;
        this->culoare = "-";
    }

    Produs(string nume, float pret,  string culoare){
        this->nume = nume;
        this->pret = pret;
        this->culoare = "-";
    }

    Produs(const Produs& prod){
        this->nume = prod.nume;
        this->pret = prod.pret;
        this->culoare = prod.culoare;
    }

    ~Produs(){}

    Produs& operator=(const Produs& prod){
        if(this != &prod){

            this->nume = prod.nume;
            this->pret = prod.pret;
            this->culoare = prod.culoare;
        }
        return *this;
    }

    istream& read(istream&in){
       cout<<"Numele produsului este: ";
        in>>this->nume;
        cout<<"Pretul produsului este: ";
        in>>this->pret;
        cout<<"Culoarea produsului este: ";
        in>>this->culoare;
        cout<<endl;
        return in;
    }

    friend istream& operator>>(istream& in, Produs& prod){
        return prod.read(in);
    }

    ostream& write(ostream& out){
        out<<"Numele produsului este "<<this->nume<<endl;
        out<<"Pretul produsului este "<<this->pret<<endl;
        out<<"Culoarea produsului este "<<this->culoare<<endl<<endl;
        return out;
    }

    friend ostream& operator<<(ostream& out, Produs& prod){
        return prod.write(out);
    }

    virtual void specProdus(){
        cout<<"Produsul nu este complet";
    };
};

class Tastatura : public virtual Produs{
private:
    int nrTaste;
    bool display;
public:
    Tastatura():Produs(){
        this->nrTaste = 0;
        this->display = false;
    }

    Tastatura(int nrTaste, bool display, string nume, float pret, string culoare):Produs(nume, pret, culoare){
        this->nrTaste = nrTaste;
        this->display = display;
    }

    ~Tastatura(){}

    Tastatura(const Tastatura& tastatura) : Produs(tastatura){
        this->nrTaste = tastatura.nrTaste;
        this->display = tastatura.display;
    }

    Tastatura& operator=(const Tastatura& tastatura){
        if (this!=&tastatura){
            Produs::operator=(tastatura);
            this->nrTaste = tastatura.nrTaste;
            this->display = display;
        }
        return *this;
    }

    istream& read(istream& in){
        Produs::read(in);
        cout << "Cate taste are: ";
        in >> this->nrTaste;
        cout << "Are display (1/0): ";
        in >> this->display;
        cout << endl<<endl;
        return in;
    }

    friend istream& operator>>(istream& in, Tastatura& tastatura){
        return tastatura.read(in);
    }

    ostream& write(ostream& out){
        Produs::write(out);
        out << "Numar de taste: ";
        out << this->nrTaste<<endl;
        out << "Are display: ";
        out << this->display<<endl<<endl;
        return out;
    }

    friend ostream& operator<<(ostream& out, Tastatura& tastatura){
        return tastatura.write(out);
    }

    void set(int nr){
        this->nrTaste=nr;
    }

    void set(bool bol){
        this->display = bol;
    }

    void specProdus()const{
        cout << "Are " << this->nrTaste << " taste"<<endl;
        if (this->display == false)
            cout<<"Nu are display"<<endl;
        else cout<<"Are display"<<endl;
    }
};

class Mouse : public virtual Produs{
private:
    int dpi;
public:
    Mouse():Produs(){
        this->dpi = 0;
    }

    Mouse(int dpi, string nume, float pret, string culoare):Produs(nume, pret, culoare){
        this->dpi = this->dpi;
    }

    ~Mouse(){}

    Mouse(const Mouse& mouse) : Produs(mouse){
        this->dpi = mouse.dpi;
    }

    Mouse& operator=(const Mouse& mouse){
        if (this!=&mouse){
            Produs::operator=(mouse);
            this->dpi = mouse.dpi;
        }
        return *this;
    }

    istream& read(istream& in){
        Produs::read(in);
        cout << "Cati DPI are: ";
        in >> this->dpi;
        cout<<endl;
        return in;
    }

    friend istream& operator>>(istream& in, Mouse& mouse){
        return mouse.read(in);
    }

    ostream& write(ostream& out){
        Produs::write(out);
        out << "Numar DPI: ";
        out << this->dpi<<endl<<endl;
        return out;
    }

    friend ostream& operator<<(ostream& out, Mouse& mouse){
        return mouse.write(out);
    }

    void specProdus(){
        cout << "Are " << this->dpi << " DPI"<<endl;
    }
};

class MouseWireless: public Mouse{
private:
    int capacitateBaterie;

public:
    MouseWireless():Mouse(){
        this->capacitateBaterie = 0;
    }

    MouseWireless(int capacitateBaterie, int dpi, string nume, float pret, string culoare):Mouse(dpi, nume, pret, culoare){
        this->capacitateBaterie = capacitateBaterie;
    }

    ~MouseWireless(){}

    MouseWireless(const MouseWireless& mousew): Mouse(mousew){
        this->capacitateBaterie = mousew.capacitateBaterie;
    }

    MouseWireless& operator=(const MouseWireless& mousew){
        if(this!=&mousew){
            Mouse::operator=(mousew);
            this->dpi = mouse.dpi;
        }
        return *this;
    }

    istream& read(istream&in){
        Mouse::read(in);
        cout << "Capacitatea bateriei: ";
        in >> this->capacitateBaterie;
        cout<<endl;
        return in;
    }

    friend istream& operator>>(istream& in, MouseWireless& mousew){
        return mousew.read(in);
    }

    ostream& write(ostream& out){
        Mouse::write(out);
        out << "Capacitate baterie: "<<this->dpi<<endl<<endl;
        return out;
    }

    friend ostream& operator<<(ostream& out, MouseWireless& mousew){
        return mouse.write(out);
    }
};

class Client{
private:
    char* nume;
    string adresa;
    string mail;
    float puncteLoialitate;

public:
    Client(){
        if(this->nume != NULL)
            delete[] this->nume;
        this->nume = new char[strlen("Anonim")+1];
        strcpy(this->nume,"Anonim");
        this->adresa = "-";
        this->mail = "-";
        this->puncteLoialitate = 0;
    }

    Client(char* nume , string adresa , string mail , float puncteLoialitate){
        if(this->nume != NULL)
            delete[] this->nume;
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
        this->adresa = adresa;
        this->mail = mail;
        this->puncteLoialitate = puncteLoialitate;
    }

    Client(const Client& client){
        if(client.nume!=NULL){
            this->nume = new char[strlen(client.nume)+1];
            strcpy(this->nume, client.nume);}
        this->adresa = client.adresa;
        this->mail = client.mail;
        this->puncteLoialitate = client.puncteLoialitate;
    }

    ~Client(){
        if(this->nume != NULL)
            delete[] this->nume;
    }

    Client& operator=(const Client& client){
        if (this != &client){
            if(this->nume != NULL)
                delete[] this->nume;
            if(client.nume != NULL)
                this->nume = new char[strlen(client.nume)+1];
            strcpy(this->nume,client.nume);
            this->adresa = client.adresa;
            this->mail = client.mail;
            this->puncteLoialitate = client.puncteLoialitate;
        }
    }

    friend istream& operator>>(istream&in, Client& client){
        cout<<"Numele clientului este: ";
        char auxnume[25];
        in>>auxnume;
        delete[] client.nume;
        client.nume = new char[strlen(auxnume)+1];
        strcpy(client.nume, auxnume);
        cout<<"Adresa clientului este: ";
        in>>client.adresa;
        cout<<"Mailul clientului este: ";
        in>>client.mail;
        cout<<"Cate puncte de loialitate are clientul: ";
        in>>client.puncteLoialitate;
        cout<<endl;
        return in;
    }

    friend ostream& operator<<(ostream&out, const Client& client){
        if(client.nume)
            out<<"Numele clientului este "<<client.nume<<endl;
        out<<"Adresa clientului este "<<client.adresa<<endl;
        out<<"Mailul clientului este "<<client.mail<<endl;
        out<<"Clientul are "<<client.puncteLoialitate<<" puncte de loialitate"<<endl;
        cout<<endl;
        return out;
    }
};

class Comanda{
private:
    Client client;
    int nrProduse;
    Produs *produse;
    const int idComanda;
    static int contorComenzi;

public:
    Comanda():idComanda(contorComenzi++){
        Client client;
        this->client = client;
        this->nrProduse = 0;
        this->produse = NULL;
    }

    Comanda(Client client, int nrProduse, Produs* produse):idComanda(contorComenzi++){
        this->client = client;
        this->nrProduse = nrProduse;
        if(this->produse != NULL)
            delete[] this->produse;
        this->produse = new Produs[this->nrProduse];
        for(int i = 0; i < this->nrProduse; i++)
            this->produse[i]=produse[i];
    }

    Comanda(const Comanda& cmd):idComanda(cmd.idComanda){
        this->client = cmd.client;
        this->nrProduse = cmd.nrProduse;
        this->produse = new Produs[this->nrProduse];
        if(this->produse != NULL)
            delete[] this->produse;
        for(int i = 0; i < this->nrProduse; i++)
            this->produse[i] = cmd.produse[i];
    }

    ~Comanda(){
        if(this->produse != NULL)
            delete[] this->produse;
    }

    Comanda& operator=(const Comanda& cmd){
        this->client = cmd.client;
        this->nrProduse = cmd.nrProduse;
        this->produse = new Produs[this->nrProduse];
        if(this->produse != NULL)
            delete[] this->produse;
        for(int i = 0; i< this->nrProduse; i++)
            this->produse[i] = cmd.produse[i];
    }

    friend istream& operator>>(istream&in, Comanda& cmd){
        cin>>cmd.client;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Comanda& cmd){
        out<<"Comanda este data de:"<<endl<<cmd.client;
        out<<"Comanda are "<<cmd.nrProduse<<" produse"<<endl;
        out<<"Acestea sunt: "<<endl;
        for(int i = 0; i< cmd.nrProduse; i++){
            out<<cmd.produse[i];
           // cout<<endl;
        }
        //out<<endl;
        out<<"Comanda are id-ul "<<cmd.idComanda<<endl<<endl;
    }
};
int Comanda::contorComenzi=1000;
