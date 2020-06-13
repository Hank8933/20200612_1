#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80

typedef struct STACK {
    char s[MAX+1];
    struct STACK *next;
} stack;

stack *findp (stack *first, stack **a, stack **b)
{
    char c = *first->s;
    if (c > 41 && c < 48) {
        return first;
    }
    *b = *a;
    *a = first;
    return findp(first->next, a, b);
}

void convert (stack **first)
{
    stack *p, *a, *b;
    a = b = 0;
    p = findp(*first, &a, &b);

    char op[2] = {0};
    *op = *p->s;
    stack *n = malloc(sizeof(stack));
    strcat(strcat(strcpy(n->s, a->s), b->s), op);

    if (b == *first) {
        *first = n;
    }
    else {
        (*first)->next = n;
    }
    n->next = p->next;
}

int main()
{
    //freopen("list", "r", stdin);
    char c;
    stack *first = calloc(1, sizeof(stack));

    for (int i = 0; !('\n' == (c = getchar())); i++) {
        char s[2] = {0};
        *s = c;
        stack *n = malloc(sizeof(stack));
        strcpy(n->s, s);
        n->next = first;
        first = n;
    }
    while (first->next->next)
        convert(&first);

    printf("%s\n", first->s);

    return 0;
}
