/****************************************************************************
** Meta object code from reading C++ file 'gameui.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../object_oriented_prgramming_pa5/ui/gameui.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSGameUiENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGameUiENDCLASS = QtMocHelpers::stringData(
    "GameUi",
    "request_move_up",
    "",
    "request_move_down",
    "request_move_left",
    "request_move_right",
    "request_restore",
    "request_restore_count",
    "update_board",
    "std::shared_ptr<std::shared_ptr<Block[]>[]>",
    "update_score",
    "get_restore_response",
    "get_restore_count_response",
    "win",
    "std::string",
    "lose",
    "exit_button_clicked",
    "request_button_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGameUiENDCLASS_t {
    uint offsetsAndSizes[36];
    char stringdata0[7];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[18];
    char stringdata5[19];
    char stringdata6[16];
    char stringdata7[22];
    char stringdata8[13];
    char stringdata9[44];
    char stringdata10[13];
    char stringdata11[21];
    char stringdata12[27];
    char stringdata13[4];
    char stringdata14[12];
    char stringdata15[5];
    char stringdata16[20];
    char stringdata17[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGameUiENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGameUiENDCLASS_t qt_meta_stringdata_CLASSGameUiENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "GameUi"
        QT_MOC_LITERAL(7, 15),  // "request_move_up"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 17),  // "request_move_down"
        QT_MOC_LITERAL(42, 17),  // "request_move_left"
        QT_MOC_LITERAL(60, 18),  // "request_move_right"
        QT_MOC_LITERAL(79, 15),  // "request_restore"
        QT_MOC_LITERAL(95, 21),  // "request_restore_count"
        QT_MOC_LITERAL(117, 12),  // "update_board"
        QT_MOC_LITERAL(130, 43),  // "std::shared_ptr<std::shared_p..."
        QT_MOC_LITERAL(174, 12),  // "update_score"
        QT_MOC_LITERAL(187, 20),  // "get_restore_response"
        QT_MOC_LITERAL(208, 26),  // "get_restore_count_response"
        QT_MOC_LITERAL(235, 3),  // "win"
        QT_MOC_LITERAL(239, 11),  // "std::string"
        QT_MOC_LITERAL(251, 4),  // "lose"
        QT_MOC_LITERAL(256, 19),  // "exit_button_clicked"
        QT_MOC_LITERAL(276, 22)   // "request_button_clicked"
    },
    "GameUi",
    "request_move_up",
    "",
    "request_move_down",
    "request_move_left",
    "request_move_right",
    "request_restore",
    "request_restore_count",
    "update_board",
    "std::shared_ptr<std::shared_ptr<Block[]>[]>",
    "update_score",
    "get_restore_response",
    "get_restore_count_response",
    "win",
    "std::string",
    "lose",
    "exit_button_clicked",
    "request_button_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGameUiENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x06,    1 /* Public */,
       3,    0,   99,    2, 0x06,    2 /* Public */,
       4,    0,  100,    2, 0x06,    3 /* Public */,
       5,    0,  101,    2, 0x06,    4 /* Public */,
       6,    0,  102,    2, 0x06,    5 /* Public */,
       7,    0,  103,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,  104,    2, 0x0a,    7 /* Public */,
      10,    1,  107,    2, 0x0a,    9 /* Public */,
      11,    1,  110,    2, 0x0a,   11 /* Public */,
      12,    1,  113,    2, 0x0a,   13 /* Public */,
      13,    1,  116,    2, 0x0a,   15 /* Public */,
      15,    1,  119,    2, 0x0a,   17 /* Public */,
      16,    0,  122,    2, 0x0a,   19 /* Public */,
      17,    0,  123,    2, 0x0a,   20 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GameUi::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGameUiENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGameUiENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGameUiENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GameUi, std::true_type>,
        // method 'request_move_up'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'request_move_down'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'request_move_left'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'request_move_right'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'request_restore'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'request_restore_count'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'update_board'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::shared_ptr<std::shared_ptr<Block[]>[]> &, std::false_type>,
        // method 'update_score'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_restore_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'get_restore_count_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'win'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'lose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'exit_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'request_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GameUi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameUi *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->request_move_up(); break;
        case 1: _t->request_move_down(); break;
        case 2: _t->request_move_left(); break;
        case 3: _t->request_move_right(); break;
        case 4: _t->request_restore(); break;
        case 5: _t->request_restore_count(); break;
        case 6: _t->update_board((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<std::shared_ptr<Block[]>[]>>>(_a[1]))); break;
        case 7: _t->update_score((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->get_restore_response((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->get_restore_count_response((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->win((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 11: _t->lose((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 12: _t->exit_button_clicked(); break;
        case 13: _t->request_button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameUi::*)();
            if (_t _q_method = &GameUi::request_move_up; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameUi::*)();
            if (_t _q_method = &GameUi::request_move_down; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameUi::*)();
            if (_t _q_method = &GameUi::request_move_left; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GameUi::*)();
            if (_t _q_method = &GameUi::request_move_right; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GameUi::*)();
            if (_t _q_method = &GameUi::request_restore; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GameUi::*)();
            if (_t _q_method = &GameUi::request_restore_count; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *GameUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameUi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGameUiENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void GameUi::request_move_up()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GameUi::request_move_down()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameUi::request_move_left()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GameUi::request_move_right()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GameUi::request_restore()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void GameUi::request_restore_count()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
