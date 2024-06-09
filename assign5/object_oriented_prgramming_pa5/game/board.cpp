#include "block.h"
#include "board.h"
#include "logunit.h"
#include <vector>
#include <cstdlib>
#include <ctime>

Board::Board(std::shared_ptr<std::queue<std::shared_ptr<LogUnit>>> _log_queue, bool log_on) : score(0), buffer_score(0), is_buffer_contained(false), restore_count(3), log_queue(_log_queue) {
    int log_argn = 0;

    // Allocate board
    board = std::shared_ptr<std::shared_ptr<Block[]>[]> (new std::shared_ptr<Block[]>[4]);
    for(int i = 0; i < 4; i++) board[i] = std::shared_ptr<Block[]> (new Block[4]);;

    std::srand(std::time(nullptr)); // Set random seed

    // Generate random
    generate_block(false, true);
    generate_block(false, true);

    if (log_on){
        std::shared_ptr<LogUnit> log_unit(new LogUnit);

        // Log Initial operation
        log_unit->action = "INITIAL";
        log_unit->values = std::unique_ptr<int[]>(new int[4]);

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(board[i][j].get_value() != 0){
                    log_unit->values[log_argn] = i;
                    log_unit->values[log_argn + 1] = j;
                    log_argn += 2;
                }
                if(log_argn == 4) break;
            }
            if(log_argn == 4) break;
        }
        log_queue->push(log_unit); // Push log unit to log queue
    }
}

Board::~Board() { }

bool Board::is_row_movable() {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j].get_value() == 0) return true; // Empty Block to Add
            else if (j < 4 - 1){
                if (board[i][j].get_value() == board[i][j+1].get_value()) return true; // Two blocks can be merged
            }
        }
    }

    return false;
}

bool Board::is_column_movable() {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j].get_value() == 0) return true; // Empty Block to Add
            else if (i < 4 - 1){
                if(board[i][j].get_value() == board[i+1][j].get_value()) return true; // Two block can be merged
            }
        }
    }

    return false;
}

bool Board::merge_block(int row_src, int col_src, int row_dst, int col_dst, bool log_on) {
    if (board[row_src][col_src].get_value() != board[row_dst][col_dst].get_value()) return false;

    // move value to dst block
    board[row_src][col_src].set_value(0);
    board[row_dst][col_dst].set_value(board[row_dst][col_dst].get_value() * 2);
    board[row_dst][col_dst].is_mergeable() = false;
    score += board[row_dst][col_dst].get_value();

    if (log_on){
        std::shared_ptr<LogUnit> log_unit(new LogUnit);

        // Log Merge operation
        log_unit->action = "MERGE";
        log_unit->values = std::unique_ptr<int[]>(new int[3]);
        log_unit->values[0] = row_dst;
        log_unit->values[1] = col_dst;
        log_unit->values[2] = board[row_dst][col_dst].get_value();
        log_queue->push(log_unit); // Push log unit to log queue
    }
    return true;
}

void Board::swap_block(Block& a, Block& b) {
    Block value_temp = a;
    a = b;
    b = value_temp;

    return;
}

bool Board::move_block(int row_src, int col_src, int row_dst, int col_dst) {

    if (board[row_dst][col_dst].get_value() != 0) return false;
    swap_block(board[row_src][col_src], board[row_dst][col_dst]);

    return true;
}

bool Board::generate_block(bool log_on, bool only_2) {
    int count = 0;
    int rand_index, value, rand_row, rand_col;
    std::vector<int> vector_of_0blocks_row(16);
    std::vector<int> vector_of_0blocks_col(16);

    // Search empty space
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(board[i][j].get_value() == 0){
                // Record empty space
                vector_of_0blocks_row[count] = i;
                vector_of_0blocks_col[count] = j;
                count++;
            }
        }
    }

    if (count == 0) return false;

    rand_index = std::rand() % count; // Randomly choose empth space to be generated

    if (only_2) value = 2; // 100% 2
    else value = std::rand() % 5 != 4 ? 2 : 4; // 80% 2, 20% 4

    rand_row = vector_of_0blocks_row[rand_index];
    rand_col = vector_of_0blocks_col[rand_index];

    board[rand_row][rand_col].set_value(value); // Generate block

    if (log_on){
        std::shared_ptr<LogUnit> log_unit(new LogUnit);

        // Log Merge operation
        log_unit->action = "GENERATE";
        log_unit->values = std::unique_ptr<int[]>(new int[3]);
        log_unit->values[0] = rand_row;
        log_unit->values[1] = rand_col;
        log_unit->values[2] = board[rand_row][rand_col].get_value();
        log_queue->push(log_unit); // Push log unit to log queue

    }
    return true;
}

