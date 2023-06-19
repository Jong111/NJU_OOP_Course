#include <iostream>
#include <stdexcept>

// 定义类模板，表示队列类
template <typename T>
class Queue {
public:
    // 定义默认构造函数，初始化队列的容量和大小
    Queue(int capacity = 10) : capacity(capacity), size(0), front(0), rear(0) {
        // 分配动态数组存储元素
        elements = new T[capacity];
    }

    // 定义拷贝构造函数，根据另一个队列对象初始化当前对象
    Queue(const Queue& queue) : capacity(queue.capacity), size(queue.size), front(queue.front), rear(queue.rear) {
        // 分配动态数组存储元素
        elements = new T[capacity];
        // 复制另一个队列对象的元素
        for (int i = 0; i < size; ++i) {
            elements[(front + i) % capacity] = queue.elements[(front + i) % capacity];
        }
    }

    // 定义拷贝赋值运算符，将另一个队列对象的值赋给当前对象
    Queue& operator=(const Queue& queue) {
        if (this != &queue) {
            // 释放当前对象的动态数组
            delete[] elements;
            // 重新分配动态数组存储元素
            capacity = queue.capacity;
            size = queue.size;
            front = queue.front;
            rear = queue.rear;
            elements = new T[capacity];
            // 复制另一个队列对象的元素
            for (int i = 0; i < size; ++i) {
                elements[(front + i) % capacity] = queue.elements[(front + i) % capacity];
            }
        }
        return *this;
    }

    // 定义移动构造函数，根据一个右值队列对象初始化当前对象
    Queue(Queue&& queue) noexcept : capacity(std::move(queue.capacity)), size(std::move(queue.size)), front(std::move(queue.front)), 
        rear(std::move(queue.rear)), elements(std::move(queue.elements)) {
        // 将右值队列对象的指针置空，避免析构时释放内存
        queue.elements = nullptr;
    }

    // 定义移动赋值运算符，将一个右值队列对象的值赋给当前对象
    Queue& operator=(Queue&& queue) noexcept {
        if (this != &queue) {
            // 释放当前对象的动态数组
            delete[] elements;
            // 移动右值队列对象的数据成员
            capacity = std::move(queue.capacity);
            size = std::move(queue.size);
            front = std::move(queue.front);
            rear = std::move(queue.rear);
            elements = std::move(queue.elements);
            // 将右值队列对象的指针置空，避免析构时释放内存
            queue.elements = nullptr;
        }
        return *this;
    }

    // 定义虚析构函数，释放动态数组
    ~Queue() {
        delete[] elements;
    }

    // 定义返回元素个数的函数
    int getSize() const {
        return size;
    }

    // 定义判断队列是否为空的函数
    bool isEmpty() const {
        return size == 0;
    }

    // 定义判断队列是否已满的函数
    bool isFull() const {
        return size == capacity;
    }

    // 定义入队函数，在队列的末尾插入元素，如果队列已满则抛出异常
    void enqueue(const T& element) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }
        elements[rear] = element;
        rear = (rear + 1) % capacity;
        ++size;
    }

    // 定义出队函数，在队列的开头删除元素，如果队列为空则抛出异常，返回被删除的元素
    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        T element = elements[front];
        front = (front + 1) % capacity;
        --size;
        return element;
    }

    // 定义获取队首元素的函数，如果队列为空则抛出异常，返回队首元素的引用
    T& getFront() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return elements[front];
    }

    // 定义获取队尾元素的函数，如果队列为空则抛出异常，返回队尾元素的引用
    T& getRear() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return elements[(rear - 1 + capacity) % capacity];
    }

    // 定义打印队列的函数，输出所有元素
    void print() const {
        std::cout << "[";
        for (int i = 0; i < size; ++i) {
            std::cout << elements[(front + i) % capacity];
            if (i < size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }

private:
    // 定义数据成员，表示队列的容量、大小、头部索引、尾部索引和元素数组
    int capacity;
    int size;
    int front;
    int rear;
    T* elements;
};

// 在main函数中测试队列的功能
int main() {
    // 创建一个队列对象，并入队一些元素
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    // 打印队列的元素个数和元素
    std::cout << "The size of the queue is " << queue.getSize() << "\n";
    std::cout << "The elements of the queue are ";
    queue.print();

    // 获取并打印队首和队尾的元素
    std::cout << "The front element of the queue is " << queue.getFront() << "\n";
    std::cout << "The rear element of the queue is " << queue.getRear() << "\n";

    // 出队一个元素，并打印被出队的元素和队列的元素
    int element = queue.dequeue();
    std::cout << "The element " << element << " is dequeued from the queue\n";
    std::cout << "The elements of the queue are ";
    queue.print();

    return 0;
}
