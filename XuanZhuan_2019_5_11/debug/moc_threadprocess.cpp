/****************************************************************************
** Meta object code from reading C++ file 'threadprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../threadprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_THREADPROCESS_t {
    QByteArrayData data[13];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_THREADPROCESS_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_THREADPROCESS_t qt_meta_stringdata_THREADPROCESS = {
    {
QT_MOC_LITERAL(0, 0, 13), // "THREADPROCESS"
QT_MOC_LITERAL(1, 14, 24), // "Table2ExcelResultSignalA"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 24), // "Table2ExcelResultSignalB"
QT_MOC_LITERAL(4, 65, 12), // "Table2ExcelA"
QT_MOC_LITERAL(5, 78, 13), // "QTableWidget*"
QT_MOC_LITERAL(6, 92, 6), // "table1"
QT_MOC_LITERAL(7, 99, 6), // "table2"
QT_MOC_LITERAL(8, 106, 6), // "title1"
QT_MOC_LITERAL(9, 113, 6), // "title2"
QT_MOC_LITERAL(10, 120, 12), // "Table2ExcelB"
QT_MOC_LITERAL(11, 133, 5), // "table"
QT_MOC_LITERAL(12, 139, 5) // "title"

    },
    "THREADPROCESS\0Table2ExcelResultSignalA\0"
    "\0Table2ExcelResultSignalB\0Table2ExcelA\0"
    "QTableWidget*\0table1\0table2\0title1\0"
    "title2\0Table2ExcelB\0table\0title"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_THREADPROCESS[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       3,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    5,   44,    2, 0x0a /* Public */,
      10,    3,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 5, QMetaType::QString, QMetaType::QString,    2,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, QMetaType::QString,    2,   11,   12,

       0        // eod
};

void THREADPROCESS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<THREADPROCESS *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Table2ExcelResultSignalA((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->Table2ExcelResultSignalB((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->Table2ExcelA((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTableWidget*(*)>(_a[2])),(*reinterpret_cast< QTableWidget*(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 3: _t->Table2ExcelB((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTableWidget*(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (THREADPROCESS::*)(bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&THREADPROCESS::Table2ExcelResultSignalA)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (THREADPROCESS::*)(bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&THREADPROCESS::Table2ExcelResultSignalB)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject THREADPROCESS::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_THREADPROCESS.data,
    qt_meta_data_THREADPROCESS,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *THREADPROCESS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *THREADPROCESS::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_THREADPROCESS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int THREADPROCESS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void THREADPROCESS::Table2ExcelResultSignalA(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void THREADPROCESS::Table2ExcelResultSignalB(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
