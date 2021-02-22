# include "stack.h"
# include "queue.h"

using std::cout;

int main() {
    // Stack tests
    cout << "Stack tests\n";

    Stack <int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    cout << stack1.pop() << "\n";
    cout << stack1.pop() << "\n";
    cout << stack1.top() << "\n";

    // Queue tests
    cout << "Queue tests\n";

    Queue <int> queue1;
    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(3);

    cout << queue1.dequeue() << "\n";
    cout << queue1.dequeue() << "\n";
    cout << queue1.dequeue() << "\n";

    queue1.enqueue(4);
    queue1.enqueue(5);
    queue1.enqueue(6);

    cout << queue1.next() << "\n";
    cout << queue1.dequeue() << "\n";
    cout << queue1.dequeue() << "\n";
    cout << queue1.dequeue() << "\n";

    return 0;
}