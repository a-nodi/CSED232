#ifndef BLOCK_H
#define BLOCK_H

class Block{
private:
    int value;
    bool _is_mergeable;
public:
    Block();
    Block(int);
    ~Block();
    int get_value() const { return value; };
    void set_value(int _value){ value = _value; };
    bool& is_mergeable() { return _is_mergeable; };

};

#endif // BLOCK_H
