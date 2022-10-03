// iter_self.h

template <typename T>
class Sequence {
    T *array;               //  Dynamic array
    unsigned current_size;  //  Current size
    unsigned capacity;      //  Maximum size

    unsigned current_position;

public:
    //  Constructor allocates space for the dynamic array
    Sequence(unsigned n): array(new T[n]), current_size(0), capacity(n),
                          current_position(0) {}
    //  Destructor frees up the space held by the dynamic array
    ~Sequence() { delete [] array; }
    //  Returns the number of elements the sequence holds
    unsigned size() const { return current_size; }

    //  Inserts a new element onto the back of the sequence
    bool insert(const T& elem) {
        if (current_size < capacity)
            array[current_size++] = elem;
        else
            return false; //  Full, no more room
        return true;  //  Successfully inserted
    }

    //  Prints the contents of the sequence
    void print() const {
        for (unsigned i = 0; i < current_size; i++)
            std::cout << array[i] << ' ';
        std::cout << '\n';
    }

    void begin() {
        current_position = 0;
    }

    int current() {
        return array[current_position];
    }

    void advance() {
        current_position++;
    }

    bool has_next() {
        return current_position < current_size - 1; 
    }
};

