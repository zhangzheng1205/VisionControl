/****************************************************************************
** Meta object code from reading C++ file 'gbase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gbase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gbase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GBase_t {
    QByteArrayData data[26];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GBase_t qt_meta_stringdata_GBase = {
    {
QT_MOC_LITERAL(0, 0, 5), // "GBase"
QT_MOC_LITERAL(1, 6, 10), // "recvOnePkg"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 3), // "pkg"
QT_MOC_LITERAL(4, 22, 14), // "updateSampling"
QT_MOC_LITERAL(5, 37, 13), // "GSimplingData"
QT_MOC_LITERAL(6, 51, 3), // "res"
QT_MOC_LITERAL(7, 55, 4), // "logd"
QT_MOC_LITERAL(8, 60, 5), // "logTX"
QT_MOC_LITERAL(9, 66, 5), // "logRX"
QT_MOC_LITERAL(10, 72, 17), // "setUIAngleAndTime"
QT_MOC_LITERAL(11, 90, 5), // "angle"
QT_MOC_LITERAL(12, 96, 4), // "time"
QT_MOC_LITERAL(13, 101, 9), // "getResult"
QT_MOC_LITERAL(14, 111, 18), // "setStartTimesValue"
QT_MOC_LITERAL(15, 130, 10), // "onRecvData"
QT_MOC_LITERAL(16, 141, 5), // "doPKG"
QT_MOC_LITERAL(17, 147, 10), // "sendCTLPkg"
QT_MOC_LITERAL(18, 158, 10), // "reqSetWiFi"
QT_MOC_LITERAL(19, 169, 9), // "reqSettem"
QT_MOC_LITERAL(20, 179, 11), // "ptSettemReq"
QT_MOC_LITERAL(21, 191, 2), // "st"
QT_MOC_LITERAL(22, 194, 15), // "reqSetBJ_dianji"
QT_MOC_LITERAL(23, 210, 5), // "delay"
QT_MOC_LITERAL(24, 216, 15), // "setAngleGetTime"
QT_MOC_LITERAL(25, 232, 15) // "setTimeGetAngle"

    },
    "GBase\0recvOnePkg\0\0pkg\0updateSampling\0"
    "GSimplingData\0res\0logd\0logTX\0logRX\0"
    "setUIAngleAndTime\0angle\0time\0getResult\0"
    "setStartTimesValue\0onRecvData\0doPKG\0"
    "sendCTLPkg\0reqSetWiFi\0reqSettem\0"
    "ptSettemReq\0st\0reqSetBJ_dianji\0delay\0"
    "setAngleGetTime\0setTimeGetAngle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GBase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,
       7,    1,  105,    2, 0x06 /* Public */,
       8,    1,  108,    2, 0x06 /* Public */,
       9,    1,  111,    2, 0x06 /* Public */,
      10,    2,  114,    2, 0x06 /* Public */,
      13,    1,  119,    2, 0x06 /* Public */,
      14,    1,  122,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  125,    2, 0x0a /* Public */,
      16,    1,  126,    2, 0x0a /* Public */,
      17,    3,  129,    2, 0x0a /* Public */,
      18,    2,  136,    2, 0x0a /* Public */,
      19,    1,  141,    2, 0x0a /* Public */,
      22,    0,  144,    2, 0x0a /* Public */,
      23,    1,  145,    2, 0x0a /* Public */,
      24,    1,  148,    2, 0x0a /* Public */,
      25,    1,  151,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Float,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void GBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recvOnePkg((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->updateSampling((*reinterpret_cast< GSimplingData(*)>(_a[1]))); break;
        case 2: _t->logd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->logTX((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->logRX((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setUIAngleAndTime((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->getResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setStartTimesValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->onRecvData(); break;
        case 9: _t->doPKG((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: _t->sendCTLPkg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 11: _t->reqSetWiFi((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->reqSettem((*reinterpret_cast< ptSettemReq(*)>(_a[1]))); break;
        case 13: _t->reqSetBJ_dianji(); break;
        case 14: _t->delay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setAngleGetTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->setTimeGetAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GBase::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GBase::recvOnePkg)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GBase::*)(GSimplingData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GBase::updateSampling)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GBase::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GBase::logd)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GBase::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GBase::logTX)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GBase::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GBase::logRX)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GBase::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GBase::setUIAngleAndTime)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GBase::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GBase::getResult)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GBase::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GBase::setStartTimesValue)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GBase::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_GBase.data,
    qt_meta_data_GBase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GBase.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int GBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void GBase::recvOnePkg(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GBase::updateSampling(GSimplingData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GBase::logd(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GBase::logTX(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GBase::logRX(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GBase::setUIAngleAndTime(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GBase::getResult(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GBase::setStartTimesValue(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
