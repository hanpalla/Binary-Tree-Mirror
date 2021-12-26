#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
struct node *temp, *bantu;

struct node *newNode (int data){
    struct node* tree = (struct node*) malloc(sizeof(struct node));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return(tree);
}

void mirror(struct node *tree){
    if(tree == NULL)
        return;
    else{
        struct node* temp;
        mirror(tree->left);
        mirror(tree->right);

        temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;
    }
}

void tambah(int value){
    struct node *tree = (struct node*) malloc(sizeof(struct node));
    tree->data = value;
    tree->left = NULL;
    tree->right = NULL;

    if(root == NULL)
        root = tree;
    else{
        bantu = root;
        temp = root;
        while(bantu != NULL) // Perulangan dipakai untuk mencari tempat yang kosong terlebih dahulu
        {
            temp = bantu;
            if(temp->data > tree->data)
                bantu = temp->left;
            else
                bantu = temp->right;
        }

        //penempatan node baru
        if(temp->data > tree->data) // Setelah dapat tempat kosong baru taruh nilai dari tree
            temp->left = tree;
        else
            temp->right = tree;
    }
}

void preOrder(struct node *tree){
    if(tree == NULL)
        return;
    
    printf("%d ", tree->data);
    preOrder(tree->left);
    preOrder(tree->right);
} 

int main(){
    system("cls");
    printf("PROGRAM MIRRORING BINARY TREE SEDERHANA.\n");
    tambah(10);
    tambah(12);
    tambah(8);
    tambah(9);
    tambah(7);
    tambah(11);
    tambah(13);
    tambah(14);
    tambah(6);
    

    printf("\nTampilan tanpa cermin.\n");
    preOrder(root);
    mirror(root);
    printf("\n\nTampilan dengan cermin.\n");
    preOrder(root);

    return 0;
}
