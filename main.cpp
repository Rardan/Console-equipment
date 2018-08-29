#include <iostream>
#include "Sword.h"
#include "Bow.h"
#include "Shield.h"
#include "Storage.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;



void dodaj_przedmiot(Sword *&s, Bow *&b, Shield *&sh, int &sword_count, int &bow_count, int &shield_count, Storage *backpack);
//funkcja dodaj¹ca nowe obiekty do tablic obiektów

void wyswietl_plecak(const Sword *s, const Bow *b, const Shield *sh, int sword_count, int bow_count, int shield_count);
//funkcja wyœwietlaj¹ca zawartoœæ plecaka

void wyswietl_skrzynie(const Sword *s_chest, const Bow *b_chest, const Shield *sh_chest, int sword_chest, int bow_chest, int shield_chest);
//funkcja wyœwietlaj¹ca zawartoœæ skrzyni
void usun_przedmiot(Sword *&s, Bow *&b, Shield *&sh, int &sword_count, int &bow_count, int &shield_count, Storage *backpack);
//funkcja usuwaj¹ca przedmiot z plecaka

void przenies_z(Sword *&s, Bow *&b, Shield *&sh, int &sword_count, int &bow_count, int &shield_count,
	Sword *&s_chest, Bow *&b_chest, Shield *&sh_chest, int &sword_chest, int &bow_chest, int &shield_chest, Storage *backpack, Storage *chest);
//funkcja przenosz¹ca przedmioty z plecaka do skrzyni

void przenies_do(Sword *&s, Bow *&b, Shield *&sh, int &sword_count, int &bow_count, int &shield_count,
	Sword *&s_chest, Bow *&b_chest, Shield *&sh_chest, int &sword_chest, int &bow_chest, int &shield_chest, Storage *backpack, Storage *chest);
//funkcja przenosz¹ca przedmioty ze skrzyni do plecaka

void zapisz(Sword s[], Bow b[], Shield sh[], int &sword_count, int &bow_count, int &shield_count,
	Sword s_chest[], Bow b_chest[], Shield sh_chest[], int &sword_chest, int &bow_chest, int &shield_chest, Storage *backpack, Storage *chest);
//funkcja zapisuj¹ca zawartoœæ plecaka i skrzyni do dwóch osobnych plików tekstowych.
//po przez pys³anie id przedmiotu

void wczytaj(Sword *&s, Bow *&b, Shield *&sh, int &sword_count, int &bow_count, int &shield_count,
	Sword *&s_chest, Bow *&b_chest, Shield *&sh_chest, int &sword_chest, int &bow_chest, int &shield_chest, Storage *backpack, Storage *chest);
//funkcja wczytuj¹ca zawartoœæ plecaka i skrzyni z plików tekstowych

Storage chest("skrzynia", 20), backpack("plecak", 20);

Sword s1("Miecz", 101, 100, 10, 100, 100);
Bow b1("Luk", 201, 100, 5, 100, 50, 100);
Shield sh1("Tarcza", 301,  100, 10, 100, 40);

