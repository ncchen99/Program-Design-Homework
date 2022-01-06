all:
	gcc -c mirror.c
	ar -rc mirror.a mirror.o
	gcc hw0601.c mirror.o -o hw0601 ./mirror.a
	# gcc hw0502.c data.o -o hw0502 ./data.a -lm
	# gcc hw0503.c func.o -o hw0503 ./func.a
	# gcc hw0504.c banqi.o -o hw0504 ./banqi.a -lm