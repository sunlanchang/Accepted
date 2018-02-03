import pdb
p, r, n = [], {}, int(input())
for i in range(n):
    a, b = input().split()
    b = int(b)
    r[a] = r.get(a, 0)+b
    p.append([r[a], a])
    m = max(r.values())
# pdb.set_trace()
for n, a in p:
    if n >= m and r[a] >= m:
        print(a)
        break