int main()
{
	Sword *s = 0, *s_chest = 0;
	Bow *b = 0, *b_chest = 0;
	Shield *sh = 0, *sh_chest = 0;

	int sword_count = 0, bow_count = 0, shield_count = 0;
	int sword_chest = 0, bow_chest = 0, shield_chest = 0;
	
	int n;
	while (1)
	{
		backpack.check_full();
		chest.check_full();

		cout << "-----------------------" << endl;
		cout << "Menu" << endl;
		cout << "-----------------------" << endl;
		cout << "1. Dodaj przedmiot" << endl;
		cout << "2. Usun przedmiot" << endl;
		cout << "3. Wyswietl przedmioty" << endl;
		cout << "4. Przenies z plecaka" << endl;
		cout << "5. Przenies do plecaka" << endl;
		cout << "6. Zapisz przedmioty do pliku" << endl;
		cout << "7. Wczytaj przedmioty z pliku" << endl;
		cout << "wybor: "; cin >> n;
		
		switch (n)
		{
		case 1: dodaj_przedmiot(s, b, sh, sword_count, bow_count, shield_count, &backpack);
			break;
		case 2: usun_przedmiot(s, b, sh, sword_count, bow_count, shield_count, &backpack);
			break;
		case 3: wyswietl_plecak(s, b, sh, sword_count, bow_count, shield_count);
			cout << endl;
			wyswietl_skrzynie(s_chest, b_chest, sh_chest, sword_chest, bow_chest, shield_chest);
			break;
		case 4: przenies_z(s, b, sh, sword_count, bow_count, shield_count, s_chest, b_chest, sh_chest, sword_chest, bow_chest, shield_chest, &backpack, &chest);
			break;
		case 5: przenies_do(s, b, sh, sword_count, bow_count, shield_count, s_chest, b_chest, sh_chest, sword_chest, bow_chest, shield_chest, &backpack, &chest);
			break;
		case 6: zapisz(s, b, sh, sword_count, bow_count, shield_count, s_chest, b_chest, sh_chest, sword_chest, bow_chest, shield_chest, &backpack, &chest);
			break;
		case 7: wczytaj(s, b, sh, sword_count, bow_count, shield_count, s_chest, b_chest, sh_chest, sword_chest, bow_chest, shield_chest, &backpack, &chest);
			break;
		default: system("cls");
			cout << "Blad" << endl;
		}
	}
	return 0;
}

void dodaj_przedmiot(Sword *&s, Bow *&b, Shield *&sh, int &sword_count, int &bow_count, int &shield_count, Storage *backpack)
{
//	Sword s1("Miecz", 101, true, 100, 10, 100, 100);
//	Bow b1("Luk", 201, true, 100, 5, 100, 50, 100);
//	Shield sh1("Tarcza", 301, true, 100, 10, 100, 40);
	if (backpack->getFull() == true) cout << "Plecak pelen!";
	else
	{
		system("cls");
		int m;
		cout << "Jaki?: " << endl;
		cout << "1. Miecz" << endl;
		cout << "2. Luk" << endl;
		cout << "3. Tarcza" << endl;
		cout << "Wybor: "; cin >> m;
		Sword *ss = 0;
		Bow *bb = 0;
		Shield *shh = 0;
		switch (m)
		{
		case 1:
			ss = new Sword[sword_count + 1];
			for (int i = 0; i < sword_count; i++)
				ss[i] = s[i];

			ss[sword_count] = s1;
			sword_count++;
			backpack->increase_curr();
			delete[]s;
			s = 0;
			s = ss;
			system("cls");
			cout << "Dodano!" << endl;
		
			break;

		case 2:		
			bb = new Bow[bow_count + 1];
			for (int i = 0; i < bow_count; i++)
				bb[i] = b[i];

			bb[bow_count] = b1;
			bow_count++;
			backpack->increase_curr();
			delete[]b;
			b = 0;
			b = bb;
			system("cls");
			cout << "Dodano!" << endl;
		
			break;
		case 3:
			shh = new Shield[shield_count + 1];
			for (int i = 0; i < shield_count; i++)
				shh[i] = sh[i];

			shh[shield_count] = sh1;
			delete[]sh;
			sh = 0;
			sh = shh;
			shield_count++;
			backpack->increase_curr();
			system("cls");
			cout << "dodano!" << endl;
		
			break;
		default: system("cls");
			cout << "blad!";
		}
	}
}

