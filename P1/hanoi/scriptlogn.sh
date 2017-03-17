#!/bin/csh -vx


g++ -o hanoi hanoi.cpp  -std=gnu++0x

printf "" > ./salidahanoi.dat


@ i = 1
while ( $i < 30 )
  ./hanoi $i >> ./salidahanoi.dat
  @ i += 1
end

./plot.sh
