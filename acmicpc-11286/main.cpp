#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// solution by http://ksh-code.tistory.com/149
int heap[100001], pos;

int abs(int a) {
    if (a < 0) return -a;
    return a;
}

void push (int number) {
    int curPos = pos;
    heap[curPos] = number;
    int parentPos = (curPos - 1) / 2;
    while (curPos > 0 && (abs(heap[parentPos]) > abs(heap[curPos]) || (abs(heap[parentPos]) == abs(heap[curPos]) && heap[curPos] <= heap[parentPos]))) {
        int temp = heap[curPos];
        heap[curPos] = heap[parentPos];
        heap[parentPos] = temp;
        curPos = parentPos;
        parentPos = (curPos - 1) / 2;
    }
    pos++;
}
int pop () {
    if (pos == 0) return 0;
    int result = heap[0];
    pos--; // Push �ϸ� ���� ���� ���� 1�� �ö��ִ� ���´�.
    heap[0] = heap[pos];

    int parentPos = 0;
    while (true) {
        int leftPos = parentPos * 2 + 1;
        int rightPos = leftPos + 1;
        if (leftPos >= pos) break; // ������ Node �� �� ��忴�ٸ�
        int temp = heap[parentPos];
        if ((rightPos >= pos || abs(heap[leftPos]) < abs(heap[parentPos]) || (abs(heap[leftPos]) == abs(heap[parentPos]) && heap[leftPos] <= heap[parentPos])) && (abs(heap[rightPos]) > abs(heap[leftPos]) || (abs(heap[rightPos]) == abs(heap[leftPos]) && heap[leftPos] < heap[rightPos]))) {
            heap[parentPos] = heap[leftPos];
            heap[leftPos] = temp;
            parentPos = leftPos;
        } else if ((abs(heap[rightPos]) == abs(heap[parentPos]) && heap[rightPos] <= heap[parentPos]) || abs(heap[rightPos]) < abs(heap[parentPos])) {
            heap[parentPos] = heap[rightPos];
            heap[rightPos] = temp;
            parentPos = rightPos;
        } else {
            break;
        }
    }
    return result;
}

int main() {
    int capacity;
    scanf("%d", &capacity);
    while(capacity--) {
        int number;
        scanf("%d", &number);
        if(number) push(number);
        else printf("%d\n", pop());
    }
}


