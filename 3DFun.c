

double c_u(int i, int j){
  return current_u[i][j];
}

double c_v(int i, int j){
  return current_v[i][j];
}

double c_x(int i, int j){
  return current_x[i][j];
}

double c_z(int i, int j){
  return current_z[i][j];
}

double prod_u(double u, double v){ // production function for u
  return 100*u*(1 - v);
}

double prod_v(double u, double v){ // production function for v
  return -100*v*(1 - u);
}

double init_u(double x, double z){ // initial conditions for u over x
    return exp(-x*x-z*z);

}
double init_v(double x, double z){ // initial conditions for v over x
  return 1 - exp(-x*x-z*z);
}

// double diffuse_u(double u){ // diffusion function for u
//   return 0;
// }
//
// double diffuse_v(double u){ // diffusion function for v, function of u
//   return 10*u;
// }

// double secondderivative(double u[3], double deltaX){
//
//     return ((u[2]) - (2 * u[1]) + (u[0])) / (deltaX * deltaX);
//
// }

void evolve(){

  double u[200][200], v[200][200];

  double dX = (max - min)/(N-1);
  double dT = 1/(M-1); // 10 time steps

  int size = N-1;


  // double a[3];        //holds the values around u[i],v[i] for second derivative
  int i = 0, j = 0;
  // double su, sv, diffusion;

  if(init == 1){                   //set up initial conditions
    for(double z = min; z <= max; z += dX){
      i = 0;
    for(double x = min; x <= max; x += dX){
      current_x[i][j] = x;
      current_z[i][j] = z;
      u[i][j] = init_u(x, z);
      v[i][j] = init_v(x, z);
      // prev_u[i][j] = u[i][j]; // state zero
      // prev_v[i][j] = v[i][j];
      current_u[i][j] = u[i][j];
      current_v[i][j] = v[i][j];
    //   if(i > 1 && i < size - 1){
    //   draw_points(x, x + dX, u[i][j], u[i + 1][j+1], 0, 1, 1);  // x1, y1, x2, y2, rgb
    //   draw_points(x, x + dX, v[i][j], v[i + 1][j+1], 0, 1, 0);
    // }
      i++;
    }
    j++;
  }
    init = 0; // every other run is not initial conditions
  }else if(init == 0){
    for(j = 0; j < size; j++){ //evolve u,v
    for(i = 0; i < size; i++){ //evolve u,v
      // if(i >= 1 && i < size - 1){ // evolve the second derivative around i of previous state
      //   a[0] = prev_u[i - 1][j-1];
      //   a[1] = prev_u[i][j];
      //   a[2] = prev_u[i + 1][j+1];
      //   su = secondderivative(a, dX);
      //   a[0] = prev_v[i - 1][j-1];
      //   a[1] = prev_v[i][j];
      //   a[2] = prev_v[i + 1][j+1];
      //   sv = secondderivative(a, dX);
      // }else if(i == size - 1 || i == 0){
      //    su = 1;  // partial u partial x is 0 at the boundary
      //    sv = 1;
      //  }

       // diffusion = diffuse_u(u[i][j]); // evaluate diffusion which depends on u at x
       u[i][j] = u[i][j] + prod_u(u[i][j],v[i][j])*dT; // euler formula

       // diffusion = diffuse_v(u[i][j]); // evaluate diffusion which depends on u at x
       v[i][j] = v[i][j] + prod_v(u[i][j], v[i][j])*dT; //diffusion constant 1/10
       // euler method^^^^
       current_u[i][j] = u[i][j];
       current_v[i][j] = v[i][j];
     //   if(i > 1 && i < size - 1){
     //   draw_points(x, u[i], x + dX, u[i + 1], 0, 1, 1);
     //   draw_points(x, v[i], x + dX, v[i + 1], 0, 1, 0);
     // }
       // x += dX;
     }
   }
}
 //  for(j = 0; j < size; j++){
 //   for(i = 0; i < size; i++){ // copy in current state into previous state
 //     prev_u[i][j] = u[i][j];
 //     prev_v[i][j] = v[i][j];
 //   }
 // }
}
