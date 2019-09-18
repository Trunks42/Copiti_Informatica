#include <iostream>
using namespace std;

struct studente
{
	string nome;
	char sesso;
	int voto;
};

studente classe[100]; //globale

int controlloN(int x)
{
	int r;
	if (x > 0)
	{
		r = 1;
	}
	else
	{
		system("clear"); //system("cls");
		cout << "Numero non valido" << endl;
		r = 0;
	}
	return r;
}

int controlloSesso(char s)
{
	int r;
	if (s == 'M' || s == 'F')
	{
		r = 1;
	}
	else
	{
		system("clear"); //system("cls");
		cout << "Carattero errato, riprova." << endl;
		r = 0;
	}
	return r;
}

int controlloVoto(int s)
{
	int r;
	if (s >= 2 && s <= 10)
	{
		r = 1;
	}
	else
	{
		system("clear"); //system("cls");
		cout << "Voto errato, riprova." << endl;
		r = 0;
	}
	return r;
}

void caricaClasse(int nStudenti)
{
	for (int i = 0; i < nStudenti; i++)
	{
		cout << "Nome dello studente " << i + 1 << " : ";
		fflush(stdin);
		cin.ignore(1000, '\n');
		getline(cin, classe[i].nome);

		do
		{
			cout << "Sesso dello studente (M o F)" << i + 1 << " : ";
			cin >> classe[i].sesso;
		} while (controlloSesso(classe[i].sesso) == 0);

		do
		{
			cout << "voto dello studente " << i + 1 << " : ";
			cin >> classe[i].voto;
		} while (controlloVoto(classe[i].voto) == 0);
	}
}

int controlloMenu(int s, int max)
{
	int r;
	if (s <= max - 1 && s >= 0)
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
	for (int i = 0; i < nStudenti; i++)
	{
		cout << i << ". Nome --> " << classe[i].nome << endl;
		cout << "Sesso --> " << classe[i].sesso << endl;
		cout << "Voto --> " << classe[i].voto << endl
			 << endl;
	}
}

void mediaPerSesso(int nStudenti)
{
	int c = 0;
	float media = 0, somma = 0;
	char sesso;
	do
	{
		cout << "Sesso dello studente (M o F)"
			 << " : ";
		cin >> sesso;
	} while (controlloSesso(sesso) == 0);

	for (int i = 0; i < nStudenti; i++)
	{
		if (classe[i].sesso == sesso)
		{
			c++;
			somma += classe[i].voto;
		}
	}
	if (c > 0)
	{
		media = somma / c;
		cout << "La media e' " << media << endl;
		//system("pause"); cristo santo non tutti usana quella merda di windows
	}
	else
	{
		cout << "Non ci sono persone di quel sesso. " << endl;
	}
}

int menu()
{
	int s;
	system("clear"); //system("cls"); cristo santo non tutti usana quella merda di windows
	cout << "        Menu         " << endl;
	cout << "      0 - EXIT       " << endl;
	cout << "     1 - Stampa      " << endl;
	cout << " 2 - Media per sesso " << endl;
	cout << " 3 - Voto più alto   " << endl;
	cout << " 4 - Voto più alto F " << endl;
	cout << " 5 - Elenco insufficenti" << endl;
	cout << " 6 - Controllo insufficenti" << endl;
	cout << " 7 - Riordina        " << endl; 
	do
	{
		cin >> s;
	} while (controlloMenu(s, 8) == 0);
	return s;
}

studente checkMajor(int nStudenti)
{
	int voto = classe[0].voto;
	int J = 0;
	for (int i = 0; i < nStudenti; i++)
	{
		if (classe[i].voto > voto)
		{
			voto = classe[i].voto;
			J = i;
		}
	}
	return classe[J];
}

studente checkMajorF(int nStudenti)
{
	int voto = classe[0].voto;
	int J = 0;
	for (int i = 0; i < nStudenti; i++)
	{
		if (classe[i].voto > voto && classe[i].sesso == 'F')
		{
			voto = classe[i].voto;
			J = i;
		}
	}
	return classe[J];
}

void insufficenti(int nStudenti)
{
	for (int i; i < nStudenti; i++)
	{
		if (classe[i].voto < 6)
		{
			cout << classe[i].nome << "\t:\t" << classe[i].voto << endl;
		}
	}
}
bool checkMarker(int nStudenti)
{
	for (int i; i < nStudenti; i++)
	{
		if (classe[i].voto < 6)
		{
			return true;
		}
	}
	return false;
}

void riordina(int nStudenti){
	studente temp; 
	for (int i=0; i<nStudenti-1; i++){
		for(int j=1; j<nStudenti; j++){
			if (classe[i].voto < classe[j].voto){
				temp  = classe[i]; 
				classe[i] = classe[j];
				classe[j] = temp; 
			}
		}
	}
}

int main()
{
	int nStudenti;
	do
	{
		cout << "Inserisci il numero di studenti: ";
		cin >> nStudenti;
	} while (controlloN(nStudenti) == 0);

	classe[nStudenti];

	caricaClasse(nStudenti);

	switch (menu())
	{
	case 0:
	{
		cout << "Exit";
		break;
	}
	case 1:
	{
		StampaClasse(nStudenti);
		break;
	case 2:
		mediaPerSesso(nStudenti);
		break;
	}
	case 3:
	{
		system("clear");
		studente migliore = checkMajor(nStudenti);
		cout << "lo studente con il voto più alto e': " << migliore.nome << "con un voto di: " << migliore.voto << endl;
		break;
	}
	case 4:
	{
		system("clear");
		studente miglioreF = checkMajorF(nStudenti);
		cout << "la studentessa con il voto più alto e': " << miglioreF.nome << "con un voto di: " << miglioreF.voto << endl;
		break;
	}
	case 5:
	{
		system("clear");
		insufficenti(nStudenti);
		break;
	}
	case 6:
	{
		system("clear");
		if (checkMarker(nStudenti))
		{
			cout << "ci sono alunni insufficenti" << endl;
		}
		break;
	}
	case 7:
	{
		system("clear");
		//StampaClasse(nStudenti);
		cout << "riordino l'array" << endl << endl; 
		riordina(nStudenti);
		StampaClasse(nStudenti);
		break;
	}
	}
}
