#!/bin/csh -vx


g++ -o  insercion insercion.cpp  -std=gnu++0x
g++ -o  burbuja burbuja.cpp  -std=gnu++0x
g++ -o  seleccion seleccion.cpp  -std=gnu++0x




printf "" > ./salidainsercion.dat
printf "" > ./salidaburbuja.dat
printf "" > ./salidaseleccion.dat



@ i = 600
while ( $i < 18600 )
  ./insercion $i >> ./salidainsercion.dat
  @ i += 600
end

@ i = 600
while ( $i < 18600 )
  ./burbuja $i >> ./salidaburbuja.dat
  @ i += 600
end

@ i = 600
while ( $i < 18600 )
  ./seleccion $i >> ./salidaseleccion.dat
  @ i += 600
end

