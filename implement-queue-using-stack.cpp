#include <iostream>
#include <stack>

/**
 * Dequeue constly queue implementation using two stacks.
*/
template<typename T>
class CustomQueue
{
    public:
    CustomQueue() = default;
    void enqueue(T val);
    T dequeue();
    bool empty();

    private:
    std::stack<T> m_primary_stack;
    std::stack<T> m_secondary_stack;
};

template<typename T>
void CustomQueue<T>::enqueue(T val)
{
    m_primary_stack.push(val);
}

template<typename T>
T CustomQueue<T>::dequeue()
{
    // Move everything from primary to seconday.
    //
    while(!m_primary_stack.empty())
    {
        m_secondary_stack.push(m_primary_stack.top());
        m_primary_stack.pop();
    }

    // Pop the top item in the stack. It is the first item in the queue.
    //
    T ans = m_secondary_stack.top();
    m_secondary_stack.pop();

    // Move back everything from seconday to primary.
    //
    while(!m_secondary_stack.empty())
    {
        m_primary_stack.push(m_secondary_stack.top());
        m_secondary_stack.pop();
    }

    return ans;
}

template<typename T>
bool CustomQueue<T>::empty()
{
    return m_primary_stack.empty();
}

int main(int argc, char const *argv[])
{
    CustomQueue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    while(!q.empty())
    {
        std::cout << q.dequeue() << ' ';
    }

    std::puts("");


    return 0;
}
