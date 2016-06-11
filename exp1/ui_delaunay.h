/********************************************************************************
** Form generated from reading UI file 'delaunay.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELAUNAY_H
#define UI_DELAUNAY_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "glviewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionClear;
    QAction *actionView_Delaunay_edges;
    QAction *actionView_Voronoi_edges;
    QAction *actionLloyd;
    QAction *actionCircle;
    QAction *actionView_centroids;
    QAction *actionView_face_under_mouse;
    QAction *actionView_faces_along_line;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    GlViewer *viewer;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuData;
    QMenu *menuView;
    QMenu *menuAlgorithms;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(798, 629);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/fileNew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon);
        actionView_Delaunay_edges = new QAction(MainWindow);
        actionView_Delaunay_edges->setObjectName(QString::fromUtf8("actionView_Delaunay_edges"));
        actionView_Delaunay_edges->setCheckable(true);
        actionView_Delaunay_edges->setChecked(true);
        actionView_Voronoi_edges = new QAction(MainWindow);
        actionView_Voronoi_edges->setObjectName(QString::fromUtf8("actionView_Voronoi_edges"));
        actionView_Voronoi_edges->setCheckable(true);
        actionView_Voronoi_edges->setChecked(true);
        actionLloyd = new QAction(MainWindow);
        actionLloyd->setObjectName(QString::fromUtf8("actionLloyd"));
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName(QString::fromUtf8("actionCircle"));
        actionView_centroids = new QAction(MainWindow);
        actionView_centroids->setObjectName(QString::fromUtf8("actionView_centroids"));
        actionView_centroids->setCheckable(true);
        actionView_centroids->setChecked(true);
        actionView_face_under_mouse = new QAction(MainWindow);
        actionView_face_under_mouse->setObjectName(QString::fromUtf8("actionView_face_under_mouse"));
        actionView_face_under_mouse->setCheckable(true);
        actionView_face_under_mouse->setChecked(false);
        actionView_faces_along_line = new QAction(MainWindow);
        actionView_faces_along_line->setObjectName(QString::fromUtf8("actionView_faces_along_line"));
        actionView_faces_along_line->setCheckable(true);
        actionView_faces_along_line->setChecked(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        viewer = new GlViewer(centralwidget);
        viewer->setObjectName(QString::fromUtf8("viewer"));
        viewer->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout->addWidget(viewer, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 798, 21));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuAlgorithms = new QMenu(menubar);
        menuAlgorithms->setObjectName(QString::fromUtf8("menuAlgorithms"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuData->menuAction());
        menubar->addAction(menuAlgorithms->menuAction());
        menubar->addAction(menuView->menuAction());
        menuData->addAction(actionClear);
        menuData->addAction(actionCircle);
        menuView->addAction(actionView_Delaunay_edges);
        menuView->addAction(actionView_Voronoi_edges);
        menuView->addAction(actionView_centroids);
        menuView->addSeparator();
        menuView->addAction(actionView_face_under_mouse);
        menuView->addAction(actionView_faces_along_line);
        menuAlgorithms->addAction(actionLloyd);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CGAL - 2D Delaunay triangulation", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionClear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionClear->setStatusTip(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionClear->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        actionView_Delaunay_edges->setText(QApplication::translate("MainWindow", "Delaunay edges", 0, QApplication::UnicodeUTF8));
        actionView_Delaunay_edges->setShortcut(QApplication::translate("MainWindow", "D", 0, QApplication::UnicodeUTF8));
        actionView_Voronoi_edges->setText(QApplication::translate("MainWindow", "Voronoi edges", 0, QApplication::UnicodeUTF8));
        actionView_Voronoi_edges->setShortcut(QApplication::translate("MainWindow", "V", 0, QApplication::UnicodeUTF8));
        actionLloyd->setText(QApplication::translate("MainWindow", "Lloyd", 0, QApplication::UnicodeUTF8));
        actionLloyd->setShortcut(QApplication::translate("MainWindow", "L", 0, QApplication::UnicodeUTF8));
        actionCircle->setText(QApplication::translate("MainWindow", "Circle", 0, QApplication::UnicodeUTF8));
        actionView_centroids->setText(QApplication::translate("MainWindow", "Centroids", 0, QApplication::UnicodeUTF8));
        actionView_centroids->setShortcut(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        actionView_face_under_mouse->setText(QApplication::translate("MainWindow", "Face under mouse", 0, QApplication::UnicodeUTF8));
        actionView_faces_along_line->setText(QApplication::translate("MainWindow", "Faces along line", 0, QApplication::UnicodeUTF8));
        menuData->setTitle(QApplication::translate("MainWindow", "Data", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuAlgorithms->setTitle(QApplication::translate("MainWindow", "Algorithms", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELAUNAY_H
