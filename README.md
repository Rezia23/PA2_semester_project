
# Maticová kalkulačka

Autor: Terezie Hrubanová

## Téma z Progtestu

Vytvořte aplikaci implementující maticovou kalkulačku.

Kalkulačka musí implementovat:
1.  práci s maticemi různé velikosti
2.  základní operace: sčítání, odčítání, násobení, transpozice
3.  sloučení (3x3 sloučeno s 3x3 => matice 6x3) a oříznutí (např. pouze levá polovina matice 6x3 => levá 3x3)
4.  pro čtvertcové matice navíc výpočet inverze
5.  efektivní paměťovou reprezentaci (pro řídké matice se nehodí 2D pole, pro husté matice naopak)
6.  funkce pro výpočet determinantu, určení hodnosti, Gaussova eliminační metoda
7.  proměnné (uložení matice do proměnné, načítání matice ze vstupu, využití proměnné ve výpočtu)


Použití polymorfismu (doporučeně)

-   typ matice: proměnná, řídká (mapa, list) vs. hustá (2D pole)
-   operace: sčítání, odčítání, násobení, ...
-   varianta GEMu: klasická, s komentářem

Ukázka běhu programu (není závazná):

	SCAN X[3][3]
	Y[3][3] = 1 // jednotkova matice
	Z = MERGE X Y
	GEM Z -v // s detaily
	X = SPLIT Z [3][3] (3, 0) // z matice Z, chci jen 3x3 od pozice (3, 0)
	PRINT X

## Zadání

Uživatel může pomocí jednoduchých příkazů načíst matice do proměnných a provádět na nich operace dle zadání. Slovo příkazu je následováno dvojtečkou, a pak jmény proměnných případně jinými parametry, s kterými počítá, příkaz je zakončen mezerou a středníkem.

- `load:pepa 2 2|1 2 3 4 ;` vytvoří novou matici 2x2, po řádcích načte její obsah a 				uloží ji do proměnné "pepa"
- `print:pepa ;` vypíše obsah proměnné "pepa"
- `add:pepa franta ;` sečte existující proměnné "pepa" a "franta" a vypíše součet
- `subtract:pepa franta ;` totéž co add, ale odečítá
- `multiply:pepa franta ;` totéž co subtract, ale násobí matice (v pořadí v jakém byly zadány)
- `transpose:lojza ;` transponuje matici uloženou v proměnné "lojza"
- `cut:franta 1 1|0 1 ;` ořízne matici v proměnné "franta" na velikost 1x1 od pozice [0][1]
- `put:henry command:variable variable ; ` do proměnné "henry" uloží výsledek vnořeného příkazu
- `help ;` zobrazí nápovědu
- `exit ;` ukončí program
- další příkazy podle zadání (inverze, hodnost, determinant atd.)

Běh programu může vypadat třeba takto (vstup od uživatele označen $):

```
$load:moric 2 2|0 0 0 1 ;
Matrix moric successfully loaded.
0.000000 0.000000
0.000000 1.000000
$load:kilian 2 2|0 0 0 0 ;**
Matrix kilian successfully loaded.
0.000000 0.000000
0.000000 0.000000
$multiply:moric kilian ;**
Result of multiplication is:
0.000000 0.000000
0.000000 0.000000
```

O běh programu se stará `CApplication`, o věci specifické pro konzolovou aplikaci (parsování vstupu) pak její potomek `CConsoleApplication`. Příkazy jsou reprezentovány potomky abstraktní třídy `CCommand` (`CCommandAdd`, `CCommandLoad`, ...).
Matice reprezentuji dvojím způsobem, podle toho, zda jsou řídké (mapa) nebo husté (2D vector). Jsou to třídy `CMatrixSparse` a `CMatrixStandard` se společným abstraktním předkem `CMatrix`.

### Kde mám polymorfismus?

Polymorfismus využívám u matic a operací s nimi. `CMatrixSparse` a `CMatrixStandard` mají různě implementované metody na sčítání, odčítání atd., v aplikaci tedy pracuji s pointery na naddtřídu `CMatrix`, na kterých se pak polymorfně tyto metody volají.

Polymorfismus je také mezi potomky třídy `CCommand`, kteří se liší v konkrétním provedení metody `Execute()`.
