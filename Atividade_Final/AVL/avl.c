#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore AVL
struct Node {
    int data;                // Valor armazenado no nó
    struct Node* left;       // Filho à esquerda
    struct Node* right;      // Filho à direita
    int height;              // Altura do nó
};

// Função para obter a altura de um nó
int height(struct Node* node) {
    return (node == NULL) ? 0 : node->height;
}

// Função para criar um novo nó com o valor fornecido
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // Nó recém-criado tem altura 1
    return node;
}

// Função para obter o fator de balanceamento de um nó
int getBalance(struct Node* node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

// Função para realizar uma rotação simples à direita
struct Node* rotateRight(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    // Atualiza as alturas
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;  // Nova raiz após a rotação
}

// Função para realizar uma rotação simples à esquerda
struct Node* rotateLeft(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    // Atualiza as alturas
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;  // Nova raiz após a rotação
}

// Função para inserir um valor na árvore AVL e balancear a árvore
struct Node* insert(struct Node* node, int data) {
    // Passo 1: Inserção normal como uma BST
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;  // Não permite duplicados
    }

    // Passo 2: Atualiza a altura do nó atual
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // Passo 3: Obtém o fator de balanceamento e verifica se o nó precisa ser balanceado
    int balance = getBalance(node);

    // Caso de rotação LL (Left Left)
    if (balance > 1 && data < node->left->data) {
        return rotateRight(node);
    }

    // Caso de rotação RR (Right Right)
    if (balance < -1 && data > node->right->data) {
        return rotateLeft(node);
    }

    // Caso de rotação LR (Left Right)
    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Caso de rotação RL (Right Left)
    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;  // Retorna o ponteiro (raiz) do nó não modificado
}

// Função para exibir a árvore em ordem crescente
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Inserindo valores na árvore AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Exibindo a árvore após balanceamento
    printf("Arvore AVL (in-order): ");
    inOrder(root);
    printf("\n");

    return 0;
}