void Board::reset_is_mergeable(){

    // Reset all blocks is_mergeable
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            board[i][j].is_mergeable() = true;
        }
    }

    return;
}

bool Board::write_buffer(){

    // Allocate new buffer
    buffer = std::shared_ptr<std::shared_ptr<Block[]>[]> (new std::shared_ptr<Block[]>[4]);
    for(int i = 0; i < 4; i++) buffer[i] = std::shared_ptr<Block[]> (new Block[4]);;

    // Deep copy board to buffer
    for(int i = 0 ; i < 4; i++){
        for(int j = 0; j < 4; j++){
            buffer[i][j].set_value(board[i][j].get_value());
        }
    }
    // Score to buffer score
    buffer_score = score;
    is_buffer_contained = true;
    return true;
}

bool Board::read_buffer(){
    // load blocks and score from buffer
    board = buffer;
    score = buffer_score;
    clear_buffer(); // clear buffer
    return true;
}

bool Board::clear_buffer(){
    buffer = std::shared_ptr<std::shared_ptr<Block[]>[]>(nullptr);
    is_buffer_contained = false;
    return true;
}

bool Board::move_up(bool log_on){

    if (log_on){
        std::shared_ptr<LogUnit> log_unit(new LogUnit);

        // Log Up operation
        log_unit->action = "UP";
        log_queue->push(log_unit); // Push log unit to log queue
    }

    if (!is_column_movable()) return false;

    write_buffer();
    for (int j = 0; j < 4; j++){
        for (int i = 0; i < 4; i++){ // Downward search
            if(board[i][j].get_value() == 0) continue; // Don't have to move empty block as source

            // Search movable space of mergeable block
            for(int k = i - 1; k >= 0; k--) {
                if (k == 0 && board[k][j].get_value() == 0) { // End of movable space and it is blank space
                    move_block(i, j, 0, j); // Move current block to End of moveable space position
                    break;
                }
                else if (board[k][j].get_value() != 0) { // Found block
                    if (board[k][j].is_mergeable() && board[k][j].get_value() == board[i][j].get_value() && i != k){ // Block is mergeable
                        merge_block(i, j, k ,j, log_on); // Merge current block and selected block
                        break;
                    }
                    else if (k + 1 != i) { // Block is not mergeable and selected block is not current block itself
                        move_block(i, j, k + 1, j); // Move current block to right below selected block
                        break;
                    }
                }
            }
        }
    }

    reset_is_mergeable();
    generate_block();

    if (log_on){
        std::shared_ptr<LogUnit> log_unit(new LogUnit);

        // Log Score operation
        log_unit->action = "SCORE";
        log_unit->values = std::unique_ptr<int[]>(new int[1]);
        log_unit->values[0] = score;
        log_queue->push(log_unit); // Push log unit to log queue
    }

    return true;
}

bool Board::move_down(bool log_on) {

    if (log_on){
        std::shared_ptr<LogUnit> log_unit(new LogUnit);

        // Log Down operation
        log_unit->action = "DOWN";
        log_queue->push(log_unit); // Push log unit to log queue
    }

    if (!is_column_movable()) return false;

    write_buffer();
    for (int j = 0; j < 4; j++) {
        for (int i = 4 - 1; i >= 0; i--) { // Upward search
            if (board[i][j].get_value() == 0) continue; // Don't have to move empty block as source

            // Search movable space of mergeable block
            for (int k = i + 1; k < 4; k++) {
                if (k == 4 - 1 && board[k][j].get_value() == 0) {  // End of movable space and it is blank space
                    move_block(i, j, 4 - 1, j); // Move current block to End of moveable space position
                    break;
                }
                else if (board[k][j].get_value() != 0) { // Found block
                    if (board[k][j].is_mergeable() && board[k][j].get_value() == board[i][j].get_value() && i != k){ // Block is mergeable
                        merge_block(i, j, k ,j, log_on); // Merge current block and selected block
                        break;
                    }
                    else if (k - 1 != i) { // Block is not mergeable and selected block is not current block itself
                        move_block(i, j, k - 1, j); // Move current block to right above selected block
                        break;
                    }
                }
            }
        }
    }

    reset_is_mergeable();
    generate_block();

    if (log_on){
        std::shared_ptr<LogUnit> log_unit(new LogUnit);

        // Log Score operation
        log_unit->action = "SCORE";
        log_unit->values = std::unique_ptr<int[]>(new int[1]);
        log_unit->values[0] = score;
        log_queue->push(log_unit); // Push log unit to log queue
    }

    return true;
}