void wyswietl_plecak(const Sword *s, const Bow *b, const Shield *sh, int sword_count, int bow_count, int shield_count)
{
	system("cls");
	if (sword_count == 0 && bow_count == 0 && shield_count == 0) cout << "Plecak pusty\n";
	else
	{
		cout << "Plecak" << endl;
		cout << "---------------------" << endl;
		int j = 1;
		cout << fixed;
		if(sword_count != 0) cout << setw(4) << "lp." << setw(10) << "nazwa" << setw(6) << "cena" << setw(6) << "waga" << setw(16) << "wytrzymalosc" << setw(9) << "dmg" << endl;
		for (int i = 0; i < sword_count; i++, j++)
		{
			cout << setw(3) << j << ". ";
			cout << s[i] << endl;
		}
		if (bow_count != 0) cout << setw(4) << "lp." << setw(10) << "nazwa" << setw(6) << "cena" << setw(6) << "waga" << setw(16) << "wytrzymalosc" << setw(9) << "min dmg" << " - " << setw(9) << "max dmg" << endl;
		for (int i = 0; i < bow_count; i++, j++)
		{
			cout << setw(3) << j << ". ";
			cout << b[i] << endl;
		}
		if (shield_count != 0) cout << setw(4) << "lp." << setw(10) << "nazwa" << setw(6) << "cena" << setw(6) << "waga" << setw(16) << "wytrzymalosc" << setw(9) << "def" << endl;
		for (int i = 0; i < shield_count; i++, j++)
		{
			cout << setw(3) << j << ". ";
			cout << sh[i] << endl;
		}
	}
}

void wyswietl_skrzynie(const Sword *s_chest, const Bow *b_chest, const Shield *sh_chest, int sword_chest, int bow_chest, int shield_chest)
{
	if (sword_chest == 0 && bow_chest == 0 && shield_chest == 0) cout << "Skrzynia pusta\n";
	else
	{
		cout << endl << "Skrzynia" << endl;
		cout << "---------------------" << endl;
		int j = 1;
		cout << fixed;
		if (sword_chest != 0) cout << setw(4) << "lp." << setw(10) << "nazwa" << setw(6) << "cena" << setw(6) << "waga" << setw(16) << "wytrzymalosc" << setw(9) << "dmg" << endl;
		for (int i = 0; i < sword_chest; i++, j++)
		{
			cout << setw(3) << j << ". ";
			cout << s_chest[i] << endl;
		}
		if (bow_chest != 0) cout << setw(4) << "lp." << setw(10) << "nazwa" << setw(6) << "cena" << setw(6) << "waga" << setw(16) << "wytrzymalosc" << setw(9) << "min dmg" << " - " << setw(9) << "max dmg" << endl;
		for (int i = 0; i < bow_chest; i++, j++)
		{
			cout << setw(3) << j << ". ";
			cout << b_chest[i] << endl;
		}
		if (shield_chest != 0) cout << setw(4) << "lp." << setw(10) << "nazwa" << setw(6) << "cena" << setw(6) << "waga" << setw(16) << "wytrzymalosc" << setw(9) << "def" << endl;
		for (int i = 0; i < shield_chest; i++, j++)
		{
			cout << setw(3) << j << ". ";
			cout << sh_chest[i] << endl;
		}
	}
}

void usun_przedmiot(Sword *&s, Bow *&b, Shield *&sh, int &sword_count, int &bow_count, int &shield_count, Storage *backpack)
{
	int g;
	wyswietl_plecak(s, b, sh, sword_count, bow_count, shield_count);
	cout << "Ktory: "; cin >> g;
	if (g <= 0 || g > sword_count + shield_count + bow_count)
	{
		system("cls");
		cout << "Blad!" << endl;
	}
	else if (g <= sword_count)
	{
		Sword *ss = new Sword[sword_count -1];

		for (int i = 0; i < g - 1; i++)
			ss[i] = s[i];

		for (int i = g; i < sword_count; i++)
			ss[i-1] = s[i];

		delete[]s;
		s = 0;
		s = ss;
		
		sword_count--;
		backpack->decrease_curr();
		system("cls");
		cout << "usunieto!" << endl;
	}
	else if (g > sword_count && g <= bow_count + sword_count)
	{
		Bow *bb = new Bow[bow_count - 1];

		for (int i = 0; i < g - 1 - sword_count; i++)
			bb[i] = b[i];

		for (int i = g - sword_count; i < bow_count; i++)
			bb[i-1] = b[i];

		delete[]b;
		b = 0;
		b = bb;
		bow_count--;
		backpack->decrease_curr();
		system("cls");
		cout << "usunieto!" << endl;
	}
	else if (g > bow_count + sword_count && g <= sword_count + bow_count + shield_count)
	{
		Shield *shh = new Shield[shield_count - 1];

		for (int i = 0; i < g - 1 - sword_count - bow_count; i++)
			shh[i] = sh[i];

		for (int i = g - sword_count - bow_count; i < shield_count; i++)
			shh[i-1] = sh[i];

		delete[]sh;
		sh = 0;
		sh = shh;
		shield_count--;
		backpack->decrease_curr();
		system("cls");
		cout << "usunieto!" << endl;
	}
	else
	{
		system("cls");
		cout << "Podano bledna wartosc!" << endl;
	}
}

