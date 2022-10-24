/**
 * Link: https://www.techiedelight.com/find-lowest-common-ancestor-lca-two-nodes-bst/
*/

#include <iostream>

struct Node
{
    int key{0};
    Node* left{nullptr};
    Node* right{nullptr};
};

int findLowestCommonAnchestor(Node* node, int x, int y)
{
    if(node == nullptr) return 0;

    if(x < node->key && y < node->key)
    {
        return findLowestCommonAnchestor(node->left, x, y);
    }
    else if(x > node->key && y > node->key)
    {
        return findLowestCommonAnchestor(node->right, x, y);
    }

    return node->key;
}

bool exists(Node* node, int key)
{
    if(node == nullptr) return false;
    if(node->key == key) return true;
    if(key < node->key) return exists(node->left, key);
    else return exists(node->right, key);
}

void insert(Node*& node, int key)
{
    if(node == nullptr)
    {
        node = new Node();
        node->key = key;
        return;
    }

    if(key < node->key) return insert(node->left, key);
    return insert(node->right, key);
}

void inorder(Node* root)
{
    if(root == nullptr) return;

    inorder(root->left);
    std::cout << root->key << ' ';
    inorder(root->right);
}

int solve(Node* node, int x, int y)
{
    if(!exists(node, x) || !exists(node, y)) return 0;
    return findLowestCommonAnchestor(node, x, y);
}

int main(int argc, char const *argv[])
{
    Node* root = nullptr;

    // Construct the left sub-tree.
    //
    insert(root, 15);
    insert(root, 10);
    insert(root, 8);
    insert(root, 12);
    insert(root, 6);
    insert(root, 9);

    // Construct the right sub-tree.
    //
    insert(root, 25);
    insert(root, 20);
    insert(root, 30);
    insert(root, 18);
    insert(root, 22);

    inorder(root);
    std::puts("");

    printf("LCA(%d, %d) = %d\n", 6, 12, solve(root, 6, 12));
    printf("LCA(%d, %d) = %d\n", 10, 12, solve(root, 10, 12));
    printf("LCA(%d, %d) = %d\n", 20, 6, solve(root, 20, 6));
    printf("LCA(%d, %d) = %d\n", 18, 22, solve(root, 18, 22));
    printf("LCA(%d, %d) = %d\n", 30, 30, solve(root, 30, 30));
    printf("LCA(%d, %d) = %d\n", 30, 1, solve(root, 30, 1));
    
    return 0;
}
