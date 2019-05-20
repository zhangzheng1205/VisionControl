/****************************************************************************
** Meta object code from reading C++ file 'terminal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "D:/yanrun/iot_pure/iot_pure/terminal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'terminal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_terminal_t {
    QByteArrayData data[16];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_terminal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_terminal_t qt_meta_stringdata_terminal = {
    {
QT_MOC_LITERAL(0, 0, 8), // "terminal"
QT_MOC_LITERAL(1, 9, 10), // "recvOnePkg"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 3), // "pkg"
QT_MOC_LITERAL(4, 25, 4), // "logd"
QT_MOC_LITERAL(5, 30, 6), // "logTX1"
QT_MOC_LITERAL(6, 37, 6), // "logRX1"
QT_MOC_LITERAL(7, 44, 10), // "onRecvData"
QT_MOC_LITERAL(8, 55, 5), // "doPKG"
QT_MOC_LITERAL(9, 61, 6), // "resCTL"
QT_MOC_LITERAL(10, 68, 11), // "resSampling"
QT_MOC_LITERAL(11, 80, 17), // "env_influence_alc"
QT_MOC_LITERAL(12, 98, 17), // "env_influence_pla"
QT_MOC_LITERAL(13, 116, 12), // "get_alc_temp"
QT_MOC_LITERAL(14, 129, 12), // "get_pla_temp"
QT_MOC_LITERAL(15, 142, 8) // "resDebug"

    },
    "terminal\0recvOnePkg\0\0pkg\0logd\0logTX1\0"
    "logRX1\0onRecvData\0doPKG\0resCTL\0"
    "resSampling\0env_influence_alc\0"
    "env_influence_pla\0get_alc_temp\0"
    "get_pla_temp\0resDebug"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_terminal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    1,   85,    2, 0x06 /* Public */,
       6,    1,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   91,    2, 0x0a /* Public */,
       8,    1,   92,    2, 0x0a /* Public */,
       9,    1,   95,    2, 0x0a /* Public */,
      10,    1,   98,    2, 0x0a /* Public */,
      11,    1,  101,    2, 0x0a /* Public */,
      12,    1,  104,    2, 0x0a /* Public */,
      13,    0,  107,    2, 0x0a /* Public */,
      14,    0,  108,    2, 0x0a /* Public */,
      15,    0,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Float, QMetaType::Float,    2,
    QMetaType::Float, QMetaType::Float,    2,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Void,

       0        // eod
};

void terminal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<terminal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recvOnePkg((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->logd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->logTX1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->logRX1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onRecvData(); break;
        case 5: _t->doPKG((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->resCTL((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 7: _t->resSampling((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 8: { float _r = _t->env_influence_alc((*reinterpret_cast< float(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 9: { float _r = _t->env_influence_pla((*reinterpret_cast< float(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 10: { float _r = _t->get_alc_temp();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 11: { float _r = _t->get_pla_temp();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->resDebug(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (terminal::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&terminal::recvOnePkg)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (terminal::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&terminal::logd)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (terminal::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&terminal::logTX1)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (terminal::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&terminal::logRX1)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject terminal::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_terminal.data,
    qt_meta_data_terminal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *terminal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *terminal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_terminal.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int terminal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void terminal::recvOnePkg(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void terminal::logd(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void terminal::logTX1(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void terminal::logRX1(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
