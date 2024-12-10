# class Cls:
#     def __init__(self, aa, bb):
#         self.a=aa
#         self.b=bb
   
#     def __str__(self):
#         return "a={} b={}".format(self.a,self.b)
#     def __repr__(self):
#         return "({}, {})".format(self.a,self.b)
   
# c1=Cls(2,5)
# print(c1) #a=2 b=5
# print(str(c1)) #a=2 b=5
# print(repr(c1)) #(2, 5)
# c2=Cls(3,3)
# c3=Cls(4,1)
# print([c1,c2,c3]) #[(2, 5), (3, 3), (4, 1)]

class NodArbore:
    def __init__(self, informatie, g = 0 , h = 0 , parinte = None):
        self.informatie = informatie
        self.parinte = parinte
        self.g = g              # costul de la nodul de start la nodul curent
        self.h = h              # costul estimativ de la nodul curent la nodul scop
        self.f = g + h          # costul total

    def __str__(self):
        return str(self.informatie)

    def __repr__(self):
        return f"{self.informatie} cost:{self.g} ({'->'.join(map(str, self.drumRadacina()))})"
    
    def __lt__(self, elem):
        return (self.f, self.g) < (elem.f, elem.g)
    
    def __eq__(self, elem):
        return self.f < elem.f or (self.f == elem.f and self.h < elem.h)

    def drumRadacina(self):
        l=[]
        nod = self
        while nod:
            l.insert(0, nod)
            nod = nod.parinte
        return l

    def inDrum(self, infonod):
        nod = self
        while nod:
            if nod.informatie == infonod:
                return True
            nod = nod.parinte
        return False
    

class Graf:
    def __init__(self, matr, start, scopuri, h):
        self.matr = matr
        self.start = start
        self.scopuri = scopuri
        self.h = h

    def scop(self, informatieNod):
        return informatieNod in self.scopuri
    
    def estimeaza_h(self, infoNod):
        return self.h[infoNod]

    def succesori(self, nod):
        lsuccesori = []
        for infoSuccesor in range(len(self.matr)):
            if self.matr[nod.informatie][infoSuccesor] > 0 and not nod.inDrum(infoSuccesor):
                lsuccesori.append(NodArbore(infoSuccesor, nod.g + self.matr[nod.informatie][infoSuccesor], self.estimeaza_h(infoSuccesor), nod))
        return lsuccesori

def astarSolMultiple(gr, nrsol=3):
    coada = [NodArbore(gr.start)]
    while coada:
        nodCurent = coada.pop(0)
        if gr.scop(nodCurent.informatie):
            print(repr(nodCurent))
            nrsol -= 1
            if nrsol == 0:
                return
        coada += gr.succesori(nodCurent)
        coada.sort()

def bfe6(gr, nrsol=3):
    coada = [NodArbore(gr.start)]
    if gr.scop(coada[-1].informatie):
        print(repr(coada[-1]))
        nrsol -= 1
        if nrsol == 0:
            return
    while coada:
        nodCurent = coada.pop(0)
        coada += gr.succesori(nodCurent)
        for nod in gr.succesori(nodCurent):
            if gr.scop(nod.informatie):
                print(repr(nod))
                nrsol -= 1
                if nrsol == 0:
                    return

def depthFirstNerecursiv(gr, nrsol=3):
    stiva = [NodArbore(gr.start)]
    while stiva:
        nodCurent = stiva.pop()
        if gr.scop(nodCurent.informatie):
            print(repr(nodCurent))
            nrsol -= 1
            if nrsol == 0:
                return
        stiva += gr.succesori(nodCurent)[::-1]

def depthFirstRecursiv(gr, nrsol=3):
    df(NodArbore(gr.start), gr, nrsol)

def df(nodCurent, gr, nrsol):
    if gr.scop(nodCurent.informatie):
        print(repr(nodCurent))
        nrsol -= 1
        if nrsol == 0:
            return nrsol
    for s in gr.succesori(nodCurent):
        nrsol = df(s, gr, nrsol)
        if nrsol == 0:
            return nrsol
    return nrsol

m = [
[0, 3, 5, 10, 0, 0, 100],
[0, 0, 0, 4, 0, 0, 0],
[0, 0, 0, 4, 9, 3, 0],
[0, 3, 0, 0, 2, 0, 0],
[0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 4, 0, 5],
[0, 0, 3, 0, 0, 0, 0],
]
start = 0
scopuri = [4,6]
h=[0,1,6,2,0,3,0]

gr = Graf(m, start, scopuri, h)

print('astarSolMultiple')
astarSolMultiple(gr, nrsol=5)



# print('breadthFirst')
# breadthFirst(gr, nrsol=4)


# print('bfe6')
# bfe6(gr, nrsol=4)

# print('depthFirstNerecursiv')
# depthFirstNerecursiv(gr, nrsol=4)
# print('depthFirstRecursiv')
# depthFirstRecursiv(gr, nrsol=4)