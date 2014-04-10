#!/usr/bin/python
# coding: utf-8

from sys import argv
from random import randint
from random import seed

def main(arg = argv):
	ri = 10
	re = 20
	iso = 1500
	inst = 1
	temp_int = 2000
	temp_ext = 1000	

	for i in range(5, 50, 5):
		f = open('./testsInforme/tiempoVsGranularidad/test'+str(i)+'.in', 'w+')
		# Escribo datos basicos
		f.write(  str(ri) )
		f.write(" ")
		f.write(  str(re) )
		f.write(" ")
		f.write(  str(i) )
		f.write(" ")
		f.write(  str(i) )
		f.write(" ")
		f.write(  str(iso) )
		f.write(" ")
		f.write( str(inst) )
		f.write("\n")
		# Escribo temperaturas externas e internas
		arr_temp_int = []
		arr_temp_ext = []

		for j in range(i):
			arr_temp_int.append(temp_int)
			arr_temp_ext.append(temp_ext)

		for j in range(i):
			f.write( str(arr_temp_int[j]) )
			f.write(" ")

		for j in range(i):
			f.write( str(arr_temp_ext[j]) )
			f.write(" ")

		f.write("\n")
		
		f.close()
				
		

if __name__ == "__main__":
    main()
