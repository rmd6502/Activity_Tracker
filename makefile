all : activityTracker

activityTracker : completeActivity.o fillActivityVector.o printActivityVector.o main.o
	g++ $+ -o $@

completeActivity.o : completeActivity.cpp completeActivity.hpp

fillActivityVector.o : fillActivityVector.cpp fillActivityVector.hpp completeActivity.hpp

printActivityVector.o : printActivityVector.cpp printActivityVector.hpp completeActivity.hpp

main.o : main.cpp completeActivity.hpp fillActivityVector.hpp printActivityVector.hpp
