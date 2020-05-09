CPPFLAGS= -c -g -Wall -pedantic -std=c++17

__start__: example.out
	./example.out

example.out: Dr3D_gnuplot_api.o main.o  templates.o m_obrotu.o
	g++ -o example.out main.o Dr3D_gnuplot_api.o  templates.o\
	 m_obrotu.o -lpthread

main.o: main.cpp Dr3D_gnuplot_api.hh  templates.cpp m_obrotu.hh
	g++ ${CPPFLAGS} -o main.o main.cpp
#example.o: example.cpp Dr3D_gnuplot_api.hh
#	g++ ${CPPFLAGS} -o example.o example.cpp
templates.o: templates.cpp vector.hh vector.cpp matrix.hh matrix.cpp
	g++ ${CPPFLAGS} -o templates.o templates.cpp

#bryla.o: bryla.cpp bryla.hh rysowanie_int.hh vector.hh
#	g++ ${CPPFLAGS} -o bryla.o bryla.cpp

m_obrotu.o: m_obrotu.cpp m_obrotu.hh matrix.hh
	g++ ${CPPFLAGS} -o m_obrotu.o m_obrotu.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

clear:
	rm example.out
	@rm -f *.o *~
