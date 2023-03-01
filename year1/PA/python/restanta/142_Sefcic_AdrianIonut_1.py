"""
Sefcic Adrian-Ionut, grupa 142
"""

f = open("text.in")
g = open("text.out","w")
prop = []
for x in f:
    s = x.rstrip('\n')
    prop.append(s)

def isVowel(char):
    if char in "aeiou":
        return 1
    else:
        return 0
count = 0
propozitii = []
for x in prop:
    i = 1
    while i < len(x)-2:
        if isVowel(x[i]) == 1:
            if isVowel(x[i-1]) == 0 and isVowel(x[i+1]) == 0 and x[i-1] != '.' and x[i+1] != ' ' and x[i-1] != ' ':
               # sa fie vocala, sa fie consoane lange el si sa nu fie . sau spatiu
                x = x[:i] + '.' + x[i] + '.' + x[i+1:]
        i += 1
    x = x.split()
    propozitii.append(x)
    count += 1

parti = 6
while parti != 0:
    print(count, "parti:")
    for a in propozitii:
        for b in a:
            if b.count('.') == parti-1:
                print(b,end=", ")
    print()
    parti -= 1




