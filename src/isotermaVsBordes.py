#!/usr/bin/python
# coding: utf-8

from sys import argv
from random import randint
from random import seed

def main(arg = argv):
	ri = 10
	re = 1000
	iso = 1500
	inst = 40
	m = 150
	n = 3

	i = 1

	f = open('./testsInforme/isotermaVsBordes/test'+str(i)+'.in', 'w')
	# Escribo datos basicos
	f.write(  str(ri) )
	f.write(" ")
	f.write(  str(re) )
	f.write(" ")
	f.write(  str(m) )
	f.write(" ")
	f.write(  str(n) )
	f.write(" ")
	f.write(  str(iso) )
	f.write(" ")
	f.write( str(inst) )
	f.write("\n")
	# Escribo temperaturas externas e internas
	iter = 0
	for temp in range(2000, 3000, 25):
		arr_temp_int = []
		arr_temp_ext = []

		for j in range(n):
			arr_temp_int.append(temp)
			arr_temp_ext.append(1000-10*iter)

		for j in range(n):
			f.write( str(arr_temp_int[j]) )
			f.write(" ")

		for j in range(n):
			f.write( str(arr_temp_ext[j]) )
			f.write(" ")

		f.write("\n")

		iter += 1
	
	f.close()
				
		

if __name__ == "__main__":
    main()
