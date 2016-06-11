//Dos de chameau à 6 bosses
//x entre -2 et 2 ; y entre -1 et 1
//beaucoup de valeurs sur l'axe x = 0 et proche, peu autour




int main(){ 

  //Dos de chameau à 6 bosses
  //x entre -2 et 2 ; y entre -1 et 1
  //beaucoup de valeurs sur l'axe x = 0 et proche, peu autour

  Delaunay_triangulation T_chameau_anis;
  std::map<Point, float> function_values_chameau_anis;

  Point p_1_cham(-2., -1.);
  Point p_2_cham(-2., 1.);
  Point p_3_cham(2., -1.);
  Point p_4_cham(2., 1.);
  function_values_chameau_anis.insert(std::make_pair(p_1_cham,function_camel(p_1_cham)));
  function_values_chameau_anis.insert(std::make_pair(p_2_cham,function_camel(p_2_cham)));
  function_values_chameau_anis.insert(std::make_pair(p_3_cham,function_camel(p_3_cham)));
  function_values_chameau_anis.insert(std::make_pair(p_4_cham,function_camel(p_4_cham)));

  T_chameau_anis.insert(p_1_cham);
  T_chameau_anis.insert(p_2_cham);
  T_chameau_anis.insert(p_3_cham);
  T_chameau_anis.insert(p_4_cham);


  for (int i=0 ; i<5; i++){
    float x = rand()/float(RAND_MAX) * 0.1;
    float y = rand()/float(RAND_MAX);
    Point p(x,y);
    Point p_2(x,-y);
    function_values_chameau_anis.insert(std::make_pair(p,function_camel(p)));
    function_values_chameau_anis.insert(std::make_pair(p_2,function_camel(p_2)));
    T_chameau_anis.insert(p);
    T_chameau_anis.insert(p_2);
  }
  
  for (int i=0 ; i<3; i++){
    float x = rand()/float(RAND_MAX) * 2.;
    float y = rand()/float(RAND_MAX);
    Point p(x,y);
    Point p_2(-x,y);
    function_values_chameau_anis.insert(std::make_pair(p,function_camel(p)));
    function_values_chameau_anis.insert(std::make_pair(p_2,function_camel(p_2)));
  }
  
  for (int i=0 ; i<3; i++){
    float x = rand()/float(RAND_MAX) * 2.;
    float y = rand()/float(RAND_MAX);
    Point p(-x,-y);
    Point p_2(x,-y);
    function_values_chameau_anis.insert(std::make_pair(p,function_camel(p)));
    function_values_chameau_anis.insert(std::make_pair(p_2,function_camel(p_2)));
  }


  //Dos de chameau à 6 bosses
  //x entre -2 et 2 ; y entre -1 et 1
  //densité partout pareil

  Delaunay_triangulation T_chameau_iso;
  std::map<Point, float> function_values_chameau_iso;

  function_values_chameau_iso.insert(std::make_pair(p_1_cham,function_camel(p_1_cham)));
  function_values_chameau_iso.insert(std::make_pair(p_2_cham,function_camel(p_2_cham)));
  function_values_chameau_iso.insert(std::make_pair(p_3_cham,function_camel(p_3_cham)));
  function_values_chameau_iso.insert(std::make_pair(p_4_cham,function_camel(p_4_cham)));

  T_chameau_iso.insert(p_1_cham);
  T_chameau_iso.insert(p_2_cham);
  T_chameau_iso.insert(p_3_cham);
  T_chameau_iso.insert(p_4_cham);


  for (int i=0 ; i<3; i++){
    float x = rand()/float(RAND_MAX) * 2.;
    float y = rand()/float(RAND_MAX);
    Point p(x,y);
    Point p_2(-x,-y);
    Point p_3(x,-y);
    Point p_4(-x,y);
    function_values_chameau_iso.insert(std::make_pair(p,function_camel(p)));
    function_values_chameau_iso.insert(std::make_pair(p_2,function_camel(p_2)));
    function_values_chameau_iso.insert(std::make_pair(p_3,function_camel(p_3)));
    function_values_chameau_iso.insert(std::make_pair(p_4,function_camel(p_4)));
 
    T_chameau_iso.insert(p);
    T_chameau_iso.insert(p_2);
    T_chameau_iso.insert(p_3);
    T_chameau_iso.insert(p_4);

  }


  //Fonction affine - points randoms uniformément répartis :

  Delaunay_triangulation T_affine_rand;
  std::map<Point, float> function_values_affine_rand;

  Point p_1_aff(4., 0.);
  Point p_2_aff(0., 0.);
  Point p_3_aff(0., 4.);
  Point p_4_aff(4., 4.);
  function_values_affine_rand.insert(std::make_pair(p_1_aff,function_affine(p_1_aff)));
  function_values_affine_rand.insert(std::make_pair(p_2_aff,function_affine(p_2_aff)));
  function_values_affine_rand.insert(std::make_pair(p_3_aff,function_affine(p_3_aff)));
  function_values_affine_rand.insert(std::make_pair(p_4_aff,function_affine(p_4_aff)));

  T_affine_rand.insert(p_1_aff);
  T_affine_rand.insert(p_2_aff);
  T_affine_rand.insert(p_3_aff);
  T_affine_rand.insert(p_4_aff);



  for (int y=0 ; y<11; y++)
    for (int x=0 ; x<11; x++){
      float x_rand = rand()/float(RAND_MAX) * 4.;
      float y_rand = rand()/float(RAND_MAX) * 4.;
      Point p(x_rand,y_rand);
      function_values_affine_rand.insert(std::make_pair(p,a + bx* x_rand+ by*y_rand));
      T_affine_rand.insert(p);
    }

  //Fonction affine :
  Delaunay_triangulation T_affine;
  std::map<Point, float> function_values_affine;

  for (int y=0 ; y<11; y++)
    for (int x=0 ; x<11; x++){
      Point p(x,y);
      function_values_affine.insert(std::make_pair(p,a + bx* x+ by*y));
      T_affine.insert(p);
    }


  //Fonction cosinus pas aléatoire :
  Delaunay_triangulation T_cosinus;
  std::map<Point, float> function_values_cosinus;

  for (int y=0 ; y<11; y++)
    for (int x=0 ; x<11; x++){
      Point p(x,y);
      function_values_cosinus.insert(std::make_pair(p, cos(x+y)));
      T_cosinus.insert(p);
	}

  //Fonction cosinus - aléa :
  Delaunay_triangulation T_cosinus_alea;
  std::map<Point, float> function_values_cosinus_alea;

  Point p_1_cos(4., 0.);
  Point p_2_cos(0., 0.);
  Point p_3_cos(0., 4.);
  Point p_4_cos(4., 4.);
  function_values_cosinus_alea.insert(std::make_pair(p_1_cos, cos( p_1_cos.x()+p_1_cos.y()) ));
  function_values_cosinus_alea.insert(std::make_pair(p_2_cos, cos( p_2_cos.x()+p_2_cos.y()) ));
  function_values_cosinus_alea.insert(std::make_pair(p_3_cos, cos( p_3_cos.x()+p_3_cos.y()) ));
  function_values_cosinus_alea.insert(std::make_pair(p_4_cos, cos( p_4_cos.x()+p_4_cos.y()) ));

  T_cosinus_alea.insert(p_1_cos);
  T_cosinus_alea.insert(p_2_cos);
  T_cosinus_alea.insert(p_3_cos);
  T_cosinus_alea.insert(p_4_cos);

  for (int y=0 ; y<11; y++)
    for (int x=0 ; x<11; x++){
      float x_rand = rand()/float(RAND_MAX) * 4.;
      float y_rand = rand()/float(RAND_MAX) * 4.;
      Point p(x_rand,y_rand);
      function_values_cosinus_alea.insert(std::make_pair(p, cos(x+y)));
      T_cosinus_alea.insert(p);
    }
  
  return 0;
}
