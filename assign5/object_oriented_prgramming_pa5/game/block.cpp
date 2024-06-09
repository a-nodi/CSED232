#include "block.h"


Block::Block() : value(0), _is_mergeable(true) { };

Block::Block(int _value) : value(_value), _is_mergeable(true) { };

Block::~Block() { };
