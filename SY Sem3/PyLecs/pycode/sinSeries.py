import myMath as m
n = int(input())
x = float(input())
x *= 3.14/180
val = 0
num = 1
for i in range(1, n+1):
    if(i % 2 != 0):
        val += m.power(x, num) / m.fact(num)
    else:
        val -= m.power(x, num) / m.fact(num)
    num += 2
print("sin(", x, ") =", val)
