/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Graphing/QuadraticGraph/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "setRange"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "xyrange"
QT_MOC_LITERAL(4, 29, 4), // "plot"
QT_MOC_LITERAL(5, 34, 5), // "clear"
QT_MOC_LITERAL(6, 40, 11), // "setEquation"
QT_MOC_LITERAL(7, 52, 9), // "getVertex"
QT_MOC_LITERAL(8, 62, 9), // "setVertex"
QT_MOC_LITERAL(9, 72, 7), // "invertX"
QT_MOC_LITERAL(10, 80, 7), // "invertY"
QT_MOC_LITERAL(11, 88, 21), // "on_invertYbtn_clicked"
QT_MOC_LITERAL(12, 110, 21), // "on_invertXbtn_clicked"
QT_MOC_LITERAL(13, 132, 26), // "on_valueRange_valueChanged"
QT_MOC_LITERAL(14, 159, 4), // "arg1"
QT_MOC_LITERAL(15, 164, 22), // "on_valueA_valueChanged"
QT_MOC_LITERAL(16, 187, 22), // "on_valueB_valueChanged"
QT_MOC_LITERAL(17, 210, 22) // "on_valueC_valueChanged"

    },
    "MainWindow\0setRange\0\0xyrange\0plot\0"
    "clear\0setEquation\0getVertex\0setVertex\0"
    "invertX\0invertY\0on_invertYbtn_clicked\0"
    "on_invertXbtn_clicked\0on_valueRange_valueChanged\0"
    "arg1\0on_valueA_valueChanged\0"
    "on_valueB_valueChanged\0on_valueC_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       4,    0,   87,    2, 0x08 /* Private */,
       5,    0,   88,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    1,   96,    2, 0x08 /* Private */,
      15,    1,   99,    2, 0x08 /* Private */,
      16,    1,  102,    2, 0x08 /* Private */,
      17,    1,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double,   14,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setRange((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 1: _t->plot(); break;
        case 2: _t->clear(); break;
        case 3: _t->setEquation(); break;
        case 4: { QString _r = _t->getVertex();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setVertex(); break;
        case 6: _t->invertX(); break;
        case 7: _t->invertY(); break;
        case 8: _t->on_invertYbtn_clicked(); break;
        case 9: _t->on_invertXbtn_clicked(); break;
        case 10: _t->on_valueRange_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->on_valueA_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->on_valueB_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->on_valueC_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
