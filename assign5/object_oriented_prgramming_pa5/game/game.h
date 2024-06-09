#ifndef GAME_H
#define GAME_H

#include "block.h"
#include "board.h"
#include "logger.h"
#include <memory>
#include <QObject>

class Game : public QObject {
    Q_OBJECT

private:
    std::shared_ptr<Board> board;
    std::shared_ptr<Logger> logger;
    bool is_movable();

public:
    Game();
    ~Game();
    int get_score();
    int get_restore_count();
    void update_board();
    void update_score();

public slots:
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void restore();
    void send_restore_count();
signals:
    void board_update(const std::shared_ptr<std::shared_ptr<Block[]>[]>&);
    void score_update(int);
    void restore_response(bool);
    void restore_count_response(int);
    void win(std::string);
    void lose(std::string);
};

inline int Game::get_score() { return board->get_score(); }

inline int Game::get_restore_count() { return board->get_restore_count(); }

#endif
