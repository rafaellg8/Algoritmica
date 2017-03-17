#!/bin/csh -vx


g++ -o floyd floyd.cpp  -std=gnu++0x

printf "" > ./salidafloyd.dat


@ i = 25
while ( $i < 675 ) #25 resultados
  ./floyd $i >> ./salidafloyd.dat
  @ i += 25
end

./plot.sh