void przenies_z(Sword *&s, Bow *&b, Shield *&sh, int &sword_count, int &bow_count, int &shield_count,
	Sword *&s_chest, Bow *&b_chest, Shield *&sh_chest, int &sword_chest, int &bow_chest, int &shield_chest, Storage *backpack, Storage *chest)
{
	if (chest->getFull() == true)
	{
		system("cls");
		cout << "Skrzynia pelna!";
	}
	else
	{
		system("cls");
		int g;
		wyswietl_plecak(s, b, sh, sword_count, bow_count, shield_count);
		cout << "Ktory: "; cin >> g;

		if (g <= sword_count)
		{
			Sword *ss = new Sword[sword_count - 1];
			Sword *sss = new Sword[sword_chest + 1];

			for (int i = 0; i < sword_chest; i++)
				sss[i] = s_chest[i];

			for (int i = 0; i < g - 1; i++)
				ss[i] = s[i];

			sss[sword_chest] = s[g-1];

			for (int i = g-1; i < sword_count-1; i++)
				ss[i] = s[i+1];

			delete[]s_chest;
			delete[]s;
			s_chest = 0;
			s = 0;
			s_chest = sss;
			s = ss;
			
			sword_count--;
			backpack->decrease_curr();
			sword_chest++;
			chest->increase_curr();
			system("cls");
			cout << "przeniesiono!" << endl;

		}
		else if (g > sword_count && g <= bow_count + sword_count)
		{
			Bow *bb = new Bow[bow_count - 1];
			Bow *bbb = new Bow[bow_chest + 1];

			for (int i = 0; i < bow_chest; i++)
				bbb[i] = b_chest[i];

			for (int i = 0; i < g - 1 - sword_count; i++)
				bb[i] = b[i];

			bbb[bow_chest] = b[g - 1 - sword_count];

			for (int i = g - sword_count - 1; i < bow_count - 1; i++)
				bb[i] = b[i+1];

			delete[]b_chest;
			delete[]b;
			b_chest = 0;
			b = 0;
			b_chest = bbb;
			b = bb;

			
			bow_count--;
			backpack->decrease_curr();
			bow_chest++;
			chest->increase_curr();
			system("cls");
			cout << "przeniesiono!" << endl;
		}
		else if (g > bow_count + sword_count && g <= sword_count + bow_count + shield_count)
		{
			Shield *shh = new Shield[shield_count - 1];
			Shield *shhh = new Shield[shield_chest + 1];

			for (int i = 0; i < shield_chest; i++)
				shhh[i] = sh_chest[i];

			for (int i = 0; i < g - 1 - sword_count - bow_count; i++)
				shh[i] = sh[i];

			shhh[shield_chest] = sh[g - 1 - sword_count - bow_count];

			for (int i = g - sword_count - bow_count - 1; i < shield_count - 1; i++)
				shh[i] = sh[i+1];

			delete[]sh_chest;
			delete[]sh;
			sh_chest = 0;
			sh = 0;
			sh_chest = shhh;
			sh = shh;

			shield_count--;
			backpack->decrease_curr();
			shield_chest++;
			chest->increase_curr();
			system("cls");
			cout << "przeniesiono!" << endl;
		}
		else
		{
			system("cls");
			cout << "Podano bledna wartosc!" << endl;
		}
	}
}

