


void plane_u(double x, double y, double z){

		double A[4][4], Ai[4][4];
		double RES = 100000;

	  f = c_x;
	  g = c_u;
	  h = c_z;

		Tn = 0 ;
	  Ttypelist[Tn] = SX ; Tvlist[Tn] = .2 ; Tn++ ;
	  Ttypelist[Tn] = SY ; Tvlist[Tn] = .2  ; Tn++ ;
	  Ttypelist[Tn] = SZ ; Tvlist[Tn] = .2  ; Tn++ ;
		Ttypelist[Tn] = TX ; Tvlist[Tn] = x   ; Tn++ ;
		Ttypelist[Tn] = TY ; Tvlist[Tn] = y   ; Tn++ ;
		Ttypelist[Tn] = TZ ; Tvlist[Tn] = z   ; Tn++ ;


		M3d_make_movement_sequence_matrix(A, Ai, Tn,
			Ttypelist, Tvlist); //move object

	  plot(A);
}

void plane_v(double x, double y, double z){

		double A[4][4], Ai[4][4];
		double RES = 100;

	  f = c_x;
	  g = c_v;
	  h = c_z;

		Tn = 0 ;
	  Ttypelist[Tn] = SX ; Tvlist[Tn] = .2 ; Tn++ ;
	  Ttypelist[Tn] = SY ; Tvlist[Tn] = .2  ; Tn++ ;
	  Ttypelist[Tn] = SZ ; Tvlist[Tn] = .2  ; Tn++ ;
		Ttypelist[Tn] = TX ; Tvlist[Tn] = x   ; Tn++ ;
		Ttypelist[Tn] = TY ; Tvlist[Tn] = y   ; Tn++ ;
		Ttypelist[Tn] = TZ ; Tvlist[Tn] = z   ; Tn++ ;


		M3d_make_movement_sequence_matrix(A, Ai, Tn,
			Ttypelist, Tvlist); //move object

	  plot(A);
}
