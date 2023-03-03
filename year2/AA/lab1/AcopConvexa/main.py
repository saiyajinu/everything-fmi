n = int(input())
P = []

for i in range(n):
    line = input().split()
    xy = (int(line[0]),int(line[1]))
    P.append(xy)
start = (P[0][0],P[0][1])
P.append(start)

convexList = [P[0], P[1]]

def direction(p1,p2,p3):
    area = p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) + p3[0] * (p1[1] - p2[1])
    if area == 0:   #touch
        convexList.pop()
        convexList.append(p3)
    elif area > 0:  #left

        convexList.append(p3)
    else:           #right
        convexList.pop()
        convexList.append(p3)

i= 2
while i<=n:
    p1 = convexList[len(convexList)-2]
    p2 = convexList[len(convexList)-1]
    p3 = P[i]
    direction(p1, p2, p3)
    i += 1
convexList.pop()

p1 = convexList[len(convexList)-1]
p2 = convexList[1]
p3 = convexList[0]
area = p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) + p3[0] * (p1[1] - p2[1])
if area == 0:
    convexList.pop(0)

print(len(convexList))
for i in range(len(convexList)):
    print(convexList[i][0], convexList[i][1])


