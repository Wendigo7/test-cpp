#include <iostream>
#include <stdexcept>
class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int d, Node* n) : data(d), next(n) {}
    };
    Node* top_;
public:
    Stack() : top_(nullptr) {}
    ~Stack() {
        while (top_) {
            Node* tmp = top_;
            top_ = top_->next;
            delete tmp;
        }
    }
    void push(int value) {
        top_ = new Node(value, top_);
    }
    int pop() {
        if (isEmpty()) throw std::runtime_error("pop from empty stack");
        int value = top_->data;
        Node* tmp = top_;
        top_ = top_->next;
        delete tmp;
        return value;
    }
    int peek() const {
        if (isEmpty()) throw std::runtime_error("peek from empty stack");
        return top_->data;
    }
    bool isEmpty() const {
        return top_ == nullptr;
    }
};
int main() {
    Stack s;
    for (int i = 1; i <= 5; ++i) s.push(i);
    while (!s.isEmpty()) {
        std::cout << s.pop() << '\n';
    }
    return 0;
}
