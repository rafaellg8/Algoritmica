#!/usr/bin/gnuplot
plot 'salidafloyd.dat' title "Floyd" with lines
set ylabel "Tiempo (seg)"
set xlabel "Tamaño"
set output "floyd.png"
set term png

replot

#ahora vamos a hacer las gráficas ajustadas

f(x) = a0*x*x*x
fit f(x) 'salidafloyd.dat' via a0

#pintamos
plot 'salidafloyd.dat' , f(x) title "Floyd curva ajustada"
set output "floydAjustada.png"
replot

quit
