EIGEN=/usr/local/eigen-3.3.7/
ANN_INCLUDE=/usr/local/ann-1.1.2/include
ANN_LIB=/usr/local/ann-1.1.2/lib

all: test

Dataset.o: Dataset.cpp
	g++ -c -I$(EIGEN) -Wall -Wextra Dataset.cpp

LogisticRegression.o: LogisticRegression.cpp
	g++ -c -I$(EIGEN) -Wall -Wextra LogisticRegression.cpp
	

ConfusionMatrix.o: ConfusionMatrix.cpp
	g++ -c -I$(EIGEN) -I$(ANN_INCLUDE) -Wall -Wextra ConfusionMatrix.cpp	



test: test.cpp ConfusionMatrix.o LogisticRegression.o Dataset.o
	g++ -I$(EIGEN) -I$(ANN_INCLUDE) -Wall -Wextra test.cpp ConfusionMatrix.o LogisticRegression.o Dataset.o -o test -L$(ANN_LIB) -lANN 


.PHONY: all clean

clean:
	rm -f *.o
	rm -f test
