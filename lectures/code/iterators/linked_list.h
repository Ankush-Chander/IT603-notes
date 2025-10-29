template <typename T>
class ForwardList {
private:
    
    struct Node {
        T data;
        Node* next;
        
        Node(const T& val){
            /*            
            In C++ the only difference between a class and a struct is that members and base classes 
            are private by default in classes, whereas they are public by default in structs.
            So structs can have constructors, and the syntax is the same as for classes.
            */
            data = val;
            next = nullptr;
        }
    };
    
    size_t list_size;

public:
    Node* head;
    ForwardList(): head(nullptr), list_size(0) {}

    ForwardList(std::initializer_list<T> init){
    /* Why use initializer_list?
        If there was no `std::initializer_list`, achieving the same functionality would be more cumbersome and less expressive. Here are some ways things could be achieved:
        1. **Using a constructor with multiple arguments**: Instead of using an `initializer_list`, a constructor could be defined with multiple arguments, one for each element in the list. For example:
        ```cpp
        ForwardList(T a, T b, T c) {
            push_front(a);
            push_front(b);
            push_front(c);
        }
        ```
        This approach has several limitations:

        * It's not flexible: the number of elements is fixed, and adding or removing elements would require changing the constructor signature.
        * It's not expressive: the code doesn't clearly convey the intention of initializing a list with multiple elements.
        2. **Using a constructor with a `std::vector` or `std::array` argument**: Another approach would be to define a constructor that takes a `std::vector` or `std::array` as an argument. For example:
        ```cpp
        ForwardList(const std::vector<T>& vec) {
            for (const T& value : vec) {
                push_front(value);
            }
        }
        ```
        This approach requires creating a temporary `vector` or `array` object, which can be less efficient and more verbose than using an `initializer_list`.
        3. **Using a separate initialization function**: A separate function could be defined to initialize the object with a list of elements. For example:
        ```cpp
        void initList(T* values, int size) {
            for (int i = 0; i < size; i++) {
                push_front(values[i]);
            }
        }
        ```
        This approach requires calling a separate function after constructing the object, which can be less convenient and less expressive than using an `initializer_list`.
        Overall, the introduction of `std::initializer_list` in C++11 has greatly improved the expressiveness and convenience of initializing objects with a list of values.
        */
        head = nullptr;
        list_size = 0;
        for (const T& value : init) {
            push_front(value);
        }
    }

    // copy constructor
    ForwardList(const ForwardList& other) {
        head = nullptr;
        list_size = 0;
        Node* current = other.head;
        while (current) {
            push_back(current->data);
            current = current->next;
        }
    }

    // assignment operator
    ForwardList& operator=(const ForwardList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    ~ForwardList() {
        clear();
    }

    void push_front(const T& value) {
        /*
        add new node to the beginning of the list
        */
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        ++list_size;
    }

    void pop_front() {
        /*
        delete the first node
        */
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            --list_size;
        }
    }

    void push_back(const T& value) {
        /*
        add new node to the end of the list
        */
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        ++list_size;
    }

    void pop_back() {
        /*
        delete the last node
        */
        if (head) {
            if (!head->next) {
                delete head;
                head = nullptr;
            } else {
                Node* current = head;
                while (current->next->next) {
                    current = current->next;
                }
                delete current->next;
                current->next = nullptr;
            }
            --list_size;
        }
    }
    

    void insert_after(Node* node, const T& value) {
        /*
        add new node after the given node
        */
        Node* newNode = new Node(value);
        newNode->next = node->next;
        node->next = newNode;
        ++list_size;
    }

    void erase_after(Node* node) {
        /*
        delete the node after the given node
        */
        if (node->next) {
            Node* temp = node->next;
            node->next = temp->next;
            delete temp;
            --list_size;
        }
    }

    bool empty() const {
        return head == nullptr;
    }

    size_t size() const {
        return list_size;
    }

    void clear() {
        while (head) {
            pop_front();
        }
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }



    // iterator related code //
    class Iterator {
        // forward iterator implementation
        // supports ++, !=, *,
    private:
        Node* node;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        Iterator(Node* ptr){
            node = ptr;
        }

        reference operator*(){ 
            return node->data;
        }
        
        Iterator& operator++() {
            node = node->next;
             return *this;
        }
        
        bool operator==(const Iterator& other) const {
             return node == other.node;
        }

        bool operator!=(const Iterator& other) const {
             return node != other.node;
        }


    };

    Iterator begin() {
        return Iterator(head);
    }
    Iterator end(){
         return Iterator(nullptr);
    }
    // iterator related code ends//
};
