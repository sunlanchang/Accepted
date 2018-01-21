import math
while True:
    try:
        a, b, c = map(int, input().strip().split())
        print(math.ceil(a/c)*math.ceil(b/c))
    except EOFError:
        break