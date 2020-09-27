#include <iostream>
#include <utility>

using std::cout;
using std::cin;
using std::string;


class HashTable {
public:
    HashTable();
    ~HashTable();
    void Insert(const string& key);
    void Erase(const string& key);
    bool Find(const string& key) const;

private:
    struct Node {
        explicit Node(string key);
        string data;
        bool deleted;
    };
    void rehash();
    int hash(const string& key) const;
    int BufferSize;
    int size;
    Node** nodes;
};

HashTable::HashTable() : BufferSize(100), size(0){
    nodes = new Node * [BufferSize];
    for (size_t i = 0; i < BufferSize; i++) {
        nodes[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < BufferSize; ++i)
        if (nodes[i] != nullptr) {
            delete nodes[i];
        }
    delete[] nodes;
}

void HashTable::Insert(const string& key) {
    if (Find(key))
        return;

    if (3 * BufferSize <= 4 * (size + 1)) {
        rehash();
    }
    int hashed = hash(key);
    int i = 0;

    while (i < BufferSize) {
        if (nodes[hashed] == nullptr) {
            nodes[hashed] = new Node(key);
            size++;
            return;
        }
        else if (nodes[hashed]->deleted) {
            nodes[hashed]->data = key;
            nodes[hashed]->deleted = false;
            size++;
            return;
        }
        i++;
        hashed = (hashed + i) % BufferSize;
    }
}

bool HashTable::Find(const string& key) const {
    int hashed = hash(key);
    int i = 0;
    while (nodes[hashed] != nullptr && i < BufferSize) {
        if (!nodes[hashed]->deleted && nodes[hashed]->data == key) {
            return true;
        }
        i++;
        hashed = (hashed + i) % BufferSize;
    }
    return false;
}

void HashTable::Erase(const string& key) {
    int hashed = hash(key);
    int i = 0;

    if (!Find(key)) {
        return;
    }
    while (i < BufferSize) {
        if (!nodes[hashed]->deleted && nodes[hashed]->data == key) {
            nodes[hashed]->deleted = true;
            size--;
            return;
        }
        i++;
        hashed = (hashed + i) % BufferSize;
    }
}

void HashTable::rehash() {
    Node** tmp = nodes;
    BufferSize *= 2;
    size = 0;
    nodes = new Node * [BufferSize];

    for (int i = 0; i < BufferSize; i++) {
        nodes[i] = nullptr;
    }
    for (int i = 0; i < BufferSize / 2; i++) {
        if (tmp[i] != nullptr) {
            if (!tmp[i]->deleted) {
                Insert(tmp[i]->data);
            }
            delete tmp[i];
        }
    }
    delete[] tmp;
}

int HashTable::hash(const string& key) const {
    std::hash<string> hashed;
    return (hashed(key)) % BufferSize;
}

HashTable::Node::Node(string key) :
        data(std::move(key)),
        deleted(false)
{}



int main() {
    HashTable hashTable;

    char action;
    string line;

    cin >> action;
    while (action != '#') {
        cin >> line;

        if (line.empty()) break;

        switch (action) {
            case '+':
                hashTable.Insert(line);
                break;
            case '-':
                hashTable.Erase(line);
                break;
            case '?':
                cout <<  ((hashTable.Find(line)) ? "YES\n" : "NO\n");
                break;
            default:
                break;
        }
        cin >> action;
    }
    return 0;
}
