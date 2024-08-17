#!/usr/bin/pyrhon3

def test_1():
    def test_1_1():
        i = 4

    def test_1_2():
        nonlocal i
        i = 10

    def test_1_3():
        global i
        i = 20

    i = 14
    print("i currently : ", str(i))
    test_1_1()
    print("after calling test_1_1() ", str(i))
    test_1_2()
    print("after calling test_1_2() ", str(i))
    test_1_3()
    print("after calling test_1_3() ", str(i))

test_1()
print("global val ", str(i))