bool Board::move_left(bool log_on) {

    if (log_on){
        std::shared_ptr<LogUnit> log_unit(new LogUnit);

        // Log Left operation
        log_unit->action = "LEFT";
        log_queue->push(log_unit); // Push log unit to log queue
    }

    if (!is_row_movable()) return false;

    write_buffer();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++){ // Rightward search
            if (board[i][j].get_value() == 0) continue; // Don't have to move empty block as source

            // Search movable space of mergeable block
            for(int k = j - 1; k >= 0; k--) {
                if (k == 0 && board[i][k].get_value() == 0) { // End of movable space and it is blank space
                    move_block(i, j, i, 0); // Move current block to End of moveable space position
                    break;
                }
                else if (board[i][k].get_value() != 0) { // Found block
                    if (board[i][k].is_mergeable() && board[i][k].get_value() == board[i][j].get_value() && j != k){ // Block is mergeable
                        merge_block(i, j, i ,k, log_on); // Merge current block and selected block
                        break;
                    }
                    else if (k + 1 != j) { // Block is not mergeable and selected block is not current block itself
                        move_block(i, j, i, k + 1); // Move current block to right below selected block
                        break;
                    }
                }
            }
        }
    }

    reset_is_mergeable();
    generate_block();

    if (log_on){
        std::shared_ptr<LogUnit> log_unit(new LogUnit);

        // Log Score operation
        log_unit->action = "SCORE";
        log_unit->values = std::unique_ptr<int[]>(new int[1]);
        log_unit->values[0] = score;
        log_queue->push(log_unit); // Push log unit to log queue
    }

    return true;
}

bool Board::move_right(bool log_on) {

    if (log_on){
        std::shared_ptr<LogUnit> log_unit(new LogUnit);

        // Log Right operation
        log_unit->action = "RIGHT";
        log_queue->push(log_unit); // Push log unit to log queue
    }

    if (!is_row_movable()) return false;

    write_buffer();
    for (int i = 0; i < 4; i++) {
        for (int j = 4 - 1; j >= 0; j--) { // Upward search
            if (board[i][j].get_value() == 0) continue; // Don't have to move empty block as source

            // Search movable space of mergeable block
            for (int k = j + 1; k < 4; k++) {
                if (k == 4 - 1 && board[i][k].get_value() == 0) {  // End of movable space and it is blank space
                    move_block(i, j, i, 4 - 1); // Move current block to End of moveable space position
                    break;
                }
                else if (board[i][k].get_value() != 0) { // Found block
                    if (board[i][k].is_mergeable() && board[i][k].get_value() == board[i][j].get_value() && j != k){ // Block is mergeable
                        merge_block(i, j, i ,k, log_on); // Merge current block and selected block
                        break;
                    }
                    else if (k - 1 != j) { // Block is not mergeable and selected block is not current block itself
                        move_block(i, j, i, k - 1); // Move current block to right above selected block
                        break;
                    }
                }
            }
        }
    }

    reset_is_mergeable();
    generate_block();

    if (log_on){
        std::shared_ptr<LogUnit> log_unit(new LogUnit);

        // Log Score operation
        log_unit->action = "SCORE";
        log_unit->values = std::unique_ptr<int[]>(new int[1]);
        log_unit->values[0] = score;
        log_queue->push(log_unit); // Push log unit to log queue
    }

    return true;
}

bool Board::restore(bool log_on) {
    if (restore_count <= 0) return false;

    if (!is_buffer_contained) return false;

    restore_count--;
    read_buffer();
    clear_buffer();

    if(log_on){
        std::shared_ptr<LogUnit> log_unit(new LogUnit);

        // Log Restore operation
        log_unit->action = "RESTORE";
        log_unit->values = std::unique_ptr<int[]>(new int[1]);
        log_unit->values[0] = restore_count;
        log_queue->push(log_unit); // Push log unit to log queue
    }
    return true;
}

bool Board::is_movable(){
    return is_row_movable() || is_column_movable();
}

bool Board::is_2048_exist(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
            if (board[i][j].get_value() == 2048)
                return true;
    }
    return false;
}
