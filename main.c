#include "FPToolkit.c"
#include "M3d_matrix_toolsS.c"
#include "FPToolkit.c"
// #include "light_model.c"
// #include "xwd_tools_03.c"


//3DShapes.c plots various parametric functions on specified domains

double rFactor; //resolution factor

double (*f)(int u, int v);//array of f(t) for x functions
double (*g)(int u, int v);//array of g(t) for y functions
double (*h)(int u, int v);//array of h(t) for z functions

// double (*f_prime)(double u, double v);//array of f(t) for x functions
// double (*g_prime)(double u, double v);//array of g(t) for y functions
// double (*h_prime)(double u, double v);//array of h(t) for z functions


// double ulo, uhi;
// double vlo, vhi;
// double dU, dV;
double zbuf[800][800];
double eye[3], coi[3], up[3] ;


int Tn, Ttypelist[100];
double Tvlist[100];
double V[4][4], Vi[4][4];

int window_width, window_height, window_square_size ;
double Half_window_size ;
double Half_angle_degrees;
double Tan_half_angle ;

int init = 1;
double current_u[10000][10000], current_v[10000][10000];
double current_x[10000][10000], current_z[10000][10000];
double min = -10;
double max = 10;
double M = 10000;
double N = 200;
// double inherent_rgb[3];
// double rgb[3];

// int idA, idB ;
// int textureWidth, textureHeight;
#include "3DFun.c" //function class
#include "plotting.c"
// #include "rgb_mapping.c"
#include "shape_constructors.c"



int main ()
{

  // char nameA[100] ;
  // int idA ;
  // int widthA,heightA ;

  // int d[2],w,h,e ;
  // double rgb[3] ;

  // w = 1 ; h = 1 ;

  // printf("enter name of xwd file\n") ;
  // scanf("%s",nameA) ;
  // idA = init_xwd_map_from_file ("moon.xwd") ;// returns -1 on error, 1 if ok
  // if (idA == -1) { printf("failure\n") ;  exit(0) ; }
  // e = get_xwd_map_dimensions(idA, d) ;
  // if (e == -1) { printf("failure\n") ;  exit(0) ; }
  // textureWidth = d[0] ; textureHeight = d[1] ;

  // idA = create_new_xwd_map (w,h) ;// returns -1 on error, 1 if ok
  // if (idA == -1) { printf("failure\n") ;  exit(0) ; }


  window_width = 800 ; window_height = 800 ;
  // size of largest square INside window
  if (window_width < window_height) { window_square_size = window_width ; }
                               else { window_square_size = window_height ; }
  Half_window_size = 0.5*window_square_size ;
  Half_angle_degrees = 30 ;
  Tan_half_angle = tan(Half_angle_degrees*M_PI/180) ;

  G_init_graphics (window_width, window_height) ;
	int fnum = -55;
	double t;
	int q;

  double x,y,z; x = z = 1; y = 1;
  rFactor = 1;
	while (q != 'q') {


	t = 0.01*fnum;

	eye[0] = x ;
	eye[1] = y ;
	eye[2] = z ;

  coi[0] = 1;
  coi[1] = 0;
  coi[2] = 1;

  up[0] = eye[0];
  up[1] = eye[1] + 1;
  up[2] = eye[2];

  G_rgb(0,0,0) ;
  G_clear() ;

  initZbuf();

    if(q == 65362){
    x += .1; // increase angle of twist
  }else if(q== 65364){
    x -= .1; // decrease angle of twist
  }else if(q == 65363){ // transform eye +
    z -= .1;
  }else if(q == 65361){ // transform eye -
    z += .1;
  }else if(q == 119){
    y += .1;
  }else if (q == 115){
    y -= .1;
  }

  evolve();
  G_rgb(1, 0, 1);
  plane_u(1, 0, 1);
  G_rgb(0, 1, 1);
  plane_v(1, 0, 1);
  usleep(1000);
  q = G_no_wait_key();
  G_display_image();
	fnum+=10;
}


}
