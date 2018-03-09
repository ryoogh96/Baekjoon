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
    pos--; // Push 하면 다음 값을 위해 1이 올라있는 상태다.
    heap[0] = heap[pos];

    int parentPos = 0;
    while (true) {
        int leftPos = parentPos * 2 + 1;
        int rightPos = leftPos + 1;
        if (leftPos >= pos) break; // 왼쪽의 Node 가 뺀 노드였다면
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
// 출처: http://blog.eairship.kr/249?category=431859 [누구나가 다 이해할 수 있는 프로그래밍 첫걸음]
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
    // 여기서 usedPos번 인덱스에 위치한 노드의 부모 노드가 위치한 인덱스는 (usedPos - 1) / 2의 몫입니다.
    // 만약 5번 인덱스에 위치한 노드의 부모 노드가 위치한 인덱스를 구하고 싶다면, (5 - 1) / 2의 몫으로 2번 인덱스에 위치함을 알 수 있습니다.
    long long parentPos = (long long) ((usedPos - 1) / 2);
    // 사용 용량과 최대 용량이 똑같을 경우 힙이 가득 찼다는 것이므로 함수를 끝냅니다.
    if (usedsize == capacity) {
        printf("힙이 가득 찼습니다.\n");
        return;
    }

    // 배열의 마지막에 데이터를 집어 넣습니다.
    heap[usedsize] = data;
    // 부모 노드의 값이 자식 노드의 값보다 클 경우
    while (usedPos > 0 && heap[usedPos] < heap[parentPos]) {
        //부모 노드와 자식 노드를 서로 교환합니다.
        Swap(&heap[usedPos], &heap[parentPos]);
        // 그리고 현재 위치는 부모 노드의 위치입니다.
        usedPos = parentPos;
        // 부모 노드의 위치를 다시 구합니다.
        parentPos = (long long) ((usedPos - 1) / 2);
    }
    // 사용 용량을 1 증가시킵니다.
    usedsize++;
}

long long Heap::extractMin() {
    // 사용 용량이 0인 것은 힙이 비어있다는 것으로, 함수를 종료합니다.
    if (usedsize == 0) return 0;
    // 루트 노드의 인덱스는 0, 왼쪽 자식 노드의 인덱스는 1, 오른쪽 자식 노드의 인덱스는 2로 초기화 합니다.
    long long parentPos = 0, leftPos = 1, rightPos = 2;

    // 루트 노드를 비웁니다.
    heap[0] = NULL;
    // 사용 용량이 줄어들었으므로 1을 감소시킵니다.
    usedsize--;
    // 루트 노드가 있던 자리에 마지막에 있던 노드를 이동시킵니다.
    Swap(&heap[0], &heap[usedsize]);
    // 무한 루프에 빠집니다.
    while (true) {
        //선택된 자식 노드의 인덱스를 0으로 초기화 시킨다.
        long long selectChild = 0;

        // 왼쪽 자식 노드의 인덱스가 사용 용량과 같거나 크다면 루프르 빠져나온다.
        if (leftPos >= usedsize) return heap[leftPos];
        // 오른쪽 자식 노드의 인덱스가 사용 용량과 같거나 크다면 선택된 자식 노드의 인덱스는 왼쪽 자식 노드의 인덱스다.
        if (rightPos >= usedsize) selectChild = leftPos;
        // 오른쪽 자식 노드의 인덱스가 사용 용량보다 작을 경우
        else {
            // 왼쪽 자식 노드의 값이 오른쪽 자식 노드의 값보다 크다면 선택된 자식 노드의 인덱스는 오른쪽 노드의 인덱스다.
            if (heap[leftPos] > heap[rightPos]) selectChild = rightPos;
            // 그 반대의 경우는 선택된 자식 노드의 인덱스가 왼쪽 노드의 인덱스다.
            else selectChild = leftPos;
        }

        // 부모 노드가 선택된 자식 노드보다 클 경우
        if (heap[selectChild] < heap[parentPos]) {
            // 부모 노드와 선택된 자식 노드를 서로 교환한다.
            Swap(&heap[parentPos], &heap[selectChild]);
            // 부모 노드의 인덱스는 선택된 자식 노드의 인덱스이다.
            parentPos = selectChild;
        }
        // 부모 노드가 선택된 자식 노드보다 작을 경우 루프를 탈출한다.
        else return heap[parentPos];

        // 왼쪽 자식 노드의 인덱스를 구해온다.
        leftPos = 2 * parentPos + 1;
        // 오른쪽 자식 노드의 인덱스는 왼쪽 자식 노드의 인덱스에 1을 더한것과 같다.
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

