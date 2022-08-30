// Exercise 6.2: Write a program that reads a C program and prints in alphabetical
// order each group of variable names that are identical in the first 6 characters,
// but different somewhere thereafter. Don't count words within strings and comments.
// Make 6 a parameter that can be set from the command line.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100
#define LEN_MATCH 6

struct tnode {
    char* word;
    int count;
    struct tnode* left;
    struct tnode* right;
};

// clang-format off
struct key {
       char *word;
       int count;
   } keytab[] = {
       {"auto", 0},
       {"break", 0},
       {"case", 0},
       {"char", 0},
       {"const", 0},
       {"continue", 0},
       {"default", 0},
       {"define", 0},
       {"if", 0},
       {"ifdef", 0},
       {"include", 0},
       /* ... */
       {"struct", 0},
       {"unsigned", 0},
       {"void", 0},
       {"volatile", 0},
       {"while", 0}
};
// clang-format on
#define NKEYS sizeof(keytab) / sizeof(keytab[0])

struct tnode* addtree(struct tnode*, char*);
void treeprint(struct tnode*);
int getword(char*, int);
int binsearch(char* word, struct key tab[], int n);

/* word frequency count */
int main()
{
    struct tnode* root;
    char word[MAXWORD];
    root = NULL;

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]) && strlen(word) >= LEN_MATCH)
            if (binsearch(word, keytab, NKEYS) == -1) // only vars
                root = addtree(root, word);

    treeprint(root);
}

/* getword:  get next word or character from input */
int getword(char* word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char* w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

/* binsearch:  find word in tab[0]...tab[n-1] */
int binsearch(char* word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

struct tnode* talloc(void);
char* my_strdup(char*);

/* addtree:  add a node with w, at or below p */
struct tnode* addtree(struct tnode* p, char* w)
{
    int cond;
    if (p == NULL) {  /* a new word has arrived */
        p = talloc(); /* make a new node */
        p->word = my_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;    /* repeated word */
    else if (cond < 0) /* less than into left subtree */
        p->left = addtree(p->left, w);
    else /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint:  in-order print of tree p */
void treeprint(struct tnode* p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* talloc:  make a tnode */
struct tnode* talloc(void) { return (struct tnode*)malloc(sizeof(struct tnode)); }

char* my_strdup(char* s) /* make a duplicate of s */
{
    char* p;
    p = (char*)malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */ { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
