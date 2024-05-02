OPT = -Wall

a03:	main.o Student.o Course.o Registration.o CourseArray.o RegList.o School.o StuArray.o Control.o View.o 
	g++ $(OPT) -o a03 main.o Student.o Course.o Registration.o CourseArray.o RegList.o School.o StuArray.o Control.o View.o 

Student.o:	Student.cc Student.h
	g++ $(OPT) -c Student.cc

Course.o:	Course.cc Course.h
	g++ $(OPT) -c Course.cc

Registration.o:	Registration.cc Registration.h
	g++ $(OPT) -c Registration.cc

CourseArray.o:	CourseArray.cc CourseArray.h
	g++ $(OPT) -c CourseArray.cc

RegList.o:	RegList.cc RegList.h
	g++ $(OPT) -c RegList.cc

School.o:	School.cc School.h
	g++ $(OPT) -c School.cc

StuArray.o:	StuArray.cc StuArray.h
	g++ $(OPT) -c StuArray.cc




View.o:	View.cc View.h
	g++ $(OPT) -c View.cc

Control.o:	Control.cc Control.h
	g++ $(OPT) -c Control.cc

main.o:	main.cc Control.h 
	g++ $(OPT) -c main.cc

clean:
	rm -f *.o a03