void przenies_do(Sword *&s, Bow *&b, Shield *&sh, int &sword_count, int &bow_count, int &shield_count,
	Sword *&s_chest, Bow *&b_chest, Shield *&sh_chest, int &sword_chest, int &bow_chest, int &shield_chest, Storage *backpack, Storage *chest)
{
	if (backpack->getFull() == true)
	{
		system("cls");
		cout << "Plecak pelny!";
	}
	else
	{
		system("cls");
		int g;
		wyswietl_skrzynie(s_chest, b_chest, sh_chest, sword_chest, bow_chest, shield_chest);
		cout << "Ktory: "; cin >> g;

		if (g <= sword_chest)
		{
			Sword *sss = new Sword[sword_chest - 1];
			Sword *ss = new Sword[sword_count + 1];
			
			for (int i = 0; i < sword_count; i++)
				ss[i] = s[i];

			for (int i = 0; i < g - 1; i++)
				sss[i] = s_chest[i];

			ss[sword_count] = s[g - 1];

			for (int i = g - 1; i < sword_chest - 1; i++)
				sss[i] = s_chest[i+1];

			delete[]s_chest;
			delete[]s;
			s_chest = 0;
			s = 0;
			s_chest = sss;
			s = ss;
			
			sword_count++;
			backpack->increase_curr();
			sword_chest--;
			chest->decrease_curr();
			system("cls");
			cout << "przeniesiono!" << endl;

		}
		else if (g > sword_chest && g <= bow_chest + sword_chest)
		{
			Bow *bbb = new Bow[bow_chest - 1];
			Bow *bb = new Bow[bow_count + 1];

			for (int i = 0; i < bow_count; i++)
				bb[i] = b[i];

			for (int i = 0; i < g - 1 - sword_chest; i++)
				bbb[i] = b_chest[i];

			bb[bow_count] = b_chest[g - 1 - sword_chest];

			for (int i = g - sword_chest - 1; i < bow_chest - 1; i++)
				bbb[i] = b_chest[i+1];

			delete[]b_chest;
			delete[]b;
			b_chest = 0;
			b = 0;
			b_chest = bbb;
			b = bb;

			bow_count++;
			backpack->increase_curr();
			bow_chest--;
			chest->decrease_curr();
			system("cls");
			cout << "przeniesiono!" << endl;
		}
		else if (g > bow_chest + sword_chest && g <= sword_chest + bow_chest + shield_chest)
		{
			Shield *shhh = new Shield[shield_chest - 1];
			Shield *shh = new Shield[shield_count + 1];

			for (int i = 0; i < shield_chest; i++)
				shh[i] = sh[i];

			for (int i = 0; i < g - 1 - sword_chest - bow_chest; i++)
				shhh[i] = sh_chest[i];

			shh[shield_count] = sh[g - 1 - sword_chest - bow_chest];

			for (int i = g - sword_chest - bow_chest - 1; i < shield_chest-1; i++)
				shhh[i] = sh_chest[i+1];

			delete[]sh_chest;
			delete[]sh;
			sh_chest = 0;
			sh = 0;
			sh_chest = shhh;
			sh = shh;

			shield_count++;
			backpack->increase_curr();
			shield_chest--;
			chest->decrease_curr();
			system("cls");
			cout << "przeniesiono!" << endl;
		}
		else
		{
			system("cls");
			cout << "Podano bledna wartosc!" << endl;
		}
	}
}

