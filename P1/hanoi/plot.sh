#!/usr/bin/gnuplot
plot 'salidahanoi.dat' title "Hanoi" with lines
set ylabel "Tiempo (seg)"
set xlabel "Tamaño"
set output "hanoi.png"
set term png

replot

#ahora vamos a hacer las gráficas ajustadas

f(x) = a0*(2**x) #2^n sintaxis de gnuplot potencia es **
fit f(x) 'salidahanoi.dat' via a0

#pintamos
plot 'salidahanoi.dat' , f(x) title "Hanoi curva ajustada"
set output "hanoiAjustada.png"
replot

quit
