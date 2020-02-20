main = 3_12.c
maino= 3_12.o
obj = 3_12.exe

$(obj): list.o $(maino)
	gcc list.o $(maino) -o $(obj)
$(maino):$(main)
	gcc -c $(main)
list.o:list.c
	gcc -c list.c

.PHONY:clean
#linux 下用 rm -rf *.o main
clean:
	@echo "=======clean project========="
	del  *.o 
	@echo "=======clean completed========="