void zapisz(Sword s[], Bow b[], Shield sh[], int &sword_count, int &bow_count, int &shield_count,
	Sword s_chest[], Bow b_chest[], Shield sh_chest[], int &sword_chest, int &bow_chest, int &shield_chest, Storage *backpack, Storage *chest)
{
	system("cls");
	fstream plik;
	plik.open("plecak.txt", ios::out);
	if (plik.good() == true)
	{
		plik << sword_count << endl;
		plik << bow_count << endl;
		plik << shield_count << endl;

		if (sword_count != 0)
		for (int i = 0; i < sword_count; i++)
			plik << s[i].getID() << endl;

		if (bow_count != 0)
		for (int i = 0; i < bow_count; i++)
			plik << b[i].getID() << endl;
		
		if (shield_count != 0)
		for (int i = 0; i < shield_count; i++)
			plik << sh[i].getID() << endl;
		
		cout << "Zapisano plecak!" << endl;
	}
	plik.close();

	plik.open("skrzynia.txt", ios::out);
	if (plik.good() == true)
	{
		plik << sword_chest << endl;
		plik << bow_chest << endl;
		plik << shield_chest << endl;

		if (sword_chest != 0)
		for (int i = 0; i < sword_chest; i++)
			plik << s_chest[i].getID() << endl;

		if (bow_chest != 0)
		for (int i = 0; i < bow_chest; i++)
			plik << b_chest[i].getID() << endl;

		if (shield_chest != 0)
		for (int i = 0; i < shield_chest; i++)
			plik << sh_chest[i].getID() << endl;
		cout << "Zapisano skrzynie!" << endl;
	}
}

void wczytaj(Sword *&s, Bow *&b, Shield *&sh, int &sword_count, int &bow_count, int &shield_count,
	Sword *&s_chest, Bow *&b_chest, Shield *&sh_chest, int &sword_chest, int &bow_chest, int &shield_chest, Storage *backpack, Storage *chest)
{
	int local_sword = 0, local_bow = 0, local_shield = 0;
	Sword *ss = 0;
	Bow *bb = 0;
	Shield *shh = 0;
	fstream plik;
	string linia;
	int licz=0;
	plik.open("plecak.txt", ios::in);
	if (plik.good() == true)
	{
		while (!plik.eof())
		{
			getline(cin, linia);
			if (licz == 0)
			{
				sword_count = atoi(linia.c_str());
				ss = new Sword[sword_count];
			}
			else if (licz == 1)
			{
				bow_count = atoi(linia.c_str());
				bb = new Bow[bow_count];
			}
			else if (licz == 2)
			{
				bow_count = atoi(linia.c_str());
				shh = new Shield[shield_count];
			}
			else
			{
				if (linia != "\0")
				{
					if (atoi(linia.c_str()) == 101)
					{
						 ss[local_sword] = s1;
						 local_sword++;
					}
					else if (atoi(linia.c_str()) == 201)
					{
						 bb[local_bow] = b1;
						 local_bow++;
					}
					else if (atoi(linia.c_str()) == 301)
					{
						shh[local_shield] = sh1;
						local_shield++;
					}
				}
			}
			licz++;
		}
		delete[]s;
		delete[]b;
		delete[]sh;
		s = 0;
		b = 0;
		sh = 0;
		s = ss;
		b = bb;
		sh = shh;
		
		cout << "Wczytano plecak!" << endl;
	}
	plik.close();
	licz = 0;
	local_sword = 0;
	local_bow = 0;
	local_shield = 0;
	plik.open("skrzynia.txt", ios::in);
	if (plik.good() == true)
	{
		while (!plik.eof())
		{
			getline(cin, linia);
			if (licz == 0)
			{
				sword_chest = atoi(linia.c_str());
				ss = new Sword[sword_chest];
			}
			else if (licz == 1)
			{
				bow_chest = atoi(linia.c_str());
				bb = new Bow[bow_chest];
			}
			else if (licz == 2)
			{
				shield_chest = atoi(linia.c_str());
				shh = new Shield[shield_chest];
			}
			else
			{
				if (linia != "\0")
				{
					if (atoi(linia.c_str()) == 101)
					{
						ss[local_sword] = s1;
						local_sword++;
					}
					else if (atoi(linia.c_str()) == 201)
					{
						bb[local_bow] = b1;
						local_bow++;
					}
					else if (atoi(linia.c_str()) == 301)
					{
						shh[local_shield] = sh1;
						local_shield++;
					}
				}
			}
			licz++;
		}
		delete[]s_chest;
		delete[]b_chest;
		delete[]sh_chest;
		s_chest = 0;
		b_chest = 0;
		sh_chest = 0;
		s_chest = ss;
		b_chest = bb;
		sh_chest = shh;
		system("cls");
		cout << "Wczytano skrzynie!" << endl;
	}
	plik.close();
}
