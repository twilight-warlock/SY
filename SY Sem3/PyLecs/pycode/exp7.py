# import threading
# import random


# def print_random(x, y):
#     return (random.randint(x, y))


# def print_cube(x, y):
#     num = print_random(x, y)
#     print("The Cube of {}: {}".format(num, num * num * num))


# def print_square(x, y):
#     num = print_random(x, y)
#     print("The Square of {}: {}".format(num, num * num))


# if __name__ == "__main__":

#     t0 = threading.Thread(target=print_random, args=(0, 9))
#     t1 = threading.Thread(target=print_square, args=(0, 9))
#     t2 = threading.Thread(target=print_cube, args=(0, 9))
#     t0.start()
#     t1.start()
#     t2.start()
#     t0.join()
#     t1.join()
#     t2.join()


# class Calculator():
#     def __init__(self, a=0, b=0):
#         self.a = a
#         self.b = b

#     def add(self):
#         try:
#             if self.a > 5000000 or self.b > 5000000:
#                 raise OverflowError('Very large values')
#             else:
#                 return self.a+self.b
#         except OverflowError:
#             print('Values too large to handle')

#     def sub(self):
#         try:
#             if self.a > 5000000 or self.b > 5000000:
#                 raise OverflowError('Very large values')
#             elif self.a-self.b != (self.a-(int(self.a))-(self.b-int(self.b))):
#                 raise FloatingPointError('Inaccurate answer')
#             else:
#                 return self.a-self.b
#         except FloatingPointError:
#             print('Accurate answer could not be calculated')
#         except OverflowError:
#             print('Values too large to handle')

#     def mul(self):
#         try:
#             if self.a > 5000000 or self.b > 5000000:
#                 raise OverflowError('Very large values')
#             else:
#                 return self.a*self.b
#         except OverflowError:
#             print('Values too large to handle')

#     def div(self):
#         try:
#             if self.b == 0:
#                 raise ZeroDivisionError("Cannot divide a number by 0")
#             else:
#                 return self.a/self.b
#         except ZeroDivisionError:
#             print('Cannot divide a number by 0')
#         except OverflowError:
#             print('Values too large to handle')

#     def power(self):
#         try:
#             if self.a < 0 or self.b < 0:
#                 raise ValueError('Values entered should be non-negative')
#             if self.a > 5000000 or self.b > 5000000:
#                 raise OverflowError('Very large values')
#             else:
#                 return self.a ** self.b
#         except OverflowError:
#             print('Values Too large to handle')
#         except ValueError:
#             print('Values entered should be non-negative')


s = input('Enter a Name(only alphabets):\t')
try:
    if s.isalpha():
        print(s)
        print("Name entered Sucessfully")
    elif s.isalpha() == False:
        raise TypeError("Only alphabets are allowed")
except TypeError:
    print('Name not entered in prescribed format')
