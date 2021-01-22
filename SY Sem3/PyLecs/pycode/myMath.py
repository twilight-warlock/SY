def power(x, y):
    return x**y


def fact(x):
    if(0 < x < 3):
        return x
    else:
        return x*fact(x-1)


def function1():  # outer function
    print("Hello from outer function")

    def function2():  # inner function
        print("Hello from inner function")
    function2()
