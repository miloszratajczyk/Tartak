# Tartak

Projekt stworzony przez Miłosza Ratajczyka (numer indeksu: 272265)
jako zadanie zaliczeniowe z przedmiotu Podstawy programowania

### Informacje

**Program wymaga wersji języka co najmniej C++11!**

Program zajmuje się zarządaniem zasobami tartaku gdzie każdy z produktów zawiera informacje o nazwie produktu, kategorii
produktu kategorii drewna, kolorze, dacie dostawy, liczbie sztuk, cenie jednostkowej i cenie za metr. Program daje
możliwość manipulowania rekordami oraz zapisu i wczytania danych w pliku tekstowym imitując prostą baze danych.

Po uruchomienu programu należy podac scieżkę do pliku w którym program ma zapisywać dane (dany jest przykładowy plik o
nazwie data.txt).
Następnie program pozwala na:

1. Wyświetlenie wszystkich zasobów tartaku
2. Wyszukanie produktu według dowolnej frazy np. listwa
3. Dodanie produktu wypełniając każde z wyżej wymienionych pól produktu
4. Edycje jednego lub wielu pól wybranego produktu
5. Usunięcie wybranego produktu
6. Wyszukanie produktu przy użyciu wyrażeń regularnych np. (Buk|Sosna)

### Polecenie:

Zadanie polega na zaprojektowaniu oraz implementacji oprogramowania do zarządzania tartakiem. Każdy produkt
charakteryzowany jest następującym rekordem danych:

- nazwa – tablica znaków o maksymalnej długości 256 znaków
- kategoria – jeden z typów: listwa, łata, belka, deska itp.
- liczba sztuk – liczba naturalna; puste, jeżeli nie dotyczy
- cena jednostkowa – liczba zmiennoprzecinkowa; puste, jeżeli nie dotyczy
- cena za metr – liczba zmiennoprzecinkowa; puste, jeżeli nie dotyczy
- barwa – tablica znaków o maksymalnej długości 50 znaków
- rodzaj drewna – jeden z predefiniowanych rodzai drzew np. buk, lipa, sosna, dąb,
  heban itp.
- przewidywana data dostawy – data w przyjętym formacie; pusta, jeżeli nie dotyczy

program powinien umożliwiać wykonywanie następujących czynności:

- dodanie produktu
- usunięcie produktu
- zmianę danych produktu
- dodanie/zmianę daty dostawy
- wyszukanie/filtrowanie produktu po nazwie/kategorii
- *wyszukiwanie przy użyciu wyrażeń regularnych
- zapisanie zgromadzonej bazy danych na dysku w postaci pliku
- wczytanie zapisanej bazy danych ze wskazanego pliku
