/****************************************************************************
** Meta object code from reading C++ file 'homewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../homewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'homewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HomeWindow_t {
    QByteArrayData data[13];
    char stringdata0[345];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HomeWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HomeWindow_t qt_meta_stringdata_HomeWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HomeWindow"
QT_MOC_LITERAL(1, 11, 34), // "on_pushButton_tableCommand_cl..."
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 34), // "on_pushButton_clampCommand_cl..."
QT_MOC_LITERAL(4, 82, 36), // "on_pushButton_doorSPCCommand_..."
QT_MOC_LITERAL(5, 119, 36), // "on_pushButton_doorHABCommand_..."
QT_MOC_LITERAL(6, 156, 32), // "on_pushButton_envCommand_clicked"
QT_MOC_LITERAL(7, 189, 26), // "on_pushButton_stop_clicked"
QT_MOC_LITERAL(8, 216, 25), // "on_pushButton_add_clicked"
QT_MOC_LITERAL(9, 242, 41), // "on_comboBox_subsystem_current..."
QT_MOC_LITERAL(10, 284, 5), // "index"
QT_MOC_LITERAL(11, 290, 28), // "on_pushButton_test_2_clicked"
QT_MOC_LITERAL(12, 319, 25) // "on_pushButton_FSU_clicked"

    },
    "HomeWindow\0on_pushButton_tableCommand_clicked\0"
    "\0on_pushButton_clampCommand_clicked\0"
    "on_pushButton_doorSPCCommand_clicked\0"
    "on_pushButton_doorHABCommand_clicked\0"
    "on_pushButton_envCommand_clicked\0"
    "on_pushButton_stop_clicked\0"
    "on_pushButton_add_clicked\0"
    "on_comboBox_subsystem_currentIndexChanged\0"
    "index\0on_pushButton_test_2_clicked\0"
    "on_pushButton_FSU_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HomeWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    1,   71,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HomeWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HomeWindow *_t = static_cast<HomeWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_tableCommand_clicked(); break;
        case 1: _t->on_pushButton_clampCommand_clicked(); break;
        case 2: _t->on_pushButton_doorSPCCommand_clicked(); break;
        case 3: _t->on_pushButton_doorHABCommand_clicked(); break;
        case 4: _t->on_pushButton_envCommand_clicked(); break;
        case 5: _t->on_pushButton_stop_clicked(); break;
        case 6: _t->on_pushButton_add_clicked(); break;
        case 7: _t->on_comboBox_subsystem_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_test_2_clicked(); break;
        case 9: _t->on_pushButton_FSU_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject HomeWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HomeWindow.data,
      qt_meta_data_HomeWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HomeWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HomeWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HomeWindow.stringdata0))
        return static_cast<void*>(const_cast< HomeWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int HomeWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
