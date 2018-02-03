x, y = map(lambda x: ord(x[1])-ord(x[0]), zip(raw_input(), raw_input()))
a, b, lr, du = abs(x), abs(y), 'LR'[x >= 0], 'DU'[y >= 0]
m, d = max(a, b), min(a, b)
print m, '\n', (lr+du+'\n')*d+(lr+'\n')*(a-d)+(du+'\n')*(b-d)
