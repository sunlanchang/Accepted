import sys
import random

DEBUG = True

########################################


def solve():
    ''' Solution here '''

    n = int(fin.readline().strip())

    for i in xrange(0, n):
        s = fin.readline().strip()
        if check_one_or_two(s) == 1:
            fout.write("%s\n" % one2two(s))
        else:
            fout.write("%s\n" % two2one(s))


def one2two(s):

    idx = 0
    while s[idx] not in '0123456789':
        idx += 1

    alpha = s[0:idx]
    number = s[idx:]

    x = 0
    len_alpha = len(alpha)
    for i in xrange(0, len_alpha):
        x *= 26
        x += ord(alpha[i]) - ord('A') + 1

    return "R%sC%d" % (number, x)


def two2one(s):
    idx = s.index('C')
    y = s[1:idx]
    x = int(s[idx+1:]) - 1
    alpha = ''
    while x >= 0:
        alpha = chr(x % 26 + ord('A')) + alpha
        x = x / 26 - 1
    return "%s%s" % (alpha, y)


def check_one_or_two(s):
    if ('C' in s) and (s.index('C') != 0) and (s[s.index('C') - 1] in '0123456789'):
        return 2
    else:
        return 1

########################################


def init():
    global fin, fout
    if DEBUG:
        fin = open('input.txt', 'r')
    else:
        fin = sys.stdin
    fout = sys.stdout


def quit():
    global fin, fout
    fin.close()
    fout.close()


if __name__ == '__main__':
    init()
    solve()
    # quit()
