"""
Sefcic Adrian-Ionut, grupa 142
"""


def citire(fisier):
    f = open(fisier)
    linie = f.readLine()
    nrElevi = int(linie)
    d = {}
    while nrElevi > 0:
        linie = f.readLine()
        if (linie.find(',') == -1):
            nrMaterii = linie[len(linie)]
            linie.split()
            # trb scos numeElev , nrMaterii

            for x in nrMaterii:
                linie = f.readLine()
                linie = f.split(',')

                materie = linie[0]
                d[numeElev][materie] = d[numeElev][materie] + (linie[x + 1] for x in range(len(linie)) - 1)
        nrElevi -= 1
    return d;


def detalii_elev(d, nume):
    medieGen = 0
    nrMaterii = 0
    for x in d[nume]:
        suma = 0
        nrMaterii += 1

        for y in d[i][x]:
            k += 1
            suma += int(d[i][x][y])
        if suma / k > 5 and k == 1:
            print(x, " 0")
        else:
            print(x, " ", suma / k)
        medieGen += suma / k
    medieGen = medieGen / nrMaterii
    return medieGen


def clasament(d, *nr):
    l = []
    for nume in nr:
        tuplu = (nume, detalii_elev(nume))
    l = l + tuplu
    return l