//#include <iostream>
//#include <stdexcept>
//
//// �������Ա���
//class LinearList {
//public:
//    // ����Ĭ�Ϲ��캯������ʼ�����Ա�������ʹ�С
//    LinearList(int capacity = 10) : capacity(capacity), size(0) {
//        // ���䶯̬����洢Ԫ��
//        elements = new int[capacity];
//    }
//
//    // ���忽�����캯����������һ�����Ա�����ʼ����ǰ����
//    LinearList(const LinearList& list) : capacity(list.capacity), size(list.size) {
//        // ���䶯̬����洢Ԫ��
//        elements = new int[capacity];
//        // ������һ�����Ա�����Ԫ��
//        for (int i = 0; i < size; ++i) {
//            elements[i] = list.elements[i];
//        }
//    }
//
//    // ���忽����ֵ�����������һ�����Ա�����ֵ������ǰ����
//    LinearList& operator=(const LinearList& list) {
//        if (this != &list) {
//            // �ͷŵ�ǰ����Ķ�̬����
//            delete[] elements;
//            // ���·��䶯̬����洢Ԫ��
//            capacity = list.capacity;
//            size = list.size;
//            elements = new int[capacity];
//            // ������һ�����Ա�����Ԫ��
//            for (int i = 0; i < size; ++i) {
//                elements[i] = list.elements[i];
//            }
//        }
//        return *this;
//    }
//
//    // �����ƶ����캯��������һ����ֵ���Ա�����ʼ����ǰ����
//    LinearList(LinearList&& list) noexcept : capacity(std::move(list.capacity)), size(std::move(list.size)), elements(std::move(list.elements)) {
//        // ����ֵ���Ա�����ָ���ÿգ���������ʱ�ͷ��ڴ�
//        list.elements = nullptr;
//    }
//
//    // �����ƶ���ֵ���������һ����ֵ���Ա�����ֵ������ǰ����
//    LinearList& operator=(LinearList&& list) noexcept {
//        if (this != &list) {
//            // �ͷŵ�ǰ����Ķ�̬����
//            delete[] elements;
//            // �ƶ���ֵ���Ա��������ݳ�Ա
//            capacity = std::move(list.capacity);
//            size = std::move(list.size);
//            elements = std::move(list.elements);
//            // ����ֵ���Ա�����ָ���ÿգ���������ʱ�ͷ��ڴ�
//            list.elements = nullptr;
//        }
//        return *this;
//    }
//
//    // �����������������ͷŶ�̬����
//    virtual ~LinearList() {
//        delete[] elements;
//    }
//
//    // ���巵��Ԫ�ظ����ĺ���
//    int getSize() const {
//        return size;
//    }
//
//    // �������Ԫ�ط���λ�õĺ���������Ҳ����򷵻�-1
//    int find(int element) const {
//        for (int i = 0; i < size; ++i) {
//            if (elements[i] == element) {
//                return i;
//            }
//        }
//        return -1;
//    }
//
//    // ������ָ��λ�ò���Ԫ�صĺ��������λ����Ч���׳��쳣
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
//    // ������ָ��λ��ɾ��Ԫ�صĺ��������λ����Ч���׳��쳣�����ر�ɾ����Ԫ��
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
//    // �����ӡ���Ա�ĺ������������Ԫ��
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
//    // ������չ�����ĺ������������ӱ�������ԭ��Ԫ��
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
//    // �������ݳ�Ա����ʾ���Ա����������С��Ԫ������
//    int capacity;
//    int size;
//    int* elements;
//};
//
//// ��������࣬�̳������Ա���
//class Queue : public LinearList {
//public:
//    // ����Ĭ�Ϲ��캯�������û���Ĺ��캯��
//    Queue(int capacity = 10) : LinearList(capacity) {}
//
//    // ���忽�����캯�������û���Ŀ������캯��
//    Queue(const Queue& queue) : LinearList(queue) {}
//
//    // ���忽����ֵ����������û���Ŀ�����ֵ�����
//    Queue& operator=(const Queue& queue) {
//        LinearList::operator=(queue);
//        return *this;
//    }
//
//    // �����ƶ����캯�������û�����ƶ����캯��
//    Queue(Queue&& queue) noexcept : LinearList(std::move(queue)) {}
//
//    // �����ƶ���ֵ����������û�����ƶ���ֵ�����
//    Queue& operator=(Queue&& queue) noexcept {
//        LinearList::operator=(std::move(queue));
//        return *this;
//    }
//
//    // ���������������������κβ���
//    ~Queue() override {}
//
//    // ������Ӻ����������Ա��ĩβ����Ԫ��
//    void enqueue(int element) {
//        insert(size, element);
//    }
//
//    // ������Ӻ����������Ա�Ŀ�ͷɾ��Ԫ�أ����ر�ɾ����Ԫ��
//    int dequeue() {
//        return remove(0);
//    }
//};
//
//// ��main�����в������Ա�Ͷ��еĹ���
//int main() {
//    // ����һ�����Ա���󣬲�����һЩԪ��
//    LinearList list;
//    list.insert(0, 1);
//    list.insert(1, 2);
//    list.insert(2, 3);
//    list.insert(3, 4);
//
//    // ��ӡ���Ա��Ԫ�ظ�����Ԫ��
//    std::cout << "The size of the list is " << list.getSize() << "\n";
//    std::cout << "The elements of the list are ";
//    list.print();
//
//    // ����һ��Ԫ�أ�����ҵ������λ�ã�����Ҳ����������ʾ��Ϣ
//    int element = 3;
//    int index = list.find(element);
//    if (index != -1) {
//        std::cout << "The element " << element << " is found at index " << index << "\n";
//    }
//    else {
//        std::cout << "The element " << element << " is not found in the list\n";
//    }
//
//    // ɾ��һ��Ԫ�أ�����ӡ��ɾ����Ԫ�غ����Ա��Ԫ��
//    element = list.remove(1);
//    std::cout << "The element " << element << " is removed from the list\n";
//    std::cout << "The elements of the list are ";
//    list.print();
//
//    // ����һ�����ж��󣬲����һЩԪ��
//    Queue queue;
//    queue.enqueue(5);
//    queue.enqueue(6);
//    queue.enqueue(7);
//    queue.enqueue(8);
//
//    // ��ӡ���е�Ԫ�ظ�����Ԫ��
//    std::cout << "The size of the queue is " << queue.getSize() << "\n";
//    std::cout << "The elements of the queue are ";
//    queue.print();
//
//    // ����һ��Ԫ�أ�����ӡ�����ӵ�Ԫ�غͶ��е�Ԫ��
//    element = queue.dequeue();
//    std::cout << "The element " << element << " is dequeued from the queue\n";
//    std::cout << "The elements of the queue are ";
//    queue.print();
//
//    return 0;
//}
//
