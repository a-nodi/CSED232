/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../object_oriented_prgramming_pa5/game/game.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGameENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGameENDCLASS = QtMocHelpers::stringData(
    "Game",
    "board_update",
    "",
    "std::shared_ptr<std::shared_ptr<Block[]>[]>",
    "score_update",
    "restore_response",
    "restore_count_response",
    "win",
    "std::string",
    "lose",
    "move_up",
    "move_down",
    "move_left",
    "move_right",
    "restore",
    "send_restore_count"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGameENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[5];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[44];
    char stringdata4[13];
    char stringdata5[17];
    char stringdata6[23];
    char stringdata7[4];
    char stringdata8[12];
    char stringdata9[5];
    char stringdata10[8];
    char stringdata11[10];
    char stringdata12[10];
    char stringdata13[11];
    char stringdata14[8];
    char stringdata15[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGameENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGameENDCLASS_t qt_meta_stringdata_CLASSGameENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "Game"
        QT_MOC_LITERAL(5, 12),  // "board_update"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 43),  // "std::shared_ptr<std::shared_p..."
        QT_MOC_LITERAL(63, 12),  // "score_update"
        QT_MOC_LITERAL(76, 16),  // "restore_response"
        QT_MOC_LITERAL(93, 22),  // "restore_count_response"
        QT_MOC_LITERAL(116, 3),  // "win"
        QT_MOC_LITERAL(120, 11),  // "std::string"
        QT_MOC_LITERAL(132, 4),  // "lose"
        QT_MOC_LITERAL(137, 7),  // "move_up"
        QT_MOC_LITERAL(145, 9),  // "move_down"
        QT_MOC_LITERAL(155, 9),  // "move_left"
        QT_MOC_LITERAL(165, 10),  // "move_right"
        QT_MOC_LITERAL(176, 7),  // "restore"
        QT_MOC_LITERAL(184, 18)   // "send_restore_count"
    },
    "Game",
    "board_update",
    "",
    "std::shared_ptr<std::shared_ptr<Block[]>[]>",
    "score_update",
    "restore_response",
    "restore_count_response",
    "win",
    "std::string",
    "lose",
    "move_up",
    "move_down",
    "move_left",
    "move_right",
    "restore",
    "send_restore_count"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGameENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x06,    1 /* Public */,
       4,    1,   89,    2, 0x06,    3 /* Public */,
       5,    1,   92,    2, 0x06,    5 /* Public */,
       6,    1,   95,    2, 0x06,    7 /* Public */,
       7,    1,   98,    2, 0x06,    9 /* Public */,
       9,    1,  101,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  104,    2, 0x0a,   13 /* Public */,
      11,    0,  105,    2, 0x0a,   14 /* Public */,
      12,    0,  106,    2, 0x0a,   15 /* Public */,
      13,    0,  107,    2, 0x0a,   16 /* Public */,
      14,    0,  108,    2, 0x0a,   17 /* Public */,
      15,    0,  109,    2, 0x0a,   18 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Game::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSGameENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGameENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGameENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Game, std::true_type>,
        // method 'board_update'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::shared_ptr<std::shared_ptr<Block[]>[]> &, std::false_type>,
        // method 'score_update'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'restore_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'restore_count_response'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'win'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'lose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'move_up'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'move_down'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'move_left'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'move_right'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'restore'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'send_restore_count'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Game *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->board_update((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<std::shared_ptr<Block[]>[]>>>(_a[1]))); break;
        case 1: _t->score_update((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->restore_response((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->restore_count_response((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->win((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 5: _t->lose((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 6: _t->move_up(); break;
        case 7: _t->move_down(); break;
        case 8: _t->move_left(); break;
        case 9: _t->move_right(); break;
        case 10: _t->restore(); break;
        case 11: _t->send_restore_count(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Game::*)(const std::shared_ptr<std::shared_ptr<Block[]>[]> & );
            if (_t _q_method = &Game::board_update; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Game::*)(int );
            if (_t _q_method = &Game::score_update; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Game::*)(bool );
            if (_t _q_method = &Game::restore_response; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Game::*)(int );
            if (_t _q_method = &Game::restore_count_response; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Game::*)(std::string );
            if (_t _q_method = &Game::win; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Game::*)(std::string );
            if (_t _q_method = &Game::lose; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGameENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Game::board_update(const std::shared_ptr<std::shared_ptr<Block[]>[]> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Game::score_update(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Game::restore_response(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Game::restore_count_response(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Game::win(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Game::lose(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
