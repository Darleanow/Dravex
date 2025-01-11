# Dravex

1. VARIABLES & TYPES DE BASE ⇒ VALIDEE

```
// Déclaration de variables
int x = 42;
float y = 3.14;
char c = 'a';
bool b = true;

// Pointeurs
int *p = x;
readonly int *p = x; // CONST
@p = 100; // Ecriture propre
int value = @p;

// Tableaux avec ptrs
array<int, 5> arr;
arr[0] = 42; // Ecrit a l'indexe 0
int val = arr[0]%; // Récup l'indexe 0, si vide, on peut utiliser les operateurs safes

// EXEMPLE LECTURE UNSET
int val =  arr[0]!; // Panic
int val = arr[0]%; // valeur par défaut, genre 0 pour int

// Ecriture si null ?
@p = 100!; // Panic si P null
@p = 100%; // Ne fait rien si p null

// Access si null ?
if (ptr%)
{
	int x = 10;
}
```

1. STRUCTURES

```
struct Point {
    int x;
    int y;
};

Point p = Point(10,20); // Par ordre de déclaration

// Annotations sur les types 
struct Point {
	@positve int x;
	@positive int y;
	
	fn distance(Point other) -> float {
		return sqrt((self.x - other.x)^2 + (self.y - other.y)^2);
	};
};
```

1. TABLEAUX

```
// Tableau fixe
int[5] arr = [1, 2, 3, 4, 5];

// Accès
int x = arr[0];
arr[1] = 42;

// Liste chaînée
List<int> list = List::new();
```

1. FONCTIONS

```
int add(int a, int b) {
    return a +! b;  // Overflow check obligatoire
}

// Génériques
T max<T>(T a, T b) {
    if a > b {
        return a;
    }
    return b;
}
```

1. CONTRÔLE DE FLUX

```
if (x > 0) {
    int y = x + 1;
} else {
    int y = x - 1;
}

while (x > 0) {
    x = x -! 1; // ! ==> crash on err
}

for (i in 1..10) {
    int val = i *! 2;
}
```

1. MODULES

```
module math {
    int add(int a, int b);
    int sub(int a, int b);
}

import std::io;
import std::fs::File;

// Export
pub int calculate(int x) {
    return x *! 2;
}
```

1. ANNOTATIONS DE SÉCURITÉ

```
@positive int count = 42;
@range(0..100) int percent = 75;
```

1. OPÉRATEURS AVEC GESTION D'OVERFLOW

```
int a = x +! y;  // Panic on overflow
int b = x +% y;  // Wrap on overflow
int c = x +| y;  // Saturate on overflow

// Pour multiplication, soustraction, division
int d = x *! y;
int e = x -! y;
int f = x /! y;
```

1. CONSTANTES

```
const int VERSION = 1;
const float PI = 3.14;
```

1. ALLOCATION SÉCURISÉE

```
// Tableau dynamique
DynArray<int> arr = DynArray::new();  // Comme un vector C++
arr.push(42);

// Allocation simple mais sécurisée
SafePtr<int> ptr = SafePtr::new();    // Vérifie les nulls automatiquement
```

1. TYPES GÉNÉRIQUES (basiques)

```
// Juste pour les containers standards
DynArray<int> numbers;
DynArray<float> values;

// Et quelques structures simples
Pair<int, float> p;
```

1. VALIDATEURS

```
@positive
@negative
@range(0..100)
@range("a", "z")
@in("Hello","World")
@nin("Hello","World")
@inre([a-zA-Z]+)
@prec(2) // bounding float
@mult(2) // Multiple de 2
@div(2) // Division entière par 2
```