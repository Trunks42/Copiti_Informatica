#include <iostream>
using namespace std;

struct studente
{
	string nome;
	char sesso;
	int voto;
};

int controlloN(int x)
{
	int r;
	if (x > 0)
	{
		r = 1;
	}
	else
	{
		system("cls");
		cout <<"Numero non valido" <<endl;
		r = 0;
	}
	return r;
}

studente classe[100]; //globale

int controlloSesso(char s)
{
	int r;
	if(s == 'M' || s == 'F')
	{
		r = 1;
	}
	else
	{
		system("cls");
		cout <<"Carattero errato, riprova." <<endl;
		r = 0;
	}
	return r;
}

int controlloVoto(int s)
{
	int r;
	if(s >= 2 && s <= 10)
	{
		r = 1;
	}
	else
	{
		system("cls");
		cout <<"Voto errato, riprova." <<endl;
		r = 0;
	}
	return r;
}

void caricaClasse(int nStudenti)
{
	for(int i = 0; i < nStudenti; i++)
	{
		cout <<"Nome dello studente " <<i+1 <<" : ";
		fflush(stdin);
		getline(cin, classe[i].nome);
		
		do
		{
			cout <<"Sesso dello studente (M o F)" <<i+1 <<" : ";
			cin >> classe[i].sesso;
		}while(controlloSesso(classe[i].sesso) == 0);
		
		do
		{
		cout <<"voto dello studente " <<i+1 <<" : ";
		cin >> classe[i].voto;
		}while(controlloVoto(classe[i].voto) == 0);
		
	}
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

void StampaClasse(int nStudenti)
{
	for(int i = 0; i < nStudenti; i++)
	{
		cout  <<i <<". Nome --> " <<classe[i].nome <<endl;
		cout <<"Sesso --> " <<classe[i].sesso <<endl;
		cout <<"Voto --> " <<classe[i].voto <<endl <<endl;
	}
}

void mediaPerSesso(int nStudenti)
{
	int c = 0;
	float media = 0, somma = 0;
	char sesso;
	do
	{
		cout <<"Sesso dello studente (M o F)" <<" : ";
		cin >> sesso;
	}while(controlloSesso(sesso) == 0);
	
	for(int i = 0; i < nStudenti; i++)
	{
		if (classe[i].sesso == sesso)
		{
			c++;
			somma += classe[i].voto;
		}
	}
	if (c > 0)
	{
		media = somma/c;
		cout <<"La media e' " <<media <<endl;
		system("pause"); 
	}
	else
	{
		cout <<"Non ci sono persone di quel sesso. " <<endl;
	}
}

int menu()
{
	int s;
	system("cls");
	cout <<"        Menu         " <<endl;
	cout <<"      0 - EXIT       " <<endl;
	cout <<"     1 - Stampa      " <<endl;
	cout <<" 2 - Media per sesso " <<endl;
	do
	{
		cin >>s;
	}while(controlloMenu(s, 3) == 0);
	return s;
}

int main()
{
	int nStudenti;
	do
	{
		cout <<"Inserisci il numero di studenti: ";
		cin >> nStudenti;
	} while(controlloN(nStudenti) == 0);
	
	classe[nStudenti];
	
	caricaClasse(nStudenti);
	
	switch (menu())
	{
		case 0:
			cout <<"Exit";
			break;
		case 1:
			StampaClasse(nStudenti);
			break;
		case 2:
			mediaPerSesso(nStudenti);
			break;
	} 
}
