#ifndef QUEUE_H
#define QUEUE_H

class Customer {
private:
    long arrive; /*客户到达时间*/
    int processtime; /*客户需要使用机器的时间*/
public:
    Customer() {arrive = processtime = 0;};
    void set(long when);
    long when() const {return arrive;};
    int ptime() const {return processtime;};
};


typedef Customer Item;

class Queue{
    enum{Q_SIZE = 10};
private:
    struct Node{
        Item item;
        Node* next;
    };
    Node* front;
    Node* rear;
    int items;
    const int qsize;
    Queue(const Queue &) = delete;
    Queue & operator=(const Queue &) = delete;
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);
    bool dequeue(Item & item);
};

#endif