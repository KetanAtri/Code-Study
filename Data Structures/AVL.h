using std::max;

struct Node{
    int key, height;
    Node* left, *right;
};

int height(Node* node)
{
    if(!node) return 0;
    return node->height;
}

int getBalance(Node* node)
{
    if(!node) return 0;
    return height(node->left) - height(node->right);
}

Node* newNode(int key)
{
    Node* node = (Node*)(malloc(sizeof(Node)));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}

Node* insertNode(Node* node, int key)
{
    if(!node) return newNode(key);
    if(key < node->key) node->left = insertNode(node->left, key);
    else if(key > node->key) node->right = insertNode(node->right, key);
    else return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if(balance>1 && key < node->left->key)
        return rightRotate(node);
    if(balance<-1 && key > node->right->key)
        return leftRotate(node);
    if(balance>1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance<-1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
