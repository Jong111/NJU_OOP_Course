#include <iostream>
#include <stdexcept>

// ������ģ�壬��ʾ������
template <typename T>
class Queue {
public:
    // ����Ĭ�Ϲ��캯������ʼ�����е������ʹ�С
    Queue(int capacity = 10) : capacity(capacity), size(0), front(0), rear(0) {
        // ���䶯̬����洢Ԫ��
        elements = new T[capacity];
    }

    // ���忽�����캯����������һ�����ж����ʼ����ǰ����
    Queue(const Queue& queue) : capacity(queue.capacity), size(queue.size), front(queue.front), rear(queue.rear) {
        // ���䶯̬����洢Ԫ��
        elements = new T[capacity];
        // ������һ�����ж����Ԫ��
        for (int i = 0; i < size; ++i) {
            elements[(front + i) % capacity] = queue.elements[(front + i) % capacity];
        }
    }

    // ���忽����ֵ�����������һ�����ж����ֵ������ǰ����
    Queue& operator=(const Queue& queue) {
        if (this != &queue) {
            // �ͷŵ�ǰ����Ķ�̬����
            delete[] elements;
            // ���·��䶯̬����洢Ԫ��
            capacity = queue.capacity;
            size = queue.size;
            front = queue.front;
            rear = queue.rear;
            elements = new T[capacity];
            // ������һ�����ж����Ԫ��
            for (int i = 0; i < size; ++i) {
                elements[(front + i) % capacity] = queue.elements[(front + i) % capacity];
            }
        }
        return *this;
    }

    // �����ƶ����캯��������һ����ֵ���ж����ʼ����ǰ����
    Queue(Queue&& queue) noexcept : capacity(std::move(queue.capacity)), size(std::move(queue.size)), front(std::move(queue.front)), 
        rear(std::move(queue.rear)), elements(std::move(queue.elements)) {
        // ����ֵ���ж����ָ���ÿգ���������ʱ�ͷ��ڴ�
        queue.elements = nullptr;
    }

    // �����ƶ���ֵ���������һ����ֵ���ж����ֵ������ǰ����
    Queue& operator=(Queue&& queue) noexcept {
        if (this != &queue) {
            // �ͷŵ�ǰ����Ķ�̬����
            delete[] elements;
            // �ƶ���ֵ���ж�������ݳ�Ա
            capacity = std::move(queue.capacity);
            size = std::move(queue.size);
            front = std::move(queue.front);
            rear = std::move(queue.rear);
            elements = std::move(queue.elements);
            // ����ֵ���ж����ָ���ÿգ���������ʱ�ͷ��ڴ�
            queue.elements = nullptr;
        }
        return *this;
    }

    // �����������������ͷŶ�̬����
    ~Queue() {
        delete[] elements;
    }

    // ���巵��Ԫ�ظ����ĺ���
    int getSize() const {
        return size;
    }

    // �����ж϶����Ƿ�Ϊ�յĺ���
    bool isEmpty() const {
        return size == 0;
    }

    // �����ж϶����Ƿ������ĺ���
    bool isFull() const {
        return size == capacity;
    }

    // ������Ӻ������ڶ��е�ĩβ����Ԫ�أ���������������׳��쳣
    void enqueue(const T& element) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }
        elements[rear] = element;
        rear = (rear + 1) % capacity;
        ++size;
    }

    // ������Ӻ������ڶ��еĿ�ͷɾ��Ԫ�أ��������Ϊ�����׳��쳣�����ر�ɾ����Ԫ��
    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        T element = elements[front];
        front = (front + 1) % capacity;
        --size;
        return element;
    }

    // �����ȡ����Ԫ�صĺ������������Ϊ�����׳��쳣�����ض���Ԫ�ص�����
    T& getFront() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return elements[front];
    }

    // �����ȡ��βԪ�صĺ������������Ϊ�����׳��쳣�����ض�βԪ�ص�����
    T& getRear() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return elements[(rear - 1 + capacity) % capacity];
    }

    // �����ӡ���еĺ������������Ԫ��
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
    // �������ݳ�Ա����ʾ���е���������С��ͷ��������β��������Ԫ������
    int capacity;
    int size;
    int front;
    int rear;
    T* elements;
};

// ��main�����в��Զ��еĹ���
int main() {
    // ����һ�����ж��󣬲����һЩԪ��
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    // ��ӡ���е�Ԫ�ظ�����Ԫ��
    std::cout << "The size of the queue is " << queue.getSize() << "\n";
    std::cout << "The elements of the queue are ";
    queue.print();

    // ��ȡ����ӡ���׺Ͷ�β��Ԫ��
    std::cout << "The front element of the queue is " << queue.getFront() << "\n";
    std::cout << "The rear element of the queue is " << queue.getRear() << "\n";

    // ����һ��Ԫ�أ�����ӡ�����ӵ�Ԫ�غͶ��е�Ԫ��
    int element = queue.dequeue();
    std::cout << "The element " << element << " is dequeued from the queue\n";
    std::cout << "The elements of the queue are ";
    queue.print();

    return 0;
}
