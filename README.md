# Tartak

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

MAGAZYN

- Categories productCategories
- vector<Product> products
- show menu
- load data
- save data