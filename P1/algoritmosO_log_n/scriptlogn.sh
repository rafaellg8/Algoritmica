#!/bin/csh -vx


g++ -o  mergesort mergesort.cpp  -std=gnu++0x
g++ -o  heapsort heapsort.cpp  -std=gnu++0x
g++ -o  quicksort quicksort.cpp  -std=gnu++0x




printf "" > ./salidamergesort.dat
printf "" > ./salidaheapsort.dat
printf "" > ./salidaquicksort.dat



@ i = 440000 
while ( $i < 13200000 )
  ./mergesort $i >> ./salidamergesort.dat
  @ i += 440000 
end

@ i = 440000 
while ( $i < 13200000 )
  ./heapsort $i >> ./salidaheapsort.dat
  @ i += 440000 
end

@ i = 440000 
while ( $i < 13200000 )
  ./quicksort $i >> ./salidaquicksort.dat
  @ i += 440000 
end

./plot.sh
