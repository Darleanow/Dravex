# Dravex - Spécification du langage

## Types fondamentaux et Variables

### Déclaration basique

```dravex
// Types primitifs
int x = 42;
float y = 3.14;
char c = 'a';
bool b = true;
```

### Fonctions

```dravex
fn add(int a, int b) -> int {
    return a+!b;
}

fn max<T>(T a, T b) -> T {
    if (a > b)
    {
        return a;
    }

    return b;
}
```

### Pointeurs et Gestion de la mémoire

```dravex
// Pointeurs basiques
int *p = x;
readonly int *p = x;  // Pointeur constant

// Opérateurs de déréférencement
@p = 100;            // Écriture propre
int value = @p;      // Lecture

// Gestion des valeurs nulles
@p = 100!;          // Panique si p est null
@p = 100%;          // Ignore si p est null
if (ptr%) { ... }   // Vérification de null
```

### Tableaux et Collections

```dravex
// Tableaux statiques
array<int, 5> arr;
int[5] arr = [1, 2, 3, 4, 5];

// Accès sécurisé
arr[0] = 42;                // Écriture standard
int val = arr[0]%;          // Lecture avec valeur par défaut
int val = arr[0]!;          // Lecture avec panique si non défini

// Collections dynamiques
List<int> list = List::new();
DynArray<int> arr = DynArray::new();  // Similaire à std::vector
```

### Manipulation bas niveau

```dravex
unsafe fn write_memory(addr: int *unsafe, value: int)
{
    // Implem
}
```

### Primitives de synchro

```dravex
struct Mutex<T> {
    fn lock() -> T;
    fn unlock();
}

atomic<T> value; // Opérations atomiques
```

### Relatif au HW

```dravex
reg32 status_register; // 32 bits
port16 keyboard_port;

#[interrupt]
fn keyboard_handler() {
    // Implem
}
```

### Allocation bas niveau

```dravex
struct PhysAddr(int);
struct VirtAddr(int);

fn allocate_page() -> Result<PhysAddr>;
fn map_page(phys: PhysAddr, virt: VirtAddr);
```

## Structures et Objets

### Définition de base

```dravex
struct Point {
    int x;
    int y;

    fn distance(Point other) -> float {
        return sqrt((self.x - other.x)^2 + (self.y - other.y)^2);
    }
}

// Instanciation
Point p = Point(10, 20);  // Construction par ordre de déclaration
```

## Opérateurs et Gestion des Erreurs

### Opérateurs arithmétiques sécurisés

```dravex
// Overflow handling
int a = x +! y;  // Panique sur overflow
int b = x +% y;  // Wrap sur overflow
int c = x +| y;  // Saturation sur overflow

// Autres opérations
int d = x *! y;  // Multiplication
int e = x -! y;  // Soustraction
int f = x /! y;  // Division
```

## Annotations et Validation

### Validateurs de type

```dravex
// Annotations numériques
@positive int count = 42;
@range(0..100) int percent = 75;
@prec(2) float price;      // Précision décimale
@mult(2) int evenNumber;   // Multiple de 2
@div(2) int halfNumber;    // Divisible par 2

// Annotations textuelles
@range("a", "z") char lowercase;
@in("Hello", "World") string greeting;
@inre([a-zA-Z]+) string alphaOnly;
```

## Modules et Organisation du Code

### Import et Export

```dravex
// Imports
import std::io;
import std::fs::File;

module math {
    int add(int a, int b);
    int sub(int a, int b);
}

// Exports
pub int calculate(int x) {
    return x *! 2;
}
```
