n = int(input())
P = []
dirArr = [0,0,0]

for i in range(n):
    line = input().split()
    xy = (int(line[0]),int(line[1]))
    P.append(xy)

start = (P[0][0],P[0][1])
P.append(start)

def direction(p1,p2,p3):
    area = p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) + p3[0] * (p1[1] - p2[1])
    if area == 0:
        dirArr[0] += 1
    elif area > 0:
        dirArr[1] += 1
    else:
        dirArr[2] += 1

p1 = (P[0][0], P[0][1])
p2 = (P[1][0], P[1][1])
p3 = (P[2][0], P[2][1])
direction(p1, p2, p3)
i = 1
while i<=n-2:
    p1 = (P[i][0], P[i][1])
    p2 = (P[i+1][0], P[i+1][1])
    p3 = (P[i+2][0], P[i+2][1])
    direction(p1, p2, p3)
    i += 1

touch = dirArr[0]
left = dirArr[1]
right = dirArr[2]
print(left, right, touch)