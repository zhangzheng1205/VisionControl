/****************************************************************************
** Meta object code from reading C++ file 'prevt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../prevt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prevt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PrEvt_t {
    QByteArrayData data[18];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PrEvt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PrEvt_t qt_meta_stringdata_PrEvt = {
    {
QT_MOC_LITERAL(0, 0, 5), // "PrEvt"
QT_MOC_LITERAL(1, 6, 4), // "logd"
QT_MOC_LITERAL(2, 11, 0), // ""
QT_MOC_LITERAL(3, 12, 16), // "logButtonRevover"
QT_MOC_LITERAL(4, 29, 21), // "clean_stop_ui_recover"
QT_MOC_LITERAL(5, 51, 10), // "logProcess"
QT_MOC_LITERAL(6, 62, 14), // "logProcessComm"
QT_MOC_LITERAL(7, 77, 22), // "logProcessdeeplearning"
QT_MOC_LITERAL(8, 100, 29), // "changeTableRowBackgroundColor"
QT_MOC_LITERAL(9, 130, 13), // "trigger_fuwei"
QT_MOC_LITERAL(10, 144, 13), // "process_event"
QT_MOC_LITERAL(11, 158, 18), // "TotalProcessState*"
QT_MOC_LITERAL(12, 177, 5), // "Total"
QT_MOC_LITERAL(13, 183, 6), // "STAGE*"
QT_MOC_LITERAL(14, 190, 3), // "sta"
QT_MOC_LITERAL(15, 194, 15), // "paraTable_9171*"
QT_MOC_LITERAL(16, 210, 4), // "para"
QT_MOC_LITERAL(17, 215, 1) // "k"

    },
    "PrEvt\0logd\0\0logButtonRevover\0"
    "clean_stop_ui_recover\0logProcess\0"
    "logProcessComm\0logProcessdeeplearning\0"
    "changeTableRowBackgroundColor\0"
    "trigger_fuwei\0process_event\0"
    "TotalProcessState*\0Total\0STAGE*\0sta\0"
    "paraTable_9171*\0para\0k"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrEvt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    0,   65,    2, 0x06 /* Public */,
       5,    1,   66,    2, 0x06 /* Public */,
       6,    1,   69,    2, 0x06 /* Public */,
       7,    1,   72,    2, 0x06 /* Public */,
       8,    2,   75,    2, 0x06 /* Public */,
       9,    0,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    4,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 13, 0x80000000 | 15, QMetaType::Int,   12,   14,   16,   17,

       0        // eod
};

void PrEvt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PrEvt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->logButtonRevover((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->clean_stop_ui_recover(); break;
        case 3: _t->logProcess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->logProcessComm((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->logProcessdeeplearning((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->changeTableRowBackgroundColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->trigger_fuwei(); break;
        case 8: _t->process_event((*reinterpret_cast< TotalProcessState*(*)>(_a[1])),(*reinterpret_cast< STAGE*(*)>(_a[2])),(*reinterpret_cast< paraTable_9171*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PrEvt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrEvt::logd)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PrEvt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrEvt::logButtonRevover)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PrEvt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrEvt::clean_stop_ui_recover)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PrEvt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrEvt::logProcess)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PrEvt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrEvt::logProcessComm)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PrEvt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrEvt::logProcessdeeplearning)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PrEvt::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrEvt::changeTableRowBackgroundColor)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PrEvt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PrEvt::trigger_fuwei)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PrEvt::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_PrEvt.data,
    qt_meta_data_PrEvt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PrEvt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrEvt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PrEvt.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int PrEvt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void PrEvt::logd(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PrEvt::logButtonRevover(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PrEvt::clean_stop_ui_recover()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PrEvt::logProcess(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PrEvt::logProcessComm(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PrEvt::logProcessdeeplearning(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PrEvt::changeTableRowBackgroundColor(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PrEvt::trigger_fuwei()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
