#include "gameui.h"
#include <QPushButton>
#include <QGridLayout>
#include "./game/block.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QKeyEvent>
#include <Qt>
#include <QString>
#include <QMessageBox>
#include <QCoreApplication>
#include <thread>
#include <chrono>
#include <QObject>

GameUi::GameUi() : QWidget(){

    hbox_layout = new QHBoxLayout(this); // Create hbox layout
    vbox_layout = new QVBoxLayout(this); // Create vbox layout
    grid_layout = new QGridLayout(this); // Create grid layout
    setFocusPolicy(Qt::StrongFocus);

    // Create 2D array of BlockUI
    board_ui.assign(4, {});
    for(int i = 0; i < 4; i++){
        board_ui[i].assign(4, {});
        for(int j = 0; j < 4; j++){
            board_ui[i][j] = new BlockUi;
        }
    }

    score_board = new QLabel(this); // Create score board

    // Create buttons
    restore_button = new QPushButton("restore", this); // Create restore button
    exit_button = new QPushButton("exit", this); // Create exit button

    setup_ui();
    connect();
}

GameUi::~GameUi() { }

void GameUi::setup_ui(){

    // Set hbox layout

    // Add board
    hbox_layout->addLayout(&(*grid_layout));
    hbox_layout->setStretchFactor(&(*grid_layout), 1000);

    // Add place that buttons and score label will locate
    hbox_layout->addLayout(&(*vbox_layout));
    hbox_layout->setStretchFactor(&(*vbox_layout), 300);


    // Set grid layout
    grid_layout->setSpacing(10); // Add spacing

    // Add BlockUis to grid layout
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            board_ui[i][j]->resize(250, 250);
            grid_layout->addWidget(board_ui[i][j], i, j, 1, 1);
            // board[i][j].update_value(int(std::pow(2, i+ 2*j + 1)));
            board_ui[i][j]->show();
        }
    }


    // Set vbox layout

    // Set score board
    score_board->setText("Score: ");
    score_board->setStyleSheet("QLabel { color: black; border style:solid; font: 40pt; font: Arial; }");
    score_board->setAlignment(Qt::AlignCenter);

    // Add score board to vbox layout
    vbox_layout->addWidget(&(*score_board));
    vbox_layout->setStretchFactor(&(*score_board), 100);

    // Add vertical space to vbox layout
    vbox_layout->addStretch(500);

    // Set restore button
    restore_button->setFont(QFont("Arial", 20));
    restore_button->setMinimumWidth(300);
    restore_button->setMinimumHeight(200);

    // Add restore button to vbox layout
    vbox_layout->addWidget(&(*restore_button));
    vbox_layout->setStretchFactor(&(*restore_button), 200);

    // Set exit button
    exit_button->setFont(QFont("Arial", 20));
    exit_button->setMinimumWidth(300);
    exit_button->setMinimumHeight(200);

    // Add exit button to vbox layout
    vbox_layout->addWidget(&(*exit_button));
    vbox_layout->setStretchFactor(&(*exit_button), 200);

    return;
}

void GameUi::connect(){
    // Connect buttons
    QObject::connect(restore_button, SIGNAL(clicked()), this, SLOT(request_button_clicked()));
    QObject::connect(exit_button, SIGNAL(clicked()), this, SLOT(exit_button_clicked()));
}

void GameUi::update_board(const std::shared_ptr<std::shared_ptr<Block[]>[]>&board){

    // Update values and colors of board
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++){
            board_ui[i][j]->update_value(board[i][j].get_value());
        }
    }

    return;
}

void GameUi::update_score(int score){
    // Update score
    std::string text = "score: " + std::to_string(score);
    score_board->setText(QString(text.c_str()));

    return;
}

void GameUi::get_restore_response(bool is_success){
    QMessageBox message_box;
    std::string message;

    // Set message box
    message_box.setIcon(QMessageBox::Information);
    message_box.setWindowTitle("Restore");
    if(is_success)
        message = "The board has been restore to its previous state!";
    else
        message = "There is no previously saved board in the buffer.";
    message_box.setText(QString(message.c_str()));
    message_box.setStandardButtons(QMessageBox::Ok);

    message_box.exec(); // Show message box

    return;
}

void GameUi::get_restore_count_response(int restore_count){
    QMessageBox message_box;
    int value;
    std::string message;

    // Set message box
    message_box.setIcon(QMessageBox::Information);
    message_box.setWindowTitle("Restore");
    if (restore_count <= 0){
        message_box.setText("No more chance to restore the board to its previous state.");
        message_box.setStandardButtons(QMessageBox::Ok);
        message_box.exec(); // Show message box
    }
    else{
        message = "Restore the game board to its previous state?\n"
                  "\n"
                  "Remaining chances: " + std::to_string(restore_count);
        message_box.setText(QString(message.c_str()));
        message_box.setStandardButtons(QMessageBox::Ok | QMessageBox::No);
        value = message_box.exec(); // Show message box

        if(value == QMessageBox::Ok)
            emit request_restore(); // restore attempt
    }
}

void GameUi::win(std::string message){
    QMessageBox message_box;
    int value;

    // Set message box
    message_box.setText(QString(message.c_str()));
    message_box.setIcon(QMessageBox::Information);
    message_box.setStandardButtons(QMessageBox::Ok);
    message_box.setWindowTitle("Win");
    std::this_thread::sleep_for (std::chrono::seconds(1)); // Wait for 1 sec

    value = message_box.exec(); // Show
    if (value == QMessageBox::Ok){
        emit QCoreApplication::quit(); // Quit
    }

    return;
}

void GameUi::lose(std::string message) {
    QMessageBox message_box;
    int value;

    // Set message box
    message_box.setText(QString(message.c_str()));
    message_box.setStandardButtons(QMessageBox::Ok);
    message_box.setWindowTitle("Lose");
    value = message_box.exec();
    if (value == QMessageBox::Ok)
        emit QCoreApplication::quit(); // Quit
    return;
}

void GameUi::keyPressEvent(QKeyEvent *event){
    // Arrow key input
    if (event->key() == Qt::Key_Up)
        emit request_move_up();
    else if (event->key() == Qt::Key_Down)
        emit request_move_down();
    else if (event->key() == Qt::Key_Left)
        emit request_move_left();
    else if (event->key() == Qt::Key_Right)
        emit request_move_right();

    return;
}

void GameUi::exit_button_clicked(){
    QMessageBox message_box;
    int value;

    // Set message box
    std::string message = "Are you sure to quit?";
    message_box.setText(QString(message.c_str()));
    message_box.setIcon(QMessageBox::Information);
    message_box.setWindowTitle("Exit");
    message_box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    value = message_box.exec();

    if (value == QMessageBox::Ok)
        emit QCoreApplication::quit(); // Quit

    return;
}

void GameUi::request_button_clicked(){
    emit request_restore_count(); // get restore count
    return;
}
