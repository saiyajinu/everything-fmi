f = open("input.in")
sigma=[]
q=[]
start=-1
stop=-1
gamma=[]
"""citire din fisier dupa modelul din laborator"""
def citire():
    global start
    global stop
    s = f.readline()
    while s[0]=='#':
        s=f.readline()
    if(str(s.rstrip("\n"))=="Sigma:"):         #verifica daca in fisier suntem la sigma apoi adauga datele la lista corespunzatoare
        s = f.readline()
        while(str(s.rstrip("\n"))!="End"):
            sigma.append(s.rstrip("\n").strip())
            s = f.readline()
    if (str(s.rstrip("\n")) == "Gamma:"):       #verifica daca in fisier suntem la gamma apoi adauga datele la lista corespunzatoare
        s = f.readline()
        while (str(s.rstrip("\n")) != "End"):
            gamma.append(s.rstrip("\n").strip())
            s = f.readline()

    if (str(s.rstrip("\n")) == "States:"):      #verifica daca in fisier suntem la setul de stari apoi adauga datele la lista corespunzatoare
        s = f.readline()
        while str(s.rstrip("\n")) != "End":
            s = s.strip()
            state_line = s.split(" ,")
            state = state_line[0][5:]
            if len(state_line) == 2:
                if (str(state_line[1]) == "S"):
                    start=int(state)
                else:
                    stop=int(state)
            q.append(state)
            s = f.readline()
    if (str(s.rstrip("\n")) == "Transitions:"):     #verifica daca in fisier suntem la tranzitii apoi adauga datele la lista corespunzatoare
        global delta                                #tranzitiile sunt de forma: stare_initiala elem_citit elem_scris directie_head starea_urmatoare
        delta = [[[] for x in range(len(q) + 2)] for y in range(len(q) + 2)]
        s = f.readline()
        while str(s.rstrip("\n")) != "End":
            s = s.strip()
            s=s.strip("\n")
            s=s.split(" ")
            s=list(s)
            delta[int(s[0])][int(s[4])].append((s[1],s[2],s[3]))
            s=f.readline()

citire()        #se face citire de 4 ori deoarece functia nu se repeta singura pentru fiecare set de date
citire()
citire()
citire()
"""Validarea TM"""
def validare():
    ok = 1
    if start == -1:
        ok = 0

    if stop == -1:
        ok = 0
    #Verificarea daca literele din tranzitii apartin alfabetelor sigma si gamma
    for i in range(len(delta)):
        for x in delta[i]:
            if x:
                for y in x:
                    if y[0] not in gamma and y[0] not in sigma and y[0]!='b':           # b = blankspace
                        ok=0
                    if y[1] not in gamma and y[1] not in sigma and y[1]!='b':
                        ok = 0
    if (ok):
        print("VALID: Da")
    else:
        print("VALID: Nu")

validare()
"""Crearea tapeurilor"""
s=f.readline()
l=[x for x in s.rstrip("\n")]
l.append('b')
l2=['b']+l
l=l2
tape1=[x for x in l]
tape2=[x for x in l]
head=1
print("Initial Tape1: ",*tape1[1:len(tape1)-1])
print("Initial Tape2: ",*tape2[1:len(tape2)-1])
#Exemplul folosit: validarea (0^n)(1^n)
#Parcurgerea
while start!=stop: #Cat timp nu se ajunge la starea de acceptare sau de neacceptare
#In exemplul folosit nu exista stare finala de neacceptare
    ok=0
    for i in range(len(delta)):
        if i==start:
            for j in range(len(delta)):
                x=delta[i][j]
                if x:
                    for y in x:
                        if y[0]==tape1[head]:
                            #Daca se indeplineste conditia ca elementul din tape
                            # sa fie egal cu cel din tranzitie se fac actualizarile pe tapeuri
                            gasit = 1
                            start=j
                            tape1[head]=y[1]
                            tape2[head]=y[1]
                            #Mutarea la dreapta sau stanga a headului unic
                            if y[2]=='R':
                                head+=1
                            else:
                                if head!=1:
                                    head-=1
                            ok=1
                        if ok:
                            break
                if ok:
                    break
        if ok:
            break

    if ok==0:
        break

if start==stop:
    accept = ""
    headpos = 1
    while accept == "":
        if tape1[headpos] == "x":               #verifica ca cele doua tapeuri sa fie identice
            if tape2[headpos] == "x":
                headpos += 1
            else:
                accept = "REJECT, TAPES ARE DIFFERENT"
                break
        else:
            if tape1[headpos] == "#":
                if tape2[headpos] == "#":
                    headpos += 1
                else:
                    accept = "REJECT, TAPES ARE DIFFERENT"
                    break
            else:
                if tape1[headpos] == "b":
                    accept = "ACCEPTED, BOTH TAPES ARE IDENTICAL"
    print(accept)
else:
    if ok==0:
        print("Nu este acceptat")


print("Final Tape1: ",*tape1[1:len(tape1)-1])
print("Final Tape2: ",*tape2[1:len(tape2)-1])




