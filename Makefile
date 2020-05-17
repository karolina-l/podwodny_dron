CPPFLAGS= -c -g -Wall -pedantic -std=c++17

__start__: example.out
	./example.out

example.out: Dr3D_gnuplot_api.o main.o interfejs_drona.o prostopadloscian.o dron.o sruba.o graniastoslup.o dno.o tafla.o templates.o m_obrotu.o
	g++ -o example.out main.o interfejs_drona.o Dr3D_gnuplot_api.o prostopadloscian.o dron.o sruba.o graniastoslup.o dno.o tafla.o templates.o\
	 m_obrotu.o -lpthread

main.o: main.cpp Dr3D_gnuplot_api.hh  templates.cpp m_obrotu.hh
	g++ ${CPPFLAGS} -o main.o main.cpp

interfejs_drona.o: sruba.hh dron.hh interfejs_drona.cpp interfejs_drona.hh rysowanie_int.hh vector.hh m_obrotu.hh
	g++ ${CPPFLAGS} -o interfejs_drona.o interfejs_drona.cpp

tafla.o: powierzchnia.hh tafla.cpp tafla.hh rysowanie_int.hh vector.hh
	g++ ${CPPFLAGS} -o tafla.o tafla.cpp

dno.o: powierzchnia.hh dno.cpp dno.hh rysowanie_int.hh vector.hh
	g++ ${CPPFLAGS} -o dno.o dno.cpp

sruba.o: graniastoslup.hh sruba.cpp sruba.hh rysowanie_int.hh vector.hh m_obrotu.hh
	g++ ${CPPFLAGS} -o sruba.o sruba.cpp

graniastoslup.o: bryla.hh graniastoslup.cpp graniastoslup.hh rysowanie_int.hh vector.hh m_obrotu.hh
	g++ ${CPPFLAGS} -o graniastoslup.o graniastoslup.cpp

dron.o: prostopadloscian.o dron.cpp dron.hh rysowanie_int.hh vector.hh m_obrotu.hh
	g++ ${CPPFLAGS} -o dron.o dron.cpp

prostopadloscian.o: bryla.hh prostopadloscian.cpp prostopadloscian.hh rysowanie_int.hh vector.hh m_obrotu.hh
	g++ ${CPPFLAGS} -o prostopadloscian.o prostopadloscian.cpp

m_obrotu.o: m_obrotu.cpp m_obrotu.hh matrix.hh vector.hh
	g++ ${CPPFLAGS} -o m_obrotu.o m_obrotu.cpp

templates.o: templates.cpp vector.hh vector.cpp matrix.hh matrix.cpp
		g++ ${CPPFLAGS} -o templates.o templates.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

clear:
	rm example.out
	@rm -f *.o *~
