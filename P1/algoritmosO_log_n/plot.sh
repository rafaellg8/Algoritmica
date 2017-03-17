#!/usr/bin/gnuplot
plot 'salidamergesort.dat' title "Mergesort" with lines
set ylabel "Tiempo ms"
set xlabel "Tamaño"
set output "mergesort.png"
set term png

replot

plot 'salidaheapsort.dat' title "Heapsort" with lines
set output "heapsort.png"
replot

plot 'salidaquicksort.dat' title "Quicksort" with lines
set output "quicksort.png"
replot

#ahora vamos a hacer las gráficas ajustadas

f(x) = a0*x*log(x)
fit f(x) 'salidamergesort.dat' via a0

#pintamos
plot 'salidamergesort.dat' , f(x) title "Mergesort curva ajustada"
set output "mergesortAjustada.png"
replot

#Heapsort
fit f(x) 'salidaheapsort.dat' via a0

#pintamos
plot 'salidaheapsort.dat' , f(x) title "Heapsort curva ajustada"
set output "heapsortAjustada.png"
replot

#Quicksort
fit f(x) 'salidaquicksort.dat' via a0

#pintamos
plot 'salidaquicksort.dat' , f(x) title "Quicksort curva ajustada"
set output "quicksortAjustada.png"
replot





quit
