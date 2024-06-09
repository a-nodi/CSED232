#ifndef BOARD_H
#define BOARD_H

#include "block.h"
#include <memory>
#include "logunit.h"
#include <queue>

class Board{
private:
    std::shared_ptr<std::shared_ptr<Block[]>[]> board;
    std::shared_ptr<std::shared_ptr<Block[]>[]> buffer;

    int score;
    int buffer_score;
    bool is_buffer_contained;
    int restore_count;

    std::shared_ptr<std::queue<std::shared_ptr<LogUnit>>> log_queue;

    bool is_row_movable();
    bool is_column_movable();

    bool merge_block(int, int, int, int, bool=true);
    void swap_block(Block&, Block&);
    bool move_block(int, int, int, int);
    bool generate_block(bool=true, bool=false);

    void reset_is_mergeable();
    bool write_buffer();
    bool read_buffer();
    bool clear_buffer();

public:
    Board(std::shared_ptr<std::queue<std::shared_ptr<LogUnit>>>, bool=true);
    ~Board();

    // Move operation
    bool move_up(bool=true);
    bool move_down(bool=true);
    bool move_left(bool=true);
    bool move_right(bool=true);

    // Restore operation
    bool restore(bool=true);

    // Utill operation
    bool is_movable();
    bool is_2048_exist();

    int get_score() const { return score; };
    int get_restore_count() const { return restore_count; };
    const std::shared_ptr<std::shared_ptr<Block[]>[]>& get_board() const { return board; };
};

#endif // BOARD_H
