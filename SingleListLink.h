struct Node {
    Census *data;
    Node *next;
};

class SingleLinkedListIterator {
public:

    SingleLinkedListIterator(Node *ptr) : m_ptr(ptr) {}


    SingleLinkedListIterator &operator++() {
        m_ptr = m_ptr->next;
        return *this;
    }

    bool operator!=(const SingleLinkedListIterator &it) {
        return m_ptr != it.m_ptr;
    }

    bool operator==(const SingleLinkedListIterator &it) {
        return m_ptr == it.m_ptr;
    }

    Census* operator*() {
        return m_ptr->data;
    }

    Node *GetNode() {
        return m_ptr;
    }


private:
    Node *m_ptr;
};

class SingleLinkedList {
public:

    SingleLinkedList() : first(nullptr), last(nullptr) {}

    ~SingleLinkedList() {
        DeleteList();
    }

    void PushBack(Census* x) {
        Node *newNode = new Node;
        newNode->data = x;

        if (first == nullptr) {
            first = newNode;
            last = newNode;
            newNode->next = nullptr;
        } else {
            last->next = newNode;
            newNode->next = nullptr;
            last = newNode;
        }
    }

    SingleLinkedListIterator begin() {
        return SingleLinkedListIterator(first);
    }

    SingleLinkedListIterator end() {
        return SingleLinkedListIterator(nullptr);
    }

    void RemoveByID(int id) {
        Node *node = first;

        if (node == nullptr) {
            return;
        }

        if (node->data->ID == id) {
            delete node->data;
            Node *nextNode = first->next;
            delete node;
            first = nextNode;
        } else {
            while (node->next != nullptr) {
                if (node->data->ID == id) {
                    delete node->next->data;
                    Node *nextNode = node->next->next;
                    delete node->next;
                    node->next = nextNode;
                }
            }
        }


    }

private:
    Node *first;
    Node *last;


    void DeleteList() {
        for (auto i = first; i != nullptr;) {
            Node *extra = i->next;
            delete i;
            i = extra;
        }
    }
};