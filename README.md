# TP2 — Algorithme de Ford-Fulkerson avec BFS (Flot Maximum & Coupe Minimale)

Ce projet implémente en C++ une version améliorée de l’algorithme de **Ford-Fulkerson** en utilisant un **parcours en largeur (BFS)** (aussi appelé algorithme d’**Edmonds-Karp**).  
Il permet :  

- de calculer le **flot maximum** d’un graphe orienté avec capacités,  
- d’identifier la **coupe minimale** à partir de l’ensemble des sommets accessibles depuis la source après saturation.  

---

## 🎯 Objectif pédagogique
- Manipuler les graphes orientés avec des capacités (réseaux de transport).  
- Appliquer un algorithme de flot (Ford-Fulkerson/Edmonds-Karp).  
- Comprendre le théorème du flot maximum et de la coupe minimale.  
- Développer un programme structuré en C++ avec séparation en `.cpp` / `.h`.  

---

## 📁 Contenu
- `src/main.cpp` — point d’entrée du programme  
- `src/utilities.cpp` — fonctions utilitaires (affichage, BFS, etc.)  
- `src/utilities.h` — en-têtes  

---

## 🧱 Prérequis
- Compilateur **C++17**  
- `make` (recommandé)  

---

## 🧩 Compilation

### Option A — avec `make`
```bash
make
```
👉 L’exécutable est généré dans `build/tp2`.

### Option B — sans `make`
```bash
g++ -std=c++17 -O2 -Isrc src/*.cpp -o tp2
```

---

## ▶️ Utilisation
Le programme lit un fichier décrivant un graphe (matrice des capacités) et calcule :  

1. La valeur du **flot maximum**.  
2. Les sommets appartenant à l’ensemble **S** (côté source de la coupe minimale).  
3. Les arêtes constituant la **coupe minimale**.  

### Exemple
Fichier d’entrée (`data/graphe.txt`) :  
```
6
0 16 13 0 0 0
0 0 10 12 0 0
0 4 0 0 14 0
0 0 9 0 0 20
0 0 0 7 0 4
0 0 0 0 0 0
```

Exécution :  
```bash
./build/tp2 data/graphe.txt
```

Sortie attendue :  
```
Flot maximum = 23
S = {0, 1, 2}
Coupe minimale : (1,3) (4,5)
```

---

## 📂 Arborescence
```
.
├── src/
│   ├── main.cpp
│   ├── utilities.cpp
│   └── utilities.h
├── Makefile
├── README.md
└── data/
    └── graphe.txt   (exemple de graphe)
```

---

## 📝 Licence
Ajoute une licence (ex. MIT) si tu souhaites autoriser la réutilisation.  
