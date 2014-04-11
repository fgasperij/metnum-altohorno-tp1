#!/usr/bin/python
# coding: utf-8

from sys import argv
from random import randint
from random import seed

def main(arg = argv):
	ri = 10
	re = 1000
	iso = 5000
	n = 3
	inst = 1
	temp_int = 10000
	temp_ext = 50

	k = 1

	for i in range(5,150,5):
		f = open('./testsInforme/isotermaVsGranularidad/test'+str(k)+'.in', 'w')
		k += 1
		# Escribo datos basicos
		f.write(  str(ri) )
		f.write(" ")
		f.write(  str(re) )
		f.write(" ")
		f.write(  str(i) )
		f.write(" ")
		f.write(  str(n) )
		f.write(" ")
		f.write(  str(iso) )
		f.write(" ")
		f.write( str(inst) )
		f.write("\n")
		# Escribo temperaturas externas e internas
		arr_temp_int = []
		arr_temp_ext = []

		for j in range(n):
			arr_temp_int.append(temp_int)
			arr_temp_ext.append(temp_ext)

		for j in range(n):
			f.write( str(arr_temp_int[j]) )
			f.write(" ")

		for j in range(n):
			f.write( str(arr_temp_ext[j]) )
			f.write(" ")

		f.write("\n")
		
		f.close()
				
		

if __name__ == "__main__":
    main()
