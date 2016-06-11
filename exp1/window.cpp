// Qt
#include <QtGui>
#include <QActionGroup>
#include <QFileDialog>
#include <QInputDialog>
#include <QClipboard>

#include "window.h"

#include <fstream>

MainWindow::MainWindow() : 
QMainWindow(), Ui_MainWindow(), 
maxNumRecentFiles(15), recentFileActs(15)
{
	setupUi(this);
    
	// init scene
	m_scene = new Scene;
	viewer->set_scene(m_scene);
    
    
	// Handling actions
	connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
	delete m_scene;
}

void MainWindow::update()
{
	viewer->repaint();
}


void MainWindow::closeEvent(QCloseEvent *event)
{
	event->accept();
}



void MainWindow::on_actionClear_triggered()
{
	m_scene->clear();
	update();
}

void MainWindow::on_actionCircle_triggered()
{
	m_scene->insert_circle();
	update();
}


void MainWindow::on_actionView_Delaunay_edges_toggled()
{
	m_scene->toggle_view_Delaunay_edges();
	update();
}

void MainWindow::on_actionView_Voronoi_edges_toggled()
{
	m_scene->toggle_view_Voronoi_edges();
	update();
}

void MainWindow::on_actionView_centroids_toggled()
{
	m_scene->toggle_view_centroids();
	update();
}

void MainWindow::on_actionView_faces_along_line_toggled()
{
	m_scene->toggle_view_faces_along_line();
	update();
}

void MainWindow::on_actionView_face_under_mouse_toggled()
{
	m_scene->toggle_view_face_under_mouse();
	update();
}

void MainWindow::on_actionLloyd_triggered()
{
	m_scene->lloyd();
	update();
}

