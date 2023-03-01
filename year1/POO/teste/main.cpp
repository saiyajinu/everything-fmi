/*
    Vrinceanu Radu-Tudor 142
    GNU G++ (Compiler)
    Szmenteanca Eduard-Gabriel
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

const float pretBiletSuprafata = 2;
const float pretBiletMetrou = 2.5;
const float pretBiletTranzit = 3;

class Card {
protected:
    int ultimaValidare;
    static int contor;
    const int id;
public:
    Card(int = -1);
    virtual int getAvailableTickets() const = 0;
    virtual void write() const = 0;
    virtual ~Card() = default;
    int getId() const {
        return id;
    }
};
int Card::contor = 1000;
Card::Card(int ultimaValidare) : id(contor++), ultimaValidare(ultimaValidare) {};

class CardSuprafata : public Card {
protected:
    int bSuprafataTotale, bSuprafataNeutilizate;
public:
    CardSuprafata(int = 0, int = 0, int = -1);
    void write() const;
    int getAvailableTickets() const {
        return bSuprafataNeutilizate;
    }
    float getSum() const;
    bool getDiff() const {
        return (bSuprafataTotale - bSuprafataNeutilizate) % 8 == 0;
    }
    CardSuprafata& operator++();
    CardSuprafata& operator--();
};
CardSuprafata::CardSuprafata(int bSuprafataTotale, int bSuprafataNeutilizate, int ultimaValidare)
    : Card(ultimaValidare), bSuprafataNeutilizate(bSuprafataNeutilizate), bSuprafataTotale(bSuprafataTotale) {

}
void CardSuprafata::write() const {
    cout << "Tipul ultimului bilet folosit: suprfata, " <<
    (ultimaValidare == -1 ? "nu a fost validat" : to_string(ultimaValidare) + " minute in urma.")
    << " Suma biletelor neutilizate: " << this->getSum() << endl;
}
float CardSuprafata::getSum() const {
    return ::pretBiletSuprafata * bSuprafataNeutilizate;
}

CardSuprafata &CardSuprafata::operator++() {
    this->bSuprafataTotale++;
    this->bSuprafataNeutilizate++;
    return *this;
}
CardSuprafata &CardSuprafata::operator--() {
    this->bSuprafataNeutilizate--;
    return *this;
}

class CardMetrou : public Card {
protected:
    int bMetrouTotale, bMetrouNeutilizate;
public:
    CardMetrou(int = 0, int = 0, int = -1);
    void write() const;
    int getAvailableTickets() const {
        return bMetrouNeutilizate;
    }
    float getSum() const;
    bool getDiff() const {
        return (bMetrouTotale - bMetrouNeutilizate) % 8 == 0;
    }
    CardMetrou& operator++();
    CardMetrou& operator--();
};
CardMetrou::CardMetrou(int bMetrouTotale, int bMetrouNeutilizate, int ultimaValidare)
        : Card(ultimaValidare), bMetrouTotale(bMetrouTotale), bMetrouNeutilizate(bMetrouNeutilizate) {
}
void CardMetrou::write() const {
    cout << "Tipul ultimului bilet folosit: metrou, " <<
         (ultimaValidare == -1 ? "nu a fost validat" : to_string(ultimaValidare) + " minute in urma.")
         << " Suma biletelor neutilizate: " << this->getSum() << endl;
}
float CardMetrou::getSum() const {
    return ::pretBiletMetrou * bMetrouNeutilizate;
}

CardMetrou &CardMetrou::operator++() {
    this->bMetrouTotale++;
    this->bMetrouNeutilizate++;
    return *this;
}
CardMetrou &CardMetrou::operator--() {
    this->bMetrouNeutilizate--;
    return *this;
}

class CardTranzit : public Card {
private:
    string lastType;
    int bTranzitNeutilizate, bTranzitTotale, minute;
public:
    CardTranzit(int = 0, int = 0, int = -1);
    void setMinute(int minute) {
        this->minute = minute;
    }
    void setLastType(string lastType) {
        this->lastType = lastType;
    }
    bool getDiff() const {
        return (bTranzitTotale - bTranzitTotale) % 8 == 0;
    }
    int getAvailableTickets() const {
        return bTranzitTotale;
    }
    void write() const;
    float getSum() const;
    CardTranzit& operator++();
    CardTranzit& operator--();

};
CardTranzit::CardTranzit(int bTranzitTotale, int bTranzitNeutilizate, int ultimaValidare)
    : Card(ultimaValidare), bTranzitTotale(bTranzitTotale), bTranzitNeutilizate(bTranzitNeutilizate) {

}
void CardTranzit::write() const {
    cout << "Tipul ultimului bilet folosit: " << lastType << " " <<
         (ultimaValidare == -1 ? "nu a fost validat" : to_string(ultimaValidare) + " minute in urma.")
         << " Suma biletelor neutilizate: " << this->getSum() << ". Statusul biletului este: "
         << (minute == 0 ? "expirat" : "valabil " + to_string(minute)) << endl;
}
float CardTranzit::getSum() const {
    return ::pretBiletTranzit * (bTranzitNeutilizate);
}

CardTranzit &CardTranzit::operator++() {
    this->bTranzitTotale++;
    this->bTranzitNeutilizate++;
    return *this;
}

CardTranzit &CardTranzit::operator--() {
    this->minute = 90;
    this->bTranzitNeutilizate--;
    return *this;
}

class Validator {
private:
    static int contor;
    string tip;
    int validari;
    const int id;
public:
    Validator(string = "subteran", int = 0);
    int getId() const {
        return id;
    }
    string getTip() const {
        return tip;
    }
    friend istream& operator>>(istream& in, Validator& validator);
    friend ostream& operator<<(ostream& out, Validator& validator);
    Validator& operator+=(Card* card) {
        if (!card->getAvailableTickets())
            throw runtime_error("Nu sunt bilete disponibile.");

        if (dynamic_cast<CardMetrou*>(card)) {
            CardMetrou *cardMetrou = dynamic_cast<CardMetrou*>(card);
            --(*cardMetrou);

            if (cardMetrou->getDiff()) {
                ++(*cardMetrou);
            }
        } else if (dynamic_cast<CardTranzit*>(card)) {
            CardTranzit *cardTranzit = dynamic_cast<CardTranzit*>(card);
            --(*cardTranzit);

            if (cardTranzit->getDiff()) {
                ++(*cardTranzit);
            }
        } else if (dynamic_cast<CardSuprafata*>(card)) {
            CardSuprafata *cardSuprafata = dynamic_cast<CardSuprafata*>(card);
            --(*cardSuprafata);

            if (cardSuprafata->getDiff()) {
                ++(*cardSuprafata);
            }
        } else throw bad_cast();


        validari++;
        return *this;
    }
};
int Validator::contor = 1000;
Validator::Validator(string tip, int validari) : id(contor++), tip(tip), validari(validari){}
istream &operator>>(istream &in, Validator &validator) {
    validator.validari = 0;
    cout << "Introdu tipul de validator: "; in >> validator.tip;

    if (validator.tip != "suprafata" && validator.tip != "subteran")
        throw runtime_error("Nu exista alt tip de validator, decat suprafata si subteran.");
    return in;
}
ostream& operator<<(ostream& out, Validator& validator) {
    out << validator.id << " | " << validator.tip << " | " << validator.validari;
    return out;
}

list<Card*> lc;
list<Validator*> lv;

int main() {
    // inserare card
    try {
        int type;
        cout << "Introdu tipul de card pe care vrei sa il creezi: (0 - suprafata, 1 - metrou, 2 - tranzit): "; cin >> type;

        if (type < 0 || type > 2)
            throw runtime_error("Tipul de card nu este corect!\n");

        Card *card = nullptr;
        switch (type) {
            case 0: {
                card = new CardSuprafata();
                break;
            }
            case 1: {
                card = new CardMetrou();
                break;
            }
            case 2: {
                card = new CardTranzit();
                break;
            }
            default: {
                throw runtime_error("Tipul de card nu este corect!\n");
                break;
            }
        }

        if (card != nullptr) {
            lc.push_back(card);
        }
    } catch (runtime_error& error) {
        cout << error.what() << endl;
    }

    // inserare validator (functionala)
    try {
        Validator validator;
        cout << "Te rugam sa introduci un nou validator: " << endl;
        cin >> validator;
        lv.push_back(&validator);
    } catch (exception& error) {
        cout << error.what() << endl;
    }

    // adaugare bilet in card
    try {
        int id;
        cout << "Te rugam sa introduci un id de card pentru a adauga un bilet la card: "; cin >> id;

        auto it = find_if(lc.begin(), lc.end(), [id](Card *card) -> bool {
            return card->getId() == id;
        });

        if (it == lc.end())
            throw runtime_error("Nu exista cardul cu id-ul mentionat!");

        Card *card = *it;
        if (dynamic_cast<CardTranzit*>(card)) {
            ++(*dynamic_cast<CardTranzit*>(card));
        } else if (dynamic_cast<CardSuprafata*>(card)) {
            ++(*dynamic_cast<CardSuprafata*>(card));
        } else if (dynamic_cast<CardMetrou*>(card)) {
            ++(*dynamic_cast<CardMetrou*>(card));
        } else throw bad_cast();
    } catch (runtime_error& error) {
        cout << error.what() << endl;
    } catch (bad_cast& error) {
        cout << error.what() << endl;
    }

    try {
        int id, idCard;
        cout << "Te rugam sa introduci un id pentru a verifica un validator: "; cin >> id;
        cout << "Te rugam sa introduci un id de card: "; cin >> idCard;

        auto itValidator = find_if(lv.begin(), lv.end(), [id](Validator *validator) -> bool {
            return validator->getId() == id;
        });

        if (itValidator == lv.end())
            throw runtime_error("Nu exista validatorul cu id-ul mentionat!");

        auto itCard = find_if(lc.begin(), lc.end(), [id](Card *card) -> bool {
            return card->getId() == id;
        });

        if (itCard == lc.end())
            throw runtime_error("Nu exista cardul cu id-ul mentionat!");

        Validator *v = *itValidator;
        Card *c = *itCard;

        if (v->getTip() == "subteran" && dynamic_cast<CardSuprafata*>(c))
            throw runtime_error("Nu poti valida un card de suprafata intr-un validator subteran");

        if (v->getTip() == "suprafata" && dynamic_cast<CardMetrou*>(c))
            throw runtime_error("Nu poti valida un card de subteran intr-un validator de suprafata");

        *v += c;
    } catch (runtime_error& error) {
        cout << error.what() << endl;
    } catch (bad_cast& error) {
        cout << error.what() << endl;
    }

    // modificare minut curent pe un card;
    try {
        int id;
        cout << "Te rugam sa introduci un id de card pentru a modifica minutul curent: "; cin >> id;

        auto it = find_if(lc.begin(), lc.end(), [id](Card *card) -> bool {
            return card->getId() == id;
        });

        if (it == lc.end())
            throw runtime_error("Nu exista cardul cu id-ul mentionat!");

        Card *card = *it;
        if (!dynamic_cast<CardTranzit*>(card))
            throw bad_cast();

        int minutes;
        cout << "Introdu numarul de minute: "; cin >> minutes;

        if (minutes < 0 || minutes > 90)
            throw runtime_error("Numarul de minute este incorect (0 - 90)");

        dynamic_cast<CardTranzit*>(card)->setMinute(minutes);
    } catch (runtime_error& error) {
        cout << error.what() << endl;
    } catch (bad_cast& error) {
        cout << error.what() << endl;
    }

    try {
        int id;
        cout << "Te rugam sa introduci un id pentru a verifica starea unui card: "; cin >> id;

        auto it = find_if(lc.begin(), lc.end(), [id](Card *card) -> bool {
            return card->getId() == id;
        });

        if (it == lc.end())
            throw runtime_error("Nu exista cardul cu id-ul mentionat!");

        Card *card = *it;
        card->write();
    } catch (runtime_error& error) {
        cout << error.what() << endl;
    }

    try {
        int id;
        cout << "Te rugam sa introduci un id pentru a verifica un validator: "; cin >> id;

        auto it = find_if(lv.begin(), lv.end(), [id](Validator *validator) -> bool {
            return validator->getId() == id;
        });

        if (it == lv.end())
            throw runtime_error("Nu exista validatorul cu id-ul mentionat!");

        Validator *v = *it;
        cout << *v << endl;
    } catch (runtime_error& error) {
        cout << error.what() << endl;
    }
    return 0;
}
