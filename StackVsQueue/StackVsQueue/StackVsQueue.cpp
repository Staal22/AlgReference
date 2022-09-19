#include "PriorityQueue.h"
#include "Queue.h"
#include "Stack.h"

// Basic Stack and Queue implementation using Linkedlist principles
// This is really slow, not useful for most situations

int main()
{

    PriorityQueue priorityQueue{};
    for (int i = 0; i < 10; ++i) {
        priorityQueue.Enqueue(i,10 - i);
    }
    priorityQueue.Enqueue(33,3);
    priorityQueue.Dequeue();
    priorityQueue.Enqueue(124, 1000);
    priorityQueue.Enqueue(124, 100);
    priorityQueue.PrintList();
    
    /*
    std::cout << "STACK" << std::endl;
    
    Stack stack{};
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Pop();
    stack.Push(4);
    stack.PrintList();

    std::cout << '|' << std::endl;
    
    std::cout << "QUEUE" << std::endl;
    
    Queue queue{};
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Dequeue();
    queue.Enqueue(4);
    queue.PrintList();
    
    std::cout << '|' << std::endl;
    
    return 0;
*/
}
