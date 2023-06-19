//#include <iostream>
//#include <stdexcept>
//
//// 定义线性表类
//class LinearList {
//public:
//    // 定义默认构造函数，初始化线性表的容量和大小
//    LinearList(int capacity = 10) : capacity(capacity), size(0) {
//        // 分配动态数组存储元素
//        elements = new int[capacity];
//    }
//
//    // 定义拷贝构造函数，根据另一个线性表对象初始化当前对象
//    LinearList(const LinearList& list) : capacity(list.capacity), size(list.size) {
//        // 分配动态数组存储元素
//        elements = new int[capacity];
//        // 复制另一个线性表对象的元素
//        for (int i = 0; i < size; ++i) {
//            elements[i] = list.elements[i];
//        }
//    }
//
//    // 定义拷贝赋值运算符，将另一个线性表对象的值赋给当前对象
//    LinearList& operator=(const LinearList& list) {
//        if (this != &list) {
//            // 释放当前对象的动态数组
//            delete[] elements;
//            // 重新分配动态数组存储元素
//            capacity = list.capacity;
//            size = list.size;
//            elements = new int[capacity];
//            // 复制另一个线性表对象的元素
//            for (int i = 0; i < size; ++i) {
//                elements[i] = list.elements[i];
//            }
//        }
//        return *this;
//    }
//
//    // 定义移动构造函数，根据一个右值线性表对象初始化当前对象
//    LinearList(LinearList&& list) noexcept : capacity(std::move(list.capacity)), size(std::move(list.size)), elements(std::move(list.elements)) {
//        // 将右值线性表对象的指针置空，避免析构时释放内存
//        list.elements = nullptr;
//    }
//
//    // 定义移动赋值运算符，将一个右值线性表对象的值赋给当前对象
//    LinearList& operator=(LinearList&& list) noexcept {
//        if (this != &list) {
//            // 释放当前对象的动态数组
//            delete[] elements;
//            // 移动右值线性表对象的数据成员
//            capacity = std::move(list.capacity);
//            size = std::move(list.size);
//            elements = std::move(list.elements);
//            // 将右值线性表对象的指针置空，避免析构时释放内存
//            list.elements = nullptr;
//        }
//        return *this;
//    }
//
//    // 定义虚析构函数，释放动态数组
//    virtual ~LinearList() {
//        delete[] elements;
//    }
//
//    // 定义返回元素个数的函数
//    int getSize() const {
//        return size;
//    }
//
//    // 定义查找元素返回位置的函数，如果找不到则返回-1
//    int find(int element) const {
//        for (int i = 0; i < size; ++i) {
//            if (elements[i] == element) {
//                return i;
//            }
//        }
//        return -1;
//    }
//
//    // 定义在指定位置插入元素的函数，如果位置无效则抛出异常
//    void insert(int index, int element) {
//        if (index < 0 || index > size) {
//            throw std::out_of_range("Invalid index");
//        }
//        if (size == capacity) {
//            expand();
//        }
//        for (int i = size - 1; i >= index; --i) {
//            elements[i + 1] = elements[i];
//        }
//        elements[index] = element;
//        ++size;
//    }
//
//    // 定义在指定位置删除元素的函数，如果位置无效则抛出异常，返回被删除的元素
//    int remove(int index) {
//        if (index < 0 || index >= size) {
//            throw std::out_of_range("Invalid index");
//        }
//        int element = elements[index];
//        for (int i = index + 1; i < size; ++i) {
//            elements[i - 1] = elements[i];
//        }
//        --size;
//        return element;
//    }
//
//    // 定义打印线性表的函数，输出所有元素
//    void print() const {
//        std::cout << "[";
//        for (int i = 0; i < size; ++i) {
//            std::cout << elements[i];
//            if (i < size - 1) {
//                std::cout << ", ";
//            }
//        }
//        std::cout << "]\n";
//    }
//
//protected:
//    // 定义扩展容量的函数，将容量加倍并复制原有元素
//    void expand() {
//        capacity *= 2;
//        int* newElements = new int[capacity];
//        for (int i = 0; i < size; ++i) {
//            newElements[i] = elements[i];
//        }
//        delete[] elements;
//        elements = newElements;
//    }
//
//    // 定义数据成员，表示线性表的容量、大小和元素数组
//    int capacity;
//    int size;
//    int* elements;
//};
//
//// 定义队列类，继承自线性表类
//class Queue : public LinearList {
//public:
//    // 定义默认构造函数，调用基类的构造函数
//    Queue(int capacity = 10) : LinearList(capacity) {}
//
//    // 定义拷贝构造函数，调用基类的拷贝构造函数
//    Queue(const Queue& queue) : LinearList(queue) {}
//
//    // 定义拷贝赋值运算符，调用基类的拷贝赋值运算符
//    Queue& operator=(const Queue& queue) {
//        LinearList::operator=(queue);
//        return *this;
//    }
//
//    // 定义移动构造函数，调用基类的移动构造函数
//    Queue(Queue&& queue) noexcept : LinearList(std::move(queue)) {}
//
//    // 定义移动赋值运算符，调用基类的移动赋值运算符
//    Queue& operator=(Queue&& queue) noexcept {
//        LinearList::operator=(std::move(queue));
//        return *this;
//    }
//
//    // 定义虚析构函数，不做任何操作
//    ~Queue() override {}
//
//    // 定义入队函数，在线性表的末尾插入元素
//    void enqueue(int element) {
//        insert(size, element);
//    }
//
//    // 定义出队函数，在线性表的开头删除元素，返回被删除的元素
//    int dequeue() {
//        return remove(0);
//    }
//};
//
//// 在main函数中测试线性表和队列的功能
//int main() {
//    // 创建一个线性表对象，并插入一些元素
//    LinearList list;
//    list.insert(0, 1);
//    list.insert(1, 2);
//    list.insert(2, 3);
//    list.insert(3, 4);
//
//    // 打印线性表的元素个数和元素
//    std::cout << "The size of the list is " << list.getSize() << "\n";
//    std::cout << "The elements of the list are ";
//    list.print();
//
//    // 查找一个元素，如果找到则输出位置，如果找不到则输出提示信息
//    int element = 3;
//    int index = list.find(element);
//    if (index != -1) {
//        std::cout << "The element " << element << " is found at index " << index << "\n";
//    }
//    else {
//        std::cout << "The element " << element << " is not found in the list\n";
//    }
//
//    // 删除一个元素，并打印被删除的元素和线性表的元素
//    element = list.remove(1);
//    std::cout << "The element " << element << " is removed from the list\n";
//    std::cout << "The elements of the list are ";
//    list.print();
//
//    // 创建一个队列对象，并入队一些元素
//    Queue queue;
//    queue.enqueue(5);
//    queue.enqueue(6);
//    queue.enqueue(7);
//    queue.enqueue(8);
//
//    // 打印队列的元素个数和元素
//    std::cout << "The size of the queue is " << queue.getSize() << "\n";
//    std::cout << "The elements of the queue are ";
//    queue.print();
//
//    // 出队一个元素，并打印被出队的元素和队列的元素
//    element = queue.dequeue();
//    std::cout << "The element " << element << " is dequeued from the queue\n";
//    std::cout << "The elements of the queue are ";
//    queue.print();
//
//    return 0;
//}
//
