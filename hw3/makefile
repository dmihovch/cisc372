
image:image.c image.h
	gcc -g image.c -o image -lm

pthreadimage: image_pthread.c image.h
	gcc -g image_pthread.c -o imagethread -lm -lpthread

ompimage: image_omp.c image.h
	gcc -g image_omp.c -o imageomp -lm -fopenmp

clean:
	rm -f image output.png
