// iter.h

template <typename T>
class Sequence {
    T *array;               //  Dynamic array
    unsigned current_size;  //  Current size
    unsigned capacity;      //  Maximum size

public:
    //  Constructor allocates space for the dynamic array
    Sequence(unsigned n): array(new T[n]), current_size(0), capacity(n) {}
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

    class iterator {
        Sequence<T> *sequence;  //  The sequence over which to iterate
        unsigned index;         //  The current location of the iteration
        //  Private constructors
        iterator(Sequence<T> *seq): sequence(seq), index(0) {}
        iterator(Sequence<T> *seq, unsigned n): sequence(seq), index(n) {}
        //  Enable only the Sequence<T> methods to create an iterator
        friend class Sequence<T>;
    public:
        T operator*() { return sequence->array[index]; } // Return current element
        iterator operator++() {  // Preincrement
            index++;
            return *this;
        }
        iterator operator++(int) {  // Postincrement
            index++;
            return *this;
        }                                                 // Compare iterators
        bool operator==(const iterator& other) const { return index == other.index; }
        bool operator!=(const iterator& other) const { return index != other.index; }
    };
    iterator begin() {     //  Iterator points to the beginning of the sequence
        return iterator(this);
    }
    
    iterator end() {       //  Iterator points just past the end of the sequence
        return iterator(this, current_size);
    }
};

