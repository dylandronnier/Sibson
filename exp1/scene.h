#ifndef _SCENE_H_
#define _SCENE_H_

// std
#include <fstream>
#include <algorithm>
#include <list>

// Qt
#include <QtOpenGL>

// CGAL
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include "dt.h"

// Delaunay triangulation
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef CGAL::Triangulation_vertex_base_2<Kernel> Vertex_base;
typedef My_vertex_base<Vertex_base> Vb;
typedef CGAL::Triangulation_face_base_2<Kernel> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb, Fb> TDS;
typedef DT<Kernel, TDS> Triangulation;

#undef min
#undef max


class Scene
{
public:
	typedef Kernel::FT FT;
	typedef Kernel::Point_2 Point;


private:
	// Delaunay triangulation
	Triangulation m_dt;
	bool m_view_centroids;
	bool m_view_voronoi_edges;
	bool m_view_delaunay_edges;
	bool m_view_face_under_mouse;
	bool m_view_faces_along_line;

	Point m_mouse_pos;

public:    
	Scene()
	{
		m_view_centroids = false;
		m_view_voronoi_edges = true;
		m_view_delaunay_edges = false;
		m_view_face_under_mouse = false;
		m_view_faces_along_line = false;

		//this->insert_circle();
		this->insert_points_de_base();
		//this->insert_points_interpolante();
	}

	~Scene()
	{
	}    

	void insert_circle()
	{
		this->clear();
		m_dt.insert_circle(100);
	}

	void insert_points_de_base()
	{
		this->clear();
		m_dt.insert_points_de_base(-2., 8., -3., 4.);
	}

	/*void insert_points_interpolante()
	{
		m_dt.insert_points_interpolante(4.5, 5.5, 10, 8, 255, 0, 0);
	}*/


	// accessors
	Point& mouse_pos() {return m_mouse_pos; }

	void clear()
	{
		m_dt.clear();
	}

	void add_point(const Point& point)
	{
		m_dt.insert(point);
	}

	void render()
	{
		// render generators

		// render Delaunay edges
		if(m_view_delaunay_edges)
			m_dt.gl_draw_delaunay_edges(1.0f, 0, 0, 128); // dark blue line segments

		// render Voronoi edges
		if(m_view_voronoi_edges)
		    //m_dt.gl_draw_voronoi_edges(1.0f, 0, 128, 0); // dark green line segments
		    m_dt.draw_graph(-2., 8., -3., 4., 250, 120, 8.0f);
		

		// render centroids
		if(m_view_centroids)
		    //m_dt.draw_centroids(3.0f, 255, 0, 0); // red points
		    m_dt.gl_draw_generators(3.0f, 0, 0, 0); // black dots


		if(m_view_face_under_mouse)
			m_dt.draw_face_under_mouse(m_mouse_pos, 255, 0, 0);

		if(m_view_faces_along_line)
			m_dt.draw_faces_along_line(0, 0, 255);
	}

	void toggle_view_centroids() { m_view_centroids = !m_view_centroids; }
	void toggle_view_Voronoi_edges() { m_view_voronoi_edges = !m_view_voronoi_edges; }
	void toggle_view_Delaunay_edges() { m_view_delaunay_edges = !m_view_delaunay_edges; }
	void toggle_view_face_under_mouse() { m_view_face_under_mouse = !m_view_face_under_mouse; }
	void toggle_view_faces_along_line() { m_view_faces_along_line = !m_view_faces_along_line; }

	void lloyd()
	{
		m_dt.lloyd(); 
	}

};

#endif // _SCENE_H_
