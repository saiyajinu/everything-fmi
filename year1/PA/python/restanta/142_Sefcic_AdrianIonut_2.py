"""
Sefcic Adrian-Ionut, grupa 142
"""

def citire_matrice(fisier):
    f=open(fisier)
    m=[[x for x in linie.split()] for linie in f]
    return m

def mutare(m, *parametri):
    for i in parametri:
        max = m[0][i]
        pozmax = 0
        min = m[0][i]
        pozmin = 0

        for x in range(0,len(m[0])):
            if m[x][i] > max:

                max = m[x][i]
                pozmax = x
            if m[x][i] < min:
                min = m[x][i]
                pozmin = x
        m[pozmax][i], m[pozmin][i] = min, max
    return m


m = citire_matrice("matrice.in")
m = mutare(m, 0, 1)
m[0][len(m[0])-1] = int(m[0][len(m[0])-1]) * 2
for a in m:
    for b in a:
        print(b, end=' ')
    print()



