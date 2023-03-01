"""
Sefcic Adrian-Ionut, grupa 142

functie citire_matrice citeste elem matricei si returneaza matricea
pt tip= 0/1 suma liniilor cu indici dati ca param
"""

def citire_matrice (fisier):
    f = open(fisier)
    line = f.readLine()
    m = line[0]
    n = line[1]
    line = f.readLine()
    line = line.split()
    lung = len(line)
    if m*n != lung:
        matrice = []
        return matrix
    k = 0
    for x in range(0,m):
        for y in range(0,n):
            matrice[x][y] = line[k]
            k += 1
    return matrice


def total (matrice, *nr, tip):
    import numpy as np
    marime = len(matrice[0])
    sumaLinii = []
    for x in marime:
        suma = 0
        for y in nr:
            suma += int(matrice[y][x])
        sumaLinii[x] = suma
    if tip == 0:
        matrice = np.append(matrice, sumaLinii, axis=0)
    if tip == 1:
        matrice = matrice + sumaLinii

    return matrice

citire_matrice("matricemn.in")
total ("matricemn.in", 0, 1, 1)
total ("matricemn.in", 3, 4, 0)