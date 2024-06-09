#ifndef GAMEUI_H
#define GAMEUI_H


#include "blockui.h"
#include "./game/block.h"
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <memory>

class GameUi : public QWidget
{
    Q_OBJECT
private:
    std::vector<std::vector<BlockUi *>> board_ui;
    QGridLayout* grid_layout;
    QLabel* score_board;
    QPushButton* restore_button;
    QPushButton* exit_button;

    QVBoxLayout* vbox_layout;
    QHBoxLayout* hbox_layout;
    void setup_ui();
    void connect();

public:

    GameUi();
    ~GameUi();

protected:
    void keyPressEvent(QKeyEvent*) override;

public slots:
    void update_board(const std::shared_ptr<std::shared_ptr<Block[]>[]>&);
    void update_score(int);
    void get_restore_response(bool);
    void get_restore_count_response(int);
    void win(std::string);
    void lose(std::string);
    void exit_button_clicked();
    void request_button_clicked();
signals:
    void request_move_up();
    void request_move_down();
    void request_move_left();
    void request_move_right();
    void request_restore();
    void request_restore_count();
};



#endif // GAMEUI_H
