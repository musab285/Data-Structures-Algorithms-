// Task 6: Consider a messaging application where users can send and receive messages. The application
// can only handle one message at a time, and each message can take a variable amount of time to send
// or receive. As messages arrive, they are added to a queue for processing. Once a message is completed,

// the next message in the queue is processed. What type of queue data structure would be most suitable
// for the given scenario?

#include <iostream>
#include <string>

using namespace std;

struct Message {
    int id;
    string content;
    Message* next;
    Message(int i = 0, const string& c = "") : id(i), content(c), next(nullptr) {}
};

class MessageQueue {
    Message* head;
    Message* tail;
public:
    MessageQueue() : head(nullptr), tail(nullptr) {}
    ~MessageQueue() {
        while (head) {
            Message* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    void enqueue(const string& content, int id) {
        Message* node = new Message(id, content);
        if (!tail) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    bool empty() const { return head == nullptr; }
    Message dequeue() {
        if (!head) return Message();
        Message node = Message(head->id, head->content);
        Message* tmp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete tmp;
        return node;
    }
};

int main() {
    MessageQueue q;
    q.enqueue("Hello, Alice", 1);
    q.enqueue("Hi, Bob", 2);
    q.enqueue("Goodbye", 3);
    while (!q.empty()) {
        Message m = q.dequeue();
        cout << "Processing message " << m.id << ": " << m.content << '\n';
    }
    return 0;
}