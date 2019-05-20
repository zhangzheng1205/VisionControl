/****************************************************************************
** Meta object code from reading C++ file 'app_autoctl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../app_autoctl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'app_autoctl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PidCtrl_t {
    QByteArrayData data[10];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PidCtrl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PidCtrl_t qt_meta_stringdata_PidCtrl = {
    {
QT_MOC_LITERAL(0, 0, 7), // "PidCtrl"
QT_MOC_LITERAL(1, 8, 13), // "logPidCtrl_xw"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "logProcess"
QT_MOC_LITERAL(4, 34, 11), // "logAutoCtrl"
QT_MOC_LITERAL(5, 46, 18), // "logAutoCtrljiujing"
QT_MOC_LITERAL(6, 65, 11), // "autoCTLTask"
QT_MOC_LITERAL(7, 77, 14), // "autoCTL_Cache*"
QT_MOC_LITERAL(8, 92, 3), // "Oil"
QT_MOC_LITERAL(9, 96, 1) // "k"

    },
    "PidCtrl\0logPidCtrl_xw\0\0logProcess\0"
    "logAutoCtrl\0logAutoCtrljiujing\0"
    "autoCTLTask\0autoCTL_Cache*\0Oil\0k"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PidCtrl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,
       4,    1,   45,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,

       0        // eod
};

void PidCtrl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PidCtrl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logPidCtrl_xw((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->logProcess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->logAutoCtrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->logAutoCtrljiujing((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->autoCTLTask((*reinterpret_cast< autoCTL_Cache*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PidCtrl::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PidCtrl::logPidCtrl_xw)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PidCtrl::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PidCtrl::logProcess)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PidCtrl::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PidCtrl::logAutoCtrl)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PidCtrl::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PidCtrl::logAutoCtrljiujing)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PidCtrl::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_PidCtrl.data,
    qt_meta_data_PidCtrl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PidCtrl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PidCtrl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PidCtrl.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int PidCtrl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void PidCtrl::logPidCtrl_xw(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PidCtrl::logProcess(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PidCtrl::logAutoCtrl(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PidCtrl::logAutoCtrljiujing(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
