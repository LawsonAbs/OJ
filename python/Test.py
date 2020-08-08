def est():
    while True:
        try:
            a, b = map(int, input().strip().split())
            print(a + b)
        except EOFError:
            break

est()