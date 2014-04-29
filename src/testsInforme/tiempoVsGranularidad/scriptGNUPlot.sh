set title "Test Tiempo vs Granularidad" #el título de arriba
#set xrange [1:80]
#set yrange [1:1e+10]
set xlabel "Granularidad (n x m)"
set ylabel "Tiempo en segundos"
set grid #para que aparezca la grilla
# set term png size 900, 600  #le digo que la salida es un PNG
# set output "./tiempovsgranularidad.png" #le digo que a la salida la guarde a un archivo, no que la trate de abrir 
set term pdf  #le digo que la salida es un PNG
set output "./tiempovsgranu.pdf" #le digo que a la salida la guarde a un archivo, no que la trate de abrir 
#set logscale #que use escala logarítmica
set key left top samplen 4 #que ponga las leyendas arriba a la izquierda
set style line 1 lt -1 lw 2 pt -1 ps 0.5 #que cambie el tipo de ploteado del primer tipo de línea (ls 1)
set style line 2 lt 1 lw 1 pt 1 ps 0.5 #que cambie el tipo de ploteado del segundo tipo de línea (ls 2)
set style line 3 lt 2 lw 1 pt 3 ps 0.5
set style line 4 lt 3 lw 1 pt 5 ps 0.5
cuad(x) = 1.5*x*x*x/10**11+2
#fit lineal(x) "Tp2Ej3.UnMov.in.testRend" via a
plot cuad(x) ls 1 title "1.5*x³/10¹¹", \
		"./todos-30-100.out" ls 4 title "Tiempo promedio en 5 instancias" # , \
    # "./Ej2/p-no-esta/completo.in.testRend" ls 3 title "q está y p no", \
    # "./Ej2/p-y-q-estan/completo.in.testRend" ls 2 title "p y q están"
# #################################################################################################
# set title "Test Arbol"
# set output "./Ej2/graficos/arbol.png"
# arbol(x) = 1.5*x*(x-1)+1150
# plot arbol(x) ls 1 title "1.5*x*(x-1)+500", \
# 		"./Ej2/ninguno-esta/arbol.in.testRend" ls 4 title "ni p ni q están", \
# 		"./Ej2/p-no-esta/arbol.in.testRend" ls 3 title "q está y p no", \
# 		"./Ej2/p-y-q-estan/arbol.in.testRend" ls 2 title "p y q están"
# #################################################################################################
# set title "Test Dispersos"
# set output "./Ej2/graficos/disperso.png"
# disperso(x) = 0.40*x*x*(x-1)+2000
# plot disperso(x) ls 1 title "0,4*x²(x-1)+2000", \
# 		"./Ej2/ninguno-esta/disperso.in.testRend" ls 4 title "ni p ni q están", \
# 		"./Ej2/p-no-esta/disperso.in.testRend" ls 3 title "q está y p no", \
# 		"./Ej2/p-y-q-estan/disperso.in.testRend" ls 2 title "p y q están"
