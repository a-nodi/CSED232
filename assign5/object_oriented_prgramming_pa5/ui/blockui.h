#ifndef BLOCKUI_H
#define BLOCKUI_H

#include <QLabel>
#include <memory>
#include <string>

class BlockUi : public QLabel
{

private:
    int value;

    void setup_ui();
    void paint();

public:
    BlockUi();
    ~BlockUi();
    void update_value(int);
};


#endif // BLOCKUI_H
