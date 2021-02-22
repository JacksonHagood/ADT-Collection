# include <iostream>

// templated implementation of the queue data type
// circular list where elements are added to the rear and removed from the front using a first-in, first-out convention

template<typename type>
class Queue {
    private:
        type* array; // templated dynamic array
        int capacity; // capacity variable
        int count; // count variable
        int front; // index of the front
        int rear; // index of the rear

        // resize function to double the capacity
        void resize() {
            // assign a new capacity
            if (capacity == 0) {
                capacity = 1;
            } else {
                capacity *= 2;
            }

            // allocate a new array and copy over elements
            type* temp = new type[capacity];

            for (int i = 0; i < count; i++) {
                temp[i] = array[i];
            }

            // resize the array
            delete[] array;
            array = temp;
        }
    public:
        // default constructor
        Queue() :
            array(nullptr),
            capacity(0),
            count(0),
            front(0),
            rear(0)
        {}

        // copy constructor
        Queue(const Queue& q) :
            array(),
            capacity(q.capacity),
            count(q.count),
            front(q.front),
            rear(q.rear)
        {
            // correctly allocate new array
            delete[] array;
            array = new type[capacity];

            // copy over elements
            for (int i = 0; i < q.count; i++) {
                array[i] = q.array[i];
            }
        }

        // copy assignment operator
        Queue& operator=(const Queue& q) {
            capacity = q.capacity;
            count = q.topIndex;
            front = q.front;
            rear = q.rear;

            // correctly allocate new array
            delete[] array;
            array = new type[capacity];

            // copy over elements
            for (int i = 0; i < q.count; i++) {
                array[i] = q.array[i];
            }

            return *this;
        }

        // destructor
        ~Queue() {
            delete[] array;
        }

        // enqueue operation (O(1) using armortized analysis)
        void enqueue(const type element) {
            // resize the array when the capacity is reached
            if (count == capacity) {
                resize();
            }

            // add the element to the rear using a circular array
            rear = (rear + 1) % capacity;
            array[rear] = element;
            count++;
        }

        // dequeue operation (O(1))
        type dequeue() {
            // check for an empty queue
            if (count == 0) {
                throw std::invalid_argument("Empty Queue");
            }

            // remove and return the front element using a circular array
            count--;
            type element = array[front];
            front = (front + 1) % capacity;
            return element;
        }

        // returns the next element (O(1))
        type next() {
            // check for an empty queue
            if (count == 0) {
                throw std::invalid_argument("Empty Queue");
            }

            return array[front];
        }

        // returns the size of the queue
        int size() const {
            return count;
        }

        // returns whether the queue is empty
        bool isEmpty() const {
            return count == 0;
        }
};