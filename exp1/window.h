#ifndef _WINDOW_
#define _WINDOW_

// std
#include <list>
#include <QWidget>

// Qt
#include <QString>
#include "scene.h"
#include "ui_delaunay.h"

class MainWindow : public QMainWindow, public Ui_MainWindow
{
	Q_OBJECT

private:
	Scene* m_scene;

	unsigned int maxNumRecentFiles;
	QAction* recentFilesSeparator;
	QVector<QAction*> recentFileActs;

public:
	MainWindow();
	~MainWindow();

	void update();

protected:

	protected slots:

		// drag & drop
		void closeEvent(QCloseEvent *event);

		public slots:

			// Data
			void on_actionClear_triggered();
			void on_actionCircle_triggered();

			// View
			void on_actionView_centroids_toggled();
			void on_actionView_Voronoi_edges_toggled();
			void on_actionView_Delaunay_edges_toggled();
			void on_actionView_face_under_mouse_toggled();
			void on_actionView_faces_along_line_toggled();

			// algorithms
			void on_actionLloyd_triggered();
};

#endif // _WINDOW_