/*
// ��ó: http://blog.eairship.kr/249?category=431859 [�������� �� ������ �� �ִ� ���α׷��� ù����]
class Heap {
private:
    long long *heap;
    long long capacity;
    long long usedsize;

public:
    Heap(long long Capacity);
    ~Heap();
    void Insert(long long data);
    long long extractMin();
    void Swap(long long* a, long long* b);
};

Heap::Heap(long long Capacity) : capacity(Capacity) {
    heap = new long long[Heap::capacity];
    usedsize = 0;
}

Heap::~Heap() {
    delete[] heap;
}

void Heap::Swap(long long* a, long long* b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

void Heap::Insert(long long data) {
    long long usedPos = usedsize;
    // ���⼭ usedPos�� �ε����� ��ġ�� ����� �θ� ��尡 ��ġ�� �ε����� (usedPos - 1) / 2�� ���Դϴ�.
    // ���� 5�� �ε����� ��ġ�� ����� �θ� ��尡 ��ġ�� �ε����� ���ϰ� �ʹٸ�, (5 - 1) / 2�� ������ 2�� �ε����� ��ġ���� �� �� �ֽ��ϴ�.
    long long parentPos = (long long) ((usedPos - 1) / 2);
    // ��� �뷮�� �ִ� �뷮�� �Ȱ��� ��� ���� ���� á�ٴ� ���̹Ƿ� �Լ��� �����ϴ�.
    if (usedsize == capacity) {
        printf("���� ���� á���ϴ�.\n");
        return;
    }

    // �迭�� �������� �����͸� ���� �ֽ��ϴ�.
    heap[usedsize] = data;
    // �θ� ����� ���� �ڽ� ����� ������ Ŭ ���
    while (usedPos > 0 && heap[usedPos] < heap[parentPos]) {
        //�θ� ���� �ڽ� ��带 ���� ��ȯ�մϴ�.
        Swap(&heap[usedPos], &heap[parentPos]);
        // �׸��� ���� ��ġ�� �θ� ����� ��ġ�Դϴ�.
        usedPos = parentPos;
        // �θ� ����� ��ġ�� �ٽ� ���մϴ�.
        parentPos = (long long) ((usedPos - 1) / 2);
    }
    // ��� �뷮�� 1 ������ŵ�ϴ�.
    usedsize++;
}

long long Heap::extractMin() {
    // ��� �뷮�� 0�� ���� ���� ����ִٴ� ������, �Լ��� �����մϴ�.
    if (usedsize == 0) return 0;
    // ��Ʈ ����� �ε����� 0, ���� �ڽ� ����� �ε����� 1, ������ �ڽ� ����� �ε����� 2�� �ʱ�ȭ �մϴ�.
    long long parentPos = 0, leftPos = 1, rightPos = 2;

    // ��Ʈ ��带 ���ϴ�.
    heap[0] = NULL;
    // ��� �뷮�� �پ������Ƿ� 1�� ���ҽ�ŵ�ϴ�.
    usedsize--;
    // ��Ʈ ��尡 �ִ� �ڸ��� �������� �ִ� ��带 �̵���ŵ�ϴ�.
    Swap(&heap[0], &heap[usedsize]);
    // ���� ������ �����ϴ�.
    while (true) {
        //���õ� �ڽ� ����� �ε����� 0���� �ʱ�ȭ ��Ų��.
        long long selectChild = 0;

        // ���� �ڽ� ����� �ε����� ��� �뷮�� ���ų� ũ�ٸ� ������ �������´�.
        if (leftPos >= usedsize) return heap[leftPos];
        // ������ �ڽ� ����� �ε����� ��� �뷮�� ���ų� ũ�ٸ� ���õ� �ڽ� ����� �ε����� ���� �ڽ� ����� �ε�����.
        if (rightPos >= usedsize) selectChild = leftPos;
        // ������ �ڽ� ����� �ε����� ��� �뷮���� ���� ���
        else {
            // ���� �ڽ� ����� ���� ������ �ڽ� ����� ������ ũ�ٸ� ���õ� �ڽ� ����� �ε����� ������ ����� �ε�����.
            if (heap[leftPos] > heap[rightPos]) selectChild = rightPos;
            // �� �ݴ��� ���� ���õ� �ڽ� ����� �ε����� ���� ����� �ε�����.
            else selectChild = leftPos;
        }

        // �θ� ��尡 ���õ� �ڽ� ��庸�� Ŭ ���
        if (heap[selectChild] < heap[parentPos]) {
            // �θ� ���� ���õ� �ڽ� ��带 ���� ��ȯ�Ѵ�.
            Swap(&heap[parentPos], &heap[selectChild]);
            // �θ� ����� �ε����� ���õ� �ڽ� ����� �ε����̴�.
            parentPos = selectChild;
        }
        // �θ� ��尡 ���õ� �ڽ� ��庸�� ���� ��� ������ Ż���Ѵ�.
        else return heap[parentPos];

        // ���� �ڽ� ����� �ε����� ���ؿ´�.
        leftPos = 2 * parentPos + 1;
        // ������ �ڽ� ����� �ε����� ���� �ڽ� ����� �ε����� 1�� ���ѰͰ� ����.
        rightPos = leftPos + 1;
    }
}

int main()
{
    long long maxSize = 100001;
    int n;
    long long x;
    Heap heap(100001);
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {


        scanf("%lld", &x);
        if(x == 0) {
            printf("%lld\n", heap.extractMin());
        }
        else heap.Insert(x);

    }
    heap.~Heap();

    return 0;
}
*/

