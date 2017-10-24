#include <iostream>
#include <string>
#include "../../Common/SafeQueue.hpp"
#include "../../Common/Worker.hpp"
int main()
{
    SafeQueue<int> q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    while(!q.Empty()) {
        int value = 0;
        q.Dequeue(value);
        std::cout << value << std::endl;
    }
    return 0;
};
