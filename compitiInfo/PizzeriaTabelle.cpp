#include <iostream>
using namespace std;

struct pizza{
  string nome;
  string ingredienti;
  double prezzo;
};

pizza menuPizzeria[100];


void ordinamento(int nPizze){
  pizza tmp;
  for (int i = 0; i < nPizze-1; i++){
    for (int j = i+1; j < nPizze; j++){
      if(menuPizzeria[i].nome>menuPizzeria[j].nome){
        tmp=menuPizzeria[i];
        menuPizzeria[i]=menuPizzeria[j];
        menuPizzeria[j]=tmp;
      }
    }
    
  }
  

}

void caricaMenuPizzeria(int nPizze){
  for (int i = 0; i < nPizze; i++) {

    cout << "nome della pizza" << endl;
    cin.ignore();
    getline(cin, menuPizzeria[i].nome);

    cout << "ingredienti della pizza" << endl;
    cin.ignore();
    getline(cin, menuPizzeria[i].ingredienti);

    cout << "prezzo della pizza" << endl;
    cin >> menuPizzeria[i].prezzo;
  }
}

void stampaMenuPizzeria(int nPizze){
  for (int i = 0; i < nPizze; i++) {
    cout << "nome: " << menuPizzeria[i].nome << endl;
    cout << "ingredienti: "<< menuPizzeria[i].ingredienti << endl;
    cout << "prezzo: "<< menuPizzeria[i].prezzo << endl;
  }
}
void pizzePrezzoMinore(int nPizze){
  int prezzoMinore;
  cout << "Inserisci un prezzo: stampo tutte le pizze con il costo minore..." << endl;
  cin >> prezzoMinore;
  for (int i = 0; i < nPizze; i++) {
    if (menuPizzeria[i].prezzo < prezzoMinore) {
      cout << "nome: " << menuPizzeria[i].nome << endl;
      cout << "ingrdienti: "<< menuPizzeria[i].ingredienti << endl;
      cout << "prezzo: "<< menuPizzeria[i].prezzo << endl;
      cout << endl;
    }
  }
}

void prezzoMedioPizze(int nPizze) {
  double media=0;
  int somma=0, counter=0;
  for (int i = 0; i < nPizze; i++) {
    somma= somma + menuPizzeria[i].prezzo;
    counter= counter +1;
  }
media = somma / counter;
  cout << "la media del prezzo di tutte le pizze e: " << media << endl;
}

void cercaPizza(int nPizze){
  string nome;
  int c=0;
  cout << "Inserisci il nome della pizza di cui vuoi sapere le informazioni: " << endl;
  cin.ignore();
  getline(cin,nome);
  for (int i = 0; i < nPizze; i++) {
    if (menuPizzeria[i].nome == nome) {
      c=1;
      cout << "nome: " << menuPizzeria[i].nome << endl;
      cout << "ingrdienti: "<< menuPizzeria[i].ingredienti << endl;
      cout << "prezzo: "<< menuPizzeria[i].prezzo << endl;
    }
  }
  if (c==0) {
    cout << "nessuna pizza corrispondente al nome inserito";
  }
}

void pizzaCostoAlto(int nPizze){
  string nomePizza, ingredientiPizza;
  double temp=0, prezzoPizza;


  for (int i = 0; i < nPizze; i++) {
    if (temp < menuPizzeria[i].prezzo) {
      prezzoPizza= menuPizzeria[i].prezzo;
      nomePizza= menuPizzeria[i].nome;
      ingredientiPizza = menuPizzeria[i].ingredienti;
    }
  }
  cout << "i dati della pizza piu costosa sono: "<<endl;
  cout << "nome: " << nomePizza << endl;
  cout << "ingrdienti: "<< ingredientiPizza << endl;
  cout << "prezzo: "<< prezzoPizza << endl;
}


int controlloMenu(int s, int max)
{
  int r;
  if(s <= max-1 && s >= 0)
  {
    r = 1;
  }
  else
  {
    r = 0;
  }
  return r;
}

int menu()
{
  int s;
  cout <<"                    Menu                   " <<endl;
  cout <<"                  0 - EXIT                 " <<endl;
  cout <<"                 1 - Stampa                " <<endl;
  cout <<"              2 - Prezzo Minore            " <<endl;
  cout <<"               3 - prezzo Medio            " <<endl;
  cout <<"               4 - Cerca Pizza             " <<endl;
  cout <<"              5 - dati pizza alto          " <<endl;
  cout <<"              6 - Ordinamento menu         " <<endl;

  do
  {
    cin >>s;
  }while(controlloMenu(s, 7) == 0);
  return s;
}

int main() {
  int nPizze;
  cout << "Quante pizze ci sono nel menu? " << endl;
  cin >> nPizze;
  menuPizzeria[nPizze];
  caricaMenuPizzeria(nPizze);

  int scelta = 0;
  do {
    switch (scelta = menu())
    {
      case 0:
        cout <<"Exit";
        break;
      case 1:
        stampaMenuPizzeria(nPizze);
        break;
      case 2:
        pizzePrezzoMinore(nPizze);
        break;
      case 3:
        prezzoMedioPizze(nPizze);
        break;
      case 4:
        cercaPizza(nPizze);
        break;
      case 5:
        pizzaCostoAlto(nPizze);
        break;
      case 6:
        if(nPizze>1){
          ordinamento(nPizze);
        }else{
          cout << "Menu ordinato." << endl;
        }
        break;

    }
  } while (scelta);



  return 0;
}
