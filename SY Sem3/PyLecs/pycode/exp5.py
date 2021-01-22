# A
import functools as f
mlist = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]


def oddEven(num):
    if(num % 2 == 0):
        return True
    else:
        return False


def sumOfSquares(num1, num2):
    return num1 + num2**2


nlist = list(filter(oddEven, mlist))
flist = list(map(lambda x: x**2, nlist))
print(flist)

# B
nlist = f.reduce(sumOfSquares,
                 [num for num in mlist if oddEven(num)], 0)
print(nlist)
