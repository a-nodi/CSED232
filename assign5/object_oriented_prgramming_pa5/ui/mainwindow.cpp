#include "mainwindow.h"
//#include "blockui.h"
#include <QObject>
#include "gameui.h"
// #include "ui_mainwindow.h"
// #include "./game/block.h"
#include <QKeyEvent>
#include "./game/game.h"

#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //ui->setupUi(this);

    game = new Game(); // Create game
    game_ui = new GameUi();

    // QObject::connect(exit)

    setup_ui(); // setup game ui
    connect(); // connect signals and slots between Mainwindow and Game
    game->update_board();
    game->update_score();
}

MainWindow::~MainWindow()
{
    // delete ui;
}

void MainWindow::connect(){

    QObject::connect(game, SIGNAL(board_update(std::shared_ptr<std::shared_ptr<Block[]>[]>)),
                     game_ui, SLOT(update_board(std::shared_ptr<std::shared_ptr<Block[]>[]>)));
    QObject::connect(game, SIGNAL(score_update(int)), game_ui, SLOT(update_score(int)));
    QObject::connect(game, SIGNAL(restore_response(bool)), game_ui, SLOT(get_restore_response(bool)));
    QObject::connect(game, SIGNAL(restore_count_response(int)), game_ui, SLOT(get_restore_count_response(int)));
    QObject::connect(game, SIGNAL(win(std::string)), game_ui, SLOT(win(std::string)));
    QObject::connect(game, SIGNAL(lose(std::string)), game_ui, SLOT(lose(std::string)));
    QObject::connect(game_ui, SIGNAL(request_move_up()), game, SLOT(move_up()));
    QObject::connect(game_ui, SIGNAL(request_move_down()), game, SLOT(move_down()));
    QObject::connect(game_ui, SIGNAL(request_move_left()), game, SLOT(move_left()));
    QObject::connect(game_ui, SIGNAL(request_move_right()), game, SLOT(move_right()));
    QObject::connect(game_ui, SIGNAL(request_restore()), game, SLOT(restore()));
    QObject::connect(game_ui, SIGNAL(request_restore_count()), game, SLOT(send_restore_count()));
    return;
}

void MainWindow::setup_ui(){
    const int main_window_width = 1300;
    const int main_window_height = 1000;

    resize(main_window_width, main_window_height); // Resize MainWindow to given width and height
    setCentralWidget(game_ui);
    show(); // Show MainWindow
    return;
}

