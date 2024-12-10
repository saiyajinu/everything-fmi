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
    def __init__(self, informatie, parinte = None):
        self.informatie = informatie
        self.parinte = parinte

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

    def __str__(self):
        return str(self.informatie)

    def __repr__(self):
        return f"{self.informatie} ({'->'.join(map(str, self.drumRadacina()))})"

class Graf:
    def __init__(self, matr, start, scopuri):
        self.matr = matr
        self.start = start
        self.scopuri = scopuri

    def scop(self, informatieNod):
        return informatieNod in self.scopuri

    def succesori(self, nod):
        lsuccesori = []
        for infoSuccesor in range(len(self.matr)):
            if self.matr[nod.informatie][infoSuccesor] == 1 and not nod.inDrum(infoSuccesor):
                lsuccesori.append(NodArbore(infoSuccesor, nod))
        return lsuccesori

def breadthFirst(gr, nrsol=3):
    coada = [NodArbore(gr.start)]
    while coada:
        nodCurent = coada.pop(0)
        if gr.scop(nodCurent.informatie):
            print(repr(nodCurent))
            nrsol -= 1
            if nrsol == 0:
                return
        coada += gr.succesori(nodCurent)

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
    [0, 1, 0, 1, 1, 0, 0, 0, 0, 0],
    [1, 0, 1, 0, 0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 1, 0, 1, 0, 0],
    [1, 0, 0, 0, 0, 0, 1, 0, 0, 0],
    [1, 0, 0, 0, 0, 0, 0, 1, 0, 0],
    [0, 1, 1, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 0, 1, 0, 0, 0, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 0, 0]
]


start = 0
scopuri = [5, 9]

gr = Graf(m, start, scopuri)
print('breadthFirst')
breadthFirst(gr, nrsol=4)
print('bfe6')
bfe6(gr, nrsol=4)

# print('depthFirstNerecursiv')
# depthFirstNerecursiv(gr, nrsol=4)
# print('depthFirstRecursiv')
# depthFirstRecursiv(gr, nrsol=4)