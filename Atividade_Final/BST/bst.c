#include <stdio.h>  
#include <stdlib.h>  

// Estrutura de um nó da árvore binária de busca (BST)
struct Node {
    int data;            // Valor armazenado no nó
    struct Node* left;   // Ponteiro para o filho à esquerda
    struct Node* right;  // Ponteiro para o filho à direita
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um valor na árvore
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);  // Insere o primeiro nó ou um novo filho
    }

    if (data < root->data) {
        root->left = insert(root->left, data);  // Insere na subárvore esquerda
    } else if (data > root->data) {
        root->right = insert(root->right, data); // Insere na subárvore direita
    }
    return root;
}

// Função para exibir a árvore em ordem crescente (in-order traversal)
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);      // Visita a subárvore esquerda
        printf("%d ", root->data);// Imprime o valor do nó atual
        inOrder(root->right);     // Visita a subárvore direita
    }
}

// Função para encontrar o menor valor em uma subárvore
struct Node* findMin(struct Node* node) {
    while (node && node->left != NULL) {
        node = node->left;  // Percorre à esquerda até encontrar o menor valor
    }
    return node;
}

// Função para remover um valor da árvore
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root; // Árvore vazia ou valor não encontrado

    if (key < root->data) {
        root->left = deleteNode(root->left, key);  // Procura na subárvore esquerda
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key); // Procura na subárvore direita
    } else {
        // Caso com um filho ou nenhum
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Caso com dois filhos: substitui pelo sucessor in-order
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;  // Inicializa a árvore como vazia

    // Inserções na árvore
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Exibe a árvore em ordem crescente
    printf("Travessia in-order: ");
    inOrder(root);
    printf("\n");

    // Remoções e nova exibição
    printf("Removendo 20\n");
    root = deleteNode(root, 20);
    printf("Travessia in-order apos remover 20: ");
    inOrder(root);
    printf("\n");

    printf("Removendo 30\n");
    root = deleteNode(root, 30);
    printf("Travessia in-order apos remover 30: ");
    inOrder(root);
    printf("\n");

    printf("Removendo 50\n");
    root = deleteNode(root, 50);
    printf("Travessia in-order apos remover 50: ");
    inOrder(root);
    printf("\n");

    return 0;
}
