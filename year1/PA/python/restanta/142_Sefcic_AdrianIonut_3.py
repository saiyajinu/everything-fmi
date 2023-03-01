"""
Sefcic Adrian-Ionut, grupa 142
"""
f=open("carti.in")
d = {}

for x in f:
    nume_carte = ''
    x = x.split()
    for y in x:
        if len(y)>1 and y[1].isalpha() :
            if nume_carte == '':
                nume_carte = y
            else:
                nume_carte = nume_carte + ' '+y
        elif len(y)>1 and y[1].isdigit():
            cod_cititor = y
        else:
            d[nume_carte] = {}
            d[nume_carte][cod_cititor] = y
            #print (d)

def sterge_nota(d, nume_carte, cod):
    del d[nume_carte][cod]
    for codes in d[nume_carte]:
        nr = 0
        sum = 0
        for note in d[nume_carte][cod]:
            sum += note
            nr += 1
    return sum/nr

def aprecieri(d, *nume_carti):
    list = []
    for nume in nume_carti:
        max = 0
        for cod in d[nume]:
            if d[nume][cod] > max:
                max = d[nume][cod]
                scod = cod




aprecieri(d, "Algorithm Design")
print(d)

#sterge_nota(d, 'Algorithm Design', "c1")


