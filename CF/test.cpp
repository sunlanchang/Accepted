#include <cstdio>
main()
{
    char a[2], b[2], c, d, x, y;
    gets(a);
    gets(b);
    x = a[0] - b[0];
    y = a[1] - b[1];
    c = x < 0 ? x = -x, 82 : 76;
    d = y < 0 ? y = -y, 85 : 68;
    printf("%d", x > y ? x : y);
    while (x | y)
    {
        puts("");
        if (x)
            x--, putchar(c);
        if (y)
            y--, putchar(d);
    }
}