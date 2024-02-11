/****************************************************************************
** Meta object code from reading C++ file 'ChessWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../guicode/ChessWindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChessWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
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
struct qt_meta_stringdata_CLASSChessWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSChessWindowENDCLASS = QtMocHelpers::stringData(
    "ChessWindow",
    "slot_clicked",
    "",
    "x",
    "y",
    "slot_newGame",
    "slot_open",
    "slot_save",
    "slot_undo",
    "slot_redo",
    "slot_visualizationChange",
    "on_actionExit_triggered",
    "closeEvent",
    "QCloseEvent*",
    "event"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSChessWindowENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[12];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[2];
    char stringdata4[2];
    char stringdata5[13];
    char stringdata6[10];
    char stringdata7[10];
    char stringdata8[10];
    char stringdata9[10];
    char stringdata10[25];
    char stringdata11[24];
    char stringdata12[11];
    char stringdata13[13];
    char stringdata14[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSChessWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSChessWindowENDCLASS_t qt_meta_stringdata_CLASSChessWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "ChessWindow"
        QT_MOC_LITERAL(12, 12),  // "slot_clicked"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 1),  // "x"
        QT_MOC_LITERAL(28, 1),  // "y"
        QT_MOC_LITERAL(30, 12),  // "slot_newGame"
        QT_MOC_LITERAL(43, 9),  // "slot_open"
        QT_MOC_LITERAL(53, 9),  // "slot_save"
        QT_MOC_LITERAL(63, 9),  // "slot_undo"
        QT_MOC_LITERAL(73, 9),  // "slot_redo"
        QT_MOC_LITERAL(83, 24),  // "slot_visualizationChange"
        QT_MOC_LITERAL(108, 23),  // "on_actionExit_triggered"
        QT_MOC_LITERAL(132, 10),  // "closeEvent"
        QT_MOC_LITERAL(143, 12),  // "QCloseEvent*"
        QT_MOC_LITERAL(156, 5)   // "event"
    },
    "ChessWindow",
    "slot_clicked",
    "",
    "x",
    "y",
    "slot_newGame",
    "slot_open",
    "slot_save",
    "slot_undo",
    "slot_redo",
    "slot_visualizationChange",
    "on_actionExit_triggered",
    "closeEvent",
    "QCloseEvent*",
    "event"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSChessWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   68,    2, 0x08,    1 /* Private */,
       5,    0,   73,    2, 0x08,    4 /* Private */,
       6,    0,   74,    2, 0x08,    5 /* Private */,
       7,    0,   75,    2, 0x08,    6 /* Private */,
       8,    0,   76,    2, 0x08,    7 /* Private */,
       9,    0,   77,    2, 0x08,    8 /* Private */,
      10,    0,   78,    2, 0x08,    9 /* Private */,
      11,    0,   79,    2, 0x08,   10 /* Private */,
      12,    1,   80,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

Q_CONSTINIT const QMetaObject ChessWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSChessWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSChessWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSChessWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ChessWindow, std::true_type>,
        // method 'slot_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_newGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_open'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_save'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_undo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_redo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_visualizationChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionExit_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>
    >,
    nullptr
} };

void ChessWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChessWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slot_clicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->slot_newGame(); break;
        case 2: _t->slot_open(); break;
        case 3: _t->slot_save(); break;
        case 4: _t->slot_undo(); break;
        case 5: _t->slot_redo(); break;
        case 6: _t->slot_visualizationChange(); break;
        case 7: _t->on_actionExit_triggered(); break;
        case 8: _t->closeEvent((*reinterpret_cast< std::add_pointer_t<QCloseEvent*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *ChessWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChessWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSChessWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ChessWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
