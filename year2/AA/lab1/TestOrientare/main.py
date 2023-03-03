n = int(input())
P = []
for i in range(n):
    line = input().split()
    p1 = (int(line[0]),int(line[1]))
    p2 = (int(line[2]), int(line[3]))
    p3 = (int(line[4]), int(line[5]))
    P.append(p1)
    P.append(p2)
    P.append(p3)

def direction(p1,p2,p3):
    det = p2[0] * p3[1] + p1[0] * p2[1] + p3[0] * p1[1] - p2[0] * p1[1] - p1[0] * p3[1] - p2[1] * p3[0]
    if det == 0:
        print("TOUCH")
    elif det > 0:
        print("LEFT")
    else:
        print("RIGHT")

for test in range(n):
    p1 = (P[test*3][0], P[test*3][1])
    p2 = (P[test*3+1][0], P[test*3+1][1])
    p3 = (P[test*3+2][0], P[test*3+2][1])
    direction(p1, p2, p3)






