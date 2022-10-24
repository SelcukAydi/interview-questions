#include <iostream>

struct Node
{
    int key{0};
    Node* next{nullptr};
};

void insert(Node*& node, int key)
{
    if(node == nullptr)
    {
        node = new Node();
        node->key = key;
        return;
    }
    Node* tmp = node;
    while(tmp->next != nullptr) tmp = tmp->next;
    Node* new_node = new Node();
    new_node->key = key;
    tmp->next = new_node;
}

void printList(Node* node)
{
    while(node != nullptr)
    {
        std::cout << node->key << ' ';
        node = node->next;
    }

    std::puts("");
}

Node* solve(Node* first, Node* second)
{
    Node* ans = nullptr;
    Node* head = nullptr;
    Node* prev = nullptr;

    while(first != nullptr && second != nullptr)
    {
        ans = new Node();

        if(first->key <= second->key)
        {
            ans->key = first->key;
            first = first->next;
        }
        else
        {
            ans->key = second->key;
            second = second->next;
        }

        if(head == nullptr)
        {
            head = ans;
        }
        else
        {
            prev->next = ans;
        }

        prev = ans;
        ans = ans->next;
    }

    while(first != nullptr)
    {
        ans = new Node();
        ans->key = first->key;
        prev->next = ans;
        prev = ans;
        ans = ans->next;
        first = first->next;
    }

    while(second != nullptr)
    {
        ans = new Node();
        ans->key = second->key;
        prev->next = ans;
        prev = ans;
        ans = ans->next;
        second = second->next;
    }

    return head;
}

int main(int argc, char const *argv[])
{
    Node* first = nullptr, *second = nullptr;

    // Populate the first list.
    //
    insert(first, 1);
    insert(first, 3);
    insert(first, 5);
    insert(first, 8);

    // Populate the second list.
    //
    insert(second, 4);
    insert(second, 5);
    insert(second, 6);
    insert(second, 7);

    Node* merged = solve(first, second);
    printList(merged);

    return 0;
}
