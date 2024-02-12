/****************************************************************************
** Meta object code from reading C++ file 'ChessWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gui/ChessWindow.h"
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
    "onFileQuit",
    "",
    "onFileNew",
    "onFileSave",
    "onFileLoad",
    "onGameUndo",
    "onGameRedo",
    "onVisualizeMoves",
    "onVisualizeThreatenedEnemy",
    "onVisualizeThreatenedPlayer"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSChessWindowENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[12];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[11];
    char stringdata5[11];
    char stringdata6[11];
    char stringdata7[11];
    char stringdata8[17];
    char stringdata9[27];
    char stringdata10[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSChessWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSChessWindowENDCLASS_t qt_meta_stringdata_CLASSChessWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "ChessWindow"
        QT_MOC_LITERAL(12, 10),  // "onFileQuit"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 9),  // "onFileNew"
        QT_MOC_LITERAL(34, 10),  // "onFileSave"
        QT_MOC_LITERAL(45, 10),  // "onFileLoad"
        QT_MOC_LITERAL(56, 10),  // "onGameUndo"
        QT_MOC_LITERAL(67, 10),  // "onGameRedo"
        QT_MOC_LITERAL(78, 16),  // "onVisualizeMoves"
        QT_MOC_LITERAL(95, 26),  // "onVisualizeThreatenedEnemy"
        QT_MOC_LITERAL(122, 27)   // "onVisualizeThreatenedPlayer"
    },
    "ChessWindow",
    "onFileQuit",
    "",
    "onFileNew",
    "onFileSave",
    "onFileLoad",
    "onGameUndo",
    "onGameRedo",
    "onVisualizeMoves",
    "onVisualizeThreatenedEnemy",
    "onVisualizeThreatenedPlayer"
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
       1,    0,   68,    2, 0x09,    1 /* Protected */,
       3,    0,   69,    2, 0x09,    2 /* Protected */,
       4,    0,   70,    2, 0x09,    3 /* Protected */,
       5,    0,   71,    2, 0x09,    4 /* Protected */,
       6,    0,   72,    2, 0x09,    5 /* Protected */,
       7,    0,   73,    2, 0x09,    6 /* Protected */,
       8,    0,   74,    2, 0x09,    7 /* Protected */,
       9,    0,   75,    2, 0x09,    8 /* Protected */,
      10,    0,   76,    2, 0x09,    9 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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
        // method 'onFileQuit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFileNew'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFileSave'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFileLoad'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onGameUndo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onGameRedo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onVisualizeMoves'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onVisualizeThreatenedEnemy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onVisualizeThreatenedPlayer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ChessWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChessWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onFileQuit(); break;
        case 1: _t->onFileNew(); break;
        case 2: _t->onFileSave(); break;
        case 3: _t->onFileLoad(); break;
        case 4: _t->onGameUndo(); break;
        case 5: _t->onGameRedo(); break;
        case 6: _t->onVisualizeMoves(); break;
        case 7: _t->onVisualizeThreatenedEnemy(); break;
        case 8: _t->onVisualizeThreatenedPlayer(); break;
        default: ;
        }
    }
    (void)_a;
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
