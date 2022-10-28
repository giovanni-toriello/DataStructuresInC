#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "item.h"
#include "BST.h"

struct node {
    item value;
    struct node *left;
    struct node *right;
};

struct node *getRoot(BST T) {
    return T;
}

item getItem(struct node *N);

void setItem(struct node *N, item el);

item getItem(struct node *N) {
    if (N == NULL) return NULL;
    return N->value;
}

void setItem(struct node *N, item el) {
    if (N == NULL) return;
    N->value = el;  // correttezza di =
}                             // dipende dal tipo item
BST newBST(void) {
    return NULL;
}

int emptyBST(BST T) {
    return T == NULL;
}

int contains(BST T, item val) {
    if (T == NULL) return 0;
    if (eq(val, getItem(T))) return 1;
    if (minore(val, getItem(T)))
        return (contains(figlioSX(T), val));
    else
        return (contains(figlioDX(T), val));
}

BST creaFoglia(item elem) {
    struct node *N;
    N = malloc(sizeof(struct node));
    if (N == NULL) return NULL;
    setItem(N, elem);
    N->left = NULL;
    N->right = NULL;
    return N;
}

BST figlioSX(BST T) {
    if (T != NULL)
        return T->left;
    else
        return NULL;
}

BST figlioDX(BST T) {
    if (T != NULL)
        return T->right;
    else
        return NULL;
}

BST insert(BST T, item elem) {
    if (T == NULL) return creaFoglia(elem);
    else if (minore(elem, getItem(T)))
        T->left = insert(T->left, elem);
    else if (minore(getItem(T), elem))
        T->right = insert(T->right, elem);
    return T;
}

//  deve essere usata sempre nel modo
//   bst = insert(bst, elem);


struct node *minValue(struct node *node) {
    struct node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node *deleteNode(struct node *root, item key) {
    if (root == NULL) return root;

    if (minore(key, root->value))
        root->left = deleteNode(root->left, key);
    else if (minore(root->value, key))
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValue(root->right);
        root->value = temp->value;


        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

int isBst(BST t) {
    int isBstSX = 0;
    int isBstDX = 0;
    item father = getItem(t);
    if (figlioSX(t) != NULL && figlioDX(t) != NULL) {
        item itemSX = getItem(figlioSX(t));
        item itemDX = getItem(figlioDX(t));
        if (getValue(father) > getValue(itemSX)) {
            isBstSX = 1;
        }
        if (getValue(father) < getValue(itemDX)) {
            isBstDX = 1;
        }
        if (isBstDX && isBstSX) {
            isBstSX = isBst(figlioSX(t));
            isBstDX = isBst(figlioDX(t));
            if (isBstSX && isBstDX) {
                return 1;
            }
        }
        return 0;
    } else {
        return 1;
    }
    return 0;
}

void printBtree(BST albero, int lv) {
    item val;
    if (emptyBST(albero)) {
        return;
    }
    for (int i = 0; i < lv - 1; ++i) {
        printf("|  ");
    }
    if (lv > 0) {
        printf("|--");
    }
    val = getItem(getRoot(albero));
    output_item(val);
    printf("\n");
    printBtree(figlioSX(albero), lv + 1);
    printBtree(figlioDX(albero), lv + 1);
}

void stampa(BST albero) {
    printBtree(albero, 0);
}

void stampaIntervallo(BST t, int a, int b) {
    if (a > b) {
        return;
    }
    if (t == NULL) {
        return;
    }
    int val = getValue(getItem(t));
    if (a <= val && val <= b) {
        printf("\n%d", getValue(getItem(t)));
    }
    stampaIntervallo(figlioSX(t), a, b);
    stampaIntervallo(figlioDX(t), a, b);
}

BST creaBilanciatoBst(int a[], int n) {
    BST b = newBST();
    if (log2(n + 1) != trunc(log2(n + 1))) {
        return NULL;
    }
    for (int i = n / 2; i < n; i++) {
        b = insert(b, newItem(a[i]));
    }
    for(int i=0;i<n/2;i++){
        b = insert(b, newItem(a[i]));
    }
    return b;
}



