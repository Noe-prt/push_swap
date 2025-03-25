# push_swap

Un projet de l'école **42** qui consiste à trier une pile d'entiers en utilisant un ensemble d'instructions restreintes.

## ✨ Objectif

L'objectif de ce projet est de créer un programme capable de trier une pile d'entiers en un nombre minimal de coups, en utilisant des **opérations sur deux piles** :

- `sa`, `sb`, `ss` : Swap (échange) les deux premiers éléments d'une pile
- `pa`, `pb` : Push (pousse) le premier élément d'une pile vers l'autre
- `ra`, `rb`, `rr` : Rotate (fait monter tous les éléments d'une pile)
- `rra`, `rrb`, `rrr` : Reverse rotate (fait descendre tous les éléments d'une pile)

## 📝 Description

Ce projet vous pousse à :

- Manipuler des piles avec une gestion rigoureuse de la mémoire.
- Implémenter des algorithmes de tri efficaces (comme l'algorithme **Turk** dans ton cas).
- Optimiser le nombre de mouvements pour le tri de petites et grandes piles.

### Algorithme Utilisé : **Turk Algorithm**

L'algorithme **Turk** est une stratégie optimisée pour diviser la pile en plusieurs parties, transférer progressivement les éléments entre les piles `a` et `b`, et assurer un tri optimal en un nombre minimal de coups.

## 🛠️ Compilation et Exécution

Cloner le dépôt :

```bash
git clone https://github.com/Noe-prt/push_swap.git
cd push_swap
```

Compiler le projet :

```bash
make
```

Exécuter :

```bash
./push_swap 4 67 3 87 23
```

Tester avec le checker :

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## 📊 Visualisation graphique de l'algorithme

![Exemple graphique de l'algorithme sur les deux piles](https://miro.medium.com/v2/resize:fit:1200/1*ZLKF3qJ75poRylB9g8wM5w.gif)

## 🔥 Fonctionnalités

- Gestion dynamique des piles `a` et `b`
- Implémentation optimisée du **Turk Algorithm**
- Supporte un nombre variable d'arguments
- Validation des erreurs (doubles, non-entiers, etc.)

## 💡 Stratégies d'Optimisation

- **3 nombres restants à trier** : Tri rapide avec un algorithme de tri pour 3 nombres.
- **Plus de 3 nombres à trier** : Utilisation du **Turk Algorithm** pour diviser et conquérir.
- Minimisation des mouvements en regroupant les opérations.

## 👤 Auteur

Projet réalisé par :

- [Noe-prt](https://github.com/Noe-prt)

