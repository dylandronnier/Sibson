/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created: Sat May 21 13:57:08 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x09,
      43,   11,   11,   11, 0x0a,
      70,   11,   11,   11, 0x0a,
      98,   11,   11,   11, 0x0a,
     132,   11,   11,   11, 0x0a,
     170,   11,   11,   11, 0x0a,
     209,   11,   11,   11, 0x0a,
     250,   11,   11,   11, 0x0a,
     291,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0event\0closeEvent(QCloseEvent*)\0"
    "on_actionClear_triggered()\0"
    "on_actionCircle_triggered()\0"
    "on_actionView_centroids_toggled()\0"
    "on_actionView_Voronoi_edges_toggled()\0"
    "on_actionView_Delaunay_edges_toggled()\0"
    "on_actionView_face_under_mouse_toggled()\0"
    "on_actionView_faces_along_line_toggled()\0"
    "on_actionLloyd_triggered()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 1: _t->on_actionClear_triggered(); break;
        case 2: _t->on_actionCircle_triggered(); break;
        case 3: _t->on_actionView_centroids_toggled(); break;
        case 4: _t->on_actionView_Voronoi_edges_toggled(); break;
        case 5: _t->on_actionView_Delaunay_edges_toggled(); break;
        case 6: _t->on_actionView_face_under_mouse_toggled(); break;
        case 7: _t->on_actionView_faces_along_line_toggled(); break;
        case 8: _t->on_actionLloyd_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    if (!strcmp(_clname, "Ui_MainWindow"))
        return static_cast< Ui_MainWindow*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
