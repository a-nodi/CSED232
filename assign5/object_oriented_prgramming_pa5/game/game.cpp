#include "board.h"
#include "logger.h"
#include "game.h"
#include <memory>
#include <string>

Game::Game() {
    std::string log_file_name = "progress.txt";

    logger = std::shared_ptr<Logger> (new Logger(log_file_name)); // Initialize Logger
    board = std::shared_ptr<Board> (new Board(logger->get_queue())); // Initialize Board
    logger->write_file(); // Write Initial log

}

Game::~Game() { }

void Game::move_up() {
    if (!(board->is_movable())) // not movable -> lose
        emit lose("You lose...\n"
                  "\n"
                  "Score: " + std::to_string(board->get_score()));

    board->move_up();
    logger->write_file();

    emit board_update(board->get_board()); // update board on gui
    emit score_update(board->get_score()); // update score on gui

    if (board->is_2048_exist()) // 2048 block detected -> win
        emit win("Congratulation!\n"
                 "\n"
                 "Score: " + std::to_string(board->get_score()));
    return;
}

void Game::move_down() {
    if (!(board->is_movable())) // not movable -> lose
        emit lose("You lose...\n"
                  "\n"
                  "Score: " + std::to_string(board->get_score()));

    board->move_down();
    logger->write_file();

    emit board_update(board->get_board()); // update board on gui
    emit score_update(board->get_score()); // update score on gui

    if (board->is_2048_exist())
        emit win("Congratulation!\n"
                 "\n"
                 "Score: " + std::to_string(board->get_score()));
    return;
}

void Game::move_left() {
    if (!(board->is_movable())) // not movable -> lose
        emit lose("You lose...\n"
                  "\n"
                  "Score: " + std::to_string(board->get_score()));

    board->move_left();
    logger->write_file();

    emit board_update(board->get_board()); // update board on gui
    emit score_update(board->get_score()); // update score on gui

    if (board->is_2048_exist())
        emit win("Congratulation!\n"
                 "\n"
                 "Score: " + std::to_string(board->get_score()));
    return;
}

void Game::move_right() {
    if (!(board->is_movable())) // not movable -> lose
        emit lose("You lose...\n"
                  "\n"
                  "Score: " + std::to_string(board->get_score()));

    board->move_right();
    logger->write_file();

    emit board_update(board->get_board()); // update board on gui
    emit score_update(board->get_score()); // update score on gui

    if (board->is_2048_exist())
        emit win("Congratulation!\n"
                 "\n"
                 "Score: " + std::to_string(board->get_score()));
    return;
}

void Game::restore(){
    bool is_success = board->restore();
    if(is_success){
        emit restore_response(is_success);
        emit board_update(board->get_board());
    }
    else{
        emit restore_response(is_success);
    }
    logger->write_file();

    return;
}

void Game::send_restore_count(){
    emit restore_count_response(get_restore_count());
    return;
}

void Game::update_board(){
    emit board_update(board->get_board());
    return;
}

void Game::update_score(){
    emit score_update(board->get_score());
}
